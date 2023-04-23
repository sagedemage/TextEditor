#include "main_window.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    QGridLayout *layout = new QGridLayout();
    QWidget *widget = new QWidget();
    widget->setLayout(layout);
    setCentralWidget(widget);

    text_edit = new QTextEdit("");

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

    MainWindow::setWindowTitle(title);

    createActions();

    createMenus();
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
        // add line to the string
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

    // get text from the text file
    std::string text_of_file = MainWindow::getTextFromFile(ReadFile);

    // set text for the text edit widget
    text_edit->setText(QString::fromStdString(text_of_file));

    MainWindow::changeWindowTitleForNewFilePath();
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

    MainWindow::changeWindowTitleForNewFilePath();
}

void MainWindow::changeWindowTitleForNewFilePath() {
    /* Change window title based on the location of the file opened */
    MainWindow::convertHomPathWithTilde();

    if (file_path != "") {
        title = main_title + " - " + file_path;
        MainWindow::setWindowTitle(title);
    }
}

void MainWindow::convertHomPathWithTilde() {
    /* Convert file path with a file path with a tilde */
    QString home = QDir::home().path();

    int home_path_length = home.length();

    file_path.replace(0, home_path_length, "~");
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(SaveAct);
    fileMenu->addAction(OpenAct);
    fileMenu->addAction(SaveAsAct);
}

void MainWindow::createActions()
{
    // Save Action
    SaveAct = new QAction(tr("&Save"), this);
    SaveAct->setShortcuts(QKeySequence::Save);
    SaveAct->setStatusTip(tr("Save the file"));

    // Open Action
    OpenAct = new QAction(tr("&Open"), this);
    OpenAct->setShortcuts(QKeySequence::Open);
    OpenAct->setStatusTip(tr("Open the file"));

    SaveAsAct = new QAction(tr("&Save As"), this);
    SaveAsAct->setShortcuts(QKeySequence::SaveAs);
    SaveAsAct->setStatusTip(tr("Save as a new file"));
    //connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
}

