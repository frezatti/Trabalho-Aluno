#include "turma.h"

Turma::Turma()
{

}

Turma::Turma(QString cod_turma, int sub_turma, int maxAlunos, int numAlunos): cod_turma(cod_turma), sub_turma(sub_turma), maxAlunos(maxAlunos), numAlunos(numAlunos)
{

}

const QString &Turma::getCod_turma() const
{
    return cod_turma;
}

void Turma::setCod_turma(const QString &newCod_turma)
{
    cod_turma = newCod_turma;
}

int Turma::getSub_turma() const
{
    return sub_turma;
}

void Turma::setSub_turma(int newSub_turma)
{
    sub_turma = newSub_turma;
}

int Turma::getMaxAlunos() const
{
    return maxAlunos;
}

void Turma::setMaxAlunos(int newMaxAlunos)
{
    maxAlunos = newMaxAlunos;
}

int Turma::getNumAlunos() const
{
    return numAlunos;
}

void Turma::setNumAlunos(int newNumAlunos)
{
    numAlunos = newNumAlunos;
}

QString Turma::toQString()const{
    return QString(cod_turma)+";"+QString::number(sub_turma)+";"+QString::number(maxAlunos)+";"+QString::number(numAlunos);
}
