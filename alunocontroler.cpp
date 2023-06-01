#include "alunocontroler.h"

AlunoControler::AlunoControler(QString filename){
    daoAluno = new AlunoDAO(filename);
}
void AlunoControler::addAluno(QString matricula, QString nome){

    a = new Aluno();
    a->setMatricula(matricula);
    a->setNome(nome);
    daoAluno->inserir(a);
    if(a==nullptr){
        throw QString ("Inserir error");
    }
    delete a;
}

void AlunoControler::buscarAluno(QString &id){
    a=daoAluno->buscar(id);
    id = a->getDados();

}

void AlunoControler::atualiazarAluno(QString matricula, QString nome){
   a = new Aluno();
   a->setMatricula(matricula);
   a->setNome(nome);
   daoAluno->alterar(a);
   delete a;
}

void AlunoControler::deleteAluno(QString matricula){
    daoAluno->deletar(matricula);
}

std::list<QString> * AlunoControler::infoAluno(){
    return daoAluno->listar();
}
