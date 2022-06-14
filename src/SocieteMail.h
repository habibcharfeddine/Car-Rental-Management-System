#ifndef SocieteMail_H
#define SocieteMail_H
#include "Assurance.h"
#include <QWidget>

namespace Ui {
class SocieteMail;
}

class SocieteMail : public QWidget
{
    Q_OBJECT

public:
    explicit SocieteMail(QWidget *parent = 0);
    ~SocieteMail();

private slots:
    void on_Annuler_clicked();

    void on_Valider_clicked();

private:
    Ui::SocieteMail *ui;
};

#endif // SocieteMail_H
