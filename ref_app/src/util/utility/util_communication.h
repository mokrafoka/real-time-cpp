///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2013.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef _UTIL_COMMUNICATION_2012_05_31_H_
  #define _UTIL_COMMUNICATION_2012_05_31_H_

  #include <cstddef>
  #include <cstdint>
  #include <util/memory/util_ring_allocator.h>
  #include <util/utility/util_dynamic_array.h>

  namespace util
  {
    class communication
    {
    public:
      typedef dynamic_array<std::uint8_t, util::ring_allocator<std::uint8_t>> buffer_type;

      typedef typename buffer_type::size_type size_type;

      virtual ~communication() { }

      virtual bool send(const std::uint8_t) = 0;
      virtual bool send(const buffer_type&) = 0;
      virtual bool recv(std::uint8_t&) = 0;
      virtual bool recv(buffer_type&) = 0;
      virtual std::size_t recv_ready() const = 0;
      virtual bool idle() const = 0;

    protected:
      communication() { }
    };
  }

#endif // _UTIL_COMMUNICATION_2012_05_31_H_
