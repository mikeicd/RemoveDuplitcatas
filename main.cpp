// implemente aqui seu programa ...
#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;


    //Definição do tipo Alunos
struct Alunos {
    string nome;
    string matricula;

    Alunos() {
    }
    //Função para inserção de dados na lista
    Alunos(const string & m, const string & n) {
        nome = n;
        matricula= m;
    }

    //Função para definição do Sort
    bool operator<(const Alunos & o) {
        if (nome == o.nome) {
            return matricula < o.matricula;
        }
        return nome < o.nome;
    }
};

//Função para remover duplicatas se a matricula for igual
bool unico(Alunos & a, Alunos & b) {
    return (a.matricula == b.matricula);
}


int main(int argc, char *argv[]) {
    //Declaração das variaveis
    string linha;
    list<Alunos> lista;


    if (argc < 1) {
        cout << "Nenhum arquivo foi informado." << endl;
        return 0;
    }
    //Loop para verificar todos arquivos.
    for (int i = 1; i < argc ; ++i) {

        //Verifica se arquivo foi aberto.
        ifstream arq(argv[i]);
        if (!arq.is_open()){
            cout << "Erro ao abrir o arquivo!" << endl;
            return 0;
        }
        //Separando nome e matricula e adicionando na lista
        while (getline(arq, linha)) {
            int endLine = linha.size();
            lista.push_back(Alunos(linha.substr(0,8), linha.substr(9,endLine)));
        }

        lista.sort(); //Organizando conforme metodo na struct.
        lista.unique(unico); //Remove duplicatas com base na função unico.


        arq.close();
    }
    //Loop para mostrar Lista.
    for (auto x : lista) {
        cout << x.matricula+" "+ x.nome << endl;
    }
    


    return 0;
}