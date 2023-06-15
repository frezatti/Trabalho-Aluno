#ifndef ALUNO_H
#define ALUNO_H

#include <QString>
class Aluno
{
public:
    Aluno();
    Aluno(QString mat):matricula(mat){}
    Aluno(QString mat, QString nome);

    QString getMatricula() const;
    void setMatricula(const QString &newMatricula);

    QString getNome() const;
    void setNome(const QString &newNome);

    QString toQString() const;



private:
    QString matricula;
    QString nome;
};

#endif // ALUNO_H
