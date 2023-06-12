#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
        for(int j= ui->tableWidget->rowCount();j>=0;j--){
            ui->tableWidget->removeRow(j);
        }
        int i=0;
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
        QString matricula = ui->lineEditMatAluno->text();
        QString nome = ui->lineEditNome->text();
        if(nome!= ""&& matricula !=""){
            controler->addAluno(matricula,nome);
        }else{
            throw QString("Ambos os campos devem estar preenchidos para que um Aluno posso ser incluido");
        }
        updateTable(controler, ui);
        ui->lineEditMatAluno->setFocus();
    } catch (QString &error) {
       QMessageBox::warning(this,"Erro",error);
    }
}


void MainWindow::on_pushButtonConsultar_clicked()
{
    try {
        QString matricula = ui->lineEditMatAluno->text();
        if(matricula == "") throw QString("Para fazer um busca e preciso fornecer uma matricula");
        controler->buscarAluno(matricula);
       QStringList aluno = matricula.split(";");
       ui->lineEditNome->setText(aluno[1]);
       ui->lineEditMatAluno->setFocus();

    } catch (QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }
}


void MainWindow::on_pushButtonAtualizar_clicked()
{
    try {
        QString matricula =  ui->lineEditMatAluno->text();
        QString nome = ui->lineEditNome->text();;
        if(matricula == ""&& nome == "") throw QString("Preencher matricula e nome");
        controler->atualiazarAluno(matricula,nome);
        updateTable(controler,ui);
        ui->lineEditMatAluno->setFocus();

    } catch (QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }
}




void MainWindow::on_pushButtonRemover_clicked()
{
    try {
        QString matricula =  ui->lineEditMatAluno->text();
        if(matricula == "") throw QString("Para fazer um busca e preciso fornecer uma matricula");
        controler->deleteAluno(matricula);
        updateTable(controler,ui);
        ui->lineEditMatAluno->setFocus();

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
        controler = new AlunoControler(filename);
        updateTable(controler,ui);
        ui->tabWidget->show();

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}


void MainWindow::on_pushButtonIncluirDis_clicked()
{
        try {
            QString codigo = ui->lineEditCodigoDis->text();
            QString nome = ui->lineEditNomeDis->text();
            if(nome!= ""&& codigo !=""){
                controlerDis->addDisciplina(codigo,nome);
            }else{
                throw QString("Ambos os campos devem estar preenchidos para que uma Disciplina posso ser incluido");
            }
            //updateTable(controlerDis, ui);
            ui->lineEditCodigoDis->setFocus();
        } catch (QString &error) {
           QMessageBox::warning(this,"Erro",error);
        }
    }


void MainWindow::on_pushButtonConsultarDis_clicked()
{
    try {
        QString codigo = ui->lineEditCodigoDis->text();
        if(codigo == "") throw QString("Para fazer um busca e preciso fornecer uma matricula");
        controlerDis->buscarDisciplina(codigo);
       QStringList disciplina = codigo.split(";");
       ui->lineEditNomeDis->setText(disciplina[1]);
       ui->lineEditCodigoDis->setFocus();

    } catch (QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }
}


void MainWindow::on_pushButtonRemoverDis_clicked()

{
    try {
        QString codigo =  ui->lineEditCodigoDis->text();
        if(codigo == "") throw QString("Para fazer um busca e preciso fornecer um codigo");
        //controlerDis->removerDisciplina(codigo);
        //updateTable(controlerDis,ui);
        ui->lineEditMatAluno->setFocus();

    } catch(QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }
}


void MainWindow::on_pushButtonAtualizarDis_clicked()
{
        try {
            QString codigo =  ui->lineEditCodigoDis->text();
            QString nome = ui->lineEditNomeDis->text();;
            if(codigo == ""&& nome == "") throw QString("Preencher codigo e nome");
            //controlerDis->atualizarDisciplina(codigo,nome);
            //updateTable(controlerDis,ui);
            ui->lineEditCodigoDis->setFocus();

        } catch (QString &error) {
            QMessageBox::warning(this,"Erro",error);
        }
}

