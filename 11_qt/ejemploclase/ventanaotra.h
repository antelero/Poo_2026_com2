#ifndef VENTANAOTRA_H
#define VENTANAOTRA_H

#include <QDialog>
#include <QMessageBox>
namespace Ui {
class VentanaOtra;
}

class VentanaOtra : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaOtra(QWidget *parent = nullptr);
    ~VentanaOtra();
    QString getTexto();

private slots:
    void on_btnEnviar_clicked();

private:
    Ui::VentanaOtra *ui;
    QString texto;
};

#endif // VENTANAOTRA_H
