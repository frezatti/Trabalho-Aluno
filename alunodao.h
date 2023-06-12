#ifndef ALUNODAO_H
#define ALUNODAO_H

#include "dao.h"
#include "aluno.h"
#include <list>
#include <QString>
#include <QStringList>
#include <fstream>
#include <QSqlDatabase>
#include <QSqlQuery>

class AlunoDAO : public DAO<Aluno>
{
public:
    AlunoDAO();
    AlunoDAO(QString filename):filename(filename){}
    void inserir(Aluno* obj);//Create
    Aluno* buscar(QString const &id);//Read
    void alterar(Aluno* obj);//Update
    void deletar(QString const &id);//Delete
    std::list<QString>* listar();//Listar
private:
    QString filename;
    std::list<Aluno*>* lerArquivo();
    void gravarArquivo(std::list<Aluno*>* lista);
    Aluno* buscarArquivo(QString const &id);
    QSqlDatabase db;
    QString nomeBD;
};

#endif // ALUNODAO_H
