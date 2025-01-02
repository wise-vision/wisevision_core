#include <pluginlib/class_loader.hpp>
#include <rclcpp/logging.hpp>

namespace wisevision::plugin_loader {
  // using SharedPtr = std::shared_ptr<T>;
  // using UniquePtr = pluginlib::UniquePtr<Parser>;

  template <class T>
  typename pluginlib::UniquePtr<T>
  loadPlugin(const std::string& package, const std::string& base_class, const std::string& name) {
    pluginlib::ClassLoader<T> parser_loader(package, base_class);
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
