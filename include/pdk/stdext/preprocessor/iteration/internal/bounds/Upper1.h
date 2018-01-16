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
// Created by softboy on 2018/01/16.

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

# include "pdk/stdext/preprocessor/slot/internal/Shared.h"

# undef PDK_PP_ITERATION_FINISH_1

# undef PDK_PP_ITERATION_FINISH_1_DIGIT_1
# undef PDK_PP_ITERATION_FINISH_1_DIGIT_2
# undef PDK_PP_ITERATION_FINISH_1_DIGIT_3
# undef PDK_PP_ITERATION_FINISH_1_DIGIT_4
# undef PDK_PP_ITERATION_FINISH_1_DIGIT_5
# undef PDK_PP_ITERATION_FINISH_1_DIGIT_6
# undef PDK_PP_ITERATION_FINISH_1_DIGIT_7
# undef PDK_PP_ITERATION_FINISH_1_DIGIT_8
# undef PDK_PP_ITERATION_FINISH_1_DIGIT_9
# undef PDK_PP_ITERATION_FINISH_1_DIGIT_10

# if PDK_PP_SLOT_TEMP_3 == 0
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_3 0
# elif PDK_PP_SLOT_TEMP_3 == 1
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_3 1
# elif PDK_PP_SLOT_TEMP_3 == 2
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_3 2
# elif PDK_PP_SLOT_TEMP_3 == 3
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_3 3
# elif PDK_PP_SLOT_TEMP_3 == 4
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_3 4
# elif PDK_PP_SLOT_TEMP_3 == 5
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_3 5
# elif PDK_PP_SLOT_TEMP_3 == 6
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_3 6
# elif PDK_PP_SLOT_TEMP_3 == 7
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_3 7
# elif PDK_PP_SLOT_TEMP_3 == 8
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_3 8
# elif PDK_PP_SLOT_TEMP_3 == 9
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_3 9
# endif

# if PDK_PP_SLOT_TEMP_2 == 0
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_2 0
# elif PDK_PP_SLOT_TEMP_2 == 1
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_2 1
# elif PDK_PP_SLOT_TEMP_2 == 2
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_2 2
# elif PDK_PP_SLOT_TEMP_2 == 3
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_2 3
# elif PDK_PP_SLOT_TEMP_2 == 4
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_2 4
# elif PDK_PP_SLOT_TEMP_2 == 5
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_2 5
# elif PDK_PP_SLOT_TEMP_2 == 6
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_2 6
# elif PDK_PP_SLOT_TEMP_2 == 7
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_2 7
# elif PDK_PP_SLOT_TEMP_2 == 8
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_2 8
# elif PDK_PP_SLOT_TEMP_2 == 9
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_2 9
# endif

# if PDK_PP_SLOT_TEMP_1 == 0
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_1 0
# elif PDK_PP_SLOT_TEMP_1 == 1
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_1 1
# elif PDK_PP_SLOT_TEMP_1 == 2
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_1 2
# elif PDK_PP_SLOT_TEMP_1 == 3
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_1 3
# elif PDK_PP_SLOT_TEMP_1 == 4
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_1 4
# elif PDK_PP_SLOT_TEMP_1 == 5
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_1 5
# elif PDK_PP_SLOT_TEMP_1 == 6
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_1 6
# elif PDK_PP_SLOT_TEMP_1 == 7
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_1 7
# elif PDK_PP_SLOT_TEMP_1 == 8
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_1 8
# elif PDK_PP_SLOT_TEMP_1 == 9
#    define PDK_PP_ITERATION_FINISH_1_DIGIT_1 9
# endif

# if PDK_PP_ITERATION_FINISH_1_DIGIT_3
#    define PDK_PP_ITERATION_FINISH_1 PDK_PP_SLOT_CC_3(PDK_PP_ITERATION_FINISH_1_DIGIT_3, PDK_PP_ITERATION_FINISH_1_DIGIT_2, PDK_PP_ITERATION_FINISH_1_DIGIT_1)
# elif PDK_PP_ITERATION_FINISH_1_DIGIT_2
#    define PDK_PP_ITERATION_FINISH_1 PDK_PP_SLOT_CC_2(PDK_PP_ITERATION_FINISH_1_DIGIT_2, PDK_PP_ITERATION_FINISH_1_DIGIT_1)
# else
#    define PDK_PP_ITERATION_FINISH_1 PDK_PP_ITERATION_FINISH_1_DIGIT_1
# endif
