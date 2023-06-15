#ifndef DISCIPLINACONTROLER_H
#define DISCIPLINACONTROLER_H
#include <list>
#include <disciplina.h>
#include <disciplinadao.h>

class DisciplinaControler
{
public:
    DisciplinaControler(QSqlDatabase *db);
    void addDisciplina(QString codigo, QString nome);
    QString buscarDisciplina(QString &id);
    void atualizarDisciplina(QString cod,QString nom);
    void removerDisciplina(QString mat);
    bool analisarDisciplina(Disciplina *id);
    std::list<QString> * info();
private:
    Disciplina* a;
    DisciplinaDAO* daoDisciplina;
};

#endif // DISCIPLINACONTROLER_H
