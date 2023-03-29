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
  void handleSaveAsButton();

private:
  QPushButton *save_button;
  QPushButton *open_button;
  QPushButton *save_as_button;
  QVBoxLayout *vboxlayout;
  QHBoxLayout *hboxlayout;
  QString file_path;
  std::string getTextFromFile(std::ifstream &ReadFile);
};

#endif // MAINWINDOW_H
