// File: src/core/SingleInstanceGuard.hpp
#pragma once

#include <QObject>
#include <memory>

class KDSingleApplication;

namespace Suno::Core {

class SingleInstanceGuard : public QObject {
    Q_OBJECT
public:
    explicit SingleInstanceGuard(QObject* parent = nullptr);
    ~SingleInstanceGuard() override;

    [[nodiscard]] bool isPrimaryInstance() const noexcept;

signals:
    void secondaryInstanceActivated();

private:
    std::unique_ptr<KDSingleApplication> m_app;
};

} // namespace Suno::Core