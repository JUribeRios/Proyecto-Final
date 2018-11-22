#include "trabajo5.h"
#include "ui_trabajo5.h"

Trabajo5::Trabajo5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Trabajo5)
{
    ui->setupUi(this);

    srand(time(NULL));
    timer=new QTimer(this);
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,ANCHO,ALTO);

    ui->graphicsView->setScene(scene);

    scene->addRect(scene->sceneRect());

    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100,ui->graphicsView->height()+100);

    part = new Particula(100,100,20);

    scene->addItem(part);

    part->mover(ALTO);

    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar_escena()));
}

Trabajo5::~Trabajo5()
{
    delete ui;
    delete part;
    delete timer;
    delete scene;
}

void Trabajo5::on_pushButton_clicked()
{
    int resultado;

    M_parabolico objeto(this);
    objeto.setWindowTitle("Movimiento parabolico");
    resultado=objeto.exec();

    if (resultado==QDialog::Rejected)
        return;

    Almacenar objeto2;

    objeto2.setVel(objeto.getVel_Inic(),objeto.getVel_Inic());
    objeto2.setPosx(objeto.getPos_InicX());
    objeto2.setPosy(objeto.getPos_InicY());
    objeto2.setAng(objeto.getAngulo());
    objeto2.setRad(objeto.getRadio());


    datos.insert(datos.begin(),objeto2);

    int pox=datos.at(0).getPosx();
    int poy=datos.at(0).getPosy();
    int ra=datos.at(0).getRad();
    int  a=datos.at(0).getAng();
    int vx=datos.at(0).getVelx();
    int vy=datos.at(0).getVely();

     part->setposicion(pox, poy);
     part->setradio(ra);
     part->setangulo(a);
     part->setvelocidad(vx,vy);


     part->mover(ALTO);

     timer->start(20);
}

void Trabajo5::actualizar_escena()
{
    part->mover(ALTO);
    part->colision(ANCHO,ALTO);
}

void Trabajo5::on_pushButton_4_clicked()
{
    int resultado;

    M_parabolico objeto(this);
    objeto.setWindowTitle("Rebotes");
    resultado=objeto.exec();

    if (resultado==QDialog::Rejected)
        return;

    Almacenar objeto2;

    objeto2.setVel(objeto.getVel_Inic(),objeto.getVel_Inic());
    objeto2.setPosx(objeto.getPos_InicX());
    objeto2.setPosy(objeto.getPos_InicY());
    objeto2.setAng(objeto.getAngulo());
    objeto2.setRad(objeto.getRadio());

    datos.insert(datos.begin(),objeto2);

    int pox=datos.at(0).getPosx();
    int poy=datos.at(0).getPosy();
    int ra=datos.at(0).getRad();
    int  a=datos.at(0).getAng();
    int vx=datos.at(0).getVelx();
    int vy=datos.at(0).getVely();

    part->setposicion(pox, poy);
    part->setradio(ra);
    part->setangulo(a);
    part->setvelocidad(vx,vy);


    part->mover(ALTO);
    part->colision(ANCHO,ALTO);
    timer->start(20);
}
