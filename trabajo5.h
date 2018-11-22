#ifndef TRABAJO5_H
#define TRABAJO5_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include "particula.h"
#include <vector>
#include "almacenar.h"
#include "m_parabolico.h"
#define ANCHO 1000
#define ALTO 500


#include <QMainWindow>

namespace Ui {
class Trabajo5;
}

class Trabajo5 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Trabajo5(QWidget *parent = nullptr);
    ~Trabajo5();


    vector<Almacenar>datos;

private slots:
    void on_pushButton_clicked();
    void actualizar_escena();

    void on_pushButton_4_clicked();

private:
    Ui::Trabajo5 *ui;
    QTimer *timer =nullptr;
    QGraphicsScene *scene = nullptr;
    Particula *part = nullptr;

};

#endif // TRABAJO5_H
