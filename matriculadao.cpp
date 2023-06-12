#include "matriculadao.h"

MatriculaDao::MatriculaDao()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    nomeBD = "C:/Users/i5/Documents/Junio/Trabalho-Aluno-master/academico.db";
    db.setDatabaseName(nomeBD);
}


void MatriculaDao::inserir(Matricula *obj){
    if (!db.open()){
        throw QString("Erro ao abrir o banco de dados");
    }
    QSqlQuery query;
    query.prepare("INSERT INTO matricula (mat_aluno, cod_turma,cod_disciplina,nota1,nota2,meida) VALUES (:mat,,:tur,:dis,:nt1,nt2,med);");
    query.bindValue(":mat", obj->getAno()+obj->getSemestre());
    query.bindValue(":tur", obj->getTurma());
    query.bindValue(":nt1", obj->getNota1());
    query.bindValue(":nt2", obj->getNota2());
    query.bindValue(":med", obj->getNotaf());
    if (!query.exec()){
        db.close();
        throw QString("Erro ao executar a inserção");
    }
    db.close();
}


Matricula* MatriculaDao::buscar(QString const &id){}
void MatriculaDao::alterar(Matricula *obj){}
void MatriculaDao::deletar(QString const &id){}//Delete
