#ifndef MATRICULA_H
#define MATRICULA_H
#include "aluno.h"
#include "disciplina.h"
#include "turma.h"

class Matricula
{
public:
    Matricula();
    Matricula(int ano, int semestre,float nota1,float nota2, Aluno aluno, Disciplina disciplina);

    int getAno() const;
    void setAno(int newAno);
    int getSemestre() const;
    void setSemestre(int newSemestre);
    float getNota1() const;
    void setNota1(float newNota1);
    float getNota2() const;
    void setNota2(float newNota2);

    const QString &getAluno() const;
    void setAluno(const Aluno &newAluno);

    const QString &getDisciplina() const;
    void setDisciplina(const Disciplina &newDisciplina);

    QString toQString()const;
    float getNotaf() const;

    QString getTurma() const;
    void setTurma(const Turma &newTurma);

private:
    int ano;
    int semestre;
    float nota1;
    float nota2;
    Aluno aluno;
    Disciplina disciplina;
    Turma turma;
};

#endif // MATRICULA_H
