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
void DisciplinaControler::atualizarDisciplina(QString cod,QString nom){
   daoDisciplina->alterar(new Disciplina(cod, nom));
}
QString DisciplinaControler::buscarDisciplina(QString &id) {
    // Verificar se o código da disciplina existe
    a =new Disciplina;
    a->setCod_disciplina(id);
    a = daoDisciplina->buscar(a);
    if (!a) {
        throw QString("Código de disciplina não encontrado.");
    }
    return a->toQString();
}

bool DisciplinaControler::analisarDisciplina(Disciplina* id) {
    // Verificar se o código da disciplina existe
    a = daoDisciplina->buscar(id);
    if (a != nullptr) {
        // O código da disciplina existe
        id = a;
       return true;
    } else {
        // O código da disciplina não existe
        throw QString("Código de disciplina não encontrado.");
    }
}

void DisciplinaControler::removerDisciplina(QString mat){
    daoDisciplina->deletar(mat);
}


std::list<QString> * DisciplinaControler::info(){
    return daoDisciplina->info();
}




