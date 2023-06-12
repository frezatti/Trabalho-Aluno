#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include <string>
#include <QString>


class Disciplina
{
public:
    Disciplina();
    Disciplina(QString codigo,QString disciplina);
    const QString &getCod_disciplina() const;
    void setCod_disciplina(const QString &newCod_disciplina);

    const QString &getNome_disciplina() const;
    void setNome_disciplina(const QString &newNome_disciplina);

    QString getDadosDisciplina() const;

    QString toQString()const;
private:
    QString cod_disciplina;
    QString nome_disciplina;
};

#endif // DISCIPLINA_H
