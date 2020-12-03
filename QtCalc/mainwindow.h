#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QString m_lVal;
    QString m_rVal;
    char m_operator;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void NumberPressed();
    void EqualPressed();
    void SignChangePressed();
    void OperatorPressed();
    void Clear();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
