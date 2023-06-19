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
    controlertur = new TurmaControler(db);

    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    QStringList headers{"Matricula","Nome do Aluno"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    std::list<QString>::iterator it;
    std::list<QString> *infoList = controler->info();

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
    ui->tableWidget->setColumnWidth(0,249);
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
        ui->tableWidget->setColumnWidth(0,249);
        ui->tableWidget->setColumnWidth(1,250);

        delete infoList;
}

void updateTableDis(DisciplinaControler *controler,Ui::MainWindow* ui){

        ui->tableWidgetDis->clear();
        ui->tableWidgetDis->setColumnCount(2);
        QStringList headers{"Codigo","Nome da Disciplina"};
        ui->tableWidgetDis->setHorizontalHeaderLabels(headers);
        std::list<QString>::iterator it;
        std::list<QString> *infoList = controler->info();

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
        ui->tableWidgetDis->setColumnWidth(0,249);
        ui->tableWidgetDis->setColumnWidth(1,250);

        delete infoList;
}

void updateTableTur(TurmaControler *controler,Ui::MainWindow* ui){

        ui->tableWidgetTur->clear();
        ui->tableWidgetTur->setColumnCount(3);
        QStringList headers{"Codigo Turma ","Codigo Disciplina","SubTurma"};
        ui->tableWidgetTur->setHorizontalHeaderLabels(headers);
        std::list<QString>::iterator it;
        std::list<QString> *infoList = controler->info();
        if(infoList->empty())throw QString("you did it wrong you dummie");
        QStringList info;
        for(int j= ui->tableWidgetTur->rowCount();j>=0;j--){
            ui->tableWidgetTur->removeRow(j);
        }
        int i=0;

        for(it = infoList->begin();it!= infoList->end();it++,i++){
            info = it->split(";");
            ui->tableWidgetTur->insertRow(i);
            ui->tableWidgetTur->setItem(i,0,new QTableWidgetItem(info[0]));
            ui->tableWidgetTur->setItem(i,1,new QTableWidgetItem(info[1]));
            ui->tableWidgetTur->setItem(i,2,new QTableWidgetItem(info[2]));
        }
        ui->tableWidgetTur->verticalHeader()->setVisible(false);
        ui->tableWidgetTur->setColumnWidth(0,166);
        ui->tableWidgetTur->setColumnWidth(1,166);
        ui->tableWidgetTur->setColumnWidth(2,167);
        delete infoList;
}
/*void updateTableMat(MatriculaControler *controler,Ui::MainWindow* ui){

        ui->tableWidgetMat->clear();
        ui->tableWidgetMat->setColumnCount(4);
        QStringList headers{"Matricula","Nome","Turma","Disciplina"};
        ui->tableWidgetMat->setHorizontalHeaderLabels(headers);
        std::list<QString>::iterator it;
        std::list<QString> *infoList = controler->info();
        if(infoList->empty())throw QString("you did it wrong you dummie");
        QStringList info;
        for(int j= ui->tableWidgetMat->rowCount();j>=0;j--){
            ui->tableWidgetMat->removeRow(j);
        }
        int i=0;

        for(it = infoList->begin();it!= infoList->end();it++,i++){
            info = it->split(";");
            ui->tableWidgetMat->insertRow(i);
            ui->tableWidgetMat->setItem(i,0,new QTableWidgetItem(info[0]));
            ui->tableWidgetMat->setItem(i,1,new QTableWidgetItem(info[1]));
            ui->tableWidgetMat->setItem(i,2,new QTableWidgetItem(info[2]));
            ui->tableWidgetMat->setItem(i,3,new QTableWidgetItem(info[2]));
        }
        ui->tableWidgetMat->verticalHeader()->setVisible(false);
        ui->tableWidgetMat->setColumnWidth(0,150);
        ui->tableWidgetMat->setColumnWidth(1,150);
        ui->tableWidgetMat->setColumnWidth(2,150);
        ui->tableWidgetMat->setColumnWidth(3,150);
        delete infoList;
}*/
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
            updateTableDis(controlerDis, ui);
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
       QStringList disciplina =controlerDis->buscarDisciplina(codigo).split(";");
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
        controlerDis->removerDisciplina(codigo);
        updateTableDis(controlerDis,ui);
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
            controlerDis->atualizarDisciplina(codigo,nome);
            updateTableDis(controlerDis,ui);
            ui->lineEditCodigoDis->setFocus();
        } catch (QString &error) {
            QMessageBox::warning(this,"Erro",error);
        }
}


/*void MainWindow::on_pushButtonIncluirMat_clicked()
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
}*/

/*
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

*/

void MainWindow::on_tabWidget_currentChanged(int index)
{
    try {
        switch (index) {
        case 0:
            updateTable(controler,ui);
            break;
        case 1:
            updateTableDis(controlerDis,ui);
            break;
        case 2:
            break;
        case 3:
            updateTableTur(controlertur,ui);
            break;
        default:
            break;
        }
    } catch(QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }
}


void MainWindow::on_pushButtonInserirTur_clicked()
{

    try {
        QString codigoDis =  ui->lineEditCod_Disciplina->text();
        QString codigotur = ui->lineEditCod_Turma->text();
        if(codigotur == "") throw QString("Para fazer um busca e preciso fornecer uma turma");
        controlertur->addTurma(codigotur,codigoDis,ui->lineEditCod_SubTurma->text().toInt());
        updateTableTur(controlertur,ui);
        ui->lineEditCod_Disciplina->setFocus();

    } catch(QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }
}


void MainWindow::on_pushButtonConsultarTurma_clicked()
{
    try {
        QString turma = ui->lineEditCod_Turma->text();
        if(turma == "") throw QString("Para fazer um busca e preciso fornecer uma turma");
        QStringList turmalist =  controlertur->buscar(turma).split(";");
        ui->lineEditCod_Disciplina->setText(turmalist[1]);
        ui->lineEditCod_SubTurma->setText(turmalist[2]);
        ui->lineEditCod_Turma->setFocus();

    } catch (QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }
}


void MainWindow::on_pushButtonAtualizarTurma_clicked()
{
    try {
        QString codturma =  ui->lineEditCod_Turma->text();
        QString coddisciplina = ui->lineEditCod_Disciplina->text();
        if(codturma == ""&& coddisciplina == "") throw QString("Preencher codigo e nome");
        controlertur->atualizarTurma(codturma,coddisciplina,ui->lineEditCod_SubTurma->text().toInt());
        updateTableTur(controlertur,ui);
        ui->lineEditCod_Turma->setFocus();
    } catch (QString &error) {
        QMessageBox::warning(this,"Erro",error);
    }
}

