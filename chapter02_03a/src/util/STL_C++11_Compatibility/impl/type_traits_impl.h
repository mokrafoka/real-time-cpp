///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2013.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef _TYPE_TRAITS_IMPL_2013_09_02_H_
  #define _TYPE_TRAITS_IMPL_2013_09_02_H_

  namespace std
  {
    template<bool, typename template_type = void>
    struct enable_if { };

    template<typename template_type>
    struct enable_if<true, template_type>
    {
      typedef template_type type;
    };

    template<typename template_type, template_type the_value>
    struct integral_constant
    {
      static const template_type my_value = the_value;

      typedef template_type value_type;
      typedef integral_constant<template_type, the_value> type;

      operator value_type() const
      {
        return my_value;
      }
    };

    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;

    template<typename template_type1, typename template_type2>
    struct is_same : false_type { };

    template<typename template_type1>
    struct is_same<template_type1, template_type1> : true_type { };
  }

#endif // _TYPE_TRAITS_IMPL_2013_09_02_H_
