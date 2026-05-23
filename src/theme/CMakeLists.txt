# File: src/theme/CMakeLists.txt
qt_add_qml_module(suno_theme
    URI Suno.Theme
    VERSION 1.0
    QML_FILES Theme.qml
    OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml/Suno/Theme
)

target_link_libraries(suno_theme PRIVATE Qt6::Quick)