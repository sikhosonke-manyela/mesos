// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef __MESOS_MODULE_AUTHORIZER_HPP__
#define __MESOS_MODULE_AUTHORIZER_HPP__

#include <mesos/module.hpp>

#include <mesos/authorizer/authorizer.hpp>

namespace mesos {
namespace modules {

template <>
inline const char* kind<mesos::Authorizer>()
{
  return "Authorizer";
}


template <>
struct Module<mesos::Authorizer> : ModuleBase
{
  Module(
      const char* _moduleApiVersion,
      const char* _mesosVersion,
      const char* _authorName,
      const char* _authorEmail,
      const char* _description,
      bool (*_compatible)(),
      mesos::Authorizer* (*_create)(const Parameters& parameters))
    : ModuleBase(
        _moduleApiVersion,
        _mesosVersion,
        mesos::modules::kind<mesos::Authorizer>(),
        _authorName,
        _authorEmail,
        _description,
        _compatible),
      create(_create) {}

  mesos::Authorizer* (*create)(const Parameters& parameters);
};

} // namespace modules {
} // namespace mesos {

#endif // __MESOS_MODULE_AUTHORIZER_HPP__
