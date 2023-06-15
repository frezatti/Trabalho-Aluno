#ifndef DISCIPLINADAO_H
#define DISCIPLINADAO_H

#include "disciplina.h"
#include <list>
#include <QString>
#include <QStringList>
#include <fstream>
#include <QSqlDatabase>
#include <QSqlQuery>

class DisciplinaDAO
{
public:
    DisciplinaDAO(QSqlDatabase *db);
    void inserir(Disciplina* obj);  // Create
    Disciplina* buscar(Disciplina *obj);  // Read
    void alterar(Disciplina* obj);  // Update
    void deletar(QString const& id);  // Delete
    std::list<QString>* info();  // Listar

private:
    QSqlDatabase *db;
};

#endif // DISCIPLINADAO_H
