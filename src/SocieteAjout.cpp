#include "SocieteAjout.h"
#include "ui_SocieteAjout.h"
#include "Societe.h"
#include "SocieteGestion.h"
#include <QMessageBox>
#include<QtWidgets>
#include <ui_SocieteMail.h>
AjouterSociete::AjouterSociete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjouterSociete)
{
    ui->setupUi(this);
}

AjouterSociete::~AjouterSociete()
{
    delete ui;
}

void AjouterSociete::on_Valider_clicked()
{
    QMessageBox msgBox;
    QRegExp regex1 ("[a-z]$");
    QRegExp regex2 ("^[a-z]");
    QRegExp regex3 ("^[0-9]*$");

    QString msg_nom ="nom  invalide";
    QString msg_telephone ="telephone invalide";
    QString msg_email ="email invalide";
    QString msg_vide="";

    QString nom= ui->nom->text();
    QString telephone= ui->telephone->text();
    QString email= ui->email->text();


    QString id=nom+"-"+telephone.rightJustified(4, '.', true);


    societe e(id,nom,telephone,email);


    if ((!nom.contains(regex1))||(!nom.contains(regex2)))
    {
        ui->nom->setStyleSheet("QLineEdit { color: red;}");
        ui->text_nom->setText(msg_nom);
        ui->text_nom->setStyleSheet("QLabel { background-color : transparent; color : red; }");
        e.setValide();
    }
    else { ui->nom->setStyleSheet("QLineEdit { color: black;}");
        ui->text_nom->setText(msg_vide);

    }
    if ((!email.contains('@')))
    {
        ui->email->setStyleSheet("QLineEdit { color: red;}");
        ui->text_email->setText(msg_email);
        ui->text_email->setStyleSheet("QLabel { background-color : transparent; color : red; }");
        e.setValide();
    }
    else { ui->email->setStyleSheet("QLineEdit { color: black;}");
        ui->text_email->setText(msg_vide);

    }

    if ((telephone.contains(regex1)) || (telephone.size()!=8))
    {
        ui->telephone->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_telephone->setText(msg_telephone);
        ui->text_telephone->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->telephone->setStyleSheet("QLineEdit { color: black;}");
        ui->text_telephone->setText(msg_vide);
    }


    if (e.getValide()==0)
    {
        if (e.ajouter())
        {

            ui->nom->setStyleSheet("QLineEdit { color: green;}");
            ui->telephone->setStyleSheet("QLineEdit { color: green;}");
            ui->email->setStyleSheet("QLineEdit { color: green;}");
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
             notifyIcon->show();
             notifyIcon->setIcon(QIcon("icone.png"));
             notifyIcon->showMessage("GESTION SOCIETE ","Societe ajouté",QSystemTrayIcon::Information,15000);
            {QPixmap pix("C:/Users/QT/Desktop/LocationVoiture/icons/success.png");

                 msgBox.setText("Societé ajouté avec succes !\n"
                                "Cliquez OK pour continuer.");
                 msgBox.setIconPixmap(pix);
                  msgBox.exec();}
        }

    }

    else
    {QMessageBox msgBox;
        QPixmap pix("C:/Users/QT/Desktop/LocationVoiture/icons/error.png");

        msgBox.setText("Erreur d'ajout de la societé!\n"
                       "Cliquez OK pour continuer.");
        msgBox.setIconPixmap(pix);
         msgBox.exec();}

}

void AjouterSociete::on_Annuler_clicked()
{
    AFFICHAGE_SOCIETE *w = new AFFICHAGE_SOCIETE;
    hide();
    w->show();

}
