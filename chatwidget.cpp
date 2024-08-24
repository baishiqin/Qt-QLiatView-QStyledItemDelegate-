#include "chatwidget.h"
#include <QIcon>
#include <QLayout>
#include <QTextEdit>
#include <QDebug>

ChatWidget::ChatWidget(QString netName,QString pixmap,QWidget *parent) : QWidget(parent)
{
    setWindowTitle(netName);
    this->setWindowIcon(QIcon(QPixmap(pixmap)));
    QTextEdit* edit = new QTextEdit(this);
    QVBoxLayout* VBoxLayout = new QVBoxLayout;
    VBoxLayout->addWidget(edit);
    this->setLayout(VBoxLayout);
}

ChatWidget::~ChatWidget()
{
    qDebug() << __FUNCTION__;
}
