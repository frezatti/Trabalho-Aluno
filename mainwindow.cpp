#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db->setDatabaseName(filepath);
    controler = new AlunoController(db);
    controlerDis = new DisciplinaControler(db);

    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    QStringList headers{"Matricula","Nome do Aluno"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    std::list<QString>::iterator it;
    std::list<QString> *infoList = controler->info();
    if(infoList->empty())throw QString("you did it wrong you dummie");
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


MainWindow::~MainWindow()
{
    delete ui;
}


void updateTable(AlunoController *controler,Ui::MainWindow* ui){

        ui->tableWidget->clear();
        ui->tableWidget->setColumnCount(2);
        QStringList headers{"Matricula","Nome do Aluno"};
        ui->tableWidget->setHorizontalHeaderLabels(headers);
        std::list<QString>::iterator it;
        std::list<QString> *infoList = controler->info();
        if(infoList->empty())throw QString("you did it wrong you dummie");
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

void updateTabledDis(DisciplinaControler *controler,Ui::MainWindow* ui){

        ui->tableWidgetDis->clear();
        ui->tableWidgetDis->setColumnCount(2);
        QStringList headers{"Codigo","Nome da Disciplina"};
        ui->tableWidgetDis->setHorizontalHeaderLabels(headers);
        std::list<QString>::iterator it;
        std::list<QString> *infoList = controler->info();
        if(infoList->empty())throw QString("you did it wrong you dummie");
        QStringList info;
        for(int j= ui->tableWidgetDis->rowCount();j>=0;j--){
            ui->tableWidgetDis->removeRow(j);
        }
        int i=0;
        for(it = infoList->begin();it!= infoList->end();it++,i++){
            info = it->split(";");
            ui->tableWidgetDis->insertRow(i);
            ui->tableWidgetDis->setItem(i,0,new QTableWidgetItem(info[0]));
            ui->tableWidgetDis->setItem(i,1,new QTableWidgetItem(info[1]));
        }
        ui->tableWidgetDis->verticalHeader()->setVisible(false);
        ui->tableWidgetDis->setColumnWidth(0,200);
        ui->tableWidgetDis->resizeColumnToContents(1);
        delete infoList;
}


void MainWindow::on_pushButtonInserir_clicked()
{
    try {
        QString matricula = ui->lineEditMatAluno->text();
        QString nome = ui->lineEditNome->text();
        if(nome!= ""&& matricula !=""){
            controler->incluir(matricula,nome);
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
        QStringList aluno =  controler->buscar(matricula).split(";");
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
        controler->alterar(matricula,nome);
        //updateTable(controler,ui);
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
        controler->remover(matricula);
        //updateTable(controler,ui);
        ui->lineEditMatAluno->setFocus();

    } catch(QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }
}

/*
void MainWindow::on_pushButtonSearch_clicked()
{
    try {
        // Buscando o arquivo no disco
        //filename = QFileDialog::getOpenFileName(this,"Abrir Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt *.*)");
        //if(filename.isEmpty()) throw QString("Arquivo nao foi selecionado");
        //updateTable(controler,ui);
        ui->tabWidget->show();

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
*/

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
           // updateTable(controlerDis, ui);
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
       // updateTable(controlerDis,ui);
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
           // updateTable(controlerDis,ui);
            ui->lineEditCodigoDis->setFocus();

        } catch (QString &error) {
            QMessageBox::warning(this,"Erro",error);
        }
}

/*
void MainWindow::on_pushButtonIncluirMat_clicked()
{
        try {
            QString matricula = ui->lineEditMatriculaMat->text();
            QString codTurma = ui->lineEditCodTurmaMat->text();
            QString codDisciplina = ui->lineEditSCodDisciplina->text();
            if(matricula!= ""&& codTurma !="" && codDisciplina!=""){
                controlerMat.addMatricula(matricula,codDisciplina,codTurma);
            }else{
                throw QString("Todos os campos devem estar preenchidos para que um Aluno posso ser incluido");
            }
            //updateTable(controler, ui);
        } catch (QString &error) {
            QMessageBox::warning(this,"Erro",error);
        }
}


void MainWindow::on_pushButtonConsultarMat_clicked()
{
        try {
            QString matricula = ui->lineEditMatriculaMat->text();
            if(matricula == "") throw QString("Para fazer um busca e preciso fornecer uma matricula");
            controlerMat.buscarMatricula(matricula);
            QStringList info = matricula.split(";");
            //ui->lineEditCodTurmaMat->setText();
            //ui->lineEditSCodDisciplina->setText()
            ui->lineEditMatriculaMat->setFocus();

        } catch (QString &error) {
            QMessageBox::warning(this,"Erro",error);
        }
}



void MainWindow::on_pushButtonRemoverMat_clicked()
{
        try {
            QString matricula =  ui->lineEditCodigoDis->text();
            QString codTurma = ui->lineEditCodTurmaMat->text();
            QString codDisciplina = ui->lineEditSCodDisciplina->text();
            if(matricula == ""&& codTurma == ""&& codDisciplina=="") throw QString("Preencher matricula, turma e disciplina");
            //controlerDis->atualizarMatricula(matricula,codTurma,codDisciplina);
            // updateTable(controlerDis,ui);
            ui->lineEditCodigoDis->setFocus();

        } catch (QString &error) {
            QMessageBox::warning(this,"Erro",error);
        }
}


void MainWindow::on_pushButtonListarMat_clicked()
{
        try {
            QString matricula =  ui->lineEditMatriculaMat->text();

            if(matricula == "") throw QString("Preencher matricula");
            //controlerDis->atualizarMatricula(matricula);
            // updateTable(controlerDis,ui);
            ui->lineEditCodigoDis->setFocus();

        } catch (QString &error) {
            QMessageBox::warning(this,"Erro",error);
        }
}
void MainWindow::on_pushButtonInserir_2_clicked()
{
    try {
        QString codigo = ui->lineEditCod_Disciplina->text();
        QString nome = ui->lineEditCod_Turma_2->text();
        if(nome!= ""&& codigo !=""){
            controlertur->addTurma(codigo,nome.toInt());
        }else{
            throw QString("Ambos os campos devem estar preenchidos para que uma Disciplina posso ser incluido");
        }
        //updateTable(controlerDis, ui);
        ui->lineEditCod_Disciplina->setFocus();
    } catch (QString &error) {
       QMessageBox::warning(this,"Erro",error);
    }
}



void MainWindow::on_pushButtonAtualizar_2_clicked()
{
    try {
        QString codigo =  ui->lineEditCod_Disciplina->text();
        QString nome = ui->lineEditCod_Turma_2->text();
        if(codigo == ""&& nome == "") throw QString("Preencher codigo e nome");
        //controlerDis->atualizarDisciplina(codigo,nome);
        //updateTable(controlerDis,ui);
        ui->lineEditCod_Disciplina->setFocus();

    } catch (QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }

}


void MainWindow::on_pushButtonConsultar_2_clicked()
{
    try {
        QString codigo = ui->lineEditCod_Disciplina->text();
        if(codigo == "") throw QString("Para fazer um busca e preciso fornecer uma matricula");
        controlertur->buscarTurma(codigo);
       QStringList turma = codigo.split(";");
       ui->lineEditCod_Turma_2->setText(turma[1]);
       ui->lineEditCod_Disciplina->setFocus();

    } catch (QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }

}


void MainWindow::on_pushButtonRemover_2_clicked()
{
    try {
        QString codigo =  ui->lineEditCod_Disciplina->text();
        if(codigo == "") throw QString("Para fazer um busca e preciso fornecer um codigo");
        //controlerDis->removerDisciplina(codigo);
        //updateTable(controlerDis,ui);
        ui->lineEditCod_Turma_2->setFocus();

    } catch(QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }

}

*/

void MainWindow::on_tabWidget_currentChanged(int index)
{
        switch (index) {
        case 0:
            updateTable(controler,ui);
            break;
        default:
            break;
        }
}

