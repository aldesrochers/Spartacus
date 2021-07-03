// ============================================================================
// Copyright (C) 2021-
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// Alexis L. Desrochers (alexisdesrochers@gmail.com)
//
// ============================================================================


#ifndef __XSMP_BimetallicCable01_hxx__
#define __XSMP_BimetallicCable01_hxx__

// OpenCascade
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Real.hxx>

// Spartacus
#include <XSMP_Model.hxx>
#include <UCrM_Model.hxx>
#include <USSM_Model.hxx>
#include <UThM_Model.hxx>


// ============================================================================
/*!
 *  \brief XSMP_BimetallicCable01
*/
// ============================================================================
class Standard_EXPORT XSMP_BimetallicCable01 : public XSMP_Model
{

public:

    DEFINE_STANDARD_ALLOC;

public:
    // constructors
    XSMP_BimetallicCable01();
    XSMP_BimetallicCable01(const Standard_Real Area1,
                           const Standard_Real Area2);
    XSMP_BimetallicCable01(const Standard_Real Area1,
                           const Standard_Real Area2,
                           const Handle(USSM_Model) StressStrainModel1,
                           const Handle(USSM_Model) StressStrainModel2);
    XSMP_BimetallicCable01(const Standard_Real Area1,
                           const Standard_Real Area2,
                           const Handle(USSM_Model) StressStrainModel1,
                           const Handle(UThM_Model) ThermalModel1,
                           const Handle(USSM_Model) StressStrainModel2,
                           const Handle(UThM_Model) ThermalModel2);
    XSMP_BimetallicCable01(const Standard_Real Area1,
                           const Standard_Real Area2,
                           const Handle(USSM_Model) StressStrainModel1,
                           const Handle(UThM_Model) ThermalModel1,
                           const Handle(UCrM_Model) CreepModel1,
                           const Handle(USSM_Model) StressStrainModel2,
                           const Handle(UThM_Model) ThermalModel2,
                           const Handle(UCrM_Model) CreepModel2);
    // destructors
    ~XSMP_BimetallicCable01();

public:

    Standard_Real           Area1() const;
    Standard_Real           Area2() const;
    Handle(UCrM_Model)      CreepModel1() const;
    Handle(UCrM_Model)      CreepModel2() const;
    Handle(USSM_Model)      StressStrainModel1() const;
    Handle(USSM_Model)      StressStrainModel2() const;
    Handle(UThM_Model)      ThermalModel1() const;
    Handle(UThM_Model)      ThermalModel2() const;

    void                    SetArea1(const Standard_Real Area1);
    void                    SetArea2(const Standard_Real Area2);
    void                    SetCreepModel1(const Handle(UCrM_Model) CreepModel1);
    void                    SetCreepModel2(const Handle(UCrM_Model) CreepModel1);
    void                    SetStressStrainModel1(const Handle(USSM_Model) StressStrainModel1);
    void                    SetStressStrainModel2(const Handle(USSM_Model) StressStrainModel2);
    void                    SetThermalModel1(const Handle(UThM_Model) ThermalModel1);
    void                    SetThermalModel2(const Handle(UThM_Model) ThermalModel2);

private:

    Standard_Real           myArea1;
    Standard_Real           myArea2;
    Handle(UCrM_Model)      myCreepModel1;
    Handle(UCrM_Model)      myCreepModel2;
    Handle(USSM_Model)      myStressStrainModel1;
    Handle(USSM_Model)      myStressStrainModel2;
    Handle(UThM_Model)      myThermalModel1;
    Handle(UThM_Model)      myThermalModel2;

};

#endif  // __XSMP_BimetallicCable01_hxx__
