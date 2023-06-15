#include "matriculacontroler.h"

MatriculaControler::MatriculaControler(QSqlDatabase * db)
{
    daoMatricula = new MatriculaDao(db);
}

void MatriculaControler::addMatricula(QString matricula, QString codDisciplina, QString codTurma){
    a = new Matricula();
    a->setMatricula(matricula);
    a->setDisciplina(codDisciplina);
    a->setTurma(codTurma);
    daoMatricula->inserir(a);
    daoTurma->inserir(a->getTurma());
    daoDisciplina->inserir(a->getDisciplina());
    int validator = analizar(matricula,codDisciplina,codTurma);
    if(validator){
        throw validator;
    }
    delete a;
}

void MatriculaControler::buscarMatricula(QString &id){
    a = daoMatricula->buscar(id);
    if (!a) {
        throw QString("Matricula nao Encontrada");
    }
    id = a->toQString();
}

int MatriculaControler::analizar(QString matricula, QString Disciplina, QString Turma){
  /*  if(!daoMatricula->buscar(matricula))return 1;
    if(!daoDisciplina->buscar(Disciplina))return 2;
    if(!daoTurma->buscar(Turma))return 3;
    return 0;
*/
}
