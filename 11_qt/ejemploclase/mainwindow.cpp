#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&temporizador,SIGNAL(timeout()),this,SLOT(OnTemporizador()));
    connect(ui->btnAbrirVentana, &QPushButton::clicked, this, &MainWindow::abrirVentana2);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString texto = ui->txtUsuario->text();

    if (texto.length()==0)
        QMessageBox::critical(this, "Proceso terminado", "No hay texto para convertir!!! Verifique por favor");
    else
    {
        ui->txtResultado->setText(texto.toUpper());
        if (ui->chkAddList->isChecked())
        {
            ui->Lista->addItem(texto.toUpper());
        }

        // Mostrar una caja de información
        QMessageBox::information(this, "Proceso terminado", "El proceso convirtio el texto de minuscula a mayuscula");
    };
}

void MainWindow::abrirVentana2()
{
    VentanaOtra ventana(this);

    if (ventana.exec() == QDialog::Accepted) {
        QString texto = ventana.getTexto(); // Obtenemos el dato
        ui->lblResultado->setText("Texto recibido: " + texto);
    } else {
        ui->lblResultado->setText("Se canceló la operación.");
    }
}
void MainWindow::on_borrarLista_clicked()
{
    ui->Lista->clear();
}


void MainWindow::on_btnIniciar_clicked()
{
    if (!(ui->btnIniciar->text()=="Parar"))
    {
        ui->btnIniciar->setText("Parar");
        temporizador.start(1000);
    }else{
        ui->btnIniciar->setText("Iniciar");
        temporizador.stop();
    };

}

void MainWindow::OnTemporizador()
{
    ui->spnContador->setValue(ui->spnContador->value()+1);
}

void MainWindow::on_btnAbrirVentana_clicked()
{

}

