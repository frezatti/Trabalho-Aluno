#ifndef DISCIPLINACONTROLER_H
#define DISCIPLINACONTROLER_H
#include <list>
#include <disciplina.h>
#include <disciplinadao.h>

class DisciplinaControler
{
public:
    DisciplinaControler(QString filename);
    void addDisciplina(QString codigo, QString nome);
    void buscarDisciplina(QString &id);
    void atualizarDisciplina();
    void removerDisciplina();
private:
    Disciplina* a;
    DisciplinaDAO *daoDisciplina;
    std::list<Disciplina*>* disciplina;
};

#endif // DISCIPLINACONTROLER_H
