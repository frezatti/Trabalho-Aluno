#ifndef ALUNOCONTROLLER_H
#define ALUNOCONTROLLER_H

#include <QString>
#include<list>
#include "aluno.h"
#include "alunodao.h"
class AlunoController
{
public:
    AlunoController(QSqlDatabase *db);
    void incluir(QString const &mat, QString const &nom);
    QString buscar(QString const &mat);
    void alterar(QString const &mat, QString const &nom);
    void remover(QString const &mat);
    std::list<QString>* info();
private:
    Aluno* aluno;
    AlunoDAO *dao;
};

#endif // ALUNOCONTROLLER_H
