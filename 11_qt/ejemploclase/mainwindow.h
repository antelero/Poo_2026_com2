#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "ventanaotra.h" // Importar ventana secundaria


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void OnTemporizador();
    void abrirVentana2();

private slots:
    void on_pushButton_clicked();
    void on_borrarLista_clicked();
    void on_btnIniciar_clicked();
    void on_btnAbrirVentana_clicked();

private:
    Ui::MainWindow *ui;
    QTimer temporizador;
};
#endif // MAINWINDOW_H
