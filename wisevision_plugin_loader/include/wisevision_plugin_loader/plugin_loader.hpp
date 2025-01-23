/*
 * Copyright (C) 2025 wisevision
 *
 * SPDX-License-Identifier: MPL-2.0
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <pluginlib/class_loader.hpp>
#include <rclcpp/logging.hpp>
#include <string>
#include <typeinfo>

namespace wisevision::plugin_loader {
  std::string getTypeName(const std::type_info& ti);

  template <class T>
  typename pluginlib::UniquePtr<T> loadPlugin(const std::string& base_class_package, const std::string& name) {
    const auto type_name = getTypeName(typeid(T));
    pluginlib::ClassLoader<T> parser_loader(base_class_package, type_name);
    typename pluginlib::UniquePtr<T> parser = nullptr;
    try {
      parser = parser_loader.createUniqueInstance(name);
    } catch (pluginlib::PluginlibException& ex) {
      RCLCPP_ERROR(rclcpp::get_logger("parser_loader"),
                   "Error occured during parser plugin loading. Error %s",
                   ex.what());
    }
    return parser;
  }
} // namespace wisevision::plugin_loader
