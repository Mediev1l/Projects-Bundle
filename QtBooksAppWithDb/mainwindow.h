#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_People_clicked(const QModelIndex &index);

    void on_PeopleName_editingFinished();

    void on_PeopleSurname_editingFinished();

    void on_PeopleAdd_clicked();

    void on_PeopleDelete_clicked();

    void on_Books_clicked(const QModelIndex &index);

    void on_BooksAdd_clicked();

    void on_BooksDelete_clicked();

    void on_BooksName_editingFinished();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    void UpdatePeople();
    void UpdateBooks();
    void UpdateRented();

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db;
    QSqlQueryModel* m_peopleModel;
    QSqlQueryModel* m_booksModel;
    QSqlQueryModel* m_rentedModel;

    void clearPeopleFields();
    void clearBooksField();
};
#endif // MAINWINDOW_H
