#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QtWidgets>
#include <QApplication>

namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);
  QLineEdit *line_edit = new QLineEdit("");

private slots:
  void handleButton1();
  void handleButton2();
  void handleButton3();
  void handleButton4();
  void handleButton5();
  void handleButton6();
  void handleButton7();
  void handleButton8();
  void handleButton9();

private:
  QPushButton *button1;
  QPushButton *button2;
  QPushButton *button3;
  QPushButton *button4;
  QPushButton *button5;
  QPushButton *button6;
  QPushButton *button7;
  QPushButton *button8;
  QPushButton *button9;

  QVBoxLayout *vboxlayout;
  QHBoxLayout *hboxlayout1;
  QHBoxLayout *hboxlayout2;
  QHBoxLayout *hboxlayout3;
};
#endif // MAINWINDOW_H
