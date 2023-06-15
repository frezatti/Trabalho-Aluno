#ifndef MATRICULA_H
#define MATRICULA_H
#include "aluno.h"
#include "disciplina.h"
#include "turma.h"

class Matricula
{
public:
    Matricula();
    Matricula(int ano, int semestre, float nota1, float nota2, Aluno aluno, Disciplina *disciplina);
    void setMatricula(QString Matricula);
    int getAno() const;
    int getSemestre() const;
    float getNota1() const;
    void setNota1(float newNota1);
    float getNota2() const;
    void setNota2(float newNota2);

    const QString &getAluno() const;
    void setAluno(const Aluno &newAluno);

    Disciplina *&getDisciplina() ;
    QString getDisciplinaQs();
    void setDisciplina(const QString newDisciplina);

    QString toQString()const;
    float getNotaf() const;

    Turma *getTurma() const;
    QString getTurmaQs();
    void setTurma(const QString &newTurma);

private:
    int ano;
    int semestre;
    float nota1;
    float nota2;
    Aluno aluno;
    Disciplina* disciplina;
    Turma *turma;
};

#endif // MATRICULA_H
