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
