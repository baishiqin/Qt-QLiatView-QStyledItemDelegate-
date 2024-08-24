#ifndef FFRIENDDELEGATE_H
#define FFRIENDDELEGATE_H
//专门处理样式的代理
#include <QObject>
#include <QStyledItemDelegate>
#include <QPainter>

class FFriendDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    FFriendDelegate(QObject* parent = nullptr);
    ~FFriendDelegate();

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

};

#endif // FFRIENDDELEGATE_H
