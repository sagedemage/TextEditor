#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QtWidgets>
#include <QApplication>
#include <iostream>
#include <fstream>

namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);
  QTextEdit *text_edit = new QTextEdit("");

private slots:
  void handleSaveButton();
  void handleOpenButton();
  void handleCreateButton();

private:
  QPushButton *save_button;
  QPushButton *open_button;
  QPushButton *create_button;
  QVBoxLayout *vboxlayout;
  QHBoxLayout *hboxlayout;
  std::string getTextFromFile(std::ifstream &ReadFile);
};
#endif // MAINWINDOW_H
