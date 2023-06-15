#ifndef TURMACONTROLER_H
#define TURMACONTROLER_H
#include <list>
#include <turma.h>
#include <turmadao.h>


class TurmaControler
{
public:
    TurmaControler();
    TurmaControler(QString filename);
    void addTurma(QString cod_turma, int sub_turma);
    void buscarTurma(QString &id);
    void atualizarTurma();
    void removerTurma();
    void analisarTurma(QString &id);
private:
    Turma* a;
    TurmaDao* daoTurma;
    std::list<Turma*>* turma;
};

#endif // TURMACONTROLER_H
