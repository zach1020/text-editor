#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onOpenButton_clicked() {
    QString filename = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            ui->textEdit->setPlainText(in.readall());
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Could not open file");
        }
    }
}

void MainWindow::on_saveButton_clicked() {
    QString fileName = QFileDialog::getSavedFileName(this, "Save File", "", "Text Files (*.txt);;All Files (*)" );
    if(!fileName.isEmpty()) {
        QFile file(fileName);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << ui->textEdit->toPlainText();
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Could not save file"_);
        }
    }
}

void MainWindow::on_exitButton_clicked() {
    QApplication::quit();
}