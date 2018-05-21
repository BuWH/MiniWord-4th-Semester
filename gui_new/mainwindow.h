#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <string>
#include <QTextStream>
#include <QDataStream>
#include <vector>
#include <QCloseEvent>
#include <QVector>
#include <QDialog>
#include <QAction>
#include <QWidget>
#include <QDebug>
#include <QFileDialog>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QLineEdit>
#include <QSize>
#include <QTextStream>
#include <QDataStream>
#include <vector>
#include <QPushButton>
#include <QLabel>
#include <QPainter>
#include <QKeyEvent>
#include <QKeySequence>
#include <QString>
#include <QCloseEvent>
#include "file_process.h"

#define LINE_WIDTH 700
#define LINE_HEIGHT 21
#define TEXT_UPPER_BLANK 40
#define TEXT_LEFT_BLANK 50
#define INPUT_LEFT_BLANK 5
#define INPUT_DOWN_BLANK 1
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void init_file(FileProcess *file_part){
       filepart = file_part;
    }
signals:
    void SendCreateSignal();
    void SendOpenPath(QString path);
    void SendSavePath(QString path);
    void SendSaveAsPath(QString path);
protected:
    //void keyReleaseEvent(QKeyEvent *);
    //void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *event);
private:
    FileProcess *filepart;

    void create();
    void open();
    void save();
    void save_as();

    QAction *createAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveasAction;

    QLineEdit Input;
    QLabel InputTips;

    bool OpenSignal;
    bool CreateSignal;
};

#endif // MAINWINDOW_H
