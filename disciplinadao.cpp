#include "disciplinadao.h"
#include "QtSql/qsqlerror.h"

DisciplinaDAO::DisciplinaDAO(QSqlDatabase *db):db(db)
{
}

void DisciplinaDAO::inserir(Disciplina* obj){
    if (!db->open()){
        throw QString("Erro ao abrir o banco de dados");
    }
    QSqlQuery query;
    query.prepare("INSERT INTO disciplina (cod_disciplina,nom_disciplina) VALUES (:dis, :nom);");
    query.bindValue(":dis", obj->getCod_disciplina());
    query.bindValue(":nom", obj->getNome_disciplina());
    if (!query.exec()){
        QString error = query.lastError().text();
        db->close();
        throw QString("Erro ao executar a inserção\n")+error;
    }
    db->close();
}

Disciplina* DisciplinaDAO::buscar(Disciplina *obj){
    if (!db->open()){
        throw QString("Erro ao abrir o banco de dados");
    }
    QString cod_disciplina (""), nome("");
    QSqlQuery query;
    if (obj!=nullptr){
        query.prepare("SELECT * FROM disciplina WHERE cod_disciplina = :mat;");
        query.bindValue(":mat", obj->getCod_disciplina());
        if (!query.exec()){
            db->close();
            throw QString("Erro ao executar a consulta");
        }
        while (query.next()){
            cod_disciplina = query.value(0).toString();
            nome = query.value(1).toString();
        }
        obj->setCod_disciplina(cod_disciplina );
        obj->setNome_disciplina(nome);
        db->close();
    }
    if (obj->getCod_disciplina()!="") return obj;
    else{
        delete obj;
        return nullptr;
    }


}


void DisciplinaDAO::alterar(Disciplina* obj){

    Disciplina* disciplina = new Disciplina();
    disciplina->setCod_disciplina(obj->getCod_disciplina());
    if (this->buscar( disciplina)==nullptr){
        throw QString(" disciplina não encontrado!");
    }
    else{
        if (!db->open()){
            throw QString("Erro ao abrir o banco de dados");
        }
        QSqlQuery query;
        query.prepare("UPDATE  disciplina SET nom_disciplina  = :nom WHERE cod_disciplina = :cod ;");
        query.bindValue(":nom", obj->getNome_disciplina());
        query.bindValue(":cod", obj->getCod_disciplina());
        if (!query.exec()){
            QString error = query.lastError().text();
            db->close();
            throw QString("Erro ao executar a update: \n")+error;
        }
        db->close();
        delete obj;
    }
}


void DisciplinaDAO::deletar(QString const &id){}//Delete

std::list<QString>* DisciplinaDAO::info(){
    QSqlQuery query;
    QString info;
    std::list<QString>* infolist = new std::list<QString>;
    if (!db->open()){
        throw QString("Erro ao abrir o banco de dados");
    }
    query.prepare("SELECT cod_disciplina, nom_disciplina FROM disciplina;");
    if (!query.exec()) {
        QString error = query.lastError().text();
        db->close();
        throw QString("Erro ao executar a consulta: ") + error;
    }

    while (query.next()){
        info = query.value(0).toString() +";"+ query.value(1).toString();
        infolist->push_back(info);
    }
    db->close();
    return infolist;
}
