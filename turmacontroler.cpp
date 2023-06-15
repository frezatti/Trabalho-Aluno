#include "turmacontroler.h"

TurmaControler::TurmaControler(QString filename){
    daoTurma = new TurmaDao(filename);
}

void TurmaControler::addTurma(QString cod_turma, int sub_turma){
        a = new Turma();
        a->setCod_turma(cod_turma);
        a->setSub_turma(sub_turma);
        daoTurma->inserir(a);
        if(a==nullptr){
            throw QString ("Inserir error");
        }
        delete a;
    }

void TurmaControler::buscarTurma(QString &id){
    a=daoTurma->buscar(id);
    id = a->getDadosTurma();
}


void TurmaControler::analisarTurma(QString &id){
    // Verificar se o código da turma existe
       a = daoTurma->buscar(id);

       if (a != nullptr) {
           // O código da turma existe
           id = a->getDadosTurma();
           delete a;
       } else {
           // O código da turma não existe
           throw QString("Código de turma não encontrado.");
       }

}
