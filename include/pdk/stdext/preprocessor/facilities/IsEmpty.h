// @copyright 2017-2018 zzu_softboy <zzu_softboy@163.com>
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by softboy on 2018/01/15.

// ****************************************************************************
// *                                                                          *
// *     (C) Copyright Paul Mensonides 2002-2011.                             *
// *     (C) Copyright Edward Diener 2011.                                    *
// *     Distributed under the Boost Software License, Version 1.0. (See      *
// *     accompanying file LICENSE_1_0.txt or copy at                         *
// *     http://www.boost.org/LICENSE_1_0.txt)                                *
// *                                                                          *
// ****************************************************************************
// 
// See http://www.boost.org for most recent version.

#ifndef PDK_STDEXT_PREPROCESSOR_FACILITIES_IS_EMPTY_H
#define PDK_STDEXT_PREPROCESSOR_FACILITIES_IS_EMPTY_H

# include "pdk/stdext/preprocessor/config/Config.h"

# if PDK_PP_VARIADICS

# include "pdk/stdext/preprocessor/facilities/IsEmptyVariadic.h"

# else
#
# if ~PDK_PP_CONFIG_FLAGS() & PDK_PP_CONFIG_MSVC() && ~PDK_PP_CONFIG_FLAGS() & PDK_PP_CONFIG_MWCC()
# include "pdk/stdext/preprocessor/tuple/Element.h"
# include "pdk/stdext/preprocessor/facilities/Identity.h"
# else
# include "pdk/stdext/preprocessor/Cat.h"
# include "pdk/stdext/preprocessor/internal/Split.h"
# endif

// PDK_PP_IS_EMPTY

# if ~PDK_PP_CONFIG_FLAGS() & PDK_PP_CONFIG_MSVC() && ~PDK_PP_CONFIG_FLAGS() & PDK_PP_CONFIG_MWCC()
#    define PDK_PP_IS_EMPTY(x) PDK_PP_IS_EMPTY_I(x PDK_PP_IS_EMPTY_HELPER)
#    define PDK_PP_IS_EMPTY_I(contents) PDK_PP_TUPLE_ELEM(2, 1, (PDK_PP_IS_EMPTY_DEF_ ## contents()))
#    define PDK_PP_IS_EMPTY_DEF_PDK_PP_IS_EMPTY_HELPER 1, PDK_PP_IDENTITY(1)
#    define PDK_PP_IS_EMPTY_HELPER() , 0
# else
#    if PDK_PP_CONFIG_FLAGS() & PDK_PP_CONFIG_MSVC()
#        define PDK_PP_IS_EMPTY(x) PDK_PP_IS_EMPTY_I(PDK_PP_IS_EMPTY_HELPER x ())
#        define PDK_PP_IS_EMPTY_I(test) PDK_PP_IS_EMPTY_II(PDK_PP_SPLIT(0, PDK_PP_CAT(PDK_PP_IS_EMPTY_DEF_, test)))
#        define PDK_PP_IS_EMPTY_II(id) id
#    else
#        define PDK_PP_IS_EMPTY(x) PDK_PP_IS_EMPTY_I((PDK_PP_IS_EMPTY_HELPER x ()))
#        define PDK_PP_IS_EMPTY_I(par) PDK_PP_IS_EMPTY_II ## par
#        define PDK_PP_IS_EMPTY_II(test) PDK_PP_SPLIT(0, PDK_PP_CAT(PDK_PP_IS_EMPTY_DEF_, test))
#    endif
#    define PDK_PP_IS_EMPTY_HELPER() 1
#    define PDK_PP_IS_EMPTY_DEF_1 1, PDK_PP_NIL
#    define PDK_PP_IS_EMPTY_DEF_PDK_PP_IS_EMPTY_HELPER 0, PDK_PP_NIL
# endif

# endif /* PDK_PP_VARIADICS */

#endif // PDK_STDEXT_PREPROCESSOR_FACILITIES_IS_EMPTY_H
