#include "disciplinacontroler.h"


DisciplinaControler::DisciplinaControler(QString filename){
    daoDisciplina = new DisciplinaDAO(filename);
}
void DisciplinaControler::addDisciplina(QString codigo, QString nome){

    a = new Disciplina();
    a->setCod_disciplina(codigo);
    a->setNome_disciplina(nome);
    daoDisciplina->inserir(a);
    if(a==nullptr){
        throw QString ("Inserir error");
    }
    delete a;
}
void DisciplinaControler::buscarDisciplina(QString &id){
    a=daoDisciplina->buscar(id);
    id = a->getDadosDisciplina();

}
