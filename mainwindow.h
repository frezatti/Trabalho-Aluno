#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "alunocontroller.h"
#include "disciplinacontroler.h"
#include "matriculacontroler.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <turmacontroler.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButtonInserir_clicked();

    void on_pushButtonConsultar_clicked();

    void on_pushButtonAtualizar_clicked();

    void on_pushButtonRemover_clicked();

    void on_pushButtonIncluirDis_clicked();

    void on_pushButtonConsultarDis_clicked();

    void on_pushButtonRemoverDis_clicked();

    void on_pushButtonAtualizarDis_clicked();
/*
    void on_pushButtonIncluirMat_clicked();

    void on_pushButtonConsultarMat_clicked();

    void on_pushButtonRemoverMat_clicked();

    void on_pushButtonListarMat_clicked();

*/
    void on_tabWidget_currentChanged(int index);

    void on_pushButtonInserirTur_clicked();

    void on_pushButtonConsultarTurma_clicked();

    void on_pushButtonAtualizarTurma_clicked();

private:
    QSqlDatabase *db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    QString filepath = "/Users/adrielfrezatti/Programing/c++/Qt/Trabalho-Aluno/academico.db";
    AlunoController *controler;
    //MatriculaControler controlerMat;
    DisciplinaControler *controlerDis;
    Ui::MainWindow *ui;
    TurmaControler* controlertur;
};
#endif // MAINWINDOW_H
