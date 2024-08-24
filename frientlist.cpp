#include "frientlist.h"
#include "ui_frientlist.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
frientList::frientList(QWidget *parent) :
    QListView(parent),
    ui(new Ui::frientList)
{
    ui->setupUi(this);
    //对于视图来讲需要添加数据项
    m_Model = new QStandardItemModel(this);
    this->setModel(m_Model);
    //创建代理
    m_Delegate = new FFriendDelegate(parent);
    this->setItemDelegate(m_Delegate);
    //设置不能在界面上修改
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //添加json文件
    QFile jsonFile(":/json/friendJson.json");
    if(jsonFile.open(QIODevice::ReadOnly))
    {
        //读取数组
        QByteArray arry = jsonFile.readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(arry);
        QJsonArray jsonArry = jsonDocument.array();
        for(auto object : jsonArry)
        {
            qDebug() << object;
            QJsonObject jsonObject = object.toObject();
            //给数据模型添加数据
            QStandardItem* item = new QStandardItem;
            item->setData(jsonObject["net_name"].toString(),Qt::UserRole + 1);
            item->setData(jsonObject["signature"].toString(),Qt::UserRole + 2);
            item->setData(jsonObject["pixmap"].toString(),Qt::UserRole + 3);
            m_Model->appendRow(item);
        }
        jsonFile.close();
    }
    connect(this,&QListView::doubleClicked,this,&frientList::doubleClicked);
}

frientList::~frientList()
{
    qDebug() << "__FUNCTION__" << __FUNCTION__;
    delete ui;
}

void frientList::doubleClicked(const QModelIndex &index)
{
    //ChatWidget* chat = new ChatWidget(index.data(Qt::UserRole +1).toString(),index.data(Qt::UserRole +3).toString());
    //chat->show();
//    QString netName = index.data(Qt::UserRole + 1).toString();
//    QString signature = index.data(Qt::UserRole + 2).toString();
//    QString pixmap = index.data(Qt::UserRole + 3).toString();

//    ChatWidget* chat = index.data(Qt::UserRole + 4).value<ChatWidget*>();
//    if(chat == nullptr)
//    {
//        chat = new ChatWidget(netName,pixmap);
//        QVariant variant;
//        variant.setValue(chat);
//        m_Model->itemFromIndex(index)->setData(variant,Qt::UserRole + 4);
//    }
//    chat->show();
}
