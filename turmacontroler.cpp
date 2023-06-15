#include "turmacontroler.h"

TurmaControler::TurmaControler(QSqlDatabase *db){
    daoTurma = new TurmaDao(db);
}

void TurmaControler::addTurma(QString cod_turma,QString cod_disciplina, int sub_turma){
    a = new Turma();
    a->setCod_turma(cod_turma);
    a->setCod_Disciplina(cod_disciplina);
    a->setSub_turma(sub_turma);
    daoTurma->inserir(a);
    if(a==nullptr){
        throw QString ("Inserir error");
    }
    delete a;
}

QString TurmaControler::buscar(QString &id){
    a = nullptr;
    a = daoTurma->buscar(new Turma(id));
    if (a!=nullptr){
        return a->toQString();
    }
    else{
        throw QString("Aluno não encontrado!");
    }
}

void TurmaControler::atualizarTurma(QString codturma,QString coddisciplina, int sub){
    Turma * turma = new Turma;
    turma->setCod_turma(codturma);
    turma->setSub_turma(sub);
    turma->setCod_Disciplina(coddisciplina);
    daoTurma->alterar(turma);
    //delete turma;
}

void TurmaControler::analisarTurma(QString &id){
    // Verificar se o código da turma existe
      /* a = daoTurma->buscar(id);

       if (a != nullptr) {
           // O código da turma existe
           id = a->getDadosTurma();
           delete a;
       } else {
           // O código da turma não existe
           throw QString("Código de turma não encontrado.");
       }
*/
}

std::list<QString>* TurmaControler::info(){
       return daoTurma->info();
}
