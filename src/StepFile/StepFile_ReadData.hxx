/* 
 Copyright (c) 1999-2020 OPEN CASCADE SAS

 This file is part of Open CASCADE Technology software library.

 This library is free software; you can redistribute it and/or modify it under
 the terms of the GNU Lesser General Public License version 2.1 as published
 by the Free Software Foundation, with special exception defined in the file
 OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
 distribution for complete text of the license and disclaimer of any warranty.

 Alternatively, this file may be used under the terms of Open CASCADE
 commercial license or contractual agreement.
*/ 

#ifndef _StepFile_ReadData_HeaderFile
#define _StepFile_ReadData_HeaderFile

#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Standard_DefineAlloc.hxx>

#include <Interface_ParamType.hxx>

//! Provides data structures and tools to collect and store the data
//! read from the STEP file. 
//! This class is designed to work in collaboration with STEP parser
//! built using flex and bison (receives the data generated by the parser).
//!
//! All text (sequence of characters) received in the parsing process
//! is stored in the CharacterPage, but the last received text value is
//! stored in a pointer to an own page position.
//!
//! This value is used to initialize a new record (representation of the
//! STEP entity) and its arguments (parameters of the STEP entity).
//! All created arguments are stored in the ArgumentsPage, records in the RecordsPage.
//!
//! NOTE:
//! - Arguments used in the record are pointers to the element of the page,
//! - All records are pointers to the element of the record page.
//!
//! EXAMPLE of parsing STEP file (flex & bison):
//!
//! 1. Initial state:
//!     - Input stream to the Flex is "#123=ADVANCED_FACE('',(#124),#125,.F.)"
//!     - State of Flex is "INITIAL"
//!     - Stack of Bison states : STEP HEADER ENDSEC endhead model block
//! 2. Flex rule detected "#123" - call CreateNewText("#123", 4)
//!    and sends a token "ENTITY". 
//!    Now class contains "#123", as current text value.
//! 3. Bison receive a token and call RecordIdent (), it
//!    creates a new record in the records page with "#123" identifier.
//!    Now current record has ident, but args and types are empty.
//! 4. Flex rule detected "ADVANCED_FACE" call CreateNewText and send a token "TYPE".
//!    Now class contains "ADVANCED_FACE", as current text value.
//! 5. Bison receive  a token and call RecordType (), it
//!    set "ADVANCED_FACE" to the current record as a type.
//!    Now current record has ident and type, but args are empty.
//! 6. Flex rule detected "(" send token "(".
//!    Now class continues to contain "ADVANCED_FACE", as current text value.
//! 7. Bison receive  a token and call RecordListStart (),
//!    it does nothing via the current state.
//!    Now current record is not update.
//! 8. Flex rule detected ('') call CreateNewText and SetTypeArg and
//!    send token TEXT. 
//!    Now class contains empty current text value.
//! 9. Bison receive  a token and call CreateNewArg (), it
//!    creates a new argument with empty text value and 'Text' type.
//!    Now current record has ident, type and one argument.
//! 10. Flex rule detected "," call PrepareNewArg(",",1), it
//!     controls arguments count to protect from a skip or double creating a new argument.
//!     Bison does nothing and the current text value and record are not updated.
//! 11. Flex rule detected "(" send token "(".
//!     Now class continues to contain empty current text value.
//! 12. Bison receive  a token and call RecordListStart (), it
//!     creates a new record with "$1" ident and "ADVANCED_FACE" type
//!     old record is the next of the new record.
//!     Now current record has ident, type, but args are empty.
//! 13. Flex  rule detected "#124" call CreateNewText("#124",4) and send token "IDENT",
//!     Now class contains "#124", as current text value.
//! 14. Bison receive  a token and call CreateNewArg (), it
//!     creates a new argument with "#124" text value and 'Ident' type.
//!     Now current record has ident, type and one argument.
//! 15. Flex rule detected ")" send token ")".
//!     Now class continues to contain "#124", as a current text value.
//! 16. Bison receive  a token and call RecordNewEntity (), it
//!     contain record to the records page, prepare to the new record
//!     and get next record as a current record and set a new arg as a sub_record.
//!     Now current record is a old record, it has ident, type and two args.
//! 17. Flex rule detected "#125" call CreateNewText, SetTypeArg and send token IDEND. 
//!     Now class contains "#125", as a current text value.
//! 18. Bison receive  a token and call CreateNewArg (), it
//!     creates a new argument with "#125" text value and 'Ident' type.
//!     Now current record has ident, type and three argument.
//! 19. Flex rule detected "#125" call CreateNewText, SetTypeArg and send token IDEND. 
//!     Now class contains "#125", as a current text value.
//! 20. Bison receive  a token and call CreateNewArg (), it
//!     creates a new argument with "#125" text value and 'Ident' type.
//!     Now current record has ident, type and three argument.
//! ...
//!
//! Reading of several STEP files simultaneously is possible (e.g. in multiple
//! threads) provided that each file is read using its own instances of Flex, Bison
//! and StepFile_ReadData tools.

class Interface_Check;

class StepFile_ReadData
{
public:
  // Standard OCCT memory allocation stuff
  DEFINE_STANDARD_ALLOC

private:

