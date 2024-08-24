#include "ffrienddelegate.h"
#include <QDebug>

FFriendDelegate::FFriendDelegate(QObject* parent): QStyledItemDelegate(parent)
{

}

FFriendDelegate::~FFriendDelegate()
{

}

void FFriendDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString netName = index.data(Qt::UserRole + 1).toString();
    QString signature = index.data(Qt::UserRole + 2).toString();
    QString pixmap = index.data(Qt::UserRole + 3).toString();
    painter->drawText(70,25+option.rect.y(),netName);
    painter->drawText(70,45+option.rect.y(),signature);
    painter->drawPixmap(0,option.rect.y() + 5,50,50,QPixmap(pixmap));

    QStyledItemDelegate::paint(painter,option,index);
}

QSize FFriendDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    qDebug() << index;
    return QSize(option.rect.width(),60);
}


