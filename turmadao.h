#ifndef TURMADAO_H
#define TURMADAO_H

#include "turma.h"
#include <list>
#include <QString>
#include <QStringList>
#include <fstream>
#include <QSqlDatabase>
#include <QSqlQuery>


class TurmaDao
{
public:
    TurmaDao(QSqlDatabase *db);

    void inserir(Turma* obj);  // Create
    Turma* buscar(Turma* id);  // Read
    void alterar(Turma* obj);  // Update
    void deletar(QString const& id);  // Delete
    std::list<QString>* info();

private:
    QSqlDatabase *db;
};

#endif // TURMADAO_H
