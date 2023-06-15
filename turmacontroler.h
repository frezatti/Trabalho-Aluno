#ifndef TURMACONTROLER_H
#define TURMACONTROLER_H
#include <list>
#include <turma.h>
#include <turmadao.h>


class TurmaControler
{
public:
    TurmaControler(QSqlDatabase *db);

    void addTurma(QString cod_turma, QString cod_disciplina, int sub_turma);
    QString buscar(QString &id);
    void atualizarTurma(QString codturma, QString coddisciplina, int sub);
    void removerTurma();
    void analisarTurma(QString &id);
    std::list<QString>* info();
private:
    Turma* a;
    TurmaDao* daoTurma;

};

#endif // TURMACONTROLER_H
