
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
using std::vector;
using std::string;
using std::map;
using namespace std;

struct Filme {
    string nome;
    int ano;
    string genero;
    string descricao;
    int quantidade;
    int quantidadeDisponivel;
};

struct Usuario {
    string cpf;
    string nome;
};

void apresentacao();

void adcFilmeseUsuarios();

void cadastrarFilme();
void editarFilme();
void imprimeFilmesDisponiveis();

void cadastrarUsuario();
void logarUsuario();
void menuUsuario();
void menuUsuarioLogado();

void opcoesGerente();
void menuGerente();


vector<Filme> filmesCadastrados;
map<string,Usuario> usuariosCadastrados;


int main(){

    adcFilmeseUsuarios();

    apresentacao();
    return 0;
}


void adcFilmeseUsuarios(){

    Filme filme1;
    filme1.nome = "Frozen";
    filme1.quantidade = 10;
    filme1.quantidadeDisponivel = 10;
    filme1.descricao = "um otimo filme de criança";
    filme1.ano = 2016;
    filme1.genero = "infantil";

    Filme filme2;
    filme2.nome = "Vingadores";
    filme2.quantidade = 15;
    filme2.quantidadeDisponivel = 15;
    filme2.descricao = "Filme de açao e super heroi";
    filme2.ano = 2018;
    filme2.genero = "ação";

    filmesCadastrados.push_back(filme1);
    filmesCadastrados.push_back(filme2);

    Usuario david;
    david.nome = "David";
    david.cpf = "123";

    Usuario mariana;
    mariana.nome = "Mariana";
    mariana.cpf = "001";

    Usuario marcos;

    marcos.nome = "Marcos";
    marcos.cpf = "002";

    usuariosCadastrados[david.cpf] = david;
    usuariosCadastrados[mariana.cpf] = mariana;
    usuariosCadastrados[marcos.cpf] = marcos;
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
    cout<<"(3)SAIR"<<endl;

    int opcao;

    cin>>opcao;

    if(opcao == 3) {}
    else if(opcao == 1) {
        menuGerente();
    } else if(opcao == 2){
        cout << "Olá, Usuário!" << endl;
        menuUsuario();
    } else {
        cout<<"SELECIONE UMA OPÇAO VALIDA!"<<endl;
        apresentacao();
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


void menuUsuario() {
    int opcao;
    cout << "Selecione uma opção: " << endl;
    cout << "(1) CADASTRAR-SE" << endl;
    cout << "(2) LOGAR-SE" << endl;
    cout << "(3) VOLTAR AO MENU PRINCIPAL" << endl;

    cin >> opcao;
    if(opcao == 1) {
        cadastrarUsuario();
    } else if( opcao == 2) {
        logarUsuario();
    } else if(opcao == 3){
        apresentacao();
    } else{
        menuUsuario();
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
            // TODO editar filme do sistema
        } else if(opcao == 3) {
            apresentacao();
        } else {
             cout<<"Opcao invalida"<<endl;
             opcoesGerente();
        }
}


void cadastrarUsuario() {
    Usuario usuario;

    cout<<"Insira o seu nome de usuario: ";
    cin>>usuario.nome;
    cout<<"Insira o seu cpf: ";
    cin>>usuario.cpf;

    if (usuariosCadastrados.find(usuario.cpf) == usuariosCadastrados.end()) {
        usuariosCadastrados[usuario.cpf] = usuario;
        cout << "Usuario cadastrado com sucesso!\n" << endl;
        menuUsuario();
    } else {
        cout << "Usuario já existe" << endl;
    }
}


void logarUsuario(){
    cout << "Insira seu CPF: " << endl;
    string cpf;
    cin >> cpf;

    if (usuariosCadastrados.find(cpf) != usuariosCadastrados.end()) {
        cout << "Usuario encontrado!" << endl;
        cout << "Você esta logado(a)!" << endl;
        menuUsuarioLogado();
    } else {
        cout << "Usuario não encontrado!" << endl;
        menuUsuario();
    }
}


void menuUsuarioLogado(){
    int opcao;
    cout << "Selecione uma opção: " << endl;
    cout << "(0) REALIZAR ALUGEL" << endl;
    cout << "(1) REALIZAR RESERVA" << endl;
    cout << "(2) LISTAR FILMES DISPONIVEIS" << endl;
    cout << "(3) SAIR E VOLTAR AO MENU PRINCIPAL" << endl;

    if (opcao == 0){
        // Realizar aluguel
    } else if(opcao == 1) {
        // Realizar reserva
    } else if (opcao == 2) {
        imprimeFilmesDisponiveis();
    } else if (opcao == 3) {
        apresentacao();
    } else {
        cout << "DIGITE UMA OPÇÃO VALIDA";
        menuUsuarioLogado();
    }
}


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
        cout<<"Insira a quantidade de copias: ";
        cin>>filme.quantidade;

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


void imprimeFilmesDisponiveis(){
    for(int i = 0; i < filmesCadastrados.size(); i++){
        if(filmesCadastrados[i].quantidadeDisponivel > 0){
            cout << filmesCadastrados[i].nome << " - " << filmesCadastrados[i].ano << " - " << filmesCadastrados[i].genero << endl;
        }
    }
}


void editarFilme(){}

void selecionaUsuario(string nome){};
