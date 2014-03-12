/*  libsimdpp
    Copyright (C) 2014  Povilas Kanapickas <povilas@radix.lt>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_MAKE_INT_H
#define LIBSIMDPP_SIMDPP_CORE_MAKE_INT_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/insn/make_const.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif

/// @{
/** Creates a vector from signed integer values known at compile-time.
    The result of this function may be assigned or converted to a vector of any
    type: standard conversions are used to convert the arguments. All
    conversions and other overhead is performed at compile-time thus even if the
    minimal optimization level is selected, the function results in a simple
    load from memory.

    The function is not guaranteed to have adequate performance if the
    arguments are not known at compile-time.

    If the vector has fewer elements than the number of the parameters this
    function accepts then the extra values are discarded.

    @par 1 parameter version
    @code
        | 0  1  2  3  ... n  |
    r = [ v0 v0 v0 v0 ... v0 ]
    @endcode

    @par 2 parameters version
    @code
        | 0  1  2  3  ... n  |
    r = [ v0 v1 v0 v1 ... v1 ]
    @endcode

    @par 4 parameters version
    @code
        | 0  1  2  3  ... n  |
    r = [ v0 v1 v2 v3 ... v3 ]
    @endcode

    @par 8 parameters version
    @code
        | 0  1  ..  7  8  ... n  |
    r = [ v0 v1 .. v7 v0  ... v7 ]
    @endcode
*/
// FIXME: return empty expr
template<class V = expr_vec_make_const<int64_t,1>>
V make_int(int64_t v0)
{
    static_assert((is_vector<V>::value && !is_mask<V>::value) ||
                  detail::is_expr_vec_make_const<V>::value,
                  "V must be a non-mask vector");
    expr_vec_make_const<int64_t,1> a;
    a.a[0] = v0;
    return detail::insn::i_make_const_dispatch<V>::run(a);
}

template<class V = expr_vec_make_const<int64_t,2>>
V make_int(int64_t v0, int64_t v1)
{
    static_assert((is_vector<V>::value && !is_mask<V>::value) ||
                  detail::is_expr_vec_make_const<V>::value,
                  "V must be a non-mask vector");
    expr_vec_make_const<int64_t,2> a;
    a.a[0] = v0;  a.a[1] = v1;
    return detail::insn::i_make_const_dispatch<V>::run(a);
}

template<class V = expr_vec_make_const<int64_t,4>>
V make_int(int64_t v0, int64_t v1, int64_t v2, int64_t v3)
{
    static_assert((is_vector<V>::value && !is_mask<V>::value) ||
                  detail::is_expr_vec_make_const<V>::value,
                  "V must be a non-mask vector");
    expr_vec_make_const<int64_t,4> a;
    a.a[0] = v0;  a.a[1] = v1;  a.a[2] = v2;  a.a[3] = v3;
    return detail::insn::i_make_const_dispatch<V>::run(a);
}

template<class V = expr_vec_make_const<int64_t,8>>
V make_int(int64_t v0, int64_t v1, int64_t v2, int64_t v3,
           int64_t v4, int64_t v5, int64_t v6, int64_t v7)
{
    static_assert((is_vector<V>::value && !is_mask<V>::value) ||
                  detail::is_expr_vec_make_const<V>::value,
                  "V must be a non-mask vector");
    expr_vec_make_const<int64_t,8> a;
    a.a[0] = v0;  a.a[1] = v1;  a.a[2] = v2;  a.a[3] = v3;
    a.a[4] = v4;  a.a[5] = v5;  a.a[6] = v6;  a.a[7] = v7;
    return detail::insn::i_make_const_dispatch<V>::run(a);
}

template<class V = expr_vec_make_const<int64_t,16>>
V make_int(int64_t v0,  int64_t v1,  int64_t v2,  int64_t v3,
           int64_t v4,  int64_t v5,  int64_t v6,  int64_t v7,
           int64_t v8,  int64_t v9,  int64_t v10, int64_t v11,
           int64_t v12, int64_t v13, int64_t v14, int64_t v15)
{
    static_assert((is_vector<V>::value && !is_mask<V>::value) ||
                  detail::is_expr_vec_make_const<V>::value,
                  "V must be a non-mask vector");
    expr_vec_make_const<int64_t,16> a;
    a.a[0] = v0;    a.a[1] = v1;    a.a[2] = v2;    a.a[3] = v3;
    a.a[4] = v4;    a.a[5] = v5;    a.a[6] = v6;    a.a[7] = v7;
    a.a[8] = v8;    a.a[9] = v9;    a.a[10] = v10;  a.a[11] = v11;
    a.a[12] = v12;  a.a[13] = v13;  a.a[14] = v14;  a.a[15] = v15;
    return detail::insn::i_make_const_dispatch<V>::run(a);
}
/// @}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

