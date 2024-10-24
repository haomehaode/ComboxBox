#pragma once

#include <QComboBox>
#include <QAbstractTableModel>
#include <QString>
#include <QCompleter>
#include <QTableView>
#include <QEvent>

struct Item
{
	QString name;
	QString age;
	QString address;
};

class QTableItemModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	explicit QTableItemModel(QObject* parent = nullptr);
	QVariant data(const QModelIndex& index, int role) const;
	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;

public:
    QString display_text(int index);

private:
	QVector<Item> m_datas;
};

class ComboBox : public QComboBox
{
	Q_OBJECT

public slots:
    void slot_activated(int index);

public:
	ComboBox(QWidget* parent = nullptr);
	~ComboBox();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    QTableView* create_view();

private:
    QTableItemModel* m_model = nullptr;
    QString m_text;
};
