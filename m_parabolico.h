#ifndef M_PARABOLICO_H
#define M_PARABOLICO_H

#include <QDialog>

namespace Ui {
class M_parabolico;
}

class M_parabolico : public QDialog
{
    Q_OBJECT

public:
    explicit M_parabolico(QWidget *parent = nullptr);
    ~M_parabolico();

    int getPos_InicX();
    int getPos_InicY();
    int getVel_Inic();
    int getAngulo();
    int getRadio();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::M_parabolico *ui;
};

#endif // M_PARABOLICO_H
