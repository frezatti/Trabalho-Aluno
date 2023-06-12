#ifndef TURMADAO_H
#define TURMADAO_H
#include"turma.h"
#include "dao.h"
#include <list>
#include <QString>
#include <QStringList>
#include <fstream>
#include <QSqlDatabase>
#include <QSqlQuery>


class TurmaDao: public DAO<Turma>
{
public:
    TurmaDao();
    void inserir(Turma* obj);  // Create
    Turma* buscar(QString const& id);  // Read
    void alterar(Turma* obj);  // Update
    void deletar(QString const& id);  // Delete
    std::list<QString>* listar();  // Listar

private:
    QString filename;
    QSqlDatabase db;
    QString nomeBD;
};

#endif // TURMADAO_H
