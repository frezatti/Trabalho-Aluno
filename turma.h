#ifndef TURMA_H
#define TURMA_H
#include <QString>


class Turma
{
public:
    Turma();
    Turma(QString cod_turma, int sub_turma, int maxAlunos, int numAlunos);

    const QString &getCod_turma() const;
    void setCod_turma(const QString &newCod_turma);

    int getSub_turma() const;
    void setSub_turma(int newSub_turma);

    int getMaxAlunos() const;
    void setMaxAlunos(int newMaxAlunos);

    int getNumAlunos() const;
    void setNumAlunos(int newNumAlunos);

    QString toQString()const;

    QString getDadosTurma() const;



private:
    QString cod_turma;
    int sub_turma;
    int maxAlunos;
    int numAlunos;
};

#endif // TURMA_H
