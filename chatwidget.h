#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>


class ChatWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChatWidget(QString netName,QString pixmap, QWidget *parent = nullptr);
    ~ChatWidget();
signals:

};

#endif // CHATWIDGET_H
