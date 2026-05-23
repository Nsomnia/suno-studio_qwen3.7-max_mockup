# suno-studio_qwen3.7-max_mockup
Testing latest models for a huge project refactored with what both I have learned and how models have advanced. Not funtional at all. Better use Arch, BTW.

---

<!-- File: README.md -->
# SunoStudio Mockup Phase

## Overview
SunoStudio is a modular desktop application integrating AI music generation (Suno), media playback, visualizer-driven rendering, and automated video creation. This repository represents the **Initial Mockup Phase**, focusing on architecture, UI/UX fidelity, and extensible interfaces without production backend implementations.

## Architectural Map
- **Core**: Application shell, dependency injection, logging, single-instance enforcement.
- **Theme**: Centralized design tokens (Glassmorphism/Dark) exposed via QML Singleton.
- **Modules**:
  - `SunoClient`: Fake API, auth state, generation history models.
  - `Player`: Transport abstraction, queue management, ProjectM integration stub.
  - `VideoAutomation`: Batch render queue, template system, overlay composition interfaces.
- **Shared**: Common models, async utilities, secure credential storage interfaces.

## Repository Hierarchy
```text
.
├── CMakeLists.txt          # Root build configuration
├── cmake/                  # CPM bootstrap, compiler presets, helper functions
├── src/
│   ├── app/                # Main entry point, DI container setup
│   ├── core/               # Logging, SingleInstance, AsyncUtils
│   ├── theme/              # Design tokens, Theme.qml singleton
│   ├── modules/
│   │   ├── suno/           # Suno frontend mockups & models
│   │   ├── player/         # Player UI, Visualizer viewport, Karaoke layer
│   │   └── automation/     # Video batch rendering UX & queues
│   └── shared/             # Cross-module models, interfaces, types
├── qml/                    # Global QML infrastructure, reusable controls
├── resources/              # Fonts, icons, default presets
└── tests/                  # Unit test scaffolds
```

## Build Overview
1. Ensure Qt 6.11+, CMake 3.28+, and Ninja are installed.
2. Configure: `cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug`
3. Build: `cmake --build build`
4. Run: `./build/bin/SunoStudio`

## Dependencies (Managed via CPM)
- Qt6 (Quick, QuickControls2, Multimedia, Svg)
- libprojectM >= 4.1
- nlohmann_json
- spdlog
- magic_enum
- range-v3
- qtkeychain
- KDSingleApplication

## Mockup Phase Scope
- ✅ Full UI shell with glassmorphic theme system
- ✅ Simulated Suno API with realistic latency/failure states
- ✅ ProjectM viewport embedding with preset browsing
- ✅ Karaoke lyric overlay system (timed text)
- ✅ Batch video render queue UX
- ❌ Real audio decoding/encoding
- ❌ Production Suno authentication
- ❌ GPU-accelerated video rendering pipeline
