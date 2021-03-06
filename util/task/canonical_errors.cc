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

#include "util/task/canonical_errors.h"
#include "util/task/status.h"

namespace cpu_instructions {
namespace util {

Status InternalError(StringPiece error_message) {
  return Status(error::INTERNAL, error_message);
}

Status InvalidArgumentError(StringPiece error_message) {
  return Status(error::INVALID_ARGUMENT, error_message);
}

bool IsInvalidArgument(const Status& status) {
  return status.error_code() == error::INVALID_ARGUMENT;
}

}  // namespace util
}  // namespace cpu_instructions
