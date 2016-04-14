#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myqgraphicsview.h"
#include <QtCore/QtDebug>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonLine,SIGNAL(clicked()),this,SLOT(modeLine()));
    connect(ui->buttonCircle,SIGNAL(clicked()),this,SLOT(modeCircle()));
    connect(ui->buttonEllipse,SIGNAL(clicked()),this,SLOT(modeEllipse()));
    connect(ui->buttonPolygone,SIGNAL(clicked()),this,SLOT(modePolygone()));
    ui->horizontalLayout->addWidget( this->myGV );
    vector<QString> colors = {"black","red", "blue","yellow","green"};
    this->ui->comboColorCircle->clear();
    this->ui->comboColorLine->clear();
    this->ui->comboColorEllipse->clear();
    this->ui->comboColorPolygone->clear();
    for(QString col : colors){
        this->ui->comboColorCircle->addItem(col);
        this->ui->comboColorPolygone->addItem(col);
        this->ui->comboColorEllipse->addItem(col);
        this->ui->comboColorLine->addItem(col);

    }

    connect(ui->buttonRotation,SIGNAL(clicked()),this,SLOT(applyRotation()));
    connect(ui->buttonTranslation,SIGNAL(clicked()),this,SLOT(applyTranslation()));
    connect(ui->buttonHomo,SIGNAL(clicked()),this,SLOT(applyHomo()));

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::modeCircle()
{

    this->myGV->setMaxtPoint(1);
    double r = 10;
    try{
        r= ui->lineEditRayonCircle->text().toDouble();
    } catch(exception *e){
        r = 10;
    }
    if(r ==0){
        r = 10;
    }
    this->myGV->setRayon(r);
    this->myGV->setColorCircle(this->ui->comboColorCircle->currentText());
    qDebug() <<"SET RAYON"<<r << ui->lineEditRayonCircle->text();
    this->myGV->updateModeCircle();
    ui->labelMode->setText("Mode Cercle ("+QString::number(r)+"),\ncolor :"+this->ui->comboColorCircle->currentText());

}

void MainWindow::modeEllipse()
{
    this->myGV->setMaxtPoint(1);
    double rlon = 20;
    double rlar = 10;
    try{
        rlar  = ui->lineEditRlar->text().toDouble();
    } catch(exception *e){
        rlar = 10;
    }
    try{
        rlon  = ui->lineEditRlon->text().toDouble();
    } catch(exception *e){
        rlon = 20;
    }
    if(rlon ==0)
        rlon = 20;
    if(rlar ==0)
        rlar = 10;

    this->myGV->setRlar(rlar);
    this->myGV->setRlon(rlon);
    this->myGV->setColorEllipse(this->ui->comboColorEllipse->currentText());
    this->myGV->updateModeEllipse();
    ui->labelMode->setText("Mode Ellipse("+QString::number(rlon)+","+QString::number(rlar)+"),\ncolor :"+this->ui->comboColorEllipse->currentText());
}

void MainWindow::modeLine()
{
    this->myGV->setMaxtPoint(2);
    this->myGV->setColorLine(this->ui->comboColorLine->currentText());
    this->myGV->updateModeLine();
    ui->labelMode->setText("Mode Line,\ncolor :"+this->ui->comboColorLine->currentText());
}

void MainWindow::modePolygone()
{
    int r = 5;
    try{
        r= ui->lineEditPolygone->text().toInt();
    } catch(exception *e){
        r = 5;
    }
    if(r ==0){
        r = 5;
    }
    this->myGV->setMaxtPoint(r);
    myGV->setPolygonPoint(r);
    this->myGV->setColorPolygone(this->ui->comboColorPolygone->currentText());
    this->myGV->updateModePoly();
    ui->labelMode->setText("Mode Polygone("+QString::number(r)+" cote),\ncolor :"+this->ui->comboColorPolygone->currentText());
}

void MainWindow::applyHomo()
{
    QString forme = ui->comboBox->currentText();
    double hx = 1.5;
    double hy = 1.5;
    try{
        hx= ui->lineEditHx->text().toDouble();
        hy= ui->lineEditHy->text().toDouble();

    } catch(exception *e){
        hx = 1.5;
        hy = 1.5;
    }
    if(hx ==0)
        hx = 0.1;
    if(hy ==0)
        hy = 0.1;

    myGV->applyHomo(forme,hx,hy);

}

void MainWindow::applyRotation()
{
    QString forme = ui->comboBox->currentText();
    double r = 20;
    try{
        r= ui->lineEditRotation->text().toDouble();
    } catch(exception *e){
        r = 20;
    }
    if(r ==0){
        r = 20;
    }
    myGV->applyRotation(forme,r);
}

void MainWindow::applyTranslation()
{

    QString forme = ui->comboBox->currentText();
    double tx = 1.5;
    double ty = 1.5;
    try{
        tx= ui->lineEditTx->text().toDouble();
        ty= ui->lineEditTy->text().toDouble();

    } catch(exception *e){
        tx = 1.5;
        ty = 1.5;
    }
    if(tx ==0)
        tx = 0.1;
    if(ty ==0)
        ty = 0.1;

    myGV->applyTranslation(forme,tx,ty);
}