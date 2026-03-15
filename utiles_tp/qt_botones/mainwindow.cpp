#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGridLayout* gl = new QGridLayout();
    ui->centralwidget->setLayout(gl);
    //Cantidad de elementos
    int cant = 10;
    //Cantidad de elementos
    this->b = new QPushButton**[cant];
    for(int i=0 ;i<cant ;++i)
       {
           b[i]=new QPushButton*[cant];
           for( int j=0;j<cant;++j)
           {
               b[i][j]=new QPushButton;
               b[i][j]->setMinimumSize(40,40);
               this->b[i][j]->setText(
                                       QString::number(i) + "-" +
                                       QString::number(j));
               gl->addWidget(b[i][j],i,j);

               QObject::connect(this->b[i][j],
                                            &QPushButton::clicked,
                                            [this, i,j]()->void{ maniButton(i,j);});


               b[i][j]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
           }
       }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::maniButton(int i, int j)
{
    this->b[i][j]->setText("X");
    qDebug() << i << " " << j;
}

