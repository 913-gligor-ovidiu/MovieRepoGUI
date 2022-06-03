#include "MoviesModel.h"
#include <qcolor.h>
#include <qbrush.h>

int MoviesModel::rowCount(const QModelIndex& parent) const
{
    return srv.getRepoSize();
}

int MoviesModel::columnCount(const QModelIndex& parent) const
{
    return 5;
}

QVariant MoviesModel::data(const QModelIndex& index, int role) const
{
    int row = index.row();
    int column = index.column();

    Movie m = srv.getAllSrv()[row];

    if (role == Qt::DisplayRole)
    {
        switch (column)
        {
        case 0:
            return QString::fromStdString(m.getName());
        case 1:
            return QString::fromStdString(m.getGenre());
        case 2:
            return QString::number(m.getYear());
        case 3:
            return QString::number(m.getNrLikes());
        case 4:
            return QString::fromStdString(m.getTrailer());
        }
    }
    else if (role == Qt::BackgroundRole)
    {
        if (row & 1)
            return QBrush(QColor(224, 224, 224));
    }
    return QVariant();
}

QVariant MoviesModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        switch (section) {
        case 0:
            return QString("Name");
        case 1:
            return QString("Genre");
        case 2:
            return QString("Year");
        case 3:
            return QString("Number of Likes");
        case 4:
            return QString("Trailer");
        default:
            break;
        }
    return QVariant();
}

