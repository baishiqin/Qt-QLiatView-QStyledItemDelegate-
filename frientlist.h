#ifndef FRIENTLIST_H
#define FRIENTLIST_H

#include <QWidget>
#include <QListView>
#include <QStandardItemModel>//数据模型
#include "ffrienddelegate.h"
#include "chatwidget.h"

namespace Ui {
class frientList;
}

class frientList : public QListView
{
    Q_OBJECT

public:
    explicit frientList(QWidget *parent = nullptr);
    ~frientList();

private slots:
    void doubleClicked(const QModelIndex& index);

private:
    Ui::frientList *ui;
    QStandardItemModel* m_Model;
    FFriendDelegate* m_Delegate;
};

#endif // FRIENTLIST_H
