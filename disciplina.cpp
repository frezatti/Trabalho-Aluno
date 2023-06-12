#include "disciplina.h"

Disciplina::Disciplina()
{

}

Disciplina::Disciplina(QString codigo, QString disciplina) {
    cod_disciplina = codigo;
    nome_disciplina = disciplina;
}

const QString &Disciplina::getCod_disciplina() const
{
    return cod_disciplina;
}

void Disciplina::setCod_disciplina(const QString &newCod_disciplina)
{
    cod_disciplina = newCod_disciplina;
}

const QString &Disciplina::getNome_disciplina() const
{
    return nome_disciplina;
}

void Disciplina::setNome_disciplina(const QString &newNome_disciplina)
{
    nome_disciplina = newNome_disciplina;
}

QString Disciplina::getDadosDisciplina()const{
    return cod_disciplina+";"+nome_disciplina;
}
QString Disciplina::toQString() const {
    QString str;
    str += cod_disciplina + ";";
    str += nome_disciplina;
    return str;
}