  class CharactersPage; //!< List of characters pages, contains all text derived from Flex
  class Record;         //!< List of records, contains all text processed by Bison
  class Argument;       //!< List of arguments, contains all argument descriptions
  class ArgumentsPage;  //!< List of arguments pages, contains all text derived from Flex
  class Scope;          //!< List of scopes pages, contains all records for external processing
  class RecordsPage;    //!< List of records pages, contains all records
  class ErrorsPage;     //!< List of errors messages, contains all errors

public:

  //! Constructs an uninitialized tool
  StepFile_ReadData();

  //! Destructor cleans allocated memory of all fields
  ~StepFile_ReadData() { ClearRecorder(3); }

  //! Preperes the text value for analysis.
  //! It is the main tool for transferring data from flex to bison
  //! If characters page is full, allocates a new page.
  void CreateNewText(const char* theNewText, int theLenText);

  //! Adds the current record to the list
  void RecordNewEntity();

  //! Creates a new record and sets Ident from myResText
  void RecordIdent();

  //! Starts reading of the type (entity)
  void RecordType();

  //! Prepares and saves a record or sub-record
  void RecordListStart();

  //! Prepares new arguments.
  //! Type and value already known.
  //! If arguments page is full, allocates a new page
  void CreateNewArg();

  //! Prepares error arguments, controls count of error arguments.
  //! If bison handles a sequence of error types,
  //! creates only one argument and updates text value
  void CreateErrorArg();

  //! Creates a new scope, containing the current record
  void AddNewScope();

  //! Ends the scope
  void FinalOfScope();

  //! Releases memory.
  //! @param theMode
  //! * 1 - clear pages of records and arguments
  //! * 2 - clear pages of characters
  //! * 3 - clear all data
  void ClearRecorder(const Standard_Integer theMode);

  //! Returns a value of fields of current argument
  Standard_Boolean GetArgDescription(Interface_ParamType* theType, char** theValue);

  //! Returns a value of all file counters
  void GetFileNbR(Standard_Integer* theNbHead, Standard_Integer* theNbRec, Standard_Integer* theNbPage);

  //! Returns a value of fields of current record
  Standard_Boolean GetRecordDescription(char** theIdent, char** theType, int* theNbArg);

  //! Initializes the record type with myResText
  void RecordTypeText();

  //! Skips to next record
  void NextRecord();

  //! Prints data of current record according to the modeprint
  void PrintCurrentRecord();

  //! Controls the correct argument count for the record.
  //! Resets error argyment mode
  void PrepareNewArg();

  //! Prepares the end of the head section
  void FinalOfHead();

  //! Sets type of the current argument
  void SetTypeArg(const Interface_ParamType theArgType);

  //! Initializes the print mode
  //! 0 - don't print descriptions
  //! 1 - print only descriptions  of record
  //! 2 - print descriptions of records and its arguments
  void SetModePrint(const Standard_Integer theMode);

  //! Returns mode print
  Standard_Integer GetModePrint() const;

  //! Returns number of records
  Standard_Integer GetNbRecord() const;

  //! Adds an error message
  void AddError(Standard_CString theErrorMessage);

  //! Transfers error messages to checker
  Standard_Boolean ErrorHandle(const Handle(Interface_Check)& theCheck) const;

  //! Returns the message of the last error
  Standard_CString GetLastError() const;

private:

  //! Prepare text to analyze
  char* RecordNewText(char* theText);

  //! Get current text value
  void GetResultText(char** theText);

  //! Add a record to the current records page
  void AddNewRecord(Record* theNewRecord);

  //! Create new empty record
  //! If records page is fill, add a new page
  Record* CreateNewRecord();

  //! Print data of the record according to the modeprint
  void PrintRecord(Record* theRecord);

private:

  Standard_Integer myMaxChar;    //!< Maximum number of characters in a characters page
  Standard_Integer myMaxRec;     //!< Maximum number of records in a records page
  Standard_Integer myMaxArg;     //!< Maximum number of arguments in a arguments page
  Standard_Integer myModePrint;  //!< Control print output (for call from yacc)
  Standard_Integer myNbRec;      //!< Total number of data records read
  Standard_Integer myNbHead;     //!< Number of records taken by the Header
  Standard_Integer myNbPar;      //!< Total number of parameters read
  Standard_Integer myYaRec;      //!< Presence record already created (after 1 Ident)
  Standard_Integer myNumSub;     //!< Number of current sublist
  Standard_Boolean myErrorArg;   //!< Control of error argument (true - error argument was created)
  char* myResText;               //!< Text value written by Flex and passed to Bison to create record
  char* myCurrType;              //!< Type of last record read
  char* mySubArg;                //!< Ident last record (possible sub-list)
  Interface_ParamType myTypeArg; //!< Type of last argument read
  Argument* myCurrArg;           //!< Current node of the arguments list
  Record* myFirstRec;            //!< First node of the records list
  Record* myCurRec;              //!< Current node of the records list
  Record* myLastRec;             //!< Last node of the records list
  Scope* myCurScope;             //!< Current node of the scopes list
  ErrorsPage* myFirstError;      //!< First node of the errors pages list
  ErrorsPage* myCurError;        //!< Current node of the errors pages list
  RecordsPage* myOneRecPage;     //!< Current node of the records pages list
  CharactersPage* myOneCharPage; //!< Current node of the characters pages list
  ArgumentsPage* myOneArgPage;   //!< Current node of the arguments pages list
};

#endif // _StepFile_ReadData_HeaderFile
