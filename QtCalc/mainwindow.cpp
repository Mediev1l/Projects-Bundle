#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_lVal("0")
    , m_rVal("0")
    , m_operator(NULL)

{
    ui->setupUi(this);

    ui->Display->setText("0");

    for(int i=0; i<10; i++)
           connect(MainWindow::findChild<QPushButton* >("Button" + QString::number(i)), SIGNAL(released()), this, SLOT(NumberPressed()));

    connect(ui->Coma, SIGNAL(released()),this,SLOT(NumberPressed()));

    connect(ui->Add, SIGNAL(released()),this,SLOT(OperatorPressed()));
    connect(ui->Subtract, SIGNAL(released()),this,SLOT(OperatorPressed()));
    connect(ui->Multiply, SIGNAL(released()),this,SLOT(OperatorPressed()));
    connect(ui->Divide, SIGNAL(released()),this,SLOT(OperatorPressed()));

    connect(ui->AC, SIGNAL(released()),this,SLOT(Clear()));
    connect(ui->Equal, SIGNAL(released()),this,SLOT(EqualPressed()));

    connect(ui->Sign, SIGNAL(released()),this,SLOT(SignChangePressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumberPressed()
{
    QPushButton* button = (QPushButton*)sender();
    QString text = button->text();

    if(m_operator == NULL)
    {
        if(m_lVal[0] == "0" && m_lVal[1] != ",")
        {
            if(text != "0")
            {
                if(text == ",")
                    m_lVal += text;
                else
                    m_lVal = text;
            }
            else
                text = "0";

        }
        else
        {
            if(m_lVal[0] == "-" && m_lVal[1] == "0" && !m_lVal.contains(","))
            {
                if(text != ",")
                    m_lVal.replace(1,1,text);
                else
                    m_lVal += text;
            }
            else if(text == "," && !m_lVal.contains(","))
                m_lVal = m_lVal.size() < 16 ? m_lVal + text : m_lVal;
            else if(text != ",")
                 m_lVal = m_lVal.size() < 16 ? m_lVal + text : m_lVal;
        }

        ui->Display->setText(m_lVal);
    }
    else
    {
        if(m_rVal == "0" && m_rVal[1] != ",")
        {
            if(text != "0")
            {
                if(text == ",")
                    m_rVal += text;
                else
                    m_rVal = text;
            }
            else
                text = "0";

        }
        else
        {
            if(m_rVal[0] == "-" && m_rVal[1] == "0" && !m_rVal.contains(","))
            {
                if(text != ",")
                    m_rVal.replace(1,1,text);
                else
                    m_rVal += text;
            }
            else if(text == "," && !m_rVal.contains(","))
                m_rVal =  m_rVal.size() < 16 ? m_rVal + text : m_rVal;
            else if(text != ",")
                m_rVal =  m_rVal.size() < 16 ? m_rVal + text : m_rVal;
        }
        ui->Display->setText(m_rVal);
    }



}

void MainWindow::EqualPressed()
{
    double tempL = m_lVal.replace(',','.').toDouble();
    double tempR = m_rVal.replace(',','.').toDouble();

    QString temp = m_lVal;


    if(m_operator == '+')
        temp= QString::number(tempL+ tempR);
    if(m_operator == '-')
        temp= QString::number(tempL - tempR);
    if(m_operator == '*')
        temp= QString::number(tempL * tempR);
    if(m_operator == '/')
    {
        if (tempR != 0)
            temp= QString::number(tempL / tempR);
    }


    ui->Display->setText(temp);

     m_lVal = QString(temp);

    m_rVal = "0";

    m_operator = NULL;
}
void MainWindow::SignChangePressed()
{
    if(m_operator == NULL)
    {
        if(m_lVal[0] != "-")
            m_lVal.insert(0,"-");
        else
            m_lVal.remove(0,1);
        ui->Display->setText(m_lVal);
    }
    else
    {
        if(m_rVal[0] != "-")
            m_rVal.insert(0, "-");
       else
            m_rVal.remove(0,1);
        ui->Display->setText(m_rVal);
    }
}
void MainWindow::OperatorPressed()
{
    QPushButton* button = (QPushButton*)sender();
    QString text = button->text();

    if(text == "+")
        m_operator = '+';
    else if(text == "-")
        m_operator = '-';
    else if(text == "*")
        m_operator = '*';
    else if(text == "/")
        m_operator = '/';
}
void MainWindow::Clear()
{
    m_lVal = "0";
    m_rVal = "0";
    m_operator = NULL;

    ui->Display->setText("0");
}
