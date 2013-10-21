#ifndef ONII_PHYSIC_UNIT_HPP
#define ONII_PHYSIC_UNIT_HPP

/////////////////////////////////////////////////
/// @file onii/physic/unit.hpp
/////////////////////////////////////////////////

#include "unit/length.hpp"
#include "unit/time.hpp"
#include "unit/mass.hpp"
#include "unit/angle.hpp"

/////////////////////////////////////////////////
/// @class onii::physic::unit::detail::unit_base
/// @brief Base-class for units
/// @remarks This class is not intended to be used by user
///
/// This class provide operators for derived classes.
///
/// In the next section:
/// - U is an unit in onii::physic::unit
/// - S is a scalar number (float)
///
/// Artimethic operators:
/// @code
/// U += U
/// U -= U
/// U *= S
/// U /= S
/// U = U + U
/// U = U - U
/// U = U * S
/// U = S * U
/// U = U / S
/// @endcode
/////////////////////////////////////////////////

#endif // ONII_PHYSIC_UNIT_HPP
