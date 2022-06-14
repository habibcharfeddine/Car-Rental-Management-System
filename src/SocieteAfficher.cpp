#include "SocieteAfficher.h"
#include "ui_SocieteAfficher.h"
#include "Societe.h"
#include "SocieteGestion.h"
#include "SocieteAjout.h"
#include "SocieteMail.h"
#include<QDebug>
#include <QMessageBox>
AFFICHAGE_SOCIETE::AFFICHAGE_SOCIETE(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AFFICHAGE_SOCIETE)
{
    ui->setupUi(this);
    societe e ;
    e.affichage(ui);
}

AFFICHAGE_SOCIETE::~AFFICHAGE_SOCIETE()
{
    delete ui;
}

void AFFICHAGE_SOCIETE::on_annuler_clicked()
{
    Gestion_Societe *w = new Gestion_Societe;
    hide();
    w->show();
}
void AFFICHAGE_SOCIETE::on_ajouter_clicked()
{
    AjouterSociete *w = new AjouterSociete;
    hide();
    w->show();
}
void AFFICHAGE_SOCIETE::on_supprimer_clicked()
{
    societe e;
    e.Supprimer(ui);
    e.affichage(ui);
}

void AFFICHAGE_SOCIETE::on_comboBox_currentIndexChanged(int index)
{
    societe e;
    if (index==0)
    { e.Tri_NOM(ui);

    }

    else
    {  e.Tri_REF(ui);

    }
}

void AFFICHAGE_SOCIETE::on_search_clicked()
{
    societe e;
    e.Recherche(ui);
}

void AFFICHAGE_SOCIETE::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->nom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());
    ui->telephone->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString());
    ui->email->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
    ui->reference->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->stackedWidget->setCurrentIndex(1);

}

void AFFICHAGE_SOCIETE::on_Annuler_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void AFFICHAGE_SOCIETE::on_Valider_clicked()
{
    societe e;

    if(e.modifier(ui))
    {
        QMessageBox msgBox;
                        QPixmap pix("C:/Users/QT/Desktop/LocationVoiture/icons/success.png");

                        msgBox.setText("Societ� modifi� avec succes !\n"
                                       "Cliquez OK pour continuer.");
                        msgBox.setIconPixmap(pix);
                         msgBox.exec();;
        ui->stackedWidget->setCurrentIndex(0);
        e.affichage(ui);
    }
    else
    { QMessageBox msgBox;
        QPixmap pix("C:/Users/QT/Desktop/LocationVoiture/icons/error.png");

        msgBox.setText("Erreur de modification de la societ�!\n"
                       "Cliquez OK pour continuer.");
        msgBox.setIconPixmap(pix);
         msgBox.exec();}
}

void AFFICHAGE_SOCIETE::on_mail_clicked()
{
    SocieteMail *w = new SocieteMail;
    hide();
    w->show();
}
