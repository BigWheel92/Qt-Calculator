#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_zero_clicked();

    void on_one_clicked();

    void on_two_clicked();

    void on_three_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_openingParenthesis_clicked();

    void on_closing_parenthesis_clicked();

    void on_point_clicked();

    void on_divide_clicked();

    void on_pushButton_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_clearAll_clicked();

    void on_backspace_clicked();

    void on_equal_clicked();

private:
    Ui::MainWindow *ui;
    QString input;
};

#endif // MAINWINDOW_H
