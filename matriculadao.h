#ifndef MATRICULADAO_H
#define MATRICULADAO_H
#include"dao.h"
#include"matricula.h"
#include <list>
#include <QString>
#include <QStringList>
#include <fstream>
#include <QSqlDatabase>
#include <QSqlQuery>

class MatriculaDao
{
public:
    MatriculaDao(QSqlDatabase *db);
    void inserir(Matricula* obj);  // Create
    Matricula* buscar(QString const& id);  // Read
    void alterar(Matricula* obj);  // Update
    void deletar(QString const& id);  // Delete
    std::list<QString>* listar();  // Listar
private:
    QSqlDatabase *db;

};

#endif // MATRICULADAO_H
