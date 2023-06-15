#include "alunocontroller.h"

AlunoController::AlunoController(QSqlDatabase *db)
{
    dao = new AlunoDAO(db);
}

void AlunoController::incluir(QString const &mat, QString const &nom){
    aluno = new Aluno();
    aluno->setMatricula(mat);
    aluno->setNome(nom);
    dao->incluir(aluno);
    aluno = nullptr;
}

QString AlunoController::buscar(QString const &mat){
    aluno = nullptr;
    aluno = dao->buscar(new Aluno(mat, ""));
    if (aluno!=nullptr)
        return aluno->toQString();
    else
        throw QString("Aluno não encontrado!");
}

void AlunoController::alterar(QString const &mat, QString const &nom){
    dao->alterar(new Aluno(mat, nom));
}

void AlunoController::remover(QString const &mat){
    dao->remover(new Aluno(mat));
}

std::list<QString>* AlunoController::info(){
    return dao->info();
}
