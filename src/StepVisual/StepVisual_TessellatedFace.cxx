// Created on : Thu Mar 24 18:30:12 2022 
// Created by: snn
// Generator: Express (EXPRESS -> CASCADE/XSTEP Translator) V2.0
// Copyright (c) Open CASCADE 2022
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#include <StepVisual_TessellatedFace.hxx>

IMPLEMENT_STANDARD_RTTIEXT(StepVisual_TessellatedFace, StepVisual_TessellatedStructuredItem)

//=======================================================================
//function : StepVisual_TessellatedFace
//purpose  : 
//=======================================================================

StepVisual_TessellatedFace::StepVisual_TessellatedFace ()
{
  myHasGeometricLink = Standard_False;
}

//=======================================================================
//function : Init
//purpose  : 
//=======================================================================

void StepVisual_TessellatedFace::Init (const Handle(TCollection_HAsciiString)& theRepresentationItem_Name,
                                       const Handle(StepVisual_CoordinatesList)& theCoordinates,
                                       const Standard_Integer thePnmax,
                                       const Handle(TColStd_HArray2OfReal)& theNormals,
                                       const Standard_Boolean theHasGeometricLink,
                                       const StepVisual_FaceOrSurface& theGeometricLink)
{
  StepVisual_TessellatedStructuredItem::Init(theRepresentationItem_Name);

  myCoordinates = theCoordinates;

  myPnmax = thePnmax;

  myNormals = theNormals;

  myHasGeometricLink = theHasGeometricLink;
  if (myHasGeometricLink)
  {
    myGeometricLink = theGeometricLink;
  }
  else
  {
    myGeometricLink = StepVisual_FaceOrSurface();
  }
}

//=======================================================================
//function : Coordinates
//purpose  : 
//=======================================================================

Handle(StepVisual_CoordinatesList) StepVisual_TessellatedFace::Coordinates () const
{
  return myCoordinates;
}

//=======================================================================
//function : SetCoordinates
//purpose  : 
//=======================================================================

void StepVisual_TessellatedFace::SetCoordinates(const Handle(StepVisual_CoordinatesList)& theCoordinates)
{
  myCoordinates = theCoordinates;
}

//=======================================================================
//function : Pnmax
//purpose  : 
//=======================================================================

Standard_Integer StepVisual_TessellatedFace::Pnmax () const
{
  return myPnmax;
}

//=======================================================================
//function : SetPnmax
//purpose  : 
//=======================================================================

void StepVisual_TessellatedFace::SetPnmax(const Standard_Integer thePnmax)
{
  myPnmax = thePnmax;
}

//=======================================================================
//function : Normals
//purpose  : 
//=======================================================================

Handle(TColStd_HArray2OfReal) StepVisual_TessellatedFace::Normals () const
{
  return myNormals;
}

//=======================================================================
//function : SetNormals
//purpose  : 
//=======================================================================

void StepVisual_TessellatedFace::SetNormals(const Handle(TColStd_HArray2OfReal)& theNormals)
{
  myNormals = theNormals;
}

//=======================================================================
//function : NbNormals
//purpose  : 
//=======================================================================

Standard_Integer StepVisual_TessellatedFace::NbNormals() const
{
  if (myNormals.IsNull())
  {
    return 0;
  }
  return myNormals->ColLength();
}

//=======================================================================
//function : GeometricLink
//purpose  : 
//=======================================================================

StepVisual_FaceOrSurface StepVisual_TessellatedFace::GeometricLink () const
{
  return myGeometricLink;
}

//=======================================================================
//function : SetGeometricLink
//purpose  : 
//=======================================================================

void StepVisual_TessellatedFace::SetGeometricLink(const StepVisual_FaceOrSurface& theGeometricLink)
{
  myGeometricLink = theGeometricLink;
}

//=======================================================================
//function : HasGeometricLink
//purpose  : 
//=======================================================================

Standard_Boolean StepVisual_TessellatedFace::HasGeometricLink () const
{
  return myHasGeometricLink;
}
