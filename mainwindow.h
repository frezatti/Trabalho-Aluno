#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "alunocontroler.h"
#include "disciplinacontroler.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

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

    void on_pushButtonSearch_clicked();

    void on_pushButtonIncluirDis_clicked();

    void on_pushButtonConsultarDis_clicked();

    void on_pushButtonRemoverDis_clicked();

    void on_pushButtonAtualizarDis_clicked();

private:
    QString filename;
    AlunoControler* controler;
    DisciplinaControler* controlerDis;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
