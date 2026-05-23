// File: src/shared/models/TrackModel.hpp
#pragma once

#include <QAbstractListModel>
#include <QString>
#include <QUrl>
#include <chrono>

namespace Suno::Shared {

struct Track {
    QString id;
    QString title;
    QString artist;
    QUrl coverArtUrl;
    std::chrono::seconds duration;
    QString styleTags;
    bool isGenerated = false;
};

class TrackModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        TitleRole,
        ArtistRole,
        CoverArtRole,
        DurationRole,
        StyleTagsRole,
        IsGeneratedRole
    };
    Q_ENUM(Roles)

    explicit TrackModel(QObject* parent = nullptr);

    [[nodiscard]] int rowCount(const QModelIndex& parent = {}) const override;
    [[nodiscard]] QVariant data(const QModelIndex& index, int role) const override;
    [[nodiscard]] QHash<int, QByteArray> roleNames() const override;

    void loadSampleData();
    void addTrack(Track track);
    void clear();

private:
    std::vector<Track> m_tracks;
};

} // namespace Suno::Shared