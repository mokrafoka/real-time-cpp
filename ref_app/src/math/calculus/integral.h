///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2014.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef _INTEGRAL_2012_01_09_H_
  #define _INTEGRAL_2012_01_09_H_

  #include <algorithm>
  #include <limits>

  namespace math
  {
    template<typename real_value_type,
             typename real_function_type,
             typename integer_value_type = std::uint_fast8_t>
    real_value_type integral(const real_value_type& a,
                             const real_value_type& b,
                             const real_value_type& tol,
                             real_function_type real_function,
                             const integer_value_type k_max = ((std::numeric_limits<integer_value_type>::max)() / 2U) - integer_value_type(1))
    {
      std::uint_fast32_t n2(1);

      real_value_type step_size      ((b - a) / 2U);
      real_value_type integral_result((real_function(a) + real_function(b)) * step_size);

      for(integer_value_type k = integer_value_type(0); k < k_max; ++k)
      {
        real_value_type sum(0);

        for(std::uint_fast32_t j = UINT32_C(0); j < n2; ++j)
        {
          const real_value_type this_step_size(((j * UINT32_C(2)) + UINT32_C(1)) * step_size);

          sum += real_function(a + this_step_size);
        }

        const real_value_type integral_result_tmp(integral_result);

        integral_result = (integral_result / 2U) + (step_size * sum);

        using std::abs;

        const real_value_type ratio(abs(integral_result_tmp / integral_result));
        const real_value_type delta(abs(ratio - 1U));

        if((k > integer_value_type(1)) && (delta < tol))
        {
          break;
        }

        n2 *= 2U;

        step_size /= 2U;
      }

      return integral_result;
    }
  } // namespace math

#endif // _INTEGRAL_2012_01_09_H_

/*
#include <cstdint>
#include <math/constants/constants.h>
#include <math/calculus/integral.h>

void do_something();

void do_something()
{
  // Compute y = cyl_bessel_j(2, 1.23) = 0.16636938378681407351267852431513159437103348245333
  // N[BesselJ[2, 123/100], 50]

  using std::sqrt;
  using boost::math::constants::pi;

  const float_type x = float_type(123U) / 100U;

  const std::uint_fast8_t n = UINT8_C(2);

  const float_type y = math::integral<float_type>(float_type(0),
                                                  pi<float_type>(),
                                                  sqrt(std::numeric_limits<float_type>::epsilon()),
                                                  [&x, &n](const float_type& t) -> float_type
                                                  {
                                                    using std::cos;
                                                    using std::sin;

                                                    return cos(x * sin(t) - (t * n));
                                                  }) / pi<float_type>();

  static_cast<void>(y);
}
*/
