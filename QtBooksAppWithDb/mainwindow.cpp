#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:/Users/Asus/Documents/Books/database.db");

    m_peopleModel = new QSqlQueryModel(this);
    m_booksModel = new QSqlQueryModel(this);
    m_rentedModel = new QSqlQueryModel(this);

    UpdatePeople();
    UpdateBooks();
    UpdateRented();
}

MainWindow::~MainWindow()
{
    delete m_peopleModel;
    delete m_booksModel;
    delete m_rentedModel;

    delete ui;
}

void MainWindow::UpdatePeople()
{
    m_db.open();

    if(!m_db.isOpen())
    {
        qDebug("Couldn't open database");
    }
    else
    {
        QSqlQuery query(m_db);
        query.exec("Select * FROM People");
        m_peopleModel->setQuery(query);

        ui->People->setModel(m_peopleModel);
        ui->People->setColumnHidden(0, true);

        query.clear();
    }


    m_db.close();


}

void MainWindow::UpdateBooks()
{
    m_db.open();

    if(!m_db.isOpen())
    {
        qDebug("Couldn't open database");
    }
    else
    {
        QSqlQuery query(m_db);
        query.exec("SELECT * FROM Books WHERE rentedby = -1");
        m_booksModel->setQuery(query);

        ui->Books->setModel(m_booksModel);
        ui->Books->setColumnHidden(0,true);
        ui->Books->setColumnHidden(2,true);

        query.clear();
    }

    m_db.close();
}

void MainWindow::UpdateRented()
{
    m_db.open();

    if(!m_db.isOpen())
    {
        qDebug("Couldn't open database");
    }
    else
    {
        QSqlQuery query(m_db);
        query.exec("SELECT Books.id, People.name, People.surname, Books.'Book name' FROM Books, People WHERE Books.rentedby = People.id");
        m_rentedModel->setQuery(query);

        ui->Rented->setModel(m_rentedModel);
        ui->Rented->setColumnHidden(0,true);


        query.clear();
    }

    m_db.close();
}

void MainWindow::clearPeopleFields()
{
    ui->PeopleName->setText("");
    ui->PeopleSurname->setText("");
}

void MainWindow::clearBooksField()
{
    ui->BooksName->setText("");
}

void MainWindow::on_People_clicked(const QModelIndex &index)
{

    QVariant data = index.sibling(index.row(), 1).data();
    QVariant data1 = index.sibling(index.row(), 2).data();

    ui->PeopleName->setText(data.toString());
    ui->PeopleSurname->setText(data1.toString());


}



void MainWindow::on_PeopleName_editingFinished()
{
    QModelIndex index = ui->People->currentIndex();
    QItemSelectionModel* item = ui->People->selectionModel();
    QVariant id = index.sibling(index.row(), 0).data();
    QString name = ui->PeopleName->text();

    if(item->isSelected(index))
    {
        m_db.open();
        if(!m_db.isOpen())
        {
            qDebug("Couldn't open database");
        }
        else
        {
            QSqlQuery query(m_db);
            query.exec("UPDATE People SET Name = '"+name+"' WHERE id = '"+ id.toString()+"'");
            UpdatePeople();
        }
        m_db.close();
        clearPeopleFields();
    }

}

void MainWindow::on_PeopleSurname_editingFinished()
{
    QModelIndex index = ui->People->currentIndex();
    QItemSelectionModel* item = ui->People->selectionModel();
    QVariant id = index.sibling(index.row(), 0).data();
    QString surname = ui->PeopleSurname->text();

    if(item->isSelected(index))
    {
        m_db.open();
        if(!m_db.isOpen())
        {
            qDebug("Couldn't open database");
        }
        else
        {
            QSqlQuery query(m_db);
            query.exec("UPDATE People SET Surname = '"+surname+"' WHERE id = '"+ id.toString()+"'");
            UpdatePeople();
        }
        m_db.close();
        clearPeopleFields();
    }
}

void MainWindow::on_PeopleAdd_clicked()
{
    QModelIndex index = ui->People->currentIndex();
    QItemSelectionModel* item = ui->People->selectionModel();
    QString name = ui->PeopleName->text();
    QString surname = ui->PeopleSurname->text();

    if(name != "" && surname != "" && !item->isSelected(index))
    {
        m_db.open();
        if(!m_db.isOpen())
        {
            qDebug("Couldn't open database");
        }
        else
        {
            QSqlQuery query(m_db);
            query.exec("INSERT INTO People (Name, Surname) VALUES ('"+name+"','"+surname+"')");
            UpdatePeople();
        }
        m_db.close();
        clearPeopleFields();
    }

}

