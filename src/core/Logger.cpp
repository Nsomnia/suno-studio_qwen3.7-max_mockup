// File: src/core/Logger.cpp
#include "Logger.hpp"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <QStandardPaths>
#include <filesystem>

namespace Suno::Core {

void Logger::initialize(std::string_view appName) {
    if (spdlog::default_logger_raw() != nullptr) return;

    try {
        auto logPath = std::filesystem::path(
            QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).toStdString()
        ) / "logs";
        
        std::filesystem::create_directories(logPath);
        
        std::vector<spdlog::sink_ptr> sinks;
        sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
            (logPath / "suno_studio.log").string(), 1048576 * 5, 3
        ));

        auto logger = std::make_shared<spdlog::logger>(std::string(appName), sinks.begin(), sinks.end());
        logger->set_level(spdlog::level::debug);
        logger->flush_on(spdlog::level::warn);
        spdlog::set_default_logger(logger);
    } catch (const std::exception& e) {
        // Fallback to console only if file logging fails
        spdlog::set_pattern("[%H:%M:%S %z] [%^%l%$] %v");
        spdlog::error("Failed to initialize file logging: {}", e.what());
    }
}

void Logger::shutdown() {
    spdlog::shutdown();
}

bool Logger::isInitialized() noexcept {
    return spdlog::default_logger_raw() != nullptr;
}

} // namespace Suno::Core