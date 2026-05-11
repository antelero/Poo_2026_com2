#include "ventanaotra.h"
#include "ui_ventanaotra.h"

VentanaOtra::VentanaOtra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaOtra)
{
    ui->setupUi(this);
}

VentanaOtra::~VentanaOtra()
{
    delete ui;
}

QString VentanaOtra::getTexto()
{
    return texto;
}

void VentanaOtra::on_btnEnviar_clicked()
{
    if (ui->lineEdit->text().isEmpty()) {
            QMessageBox::warning(this, "Error", "El campo está vacío.");
            return;
        }

        texto = ui->lineEdit->text(); // Guardamos el texto
        accept(); // Cerramos la ventana con código de aceptación
}

