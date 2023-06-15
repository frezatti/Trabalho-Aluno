#ifndef ALUNODAO_H
#define ALUNODAO_H

#include "aluno.h"
#include <QString>
#include<list>
#include <string>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
class AlunoDAO
{
public:
    AlunoDAO(QSqlDatabase *db);
    void incluir(Aluno* obj);
    Aluno* buscar(Aluno* obj);
    void alterar(Aluno* obj);
    Aluno* remover(Aluno* obj);
    std::list<QString> *info();
private:
    QSqlDatabase *db;
};

#endif // ALUNODAO_H
