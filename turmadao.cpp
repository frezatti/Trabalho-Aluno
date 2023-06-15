#include "turmadao.h"

TurmaDao::TurmaDao()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    nomeBD = "/Users/adrielfrezatti/Programing/c++/Qt/Trabalho-Aluno/academico.db";
    db.setDatabaseName(nomeBD);
}


void TurmaDao::inserir(Turma *obj){
    if (!db.open()){
        throw QString("Erro ao abrir o banco de dados");
    }
    QSqlQuery query;
    query.prepare("INSERT INTO turma (cod_turma, cod_disciplina , sub_turma, max_alunos, num_alunos) VALUES (:tur, :dis, :subt, :maxA, :numA);");
    query.bindValue(":tur", obj->getCod_turma());
    query.bindValue(":dis", obj->getCod_turma());
    query.bindValue(":subt", obj->getSub_turma());
    query.bindValue(":maxA", obj->getMaxAlunos());
    query.bindValue(":numA", obj->getNumAlunos());
    if (!query.exec()){
        db.close();
        throw QString("Erro ao executar a inserção");
    }
    db.close();
}

Turma* TurmaDao::buscar(QString const &id){}
void TurmaDao::alterar(Turma *obj){}
void TurmaDao::deletar(QString const &id){}//Delete
