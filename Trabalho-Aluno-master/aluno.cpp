#include"aluno.h"

Aluno::Aluno(){
}

Aluno::Aluno(QString matricula,QString nome):matricula(matricula),nome(nome){}

void Aluno::setMatricula(const QString &matricula){
    this->matricula=matricula;
}

QString Aluno::getMatricula()const{
    return matricula;
}

void Aluno::setNome(const QString &nome){
    this->nome= nome;
}

QString Aluno::getNome()const{
    return nome;
}

QString Aluno::getDados()const{
    return matricula+";"+nome;
}
