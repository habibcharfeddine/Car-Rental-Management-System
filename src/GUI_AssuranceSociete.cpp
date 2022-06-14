#include "GUI_AssuranceSociete.h"
#include "ui_GUI_AssuranceSociete.h"
#include "AssuranceGestion.h"
#include "SocieteGestion.h"
#include "mainwindow.h"
GUI_AssuranceSociete::GUI_AssuranceSociete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUI_AssuranceSociete)
{
    ui->setupUi(this);

    animation = new QPropertyAnimation(ui->assurance, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(-170,130,171,171));
    animation->setEndValue(QRect(200,130,171,161));
    animation->start();

    animation = new QPropertyAnimation(ui->label_2, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(-150,300,141,51));
    animation->setEndValue(QRect(220,300,141,51));
    animation->start();

    animation = new QPropertyAnimation(ui->societe, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(840,130,171,171));
    animation->setEndValue(QRect(460,130,171,161));
    animation->start();

    animation = new QPropertyAnimation(ui->label_3, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(870,300,141,51));
    animation->setEndValue(QRect(500,300,141,51));
    animation->start();
}

GUI_AssuranceSociete::~GUI_AssuranceSociete()
{
    delete ui;
}

void GUI_AssuranceSociete::on_societe_clicked()
{

    Gestion_Societe *w = new Gestion_Societe;
    hide();
    w->show();
}



void GUI_AssuranceSociete::on_assurance_clicked()
{

    Gestion_Assurance *w = new Gestion_Assurance;
    hide();
    w->show();
}

void GUI_AssuranceSociete::on_pushButton_clicked()
{
   acceuil *w = new acceuil;
   hide();
   w->show();
}
