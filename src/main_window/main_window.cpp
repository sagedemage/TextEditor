#include "main_window.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

  QGridLayout *layout = new QGridLayout();
  QWidget *widget = new QWidget();
  widget->setLayout(layout);
  setCentralWidget(widget);

  // Create the button, make "this" the parent
  save_button = new QPushButton("Save");
  open_button = new QPushButton("Open");
  save_as_button = new QPushButton("Save As");

  hboxlayout = new QHBoxLayout();

  hboxlayout->addWidget(save_button);
  hboxlayout->addWidget(open_button);
  hboxlayout->addWidget(save_as_button);

  layout->addLayout(hboxlayout, 0, 0, 1, 1);

  vboxlayout = new QVBoxLayout();
  vboxlayout->addWidget(text_edit);

  layout->addLayout(vboxlayout, 1, 0, 1, 1);

  // Connect button signal to appropriate slot
  connect(save_button, &QPushButton::clicked, this, &MainWindow::handleSaveButton);
  connect(open_button, &QPushButton::clicked, this, &MainWindow::handleOpenButton);
  connect(save_as_button, &QPushButton::clicked, this, &MainWindow::handleSaveAsButton);
}

void MainWindow::handleSaveButton()
{
  /* Save a File */
  QString plain_text = text_edit->toPlainText();
    std::string text_string = plain_text.toStdString();

    if (file_path.toStdString() != "") {
      // Create and open a text file
      std::ofstream MyFile(file_path.toStdString());

      // Write to the file
      MyFile << text_string;

      // Close the file
      MyFile.close();
    }
    else {
      // Save file
      file_path = QFileDialog::getSaveFileName(this, tr("Save File"),
                            QString::fromStdString("untitled.txt"),
                            tr("Text files (*.txt)"));

      // Create and open a text file
      std::ofstream MyFile(file_path.toStdString());

      // Write to the file
      MyFile << text_string;

      // Close the file
      MyFile.close();
    }
}

std::string MainWindow::getTextFromFile(std::ifstream &ReadFile) {
  std::string myText;
  std::string tempText;

  while (getline (ReadFile, tempText)) {
    // Output the text from the file
    //cout << myText;
    myText += tempText + "\n";

  }
  return myText;
}


void MainWindow::handleOpenButton()
{
  /* Open a file */
  file_path = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(), tr("Text files (*.txt)"));

  // Create and open a text file
  std::ifstream ReadFile(file_path.toStdString());

  std::string myText = MainWindow::getTextFromFile(ReadFile);

  text_edit->setText(QString::fromStdString(myText));
}

void MainWindow::handleSaveAsButton()
{
  /* Save a File */
  QString plain_text = text_edit->toPlainText();
  std::string text_string = plain_text.toStdString();

  // Save file
  file_path = QFileDialog::getSaveFileName(this, tr("Save File"),
                            QString::fromStdString("untitled.txt"),
                            tr("Text files (*.txt)"));

  // Create and open a text file
  std::ofstream MyFile(file_path.toStdString());

  // Write to the file
  MyFile << text_string;

  // Close the file
  MyFile.close();
}


