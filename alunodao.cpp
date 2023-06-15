#include "alunodao.h"

AlunoDAO::AlunoDAO(QSqlDatabase *db):db(db)
{
}

void AlunoDAO::incluir(Aluno* obj){
    if (!db->open()){
        throw QString("Erro ao abrir o banco de dados");
    }
    QSqlQuery query;
    query.prepare("INSERT INTO aluno (mat_aluno, nom_aluno) VALUES (:mat, :nom);");
    query.bindValue(":mat", obj->getMatricula());
    query.bindValue(":nom", obj->getNome());
    if (!query.exec()){
        db->close();
        throw QString("Erro ao executar a inserção");
    }
    db->close();
}

Aluno* AlunoDAO::buscar(Aluno* obj){
    if (!db->open()){
        throw QString("Erro ao abrir o banco de dados");
    }
    QString matricula(""), nome("");
    QSqlQuery query;
    if (obj!=nullptr){
        query.prepare("SELECT * FROM aluno WHERE mat_aluno = :mat;");
        query.bindValue(":mat", obj->getMatricula());
        if (!query.exec()){
            db->close();
            throw QString("Erro ao executar a consulta");
        }
        while (query.next()){
            matricula = query.value(0).toString();
            nome = query.value(1).toString();
        }
        obj->setMatricula(matricula);
        obj->setNome(nome);
        db->close();
    }
    if (obj->getMatricula()!="") return obj;
    else{
        delete obj;
        return nullptr;
    }
}

void AlunoDAO::alterar(Aluno* obj){
    Aluno* aluno = new Aluno();
    aluno->setMatricula(obj->getMatricula());
    if (this->buscar(aluno)==nullptr){
        throw QString("Aluno não encontrado!");
    }
    else{
        if (!db->open()){
            throw QString("Erro ao abrir o banco de dados");
        }
        QSqlQuery query;
        query.prepare("UPDATE aluno SET nom_aluno = :nom WHERE mat_aluno = :mat ;");
        query.bindValue(":nom", obj->getNome());
        query.bindValue(":mat", obj->getMatricula());
        if (!query.exec()){
            db->close();
            throw QString("Erro ao executar a update");
        }
        db->close();
        delete obj;
    }
}

Aluno* AlunoDAO::remover(Aluno* obj){
    Aluno* aluno = new Aluno();
    aluno->setMatricula(obj->getMatricula());
    if (this->buscar(aluno)==nullptr){
        throw QString("Aluno não encontrado!");
    }
    else{
        if (!db->open()){
            throw QString("Erro ao abrir o banco de dados");
        }
        QSqlQuery query;
        query.prepare("DELETE FROM aluno WHERE mat_aluno = :mat ;");
        query.bindValue(":mat", obj->getMatricula());
        if (!query.exec()){
            db->close();
            throw QString("Erro ao executar a delete");
        }
        db->close();
        delete obj;
    }
}

std::list<QString>* AlunoDAO::info(){
    QSqlQuery query;
    QString info;
    std::list<QString>* infolist = new std::list<QString>;
    if (!db->open()){
        throw QString("Erro ao abrir o banco de dados");
    }
    query.prepare("SELECT mat_aluno , nom_aluno FROM aluno;");
    if (!query.exec()) {
        QString error = query.lastError().text();
        throw QString("Erro ao executar a consulta: ") + error;
    }

    while (query.next()){
        info = query.value(0).toString() +";"+ query.value(1).toString();
        infolist->push_back(info);
    }
    db->close();
    return infolist;
}
