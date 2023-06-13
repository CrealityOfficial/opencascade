// Created on: 1996-03-05
// Created by: Joelle CHAUVET
// Copyright (c) 1996-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
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

#ifndef _GeomPlate_MakeApprox_HeaderFile
#define _GeomPlate_MakeApprox_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Integer.hxx>
#include <GeomAbs_Shape.hxx>
class GeomPlate_Surface;
class Geom_BSplineSurface;
class AdvApp2Var_Criterion;



//! Allows you to convert a GeomPlate surface into a BSpline.
class GeomPlate_MakeApprox 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Converts SurfPlate into a Geom_BSplineSurface with
  //! n Bezier pieces (n<=Nbmax) of degree <= dgmax
  //! and an approximation error < Tol3d if possible
  //! the criterion CritPlate is satisfied if possible
  Standard_EXPORT GeomPlate_MakeApprox(const Handle(GeomPlate_Surface)& SurfPlate, const AdvApp2Var_Criterion& PlateCrit, const Standard_Real Tol3d, const Standard_Integer Nbmax, const Standard_Integer dgmax, const GeomAbs_Shape Continuity = GeomAbs_C1, const Standard_Real EnlargeCoeff = 1.1);
  
  //! Converts SurfPlate into a Geom_BSplineSurface with
  //! n Bezier pieces (n<=Nbmax) of degree <= dgmax
  //! and an approximation error < Tol3d if possible
  //! if CritOrder = -1 , no criterion is used
  //! if CritOrder = 0 , a PlateG0Criterion is used with max value > 10*dmax
  //! if CritOrder = 1 , a PlateG1Criterion is used with max value > 10*dmax
  //! WARNING : for CritOrder = 0 or 1, only the constraints points of SurfPlate
  //! are used to evaluate the value of the criterion
  Standard_EXPORT GeomPlate_MakeApprox(const Handle(GeomPlate_Surface)& SurfPlate, const Standard_Real Tol3d, const Standard_Integer Nbmax, const Standard_Integer dgmax, const Standard_Real dmax, const Standard_Integer CritOrder = 0, const GeomAbs_Shape Continuity = GeomAbs_C1, const Standard_Real EnlargeCoeff = 1.1);
  
  //! Returns the BSpline surface extracted from the
  //! GeomPlate_MakeApprox object.
  Standard_EXPORT Handle(Geom_BSplineSurface) Surface() const;
  
  //! Returns the error in computation of the approximation
  //! surface. This is the distance between the entire target
  //! BSpline surface and the entire original surface
  //! generated by BuildPlateSurface and converted by GeomPlate_Surface.
  Standard_EXPORT Standard_Real ApproxError() const;
  
  //! Returns the criterion error in computation of the
  //! approximation surface. This is estimated relative to the
  //! curve and point constraints only.
  Standard_EXPORT Standard_Real CriterionError() const;




protected:





private:



  Handle(GeomPlate_Surface) myPlate;
  Handle(Geom_BSplineSurface) mySurface;
  Standard_Real myAppError;
  Standard_Real myCritError;


};







#endif // _GeomPlate_MakeApprox_HeaderFile
