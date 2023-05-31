#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include <string>
#include <QString>


class Disciplina
{
public:
    Disciplina();
    Disciplina(std::string codigo,std::string disciplina);
    const std::string &getCod_disciplina() const;
    void setCod_disciplina(const std::string &newCod_disciplina);

    const std::string &getNome_disciplina() const;
    void setNome_disciplina(const std::string &newNome_disciplina);

    QString toQString()const;
private:
    std::string cod_disciplina;
    std::string nome_disciplina;
};

#endif // DISCIPLINA_H
