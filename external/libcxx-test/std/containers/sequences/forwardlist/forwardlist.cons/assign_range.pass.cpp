/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <forward_list>

// template <class InputIterator>
//     void assign(InputIterator first, InputIterator last);

#include <forward_list>
#include <cassert>
#include <iterator>

#include "test_iterators.h"

int main()
{
    {
        typedef int T;
        typedef std::forward_list<T> C;
        const T t0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        const T t1[] = {10, 11, 12, 13};
        C c(std::begin(t1), std::end(t1));
        typedef input_iterator<const T*> I;
        c.assign(I(std::begin(t0)), I(std::end(t0)));
        int n = 0;
        for (C::const_iterator i = c.cbegin(); i != c.cend(); ++i, ++n)
            assert(*i == n);
        assert(n == 10);
    }
    {
        typedef int T;
        typedef std::forward_list<T> C;
        const T t0[] = {10, 11, 12, 13};
        const T t1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        C c(std::begin(t1), std::end(t1));
        typedef input_iterator<const T*> I;
        c.assign(I(std::begin(t0)), I(std::end(t0)));
        int n = 0;
        for (C::const_iterator i = c.cbegin(); i != c.cend(); ++i, ++n)
            assert(*i == 10+n);
        assert(n == 4);
    }
}
