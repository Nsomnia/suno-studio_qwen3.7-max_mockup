// File: src/shared/models/TrackModel.cpp
// File: src/shared/models/TrackModel.cpp
#include "TrackModel.hpp"
#include <random>

namespace Suno::Shared {

TrackModel::TrackModel(QObject* parent)
    : QAbstractListModel(parent) 
{
    loadSampleData();
}

int TrackModel::rowCount(const QModelIndex& parent) const {
    return parent.isValid() ? 0 : static_cast<int>(m_tracks.size());
}

QVariant TrackModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() >= static_cast<int>(m_tracks.size()))
        return {};

    const auto& track = m_tracks[index.row()];
    switch (role) {
        case IdRole: return track.id;
        case TitleRole: return track.title;
        case ArtistRole: return track.artist;
        case CoverArtRole: return track.coverArtUrl;
        case DurationRole: return static_cast<int>(track.duration.count());
        case StyleTagsRole: return track.styleTags;
        case IsGeneratedRole: return track.isGenerated;
        default: return {};
    }
}

QHash<int, QByteArray> TrackModel::roleNames() const {
    return {
        {IdRole, "id"},
        {TitleRole, "title"},
        {ArtistRole, "artist"},
        {CoverArtRole, "coverArtUrl"},
        {DurationRole, "durationSecs"},
        {StyleTagsRole, "styleTags"},
        {IsGeneratedRole, "isGenerated"}
    };
}

void TrackModel::loadSampleData() {
    beginResetModel();
    m_tracks.clear();
    
    m_tracks.push_back({"trk_001", "Neon Horizons", "SynthWave AI", 
                        QUrl("qrc:/assets/covers/neon.jpg"), 
                        std::chrono::seconds(214), "synthwave,retro,upbeat", true});
                        
    m_tracks.push_back({"trk_002", "Midnight Rain", "LoFi Generator", 
                        QUrl("qrc:/assets/covers/rain.jpg"), 
                        std::chrono::seconds(180), "lofi,chill,ambient", true});
                        
    m_tracks.push_back({"trk_003", "Quantum Dreams", "Cybernetic Soul", 
                        QUrl("qrc:/assets/covers/quantum.jpg"), 
                        std::chrono::seconds(245), "cyberpunk,dark,bass", true});
    
    endResetModel();
}

void TrackModel::addTrack(Track track) {
    beginInsertRows({}, static_cast<int>(m_tracks.size()), static_cast<int>(m_tracks.size()));
    m_tracks.push_back(std::move(track));
    endInsertRows();
}

void TrackModel::clear() {
    beginResetModel();
    m_tracks.clear();
    endResetModel();
}

} // namespace Suno::Shared