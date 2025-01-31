/*
 * Copyright (C) 2025 wisevision
 *
 * SPDX-License-Identifier: MPL-2.0
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <pluginlib/class_loader.hpp>
#include <rclcpp/serialization.hpp>
#include <rclcpp/serialized_message.hpp>
#include <vector>

namespace wisevision {
  class Parser {
  public:
    using SharedPtr = std::shared_ptr<Parser>;
    using UniquePtr = pluginlib::UniquePtr<Parser>;

    virtual ~Parser() = default;

    virtual std::optional<std::vector<uint8_t>> rosMessageToBytes(const rclcpp::SerializedMessage& message) = 0;
    virtual std::optional<rclcpp::SerializedMessage> bytesToRosMessage(const std::vector<uint8_t>& bytes) = 0;
    virtual std::string getPublisherMessageType() const = 0;
    virtual std::string getSubscriptionMessageType() const = 0;
    virtual std::string getName() const = 0;
  };
} // namespace wisevision
