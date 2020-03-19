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
/// @file Callback.h
/// @author Ben Minerd
/// @date 7/8/2013
/// @brief Callback class header file.
///

#ifndef PLAT4M_TYPES_CALLBACK_H
#define PLAT4M_TYPES_CALLBACK_H

//------------------------------------------------------------------------------
// Namespaces
//------------------------------------------------------------------------------

namespace Plat4m
{

namespace Types
{

//------------------------------------------------------------------------------
// Classes
//------------------------------------------------------------------------------

template <typename TReturn = void, typename... Types>
class Callback
{
public:

    //--------------------------------------------------------------------------
    // Nested forward class declarations
    //--------------------------------------------------------------------------

    template <typename TReturn, typename... Types>
    class Function;

    template <class TClass, typename TReturn, typename... Types>
    class Method;

    //--------------------------------------------------------------------------
    // Public static methods
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    template <typename TReturn, typename... TParameters>
    static Callback<TReturn>& create(TReturn (*callback)(TParameters...))
    {
        return *(new Function<TReturn, TParameters...>(callback));
    }

    //--------------------------------------------------------------------------
    template <class TClass, typename TReturn, typename... TParameters>
    static Callback<TReturn>& create(
                                    TClass* object,
                                    TReturn (TClass::*callback)(TParameters...))
    {
        return *(new Method<TClass, TReturn, TParameters...>(object, callback));
    }

    //--------------------------------------------------------------------------
    // Public constructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    Callback()
    {
    }

    //--------------------------------------------------------------------------
    // Public virtual destructors
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    virtual ~Callback()
    {
    }

    //--------------------------------------------------------------------------
    // Public virtual methods
    //--------------------------------------------------------------------------
    
    virtual inline TReturn call(Types... parameters) = 0;

    //--------------------------------------------------------------------------
    // Private nested classes
    //--------------------------------------------------------------------------

    template <typename TReturn, typename... TParameters>
    class Function : public Callback<TReturn, TParameters...>
    {
    public:
        
        //----------------------------------------------------------------------
        // Public typedefs
        //----------------------------------------------------------------------
        
        typedef TReturn (*CallbackFunctionType)();
        
        //----------------------------------------------------------------------
        // Public constructors
        //----------------------------------------------------------------------
        
        //----------------------------------------------------------------------
        Function(CallbackFunctionType callbackFunction) :
            Callback<TReturn, TParameters...>(),
            myCallbackFunction(callbackFunction)
        {
        }
        
        //----------------------------------------------------------------------
        // Public virtual destructors
        //----------------------------------------------------------------------

        //----------------------------------------------------------------------
        ~Function()
        {
        }

        //----------------------------------------------------------------------
        // Public methods implemented from Callback
        //----------------------------------------------------------------------
        
        //----------------------------------------------------------------------
        inline TReturn call(TParameters... parameters)
        {
            return (*myCallbackFunction)(parameters...);
        }

    private:
        
        //----------------------------------------------------------------------
        // Private data members
        //----------------------------------------------------------------------
        
        CallbackFunctionType myCallbackFunction;
    };

    template <class TClass, typename TReturn, typename... TParameters>
    class Method : public Callback<TReturn, TParameters...>
    {
    public:

        //----------------------------------------------------------------------
        // Public typedefs
        //----------------------------------------------------------------------
        
        typedef TReturn (TClass::*CallbackMethodType)(TParameters...);
        
        //----------------------------------------------------------------------
        // Public constructors
        //----------------------------------------------------------------------
        
        //----------------------------------------------------------------------
        Method(TClass* object, CallbackMethodType callbackMethod) :
            Callback<TReturn, TParameters...>(),
            myObject(object),
            myCallbackMethod(callbackMethod)
        {
        }
        
        //----------------------------------------------------------------------
        // Public virtual destructors
        //----------------------------------------------------------------------

        //----------------------------------------------------------------------
        ~Method()
        {
        }

        //----------------------------------------------------------------------
        // Public methods implemented from Callback
        //----------------------------------------------------------------------
        
        //----------------------------------------------------------------------
        inline TReturn call(TParameters... parameters)
        {
            return (*myObject.*myCallbackMethod)(parameters...);
        }

    private:
        
        //----------------------------------------------------------------------
        // Private data members
        //----------------------------------------------------------------------
        
        TClass* myObject;
        CallbackMethodType myCallbackMethod;
    };
};

}; // namespace Types

}; // namespace Plat4m

#endif // PLAT4M_TYPES_CALLBACK_H
