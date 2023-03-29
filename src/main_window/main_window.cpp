#include "main_window.h"
#include <iostream>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

  QGridLayout *layout = new QGridLayout();
  QWidget *widget = new QWidget();
  widget->setLayout(layout);
  setCentralWidget(widget);

  //QLineEdit *line_edit = new QLineEdit("");

  //line_edit->setText("Word");

  // Create the button, make "this" the parent
  save_button = new QPushButton("Save");
  open_button = new QPushButton("Open");
  create_button = new QPushButton("Create File");

  hboxlayout = new QHBoxLayout();

  hboxlayout->addWidget(save_button);
  hboxlayout->addWidget(open_button);
  hboxlayout->addWidget(create_button);

  layout->addLayout(hboxlayout, 0, 0, 1, 1);

  vboxlayout = new QVBoxLayout();
  vboxlayout->addWidget(text_edit);

  layout->addLayout(vboxlayout, 1, 0, 1, 1);

  // Connect button signal to appropriate slot
  connect(save_button, &QPushButton::clicked, this, &MainWindow::handleSaveButton);
  connect(open_button, &QPushButton::clicked, this, &MainWindow::handleOpenButton);
  connect(create_button, &QPushButton::clicked, this, &MainWindow::handleCreateButton);
}

void MainWindow::handleSaveButton()
{
  //text_edit->setText("Save");
  QString plain_text = text_edit->toPlainText();
  std::string text_string = plain_text.toStdString();
  std::cout << text_string << std::endl;
}

void MainWindow::handleOpenButton()
{
  text_edit->setText("Open");
}

void MainWindow::handleCreateButton()
{
  text_edit->setText("Create");
}

