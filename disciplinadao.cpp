#include "disciplinadao.h"

DisciplinaDAO::DisciplinaDAO()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    nomeBD = "C:/Users/i5/Documents/Junio/Trabalho-Aluno-master/academico.db";
    db.setDatabaseName(nomeBD);
}

void DisciplinaDAO::inserir(Disciplina* obj){
    if (!db.open()){
        throw QString("Erro ao abrir o banco de dados");
    }
    QSqlQuery query;
    query.prepare("INSERT INTO disciplina (cod_disciplina,nom_disciplina) VALUES (:dis, :nom);");
    query.bindValue(":dis", obj->getCod_disciplina());
    query.bindValue(":nom", obj->getNome_disciplina());
    if (!query.exec()){
        db.close();
        throw QString("Erro ao executar a inserção");
    }
    db.close();
}

Disciplina* DisciplinaDAO::buscar(QString const &id){}


void DisciplinaDAO::alterar(Disciplina* obj){}
void DisciplinaDAO::deletar(QString const &id){}//Delete
