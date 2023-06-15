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

Disciplina* DisciplinaDAO::buscar(QString const &id){}


void DisciplinaDAO::alterar(Disciplina* obj){}
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
        throw QString("Erro ao executar a consulta: ") + error;
    }

    while (query.next()){
        info = query.value(0).toString() +";"+ query.value(1).toString();
        infolist->push_back(info);
    }
    db->close();
    return infolist;
}
