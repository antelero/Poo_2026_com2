#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customtablemodel.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->agenda = new Agenda();
    //this->agenda->generarDatosDeEjemplo();
    this->agenda->leer();
    ui->setupUi(this);
    this->refrescar();
}

MainWindow::~MainWindow()
{
    delete agenda;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::string nombre = this->ui->lineEdit->text().toStdString();
    std::string dir = this->ui->lineEdit_2->text().toStdString();
    Persona p(nombre.c_str());
    p.setDir(dir.c_str());
    agenda->save(p);
    this->refrescar();
}

void MainWindow::refrescar()
{
    auto personas = agenda->getPersonas();
    this->refrescar(personas);
}

void MainWindow::refrescar(std::vector<Persona> personas)
{
    this->personas = personas;
    this->ui->tableWidget->clear();
    this->ui->tableWidget->setRowCount(personas.size());
    QStringList headers;
    headers << "Nombre" << "Dirrección";
    this->ui->tableWidget->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < personas.size(); i++) {
        QTableWidgetItem * cellNombre=
                new QTableWidgetItem(QString(personas[i].getNombre()));
        this->ui->tableWidget->setItem(i, 0, cellNombre);

        QTableWidgetItem * cellDir=
                new QTableWidgetItem(QString(personas[i].getDir()));
        this->ui->tableWidget->setItem(i, 1, cellDir);
    }

    if (personas.size() > 0) {
        auto contactos = personas[0].getContactos();
        this->ui->tableWidget_2->clear();
        this->ui->tableWidget_2->setRowCount(contactos.size());
        QStringList headers;
        headers << "Tipo" << "Valor";
        this->ui->tableWidget_2->setHorizontalHeaderLabels(headers);
        for(int j= 0; j < contactos.size(); j++) {
            QTableWidgetItem * celltipo=
                    new QTableWidgetItem(QString::fromStdString(contactos[j].getTipo()));
            this->ui->tableWidget_2->setItem(j, 0, celltipo);

            QTableWidgetItem * cellValor=
                    new QTableWidgetItem(QString::fromStdString(contactos[j].getValor()));
            this->ui->tableWidget_2->setItem(j, 1, cellValor);
        }
        this->ui->tableWidget->selectRow(0);
    }

}


void MainWindow::on_pushButton_3_clicked()
{
    this->ui->lineEdit_3->clear();
    this->refrescar();
}


void MainWindow::on_pushButton_2_clicked()
{
    std::string nombre = this->ui->lineEdit_3->text().toStdString();
    auto personas = agenda->filtrar((char*)nombre.c_str());
    this->refrescar(personas);
}


void MainWindow::on_tableWidget_itemSelectionChanged()
{


    }



void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    if (row < 0 || row >= (int)this->personas.size()) return;
    int selectRow = row;
    auto personas = this->personas;
        auto contactos = personas[selectRow].getContactos();
        this->ui->tableWidget_2->clear();
        this->ui->tableWidget_2->setRowCount(contactos.size());
        QStringList headers;
        headers << "Tipo" << "Valor";
        this->ui->tableWidget_2->setHorizontalHeaderLabels(headers);
        for(int j= 0; j < contactos.size(); j++) {
            QTableWidgetItem * celltipo=
                    new QTableWidgetItem(QString::fromStdString(contactos[j].getTipo()));
            this->ui->tableWidget_2->setItem(j, 0, celltipo);

            QTableWidgetItem * cellValor=
                    new QTableWidgetItem(QString::fromStdString(contactos[j].getValor()));
            this->ui->tableWidget_2->setItem(j, 1, cellValor);
        }
}







void MainWindow::on_pushButton_contacto_clicked()
{
    // 1. Validar que haya una fila seleccionada en la tabla de personas
    int filaSeleccionada = ui->tableWidget->currentRow(); // O la lista/tabla que uses
    if (filaSeleccionada < 0) {
        QMessageBox::warning(this, "Atención", "Por favor, selecciona una persona de la lista primero.");
        return;
    }

    // 2. Obtener los valores de los lineEdit de contacto
    QString tipoContacto = ui->lineEdit_contacto->text().trimmed();
    QString valorContacto = ui->lineEdit_valor->text().trimmed();

    if (tipoContacto.isEmpty() || valorContacto.isEmpty()) {
        QMessageBox::warning(this, "Atención", "Debes completar el tipo de contacto y su valor.");
        return;
    }

    // 3. El id sale de la persona seleccionada (this->personas es lo que muestra la tabla)
    if (filaSeleccionada >= (int)this->personas.size()) return;
    int idPersona = this->personas[filaSeleccionada].getId();

    // 4. Agregar (y guardar) el contacto
    if (!agenda->agregarContactoAPersona(idPersona,
                                         tipoContacto.toStdString(),
                                         valorContacto.toStdString())) {
        QMessageBox::warning(this, "Error", "No se pudo guardar el contacto.");
        return;
    }

    // 5. Limpiar campos y refrescar manteniendo la persona seleccionada
    ui->lineEdit_contacto->clear();
    ui->lineEdit_valor->clear();
    this->refrescar();
    ui->tableWidget->selectRow(filaSeleccionada);
    this->on_tableWidget_cellClicked(filaSeleccionada, 0);
}

