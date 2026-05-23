// File: src/core/Logger.hpp
#pragma once

#include <memory>
#include <string_view>

namespace Suno::Core {

class Logger {
public:
    static void initialize(std::string_view appName = "SunoStudio");
    static void shutdown();
    
    [[nodiscard]] static bool isInitialized() noexcept;
};

} // namespace Suno::Core