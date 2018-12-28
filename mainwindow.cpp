#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    proc = new QProcess;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_helpPushButton_clicked()
{
    /*
     * 注意：读者自行编译运行时，需要将exe改为"./release/assistant.exe"。
     * 因为项目路径与发布的实际exe路径差了release.
     * 将params改为./assistant/assistant.qhc。因为项目路径与发布的实际qhc路径差了前后级。
     */
    QString exe("./release/assistant.exe");
    QStringList params;
    params << "-collectionFile" << "./assistant/assistant.qhc";
    proc->start(exe, params);
    if (!proc->waitForStarted()) {
        QMessageBox::critical(0, QObject::tr("Tips"),
            QObject::tr("Unable to launch Qt Assistant (%1)").arg(exe));
    }
}
