#ifndef ALUNOCONTROLER_H
#define ALUNOCONTROLER_H

#include "aluno.h"
#include "alunodao.h"
#include <list>
class AlunoControler
{
public:
    AlunoControler(QString filename);
    std::list<QString>* infoAluno();
    void addAluno(QString matricula, QString nome);
    void buscarAluno(QString &matricula);
    void atualiazarAluno(QString matricula, QString nome);
    void deleteAluno(QString matricula);

private:
    Aluno* a;
    AlunoDAO *daoAluno;
    std::list<Aluno*>* alunos;
};

#endif // ALUNOCONTROLER_H
