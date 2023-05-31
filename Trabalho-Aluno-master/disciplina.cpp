#include "disciplina.h"

Disciplina::Disciplina()
{

}
Disciplina::Disciplina(std::string codigo,std::string disciplina):cod_disciplina(codigo),nome_disciplina(disciplina){}

const std::string &Disciplina::getCod_disciplina() const
{
    return cod_disciplina;
}

void Disciplina::setCod_disciplina(const std::string &newCod_disciplina)
{
    cod_disciplina = newCod_disciplina;
}

const std::string &Disciplina::getNome_disciplina() const
{
    return nome_disciplina;
}

void Disciplina::setNome_disciplina(const std::string &newNome_disciplina)
{
    nome_disciplina = newNome_disciplina;
}
QString Disciplina::toQString() const {
    QString str;
    str += QString::fromStdString(cod_disciplina) + ";";
    str += QString::fromStdString(nome_disciplina);
    return str;
}

