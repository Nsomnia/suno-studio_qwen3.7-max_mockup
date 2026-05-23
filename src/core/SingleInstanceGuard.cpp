// File: src/core/SingleInstanceGuard.cpp
#include "SingleInstanceGuard.hpp"
#include <kdsingleapplication.h>

namespace Suno::Core {

SingleInstanceGuard::SingleInstanceGuard(QObject* parent)
    : QObject(parent)
    , m_app(std::make_unique<KDSingleApplication>()) 
{
    if (!isPrimaryInstance()) {
        // In a real app, we'd send args to primary here
        // For mockup, just emit signal for UI feedback
        emit secondaryInstanceActivated();
    }
}

SingleInstanceGuard::~SingleInstanceGuard() = default;

bool SingleInstanceGuard::isPrimaryInstance() const noexcept {
    return m_app->isPrimaryInstance();
}

} // namespace Suno::Core