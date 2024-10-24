#include "ComboBox.h"
#include <QTableView>
#include <QHeaderView>

#include <QLineEdit>
#include <QSortFilterProxyModel>
#include <QKeyEvent>

void ComboBox::slot_activated(int index)
{
    lineEdit()->setText(m_model->display_text(index));
}

ComboBox::ComboBox(QWidget *parent)
	: QComboBox(parent)
{
    setEditable(true);

    m_model = new QTableItemModel(this);

    setModelColumn(3);
    setView(create_view());

    setModel(m_model);

    QCompleter *completer = new QCompleter;
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    completer->setFilterMode(Qt::MatchStartsWith);
    completer->setPopup(create_view());
    completer->setModel(m_model);
    setCompleter(completer);
    connect(lineEdit(), &QLineEdit::textChanged, this, [=](const QString & text){m_text = text;});
    connect(lineEdit(), &QLineEdit::returnPressed, this, [=](){

        if (completer->completionCount() > 0) {
            QModelIndex index = completer->completionModel()->index(0, 0);
            lineEdit()->setText(completer->completionModel()->data(index).toString());
        }
        else{
            setCurrentText("");
            setCurrentIndex(-1);
        }
    });
    connect(this, SIGNAL(activated(int)), this, SLOT(slot_activated(int)));

    installEventFilter(this);
}

ComboBox::~ComboBox()
{}

bool ComboBox::eventFilter(QObject *obj, QEvent *event)
{
    if (obj==this&&event->type() == QEvent::KeyPress)
    {

        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Return)
        {
            QString sd= currentText();
            int sdf=9;
            return true;
        }
        QString sd= currentText();
        int sdf=9;
    }

    return QComboBox::eventFilter(obj, event);
}

QTableView *ComboBox::create_view()
{
    QTableView* view = new QTableView;
    view->horizontalHeader()->setVisible(false);
    view->verticalHeader()->setVisible(false);
    view->setMinimumHeight(300);
    view->setMinimumWidth(400);
    view->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
    view->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
    view->verticalHeader()->setDefaultSectionSize(15);
    return view;
}

QTableItemModel::QTableItemModel(QObject* parent)
	: QAbstractTableModel(parent)
{
    for (int i=0;i<200;i++)
    {
        Item item;
        item.name = QString::number(i);
        item.age = QString::number(i)+ QString::number(i);
        item.address = QString::number(i)+ QString::number(i)+ QString::number(i);
        m_datas.append(item);
    }
}

QVariant QTableItemModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole || role == Qt::EditRole){
        if(index.column()==0)
            return m_datas[index.row()].name;
        if(index.column()==1)
            return m_datas[index.row()].age;
        if(index.column()==2)
            return m_datas[index.row()].address;
	}
	return QVariant();
}

int QTableItemModel::rowCount(const QModelIndex& parent) const
{
	return m_datas.size();
}

int QTableItemModel::columnCount(const QModelIndex& parent ) const
{
	return 3;
}

QVariant QTableItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

QString QTableItemModel::display_text(int index)
{
    return m_datas[index].name;
}
