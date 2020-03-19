//------------------------------------------------------------------------------
//       _______    __                           ___
//      ||  ___ \  || |             __          //  |
//      || |  || | || |   _______  || |__      //   |    _____  ___
//      || |__|| | || |  // ___  | ||  __|    // _  |   ||  _ \/ _ \
//      ||  ____/  || | || |  || | || |      // /|| |   || |\\  /\\ \
//      || |       || | || |__|| | || |     // /_|| |_  || | || | || |
//      || |       || |  \\____  | || |__  //_____   _| || | || | || |
//      ||_|       ||_|       ||_|  \\___|       ||_|   ||_| ||_| ||_|
//
//
// The MIT License (MIT)
//
// Copyright (c) 2020 Benjamin Minerd
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//------------------------------------------------------------------------------

///
/// @file Plat4mTypes.h
/// @author Ben Minerd
/// @date 3/18/2020
/// @brief Plat4mTypes namespace file.
///

#ifndef PLAT4M_TYPES_H
#define PLAT4M_TYPES_H

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------

#include <cstdint>

//------------------------------------------------------------------------------
// Namespaces
//------------------------------------------------------------------------------

namespace Plat4m
{

namespace Types
{
    //--------------------------------------------------------------------------
    // Types
    //--------------------------------------------------------------------------

    enum BitValue
    {
        BIT_VALUE_0 = 0,
        BIT_VALUE_1 = 1
    };
    
    enum LogicLevel
    {
        LOGIC_LEVEL_LOW  = 0,
        LOGIC_LEVEL_HIGH = 1
    };

    enum Endian
    {
        ENDIAN_LITTLE,
        ENDIAN_BIG
    };

    typedef uint32_t Id;

    typedef uint32_t TimeS;
    typedef uint32_t TimeMs;
    typedef uint32_t TimeUs;

    typedef float RealNumber;

    typedef RealNumber VoltageV;
    typedef RealNumber VoltageMv;

    typedef RealNumber CurrentA;
    typedef RealNumber CurrentMa;

    typedef RealNumber PositionM;

    typedef RealNumber VelocityMpS;
    typedef RealNumber VelocityMpm;
    typedef RealNumber VelocityKph;
    typedef RealNumber VelocityFps;
    typedef RealNumber VelocityFpm;
    typedef RealNumber VelocityMph;

    typedef RealNumber AccelerationG;
    typedef RealNumber AccelerationMg;

    typedef RealNumber FrequencyHz;

    typedef RealNumber AngleDegrees;
    typedef RealNumber AngleRadians;

    typedef RealNumber AngularSpeedDps;
    typedef RealNumber AngularSpeedRadPs;
    typedef RealNumber AngularSpeedRpm;

    typedef RealNumber AngularVelocityDps;
    typedef RealNumber AngularVelocityRadPs;
    typedef RealNumber AngularVelocityRpm;

    typedef RealNumber AngularAccelerationDps2;
    typedef RealNumber AngularAccelerationRadPs2;

    //--------------------------------------------------------------------------
    // Variables
    //--------------------------------------------------------------------------

    static const char* version = "1.0.0";

    static const RealNumber pi = 3.14159265358979323846;

    //--------------------------------------------------------------------------
    // Inline functions
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    inline char uint8ToAscii(const uint8_t value)
    {
        return (0x30 + value);
    }

    //--------------------------------------------------------------------------
    inline uint8_t asciiToUint8(const char character)
    {
        return (character - 0x30);
    }

    //--------------------------------------------------------------------------
    inline AngleDegrees radiansToDegrees(const AngleRadians angleRadians)
    {
        return (angleRadians * (180.0 / pi));
    }

    //--------------------------------------------------------------------------
    inline AngleRadians degreesToRadians(const AngleDegrees angleDegrees)
    {
        return (angleDegrees * (pi / 180.0));
    }

    //--------------------------------------------------------------------------
    inline AngularVelocityDps radPsToDps(const AngularVelocityRadPs radPs)
    {
        return (radPs * (180.0 / pi));
    }

    //--------------------------------------------------------------------------
    inline AngularVelocityRadPs dpsToRadPs(const AngularVelocityDps dps)
    {
        return (dps * (pi / 180.0));
    }

    //--------------------------------------------------------------------------
    inline AngularAccelerationDps2 radPs2ToDps2(
    									 const AngularAccelerationRadPs2 radPs2)
    {
        return (radPs2 * (180.0 / pi));
    }

    //--------------------------------------------------------------------------
    inline AngularAccelerationRadPs2 dps2ToRadPs2(
    										 const AngularAccelerationDps2 dps2)
    {
        return (dps2 * (pi / 180.0));
    }
}; // namespace Types

}; // namespace Plat4m

#endif // PLAT4M_TYPES_H