void MainWindow::on_PeopleDelete_clicked()
{
    QModelIndex index = ui->People->currentIndex();
    QItemSelectionModel* item = ui->People->selectionModel();
    QVariant id = index.sibling(index.row(), 0).data();

    if(item->isSelected(index))
    {
        m_db.open();
        if(!m_db.isOpen())
        {
            qDebug("Couldn't open database");
        }
        else
        {
            QSqlQuery query(m_db);
            query.exec("DELETE FROM People WHERE id = '"+id.toString()+"'");
            UpdatePeople();
        }
        m_db.close();
        clearPeopleFields();
    }
}

void MainWindow::on_Books_clicked(const QModelIndex &index)
{
    QVariant data = index.sibling(index.row(), 1).data();

    ui->BooksName->setText(data.toString());
}

void MainWindow::on_BooksAdd_clicked()
{
    QModelIndex index = ui->Books->currentIndex();
    QItemSelectionModel* item = ui->Books->selectionModel();
    QString name = ui->BooksName->text();


    if(name != "" && !item->isSelected(index))
    {
        m_db.open();
        if(!m_db.isOpen())
        {
            qDebug("Couldn't open database");
        }
        else
        {
            QSqlQuery query(m_db);
            query.exec("INSERT INTO Books ('Book name') VALUES ('"+name+"')");
            UpdateBooks();
        }
        m_db.close();
        clearBooksField();
    }
}

void MainWindow::on_BooksDelete_clicked()
{
    QModelIndex index = ui->Books->currentIndex();
    QItemSelectionModel* item = ui->Books->selectionModel();
    QVariant id = index.sibling(index.row(), 0).data();

    if(item->isSelected(index))
    {
        m_db.open();
        if(!m_db.isOpen())
        {
            qDebug("Couldn't open database");
        }
        else
        {
            QSqlQuery query(m_db);
            query.exec("DELETE FROM Books WHERE id = '"+id.toString()+"'");
            UpdateBooks();
        }
        m_db.close();
        clearBooksField();
    }
}

void MainWindow::on_BooksName_editingFinished()
{
    QModelIndex index = ui->Books->currentIndex();
    QItemSelectionModel* item = ui->Books->selectionModel();
    QVariant id = index.sibling(index.row(), 0).data();
    QString name = ui->BooksName->text();

    if(item->isSelected(index))
    {
        m_db.open();
        if(!m_db.isOpen())
        {
            qDebug("Couldn't open database");
        }
        else
        {
            QSqlQuery query(m_db);
            query.exec("UPDATE Books SET 'Book name' = '"+name+"' WHERE id = '"+ id.toString()+"'");
            UpdateBooks();
        }
        m_db.close();
        clearBooksField();
    }
}

void MainWindow::on_pushButton_clicked()
{
    QModelIndex BookIndex = ui->Books->currentIndex();
    QItemSelectionModel* BookItem = ui->Books->selectionModel();
    QVariant BookId = BookIndex.sibling(BookIndex.row(), 0).data();

    QModelIndex PersonIndex = ui->People->currentIndex();
    QItemSelectionModel* PersonItem = ui->People->selectionModel();
    QVariant PersonId = PersonIndex.sibling(PersonIndex.row(), 0).data();

    if(BookItem->isSelected(BookIndex) && PersonItem->isSelected(PersonIndex))
    {
        m_db.open();
        if(!m_db.isOpen())
        {
            qDebug("Couldn't open database");
        }
        else
        {
            QSqlQuery query(m_db);
            query.exec("UPDATE Books SET rentedby = '"+PersonId.toString()+"' WHERE id = '"+ BookId.toString()+"'");
            UpdateBooks();
            UpdateRented();
        }
        m_db.close();
        clearBooksField();
        clearPeopleFields();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QModelIndex BookIndex = ui->Rented->currentIndex();
    QItemSelectionModel* BookItem = ui->Rented->selectionModel();
    QVariant BookId = BookIndex.sibling(BookIndex.row(), 0).data();

    if(BookItem->isSelected(BookIndex))
    {
        m_db.open();
        if(!m_db.isOpen())
        {
            qDebug("Couldn't open database");
        }
        else
        {
            QSqlQuery query(m_db);
            query.exec("UPDATE Books SET rentedby = '-1' WHERE id = '"+ BookId.toString()+"'");
            UpdateBooks();
            UpdateRented();
        }
        m_db.close();
    }
}
