/*
 * Copyright (C) 2025 wisevision
 *
 * SPDX-License-Identifier: MPL-2.0
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "wisevision_plugin_loader/plugin_loader.hpp"

#include <cxxabi.h>

namespace wisevision::plugin_loader {
  std::string getTypeName(const std::type_info& ti) {
    int status;
    return std::string(abi::__cxa_demangle(ti.name(), NULL, NULL, &status));
  }
} // namespace wisevision::plugin_loader
