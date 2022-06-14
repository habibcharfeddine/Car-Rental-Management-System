#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include"GUI_AssuranceSociete.h"
#include"connexion.h"
#include <QSplashScreen>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    MainWindow v;
    QSplashScreen *splash=new QSplashScreen ;
    splash->setPixmap(QPixmap("C:/Users/QT/Desktop/LocationVoiture/icons/photo.png"));
            splash->show();
           QMessageBox msgBox;
           bool test=c.ouvrirConnexion();

            if(test)
                {
                    QTimer::singleShot(10000,splash,SLOT(close()));
                        QTimer::singleShot(2500,&v,SLOT(show()));
                   // w.show();
                      QPixmap pix("C:/Users/QT/Desktop/LocationVoiture/icons/success.png");

                      msgBox.setText("Database is opened\nConnection Successful.\Click OK to continue.");
                      msgBox.setIconPixmap(pix);
                       msgBox.exec();
                }
            else {
                QMessageBox msgBox;
                                QPixmap pix("C:/Users/QT/Desktop/LocationVoiture/icons/error.png");

                                msgBox.setText("Database could not be opened!\n"
                                               "Click OK to continue.");
                                msgBox.setIconPixmap(pix);
                                 msgBox.exec();}

                return a.exec();

    //w.show();

    return a.exec();
}
