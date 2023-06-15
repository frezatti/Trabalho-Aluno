#ifndef DISCIPLINADAO_H
#define DISCIPLINADAO_H

#include "disciplina.h"
#include "dao.h"
#include <list>
#include <QString>
#include <QStringList>
#include <fstream>
#include <QSqlDatabase>
#include <QSqlQuery>

class DisciplinaDAO: public DAO<Disciplina>
{
public:
    DisciplinaDAO(QSqlDatabase *db);
    void inserir(Disciplina* obj);  // Create
    Disciplina* buscar(QString const& id);  // Read
    void alterar(Disciplina* obj);  // Update
    void deletar(QString const& id);  // Delete
    std::list<QString>* info();  // Listar

private:
    QSqlDatabase *db;
};

#endif // DISCIPLINADAO_H
