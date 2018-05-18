
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Filme {
    string nome;
    int ano;
    string genero;
    string descricao;
};

class Usuario {
    string nome;

};
void gerente(){
    string codigo;
    cout<<"Bem-vindo a sessão de gerência do sistema"<<endl;
    cout<<"Informe o codigo de permissao para continuar"<<endl;
    cin>>codigo;

    if(codigo == "admin") {
        cout<<"Informe uma opçao para seguir:"<<endl;
    }



};
void selecionaUsuario(string nome){};

void apresentacao() {


    cout<<"██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ "<<endl;
    cout<<"██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗"<<endl;
    cout<<"██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║"<<endl;
    cout<<"██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║"<<endl;
    cout<<"██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝"<<endl;
    cout<<"╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ "<<endl;

    cout<<"À LOCADORA DE FILMES"<<endl;
    cout<<"COMO VOCÊ DESEJA SEGUIR?"<<endl;
    cout<<"(1)GERENTE"<<endl;
    cout<<"(2)USUÁRIO"<<endl;

    int opcao;

    cin>>opcao;

    if(opcao == 1) gerente();
    else {
        string nome;
        cout<<"QUAL O SEU NOME DE USUÁRIO?"<<endl;
        cin>>nome;
        selecionaUsuario(nome);
    }
}

int main(){


    apresentacao();
    return 0;
}
