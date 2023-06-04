#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "listofsongs.h"
#include <QtMultimedia/QMediaPlayer>
#include "QTimer"
#include "QPalette"
//#include "vector"
#include "QKeyEvent"
#include "QLineEdit"
#include <QList>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_addTrack_clicked();

    void on_play_clicked();

    void on_save_clicked();

private:
    Ui::MainWindow *ui;
    void updateList();
    void loadSong();
    void next();
    void prev();
    void shuffleList();
    int getIndex();

    bool repeat = false;
    bool muted = false;
    bool shuffle = false;

    int lSong = 0;

    QTimer *updater = new QTimer(this);
    QMediaPlayer *player = new QMediaPlayer();
    QAudioOutput *audioOutout = new QAudioOutput();

    ListOfSongs playlist;

};
#endif // MAINWINDOW_H
