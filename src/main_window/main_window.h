#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QtWidgets>

namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);
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
  QPushButton *m_button;
};
#endif // MAINWINDOW_H