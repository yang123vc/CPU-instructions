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

#include "cpu_instructions/base/transform_factory.h"

#include "gflags/gflags.h"
#include "glog/logging.h"
#include "strings/str_split.h"
#include "util/gtl/map_util.h"

DEFINE_string(
    cpu_instructions_transforms, "",
    "The list of transformations applied to the instruction "
    "database. This can be a (possibly empty) list of names or "
    "'default' to apply the default list of transforms for the architecture.");

namespace cpu_instructions {

std::vector<InstructionSetTransform> GetTransformsFromCommandLineFlags() {
  static constexpr const char kDefaultSet[] = "default";
  const auto& transforms_by_name = GetTransformsByName();
  std::vector<InstructionSetTransform> transforms;
  const std::vector<string> transform_names =
      strings::Split(FLAGS_cpu_instructions_transforms, ",",  // NOLINT
                     strings::SkipEmpty());
  for (const string& transform_name : transform_names) {
    if (transform_name == kDefaultSet) {
      const auto default_transforms = GetDefaultTransformPipeline();
      transforms.insert(transforms.end(), default_transforms.begin(),
                        default_transforms.end());
    } else {
      auto* transform = FindOrNull(transforms_by_name, transform_name);
      CHECK(transform != nullptr) << "Transform was not found: "
                                  << transform_name;
      transforms.push_back(*transform);
    }
  }
  return transforms;
}

}  // namespace cpu_instructions
