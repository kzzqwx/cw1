#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());

    updateList();

    connect(updater, SIGNAL(timeout()), this, SLOT(update()));

    player = new QMediaPlayer();
    audioOutout = new QAudioOutput();
    player->setAudioOutput(audioOutout);
    audioOutout->setVolume(100);

    ui->listWidget->setCurrentRow(0);

    if(ui->listWidget->count() != 0){
        loadSong();
        player->pause();
        updater->start();

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateList(){
    //ui->listWidget->clear();
    ui->listWidget->addItems(playlist.getNameOfSongInList());
};

void MainWindow::loadSong(){
    QString qs = QString::fromStdString(playlist.songs[getIndex()].getLoc());
    player->setSource(QUrl::fromLocalFile(qs));
    qs = QString::fromStdString(playlist.songs[getIndex()].getName());
    //ui->currentSong->setText(qs);
}



int MainWindow::getIndex()
{
    return ui->listWidget->currentIndex().row();
}


void MainWindow::on_addTrack_clicked()
{
    bool flag = false;
    if (ui->listWidget->count() == 0){
        flag = true;
    }
    QStringList files = QFileDialog::getOpenFileNames(this, "Choose your music");
    if (!files.empty()){
        playlist.add(files);
        updateList();
        ui->save->setChecked(false);
    }
}


void MainWindow::on_play_clicked()
{

}


void MainWindow::on_save_clicked()
{
    playlist.save();
    ui->save->setChecked(true);
}

