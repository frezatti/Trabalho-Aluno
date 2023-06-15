#ifndef TURMA_H
#define TURMA_H
#include <QString>


class Turma
{
public:
    Turma();
    Turma(QString cod_turma);
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



    QString getCod_Disciplina() const;
    void setCod_Disciplina(const QString &newCod_Disciplina);

private:
    QString cod_turma;
    QString cod_Disciplina;
    int sub_turma;
    int maxAlunos = 100;
    int numAlunos = 100;
};

#endif // TURMA_H
