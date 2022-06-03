#pragma once
#include "Repository.h"
#include "service.h"
#include <QAbstractTableModel>

class MoviesModel: public QAbstractTableModel
{
private:
	Service& srv;
public:
	MoviesModel(Service& srv):srv(srv){}

	int rowCount(const QModelIndex& parent = QModelIndex())const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

};

