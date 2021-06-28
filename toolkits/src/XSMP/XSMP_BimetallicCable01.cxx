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


// Spartacus
#include <XSMP_BimetallicCable01.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
XSMP_BimetallicCable01::XSMP_BimetallicCable01()
    : myArea1(0.), myArea2(0.)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
XSMP_BimetallicCable01::XSMP_BimetallicCable01(const Standard_Real Area1,
                                               const Standard_Real Area2)
    : myArea1(Area1), myArea2(Area2)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
XSMP_BimetallicCable01::XSMP_BimetallicCable01(const Standard_Real Area1,
                                               const Standard_Real Area2,
                                               const Handle(USSM_Model) StressStrainModel1,
                                               const Handle(USSM_Model) StressStrainModel2)
    : myArea1(Area1), myArea2(Area2),
      myStressStrainModel1(StressStrainModel1), myStressStrainModel2(StressStrainModel2)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
XSMP_BimetallicCable01::XSMP_BimetallicCable01(const Standard_Real Area1,
                                               const Standard_Real Area2,
                                               const Handle(USSM_Model) StressStrainModel1,
                                               const Handle(UThM_Model) ThermalModel1,
                                               const Handle(USSM_Model) StressStrainModel2,
                                               const Handle(UThM_Model) ThermalModel2)
    : myArea1(Area1), myArea2(Area2),
      myStressStrainModel1(StressStrainModel1), myStressStrainModel2(StressStrainModel2),
      myThermalModel1(ThermalModel1), myThermalModel2(ThermalModel2)
{

}

// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
XSMP_BimetallicCable01::XSMP_BimetallicCable01(const Standard_Real Area1,
                                               const Standard_Real Area2,
                                               const Handle(USSM_Model) StressStrainModel1,
                                               const Handle(UThM_Model) ThermalModel1,
                                               const Handle(UCrM_Model) CreepModel1,
                                               const Handle(USSM_Model) StressStrainModel2,
                                               const Handle(UThM_Model) ThermalModel2,
                                               const Handle(UCrM_Model) CreepModel2)
    : myArea1(Area1), myArea2(Area2),
      myCreepModel1(CreepModel1), myCreepModel2(CreepModel2),
      myStressStrainModel1(StressStrainModel1), myStressStrainModel2(StressStrainModel2),
      myThermalModel1(ThermalModel1), myThermalModel2(ThermalModel2)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
XSMP_BimetallicCable01::~XSMP_BimetallicCable01()
{

}

// ============================================================================
/*!
 *  \brief Area1()
*/
// ============================================================================
Standard_Real XSMP_BimetallicCable01::Area1() const
{
    return myArea1;
}

// ============================================================================
/*!
 *  \brief Area2()
*/
// ============================================================================
Standard_Real XSMP_BimetallicCable01::Area2() const
{
    return myArea2;
}

// ============================================================================
/*!
 *  \brief CreepModel1()
*/
// ============================================================================
Handle(UCrM_Model) XSMP_BimetallicCable01::CreepModel1() const
{
    return myCreepModel1;
}

// ============================================================================
/*!
 *  \brief CreepModel2()
*/
// ============================================================================
Handle(UCrM_Model) XSMP_BimetallicCable01::CreepModel2() const
{
    return myCreepModel2;
}

// ============================================================================
/*!
 *  \brief StressStrainModel1()
*/
// ============================================================================
Handle(USSM_Model) XSMP_BimetallicCable01::StressStrainModel1() const
{
    return myStressStrainModel1;
}

// ============================================================================
/*!
 *  \brief StressStrainModel2()
*/
// ============================================================================
Handle(USSM_Model) XSMP_BimetallicCable01::StressStrainModel2() const
{
    return myStressStrainModel2;
}

// ============================================================================
/*!
 *  \brief ThermalModel1()
*/
// ============================================================================
Handle(UThM_Model) XSMP_BimetallicCable01::ThermalModel1() const
{
    return myThermalModel1;
}

// ============================================================================
/*!
 *  \brief ThermalModel2()
*/
// ============================================================================
Handle(UThM_Model) XSMP_BimetallicCable01::ThermalModel2() const
{
    return myThermalModel2;
}

// ============================================================================
/*!
 *  \brief SetArea1()
*/
// ============================================================================
void XSMP_BimetallicCable01::SetArea1(const Standard_Real Area1)
{
    myArea1 = Area1;
}

// ============================================================================
/*!
 *  \brief SetArea2()
*/
// ============================================================================
void XSMP_BimetallicCable01::SetArea2(const Standard_Real Area2)
{
    myArea2 = Area2;
}

// ============================================================================
/*!
 *  \brief SetCreepModel1()
*/
// ============================================================================
void XSMP_BimetallicCable01::SetCreepModel1(const Handle(UCrM_Model) CreepModel1)
{
    myCreepModel1 = CreepModel1;
}

// ============================================================================
/*!
 *  \brief SetCreepModel2()
*/
// ============================================================================
void XSMP_BimetallicCable01::SetCreepModel2(const Handle(UCrM_Model) CreepModel2)
{
    myCreepModel2 = CreepModel2;
}

// ============================================================================
/*!
 *  \brief SetStressStrainModel1()
*/
// ============================================================================
void XSMP_BimetallicCable01::SetStressStrainModel1(const Handle(USSM_Model) StressStrainModel1)
{
    myStressStrainModel1 = StressStrainModel1;
}

// ============================================================================
/*!
 *  \brief SetStressStrainModel2()
*/
// ============================================================================
void XSMP_BimetallicCable01::SetStressStrainModel2(const Handle(USSM_Model) StressStrainModel2)
{
    myStressStrainModel2 = StressStrainModel2;
}

// ============================================================================
/*!
 *  \brief SetThermalModel1()
*/
// ============================================================================
void XSMP_BimetallicCable01::SetThermalModel1(const Handle(UThM_Model) ThermalModel1)
{
    myThermalModel1 = ThermalModel1;
}

// ============================================================================
/*!
 *  \brief SetThermalModel2()
*/
// ============================================================================
void XSMP_BimetallicCable01::SetThermalModel2(const Handle(UThM_Model) ThermalModel2)
{
    myThermalModel2 = ThermalModel2;
}

