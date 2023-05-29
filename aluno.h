#ifndef ALUNO_H
#define ALUNO_H

#include <QString>
class Aluno
{
public:
    Aluno();
    Aluno(QString mat, QString nome);

    QString getMatricula() const;
    void setMatricula(const QString &newMatricula);

    QString getNome() const;
    void setNome(const QString &newNome);

    QString getDados() const;

private:
    QString matricula;
    QString nome;
};

#endif // ALUNO_H
