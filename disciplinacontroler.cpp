#include "disciplinacontroler.h"



DisciplinaControler::DisciplinaControler(QSqlDatabase *db){
    daoDisciplina = new DisciplinaDAO(db);
}



void DisciplinaControler::addDisciplina(QString codigo, QString nome) {

 // Verificar se o código da disciplina já existe
 try {

       // analisarDisciplina(codigo);
        throw QString("Código de disciplina já existe.");
        } catch (QString exception) {
        // O código de disciplina não existe, então podemos adicioná-lo
        Disciplina* novaDisciplina = new Disciplina();
        novaDisciplina->setCod_disciplina(codigo);
        novaDisciplina->setNome_disciplina(nome);
        daoDisciplina->inserir(novaDisciplina);
        delete novaDisciplina;
 }

}

void DisciplinaControler::buscarDisciplina(QString &id) {
    // Verificar se o código da disciplina existe
    if (!analisarDisciplina(id)) {
        throw QString("Código de disciplina não encontrado.");
    }
    a = daoDisciplina->buscar(id);
    id = a->getDadosDisciplina();
}

bool DisciplinaControler::analisarDisciplina(QString &id) {
    // Verificar se o código da disciplina existe
    a = daoDisciplina->buscar(id);
    if (a != nullptr) {
        // O código da disciplina existe
        id = a->getDadosDisciplina();
        return true;
        delete a;
    } else {
        // O código da disciplina não existe
        throw QString("Código de disciplina não encontrado.");
    }
}

std::list<QString> * DisciplinaControler::info(){
    return daoDisciplina->info();
}




