#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->hide();
}


MainWindow::~MainWindow()
{
    delete ui;
}



void updateTable(AlunoControler *controler,Ui::MainWindow* ui){

        ui->tableWidget->clear();
        ui->tableWidget->setColumnCount(2);
        QStringList headers{"Matricula","Nome do Aluno"};
        ui->tableWidget->setHorizontalHeaderLabels(headers);
        std::list<QString>::iterator it;
        std::list<QString> *infoList = controler->infoAluno();
        QStringList info;

        int i=0;
        for(int j=ui->tableWidget->rowCount();j>=0;j--){
            ui->tableWidget->removeRow(j);
        }
        for(it = infoList->begin();it!= infoList->end();it++,i++){
            info = it->split(";");
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(info[0]));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(info[1]));
        }
        ui->tableWidget->verticalHeader()->setVisible(false);
        ui->tableWidget->setColumnWidth(0,200);
        ui->tableWidget->resizeColumnToContents(1);
        delete infoList;
}


void MainWindow::on_pushButtonInserir_clicked()
{
    try {
        QString matricula = ui->lineEditMat->text();
        QString nome = ui->lineEditNome->text();
        if(nome!= ""&& matricula !=""){
            controler->addAluno(matricula,nome);
        }else{
            throw QString("Ambos os campos devem estar preenchidos para que um Aluno posso ser incluido");
        }
        updateTable(controler, ui);
    } catch (QString &error) {
       QMessageBox::warning(this,"Erro",error);
    }
}


void MainWindow::on_pushButtonConsultar_clicked()
{
    try {
        QString matricula = ui->lineEditMat->text();
        if(matricula == "") throw QString("Para fazer um busca e preciso fornecer uma matricula");
        controler->buscarAluno(matricula);
       QStringList aluno = matricula.split(";");
       ui->lineEditNome->setText(aluno[1]);
    } catch (QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }
}


void MainWindow::on_pushButtonAtualizar_clicked()
{
    try {
        QString matricula =  ui->lineEditMat->text();
        QString nome = ui->lineEditNome->text();;
        if(matricula == ""&& nome == "") throw QString("Preencher matricula e nome");
        controler->atualiazarAluno(matricula,nome);
        updateTable(controler,ui);
    } catch (QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }
}




void MainWindow::on_pushButtonRemover_clicked()
{
    try {
        QString matricula =  ui->lineEditMat->text();
        if(matricula == "") throw QString("Para fazer um busca e preciso fornecer uma matricula");
        controler->deleteAluno(matricula);
        updateTable(controler,ui);
    } catch(QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }
}


void MainWindow::on_pushButtonSearch_clicked()
{
    try {
        // Buscando o arquivo no disco
        filename = QFileDialog::getOpenFileName(this,"Abrir Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt *.*)");
        if(filename.isEmpty()) throw QString("Arquivo nao foi selecionado");
        ui->lineEditSearch->setText(filename);
        controler = new AlunoControler(filename);
        updateTable(controler,ui);
        ui->tabWidget->show();
        ui->pushButtonSearch->hide();
        ui->lineEditSearch->hide();
        ui->labelSearch->hide();

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }

}

