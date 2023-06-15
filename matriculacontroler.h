#ifndef MATRICULACONTROLER_H
#define MATRICULACONTROLER_H

#include<list>
#include<matricula.h>
#include<turmadao.h>
#include<disciplinadao.h>
#include<matriculadao.h>

class MatriculaControler
{
public:
    MatriculaControler();
    MatriculaControler(QString Filename);
    void addMatricula(QString matricula, QString codDisciplina, QString codTurma);
    void buscarMatricula(QString &id);
    void atualizarMatricula();
    void removerMatricula();
    int analizar(QString matricula, QString Disciplina, QString Turma);

private:
    Matricula* a;
    MatriculaDao *daoMatricula;
    DisciplinaDAO *daoDisciplina;
    TurmaDao *daoTurma;
    std::list<Matricula*>* disciplina;
};

#endif // MATRICULACONTROLER_H
