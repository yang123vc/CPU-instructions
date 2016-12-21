// Copyright 2016 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef UTIL_GTL_PTR_UTIL_H_
#define UTIL_GTL_PTR_UTIL_H_

namespace cpu_instructions {
namespace gtl {

// A replacement for std::make_unique, which is not available in C++11.
// TODO(user): Remove this function when we switch to C++14 and
// std:make_unique becomes available.
template <typename T, typename... Args>
typename std::unique_ptr<T> MakeUnique(Args&&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

}  // namespace gtl
}  // namespace cpu_instructions

#endif  // UTIL_GTL_PTR_UTIL_H_
