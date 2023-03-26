#include "main_window.h"
#include <iostream>

// #include <QApplication>
// #include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

  QGridLayout *layout = new QGridLayout();
  QWidget *widget = new QWidget();
  widget->setLayout(layout);
  setCentralWidget(widget);

  // Create the button, make "this" the parent
  QPushButton *button1 = new QPushButton("Number 1");
  QPushButton *button2 = new QPushButton("Number 2");
  QPushButton *button3 = new QPushButton("Number 3");
  QPushButton *button4 = new QPushButton("Number 4");
  QPushButton *button5 = new QPushButton("Number 5");
  QPushButton *button6 = new QPushButton("Number 6");
  QPushButton *button7 = new QPushButton("Number 7");
  QPushButton *button8 = new QPushButton("Number 8");
  QPushButton *button9 = new QPushButton("Number 9");

  layout->addWidget(button1, 0, 0);
  layout->addWidget(button2, 0, 1);
  layout->addWidget(button3, 0, 2);
  layout->addWidget(button4, 1, 0);
  layout->addWidget(button5, 1, 1);
  layout->addWidget(button6, 1, 2);
  layout->addWidget(button7, 2, 0);
  layout->addWidget(button8, 2, 1);
  layout->addWidget(button9, 2, 2);

  // Connect button signal to appropriate slot
  connect(button1, &QPushButton::clicked, this, &MainWindow::handleButton1);
  connect(button2, &QPushButton::clicked, this, &MainWindow::handleButton2);
  connect(button3, &QPushButton::clicked, this, &MainWindow::handleButton3);
  connect(button4, &QPushButton::clicked, this, &MainWindow::handleButton4);
  connect(button5, &QPushButton::clicked, this, &MainWindow::handleButton5);
  connect(button6, &QPushButton::clicked, this, &MainWindow::handleButton6);
  connect(button7, &QPushButton::clicked, this, &MainWindow::handleButton7);
  connect(button8, &QPushButton::clicked, this, &MainWindow::handleButton8);
  connect(button9, &QPushButton::clicked, this, &MainWindow::handleButton9);
}

void MainWindow::handleButton1()
{
  std::cout << "Number 1" << std::endl;
}

void MainWindow::handleButton2()
{
  std::cout << "Number 2" << std::endl;
}

void MainWindow::handleButton3()
{
  std::cout << "Number 3" << std::endl;
}

void MainWindow::handleButton4()
{
  std::cout << "Number 4" << std::endl;
}

void MainWindow::handleButton5()
{
  std::cout << "Number 5" << std::endl;
}

void MainWindow::handleButton6()
{
  std::cout << "Number 6" << std::endl;
}

void MainWindow::handleButton7()
{
  std::cout << "Number 7" << std::endl;
}

void MainWindow::handleButton8()
{
  std::cout << "Number 8" << std::endl;
}

void MainWindow::handleButton9()
{
  std::cout << "Number 9" << std::endl;
}