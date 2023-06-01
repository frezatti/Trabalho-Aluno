#include "alunodao.h"
#include <string>

void AlunoDAO::inserir(Aluno* obj){//Create
   std::list<Aluno*>* lista = lerArquivo();//cria list do arquivo
   if(this->buscarArquivo(obj->getMatricula())!=nullptr)
       throw QString("Matrícula já cadastrada");
   else
       lista->push_back(obj);
   gravarArquivo(lista);
   lista = nullptr;
}
//Buscar aluno no arquivo
Aluno* AlunoDAO::buscarArquivo(QString const &id){
    Aluno* a=nullptr;//Ponteiro Obj Aluno
    std::string linha;//Linha lida do arquivo
    QString qLinha;//Linha lida no Formato QString
    QStringList qLinhaList;//Lista de QString divididas ;
    std::ifstream arquivo;//Arquivo CSV
    arquivo.open(filename.toStdString().c_str());//Abrir arquivo
    if(!arquivo.is_open())
        throw QString("Erro: Arquivo não pode ser aberto");
    getline(arquivo, linha);
    while (!arquivo.eof()){
        qLinha = QString::fromStdString(linha);
        qLinhaList = qLinha.split(';');
        if(qLinhaList[0] == id){
            a = new Aluno(qLinhaList[0], qLinhaList[1]);
            break;
        }
        getline(arquivo, linha);
    }
    arquivo.close();//Fecha arquivo
    return a;
}
//Buscar aluno
Aluno* AlunoDAO::buscar(QString const &id){//Read
    Aluno* a = this->buscarArquivo(id);
    if(a != nullptr)
        return a;
    else
        throw QString("Aluno não encontrado");
}
//Alterar aluno
void AlunoDAO::alterar(Aluno* obj){//Update
    bool achou = false;
    std::list<Aluno*>* lista = lerArquivo();
    std::list<Aluno*>::iterator it;
    for(it = lista->begin(); it != lista->end(); ++it){
        if((*it)->getMatricula() == obj->getMatricula()){
            lista->erase(it);//Remove obj_antigo da lista
            delete (*it);//Destroi obj_antigo
            lista->push_back(obj);//Insere obj na lista
            this->gravarArquivo(lista);//grava lista
            achou = true;
            break;
        }
    }
    if (!achou)
        throw QString("Aluno não encontrado");
}
//Deletar aluno
void AlunoDAO::deletar(QString const &id){//Delete
    bool achou=false;
    std::list<Aluno*>* lista = this->lerArquivo();
    std::list<Aluno*>::iterator it;
    for(it = lista->begin(); it != lista->end(); ++it){
      if((*it)->getMatricula() == id){
          lista->erase(it);
          delete (*it);
          this->gravarArquivo(lista);
          achou = true;
          break;
      }
    }
    if (!achou)
        throw QString("Aluno não encontrado");
}
//Ler arquivo CSV
std::list<Aluno*>* AlunoDAO::lerArquivo(){
    std::list<Aluno*>* lista = new std::list<Aluno*>();
    Aluno* a=nullptr;//Ponteiro Obj Aluno
    std::string linha;//Linha lida do arquivo
    QString qLinha;//Linha lida no Formato QString
    QStringList qLinhaList;//Lista de QString divididas ;
    std::ifstream arquivo;//Arquivo CSV
    arquivo.open(filename.toStdString().c_str());
    if(!arquivo.is_open())
        throw QString("Erro: Arquivo não pode ser aberto");
    getline(arquivo, linha);
    while (!arquivo.eof()){
        qLinha = QString::fromStdString(linha);
        qLinhaList = qLinha.split(';');
        if(qLinhaList.size()>=2){
            a = new Aluno(qLinhaList[0], qLinhaList[1]);
            lista->push_back(a);
        }
        getline(arquivo, linha);
    }
    arquivo.close();//Fecha arquivo
    return lista;
}
//Gravar Arquivo CSV
void AlunoDAO::gravarArquivo(std::list<Aluno*>* lista){
    std::ofstream arquivo;//Arquivo CSV
    arquivo.open(filename.toStdString().c_str());
    if(!arquivo.is_open())
        throw QString("Erro: Arquivo não pode ser aberto");
    //Grava arquivo
    std::list<Aluno*>::iterator it;
    for(it = lista->begin(); it != lista->end(); ++it)
        arquivo << (*it)->getDados().toStdString()<<std::endl;
    arquivo.close();//Fecha arquivo
    delete lista;
}
//Listar alunos
std::list<QString>* AlunoDAO::listar(){
    std::list<Aluno*>* listaAluno = lerArquivo();
    std::list<QString>* lista = new std::list<QString>();
    std::list<Aluno*>::iterator it;
    for(it = listaAluno->begin(); it != listaAluno->end(); ++it){
        lista->push_back((*it)->getDados());
    }
    delete listaAluno;
    return lista;
}
