#include "matricula.h"

Matricula::Matricula()
{

}
Matricula::Matricula(int ano, int semestre,float nota1,float nota2, Aluno aluno, Disciplina *disciplina):ano(ano),
    semestre(semestre),
    aluno(aluno),
    disciplina(disciplina)
{
   if(nota1<0||nota2<0) throw QString("nota deve ser maior que zero");
    this->nota1 = nota1;
    this->nota2 = nota2;
}

void Matricula::setMatricula(QString matricula){
    ano = matricula.mid(0,5).toInt();
    semestre = matricula.mid(5,7).toInt();
}
int Matricula::getAno() const
{
    return ano;
}

int Matricula::getSemestre() const
{
    return semestre;
}

float Matricula::getNota1() const
{
    return nota1;
}

void Matricula::setNota1(float newNota1)
{
   if(newNota1<0) throw QString("nota deve ser maior que zero");
    nota1 = newNota1;
}

float Matricula::getNota2() const
{
    return nota2;
}

void Matricula::setNota2(float newNota2)
{
   if(newNota2<0) throw QString("nota deve ser maior que zero");
    nota2 = newNota2;
}

const QString &Matricula::getAluno() const
{
    return aluno.toQString();
}

void Matricula::setAluno(const Aluno &newAluno)
{
    aluno = newAluno;
}

Disciplina* &Matricula::getDisciplina()
{
    return disciplina;
}
QString Matricula::getDisciplinaQs(){
    return disciplina->toQString();
}
void Matricula::setDisciplina(const QString newDisciplina)
{
    disciplina = new Disciplina();
    disciplina->setCod_disciplina(newDisciplina);
}

QString Matricula::toQString()const{
    return QString::number(ano)+";"+QString::number(semestre)+";"+aluno.toQString()+";"+QString::number(nota1)+";"+QString::number(nota2)+";"+QString::number((nota1+nota2)/2);

}

float Matricula::getNotaf() const
{
    return (nota1+nota2)/2;
}

Turma* Matricula::getTurma() const
{
    return turma;
}
QString Matricula::getTurmaQs(){
    return turma->toQString();
}
void Matricula::setTurma(const QString &newTurma)
{
    turma = new Turma();
    turma->setCod_turma(newTurma);
}
