#include "turmadao.h"
#include "qsqlerror.h"

TurmaDao::TurmaDao(QSqlDatabase *db):db(db)
{
}


void TurmaDao::inserir(Turma *obj){
    if (!db->open()){
        throw QString("Erro ao abrir o banco de dados");
    }
    QSqlQuery query;
    query.prepare("INSERT INTO turma (cod_turma, cod_disciplina , sub_turma, max_alunos, num_alunos) VALUES (:tur, :dis, :subt, :maxA, :numA);");
    query.bindValue(":tur", obj->getCod_turma());
    query.bindValue(":dis", obj->getCod_Disciplina());
    query.bindValue(":subt", obj->getSub_turma());
    query.bindValue(":maxA", obj->getMaxAlunos());
    query.bindValue(":numA", obj->getNumAlunos());
    if (!query.exec()){
        QString error = query.lastError().text();
        db->close();
        throw QString("Erro ao executar a inserção: \n "+error);
    }
    db->close();
}

Turma* TurmaDao::buscar(Turma* obj){
    if (!db->open()){
        throw QString("Erro ao abrir o banco de dados");
    }
    QString cod_turma(""), cod_disciplina(""),codSubTurma("");
    QSqlQuery query;
    if (obj!=nullptr){
        query.prepare("SELECT * FROM turma WHERE cod_turma = :mat;");
        query.bindValue(":mat", obj->getCod_turma());
        if (!query.exec()){
            QString error = query.lastError().text();
            db->close();
            throw QString("Erro ao executar a consulta: \n")+error;
        }
        while (query.next()){
            cod_turma = query.value(0).toString();
            cod_disciplina = query.value(1).toString();
            codSubTurma = query.value(2).toString();
        }
        obj->setCod_turma(cod_turma);
        obj->setCod_Disciplina(cod_disciplina);
        obj->setSub_turma(codSubTurma.toInt());
        db->close();
    }
    if (obj->getCod_turma()!="") return obj;
    else{
        delete obj;
        return nullptr;
    }
}
void TurmaDao::alterar(Turma *obj){

    Turma* turma = new Turma();
     turma->setCod_turma(obj->getCod_turma());
    if (this->buscar(turma)==nullptr){
        throw QString("  turma não encontrado!");
    }
    else{
        if (!db->open()){
            throw QString("Erro ao abrir o banco de dados");
        }
        QSqlQuery query;
        query.prepare("UPDATE   turma SET cod_disciplina  = :nom , sub_turma = :sub WHERE cod_turma = :cod ;");
        query.bindValue(":nom", obj->getCod_Disciplina());
        query.bindValue(":sub", obj->getSub_turma());
        query.bindValue(":cod", obj->getCod_turma());
        if (!query.exec()){
            QString error = query.lastError().text();
            db->close();
            throw QString("Erro ao executar a update: \n")+error;
        }
        db->close();
        delete obj;
    }
}

void TurmaDao::deletar(QString const &id){

    Turma* turma = new Turma();
    turma->setCod_turma(id);
    if (this->buscar(turma)==nullptr){
        throw QString("Disciplina não encontrado!");
    }
    else{
        if (!db->open()){
            throw QString("Erro ao abrir o banco de dados");
        }
        QSqlQuery query;
        query.prepare("DELETE FROM turma WHERE cod_turma = :mat ;");
        query.bindValue(":mat",turma->getCod_turma());
        if (!query.exec()){
            db->close();
            throw QString("Erro ao executar a delete");
        }
        db->close();
        delete turma;
    }
}

std::list<QString>* TurmaDao::info(){

    QSqlQuery query(*db);
    std::list<QString>* infolist = new std::list<QString>;

    if (!db->open()) {
        throw QString("Erro ao abrir o banco de dados");
    }

    query.prepare("SELECT cod_turma, cod_disciplina, sub_turma, max_alunos, num_alunos FROM turma;");
    if (!query.exec()) {
        QString error = query.lastError().text();
        db->close();
        throw QString("Erro ao executar a consulta: ") + error;
    }

    while (query.next()) {
        QString info = query.value(0).toString() + ";" + query.value(1).toString() + ";" +
                       query.value(2).toString() + ";" + query.value(3).toString() + ";" +
                       query.value(4).toString();
        infolist->push_back(info);
    }

    db->close();
    return infolist;


}
