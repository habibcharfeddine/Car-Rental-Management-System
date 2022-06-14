#include "SocieteMail.h"
#include "ui_SocieteMail.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QPainter>
#include<QPdfWriter>
#include<QtWidgets>
#include<QNetworkConfiguration>
#include<QNetworkAddressEntry>
#include"stmp.h"
#include <src/SmtpMime>
SocieteMail::SocieteMail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SocieteMail)
{
    ui->setupUi(this);


}

SocieteMail::~SocieteMail()
{
    delete ui;
}

void SocieteMail::on_Annuler_clicked()
{
    AFFICHAGE_SOCIETE *w = new AFFICHAGE_SOCIETE;
    hide();
    w->show();
}

void SocieteMail::on_Valider_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
            smtp.setUser("habib.charfeddine@esprit.tn");
            smtp.setPassword("13021999habibch");
            MimeMessage message;
            message.setSender(new EmailAddress("habib.charfeddine@esprit.tn", "Charfeddine habib"));
            QString email =ui->email->text();
            message.addRecipient(new EmailAddress(email, "Cherif sourour"));
            message.setSubject("voiture");
            MimeText text;
            QString emaill = ui->body->toPlainText();
            text.setText(emaill);
            message.addPart(&text);
            smtp.connectToHost();
            smtp.login();
            if(smtp.sendMail(message))
            {
                QMessageBox msgBox;
                        QPixmap pix("C:/Users/QT/Desktop/LocationVoiture/icons/success.png");

                        msgBox.setText("Mail envoyé avec succes!\n"
                                       "Cliquez OK pour continuer.");
                        msgBox.setIconPixmap(pix);
                         msgBox.exec();
            }
            else
            {
                QMessageBox msgBox;
                        QPixmap pix("C:/Users/QT/Desktop/LocationVoiture/icons/error.png");

                        msgBox.setText("Erreur, mail n'est pas envoyé!\n"
                                       "Cliquez OK pour continuer.");
                        msgBox.setIconPixmap(pix);
                         msgBox.exec();
            }
            smtp.quit();


}
