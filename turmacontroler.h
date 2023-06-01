#ifndef TURMACONTROLER_H
#define TURMACONTROLER_H

#include <turma.h>
#include <turmadao.h>


class TurmaControler
{
public:
    TurmaControler();
    void addTurma();
    void buscarTurma();
    void atualizarTurma();
    void removerTurma();
};

#endif // TURMACONTROLER_H
