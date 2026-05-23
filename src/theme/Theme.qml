// File: src/theme/Theme.qml
pragma Singleton
import QtQuick

QtObject {
    // Color Tokens - Glassmorphic Dark
    readonly property color backgroundBase: "#0f0f12"
    readonly property color surfacePrimary: Qt.rgba(1, 1, 1, 0.05)
    readonly property color surfaceSecondary: Qt.rgba(1, 1, 1, 0.08)
    readonly property color surfaceHover: Qt.rgba(1, 1, 1, 0.12)
    readonly property color borderSubtle: Qt.rgba(1, 1, 1, 0.08)
    readonly property color borderStrong: Qt.rgba(1, 1, 1, 0.15)
    
    readonly property color textPrimary: "#ffffff"
    readonly property color textSecondary: Qt.rgba(1, 1, 1, 0.7)
    readonly property color textTertiary: Qt.rgba(1, 1, 1, 0.4)
    
    readonly property color accentPrimary: "#8b5cf6"
    readonly property color accentGlow: Qt.rgba(139, 92, 246, 0.4)
    
    // Spacing Scale
    readonly property int spacingXs: 4
    readonly property int spacingSm: 8
    readonly property int spacingMd: 16
    readonly property int spacingLg: 24
    readonly property int spacingXl: 32
    
    // Radii
    readonly property int radiusSm: 6
    readonly property int radiusMd: 12
    readonly property int radiusLg: 20
    readonly property int radiusFull: 9999
    
    // Typography
    readonly property font fontDisplay: Qt.font({ family: "Inter", pixelSize: 32, weight: Font.Bold })
    readonly property font fontHeading: Qt.font({ family: "Inter", pixelSize: 20, weight: Font.SemiBold })
    readonly property font fontBody: Qt.font({ family: "Inter", pixelSize: 14, weight: Font.Normal })
    readonly property font fontCaption: Qt.font({ family: "Inter", pixelSize: 12, weight: Font.Normal })
    
    // Animation
    readonly property int durationFast: 150
    readonly property int durationNormal: 250
    readonly property int durationSlow: 400
    readonly property string easingStandard: "Easing.OutCubic"
}