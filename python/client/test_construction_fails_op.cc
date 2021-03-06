/* Copyright 2015 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/core/framework/op.h"
#include "tensorflow/core/framework/op_kernel.h"
#include "tensorflow/core/lib/core/status.h"

namespace tensorflow {

REGISTER_OP("ConstructionFails");

class ConstructionFailsOp : public OpKernel {
 public:
  explicit ConstructionFailsOp(OpKernelConstruction* ctx) : OpKernel(ctx) {
    OP_REQUIRES(ctx, false,
                errors::InvalidArgument("Failure during construction."));
  }

  void Compute(OpKernelContext* ctx) override {}
};

REGISTER_KERNEL_BUILDER(Name("ConstructionFails").Device(DEVICE_CPU),
                        ConstructionFailsOp);

}  // end namespace tensorflow
