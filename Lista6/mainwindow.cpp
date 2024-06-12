

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

///
/// \brief 
/// \param  
///
MainWindow::MainWindow(QWidget *parent)  
    : QMainWindow(parent),               
      ui(new Ui::MainWindow)             
{
    ui->setupUi(this);                            
    QMessageBox::information(this, "Informacja",  
                             "Ten program reaguje na <br/>"                                     
                             "<b>kliknięcia myszka<br/>"  
                             "w oknie programu"
                             );
}

MainWindow::~MainWindow()
{
    delete ui;   
}


void MainWindow::on_action_Zakoncz_triggered()
{
    qApp->quit();  
}
