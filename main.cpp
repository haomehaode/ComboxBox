#include "ComboBox.h"
#include <QtWidgets/QApplication>
#include <QStringList>
#include <QLineEdit>
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ComboBox w;
    w.show();



   //QStringList wordList;
   //wordList << "alpha" << "omega" << "omicron" << "zeta";

   //QLineEdit *lineEdit = new QLineEdit;
   //QTableItemModel*moel=new QTableItemModel;
   //QStandardItemModel *model = new QStandardItemModel;
   //model->setColumnCount(3);
   //QStandardItem *item1 = new QStandardItem("Data 1-1");
   //QStandardItem *item2 = new QStandardItem("Data 1-2");
   //QStandardItem *item3 = new QStandardItem("Data 1-3");
   //QList<QStandardItem *> row1;
   //row1 << item1 << item2 << item3;
   //model->appendRow(row1);
   //QStandardItem *item4 = new QStandardItem("Data 2-1");
   //QStandardItem *item5 = new QStandardItem("Data 2-2");
   //QStandardItem *item6 = new QStandardItem("Data 2-3");
   //QList<QStandardItem *> row2;
   //row2 << item4 << item5 << item6;
   //model->appendRow(row2);
   //QCompleter *completer = new QCompleter(model);
   //completer->setCaseSensitivity(Qt::CaseInsensitive);
   //lineEdit->setCompleter(completer);
   //lineEdit->show();

   //QComboBox co;
   //QStringList itemList{"1","11","12","3","2","34"};
   //co.addItems(itemList);
   //co.setEditable(true);
   //QCompleter *comp = new QCompleter(itemList);
   //comp->setFilterMode(Qt::MatchContains);
   //comp->setCaseSensitivity(Qt::CaseInsensitive);
   //comp->setCompletionMode(QCompleter::PopupCompletion);
   //co.setCompleter(comp);
   //co.show();







    return a.exec();
}
