#include "wisevision_plugin_loader/plugin_loader.hpp"

#include <cxxabi.h>

namespace wisevision::plugin_loader {
  std::string getTypeName(const std::type_info& ti) {
    int status;
    return std::string(abi::__cxa_demangle(ti.name(), NULL, NULL, &status));
  }
} // namespace wisevision::plugin_loader
