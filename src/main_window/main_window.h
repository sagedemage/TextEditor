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
        QTextEdit *text_edit;

    private:
        // Variables
        const QString main_title = "Text Editor";
        QPushButton *save_button;
        QPushButton *open_button;
        QPushButton *save_as_button;
        QVBoxLayout *vboxlayout;
        QHBoxLayout *hboxlayout;
        QString file_path;
        QString file_path_tilda;
        QString title = main_title + " - Untitled";
        QMenu *fileMenu;
        QAction *SaveAct;
        QAction *OpenAct;
        QAction *SaveAsAct;
        QWidget *widget;
        QGridLayout *layout;

        // Methods
        void changeWindowTitleForNewFilePath();
        void convertHomPathWithTilde();
        void createMenus();
        void createActions();
        void createLayouts();
        void createWidgets();
        std::string getTextFromFile(std::ifstream &ReadFile);

    private slots:
        void handleSaveButton();
        void handleOpenButton();
        void handleSaveAsButton();
};

#endif // MAINWINDOW_H
