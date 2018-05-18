
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using std::vector;
using std::string;
using namespace std;

struct Filme {
    string nome;
    int ano;
    string genero;
    string descricao;
};


struct Usuario {
    string cpf;
    string nome;


};

void apresentacao();
void editarFilme();
void opcoesGerente();
void menuUsuario();

vector<Filme> filmesCadastrados;
vector<Usuario> usuariosCadastrados;

void cadastrarFilme(){
    Filme filme;

    try {
        cout<<"Insira o nome do filme: ";
        cin>>filme.nome;
        cout<<"Insira o ano do filme: ";
        cin>>filme.ano;
        cout<<"Insira o genero do filme: ";
        cin>>filme.genero;
        cout<<"Insira uma descriçao para o filme: ";
        cin>>filme.descricao;

        filmesCadastrados.push_back(filme);

        int op;
        cout<<"Deseja cadastrar outro filme?"<<endl;
        cout<<"(1) SIM"<<endl;
        cout<<"(2) NÃO"<<endl;

        cin>>op;

        if(op == 1 ) {
            cadastrarFilme();
        } else if(op == 2) {
            opcoesGerente();
        }

    } catch(exception e) {
        cout<<"Erro no cadastro de filme"<<endl;
    }

}

void opcoesGerente() {

        int opcao;
        cout<<"Informe uma opçao para seguir:"<<endl;
        cout<<"(1) CADASTRAR FILME NO SISTEMA"<<endl;
        cout<<"(2) EDITAR FILME DO SISTEMA"<<endl;
        cout<<"(3) VOLTAR PARA O MENU PRINCIPAL"<<endl;

        cin>>opcao;

        if(opcao == 1) {
            cadastrarFilme();
        } else if (opcao == 2) {
            opcoesGerente();
        } else if(opcao == 3) {
            apresentacao();
        } else {
             cout<<"Opcao invalida"<<endl;
             opcoesGerente();
        }

}

void menuGerente(){
    string codigo;
    cout<<"Bem-vindo a sessão de gerência do sistema"<<endl;
    cout<<"Informe o codigo de permissao para continuar"<<endl;
    cin>>codigo;

    if(codigo == "admin") {
        opcoesGerente();

    } else {
        cout<<"Código incorreto!"<<endl;
        menuGerente();
    }
}


void editarFilme(){}



void selecionaUsuario(string nome){};

bool usuariosIguais(Usuario usuario1, Usuario usuario2) {
    return usuario1.cpf == usuario2.cpf;
}

bool usuarioNaoExiste(Usuario usuario) {
    bool usuarioExiste = false;
    for (int i = 0; i < usuariosCadastrados.size(); i++) {
        if (usuariosIguais(usuario, usuariosCadastrados.at(i))) {
            usuarioExiste = true;
        }
    }
    return !usuarioExiste;
    
}
void cadastrarUsuario() {
    Usuario usuario;

    // try {
        cout<<"Insira o seu nome de usuario: ";
        cin>>usuario.nome;
        cout<<"Insira o seu cpf: ";
        cin>>usuario.cpf;
        
        if(usuarioNaoExiste(usuario)) {
            usuariosCadastrados.push_back(usuario);
            cout << "Usuario cadastrado com sucesso!\n" << endl;
            menuUsuario();
        } else{
            cout << "Usuario já existe" << endl;
        }

}

void menuUsuario() {
    int opcao;
    cout << "Selecione uma opção: " << endl;
    cout << "(0) VOLTAR AO MENU PRINCIPAL" << endl;
    cout << "(1) CADASTRAR-SE" << endl;
    cout << "(2) LOGAR-SE" << endl;

    cin >> opcao;
    if(opcao == 0){
        apresentacao();
    } else if(opcao == 1) {
        cadastrarUsuario();
    } else if( opcao == 2) {
        // logarUsuario();
    }
    else{
        menuUsuario();
    } 

    // string nome;
    //     cout<<"QUAL O SEU NOME DE USUÁRIO?"<<endl;
    //     cin>>nome;
    //     selecionaUsuario(nome);


}

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

    if(opcao == 1) {
        menuGerente();
    }
    else if(opcao == 2){
        cout << "Olá, Usuário!" << endl;
        menuUsuario();
    } else {
        cout<<"SELECIONE UMA OPÇAO VALIDA!"<<endl;
        apresentacao();
    }
}



int main(){


    apresentacao();
    return 0;
}
