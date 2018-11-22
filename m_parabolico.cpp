#include "m_parabolico.h"
#include "ui_m_parabolico.h"

M_parabolico::M_parabolico(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::M_parabolico)
{
    ui->setupUi(this);
}

M_parabolico::~M_parabolico()
{
    delete ui;
}

void M_parabolico::on_buttonBox_accepted()
{
    accept();
}

void M_parabolico::on_buttonBox_rejected()
{
    reject();
}

int M_parabolico::getPos_InicX()
{
    return ui->spinBox->value();
}

int M_parabolico::getPos_InicY()
{
    return ui->spinBox_2->value();
}

int M_parabolico::getVel_Inic()
{
    return ui->spinBox_4->value();
}

int M_parabolico::getAngulo()
{
    return ui->spinBox_3->value();
}

int M_parabolico::getRadio()
{
    return ui->spinBox_5->value();
}
