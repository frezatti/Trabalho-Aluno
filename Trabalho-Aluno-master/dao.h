#ifndef DAO_H
#define DAO_H

#include <QString>
template <class Tipo>
class DAO //CRUD
{
public:
    DAO(){}
    virtual void inserir(Tipo* obj)=0;//Create
    virtual Tipo* buscar(QString const &id)=0;//Read
    virtual void alterar(Tipo* obj)=0;//Update
    virtual void deletar(QString const &id)=0;//Delete

};

#endif // DAO_H
