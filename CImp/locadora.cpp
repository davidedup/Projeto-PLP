
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
void editarFilme();
void opcoesGerente();
void menuUsuario();
void logarUsuario();

vector<Filme> filmesCadastrados;
vector<Usuario> usuariosCadastrados;
map<string,Usuario> usuariossCadastrados;


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

        if (usuariossCadastrados.find(usuario.cpf) == usuariossCadastrados.end()) {
            usuariossCadastrados[usuario.cpf] = usuario;
            cout << "Usuario cadastrado com sucesso!\n" << endl;
            menuUsuario();
        } else {
            cout << "Usuario já existe" << endl;
        }

        /*
        if(usuarioNaoExiste(usuario)) {
            usuariosCadastrados.push_back(usuario);
            cout << "Usuario cadastrado com sucesso!\n" << endl;
            menuUsuario();
        } else{
            cout << "Usuario já existe" << endl;
        }
        */

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
        logarUsuario();
    }
    else{
        menuUsuario();
    }

    // string nome;
    //     cout<<"QUAL O SEU NOME DE USUÁRIO?"<<endl;
    //     cin>>nome;
    //     selecionaUsuario(nome);
}

void imprimeFilmesDisponiveis(){

    for(int i = 0; i < filmesCadastrados.size(); i++){
        if(filmesCadastrados[i].quantidadeDisponivel > 0){
            cout << filmesCadastrados[i].nome << " - " << filmesCadastrados[i].ano << " - " << filmesCadastrados[i].genero << endl;
        }
    }

}

void menuUsuarioLogado(){
    int opcao;
    cout << "Selecione uma opção: " << endl;
    cout << "(0) REALIZAR ALUGEL" << endl;
    cout << "(1) REALIZAR RESERVA" << endl;
    cout << "(2) LISTAR FILMES DISPONIVEIS" << endl;
    cout << "(3) SAIR E VOLTAR AO MENU PRINCIPAL" << endl;

    if(opcao == 0){
        // Realizar aluguel
    } else if(opcao == 1) {
        // Realizar reserva
    } else if( opcao == 2) {
        imprimeFilmesDisponiveis();
    } else if( opcao == 3) {
        apresentacao();
    }else{
        cout << "DIGITE UMA OPÇÃO VALIDA";
        menuUsuarioLogado();
    }

}

void logarUsuario(){
    cout << "Insira seu CPF: " << endl;
    string cpf;
    cin >> cpf;

    if (usuariossCadastrados.find(cpf) != usuariossCadastrados.end()) {
        cout << "Usuario encontrado!" << endl;
        cout << "Você esta logado(a)!" << endl;
        menuUsuarioLogado();
    } else {
        cout << "Usuario não encontrado!" << endl;
        menuUsuario();
    }


    /*
    for(int i = 0; i < usuariosCadastrados.size(); i++){
        if(usuariosCadastrados[i].cpf == cpf){
            cout << "Usuario encontrado!" << endl;
            cout << "Você esta logado(a)!" << endl;
            menuUsuarioLogado();
        }
    }
    */

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

    usuariosCadastrados.push_back(david);
    usuariosCadastrados.push_back(mariana);
    usuariosCadastrados.push_back(marcos);

}

int main(){

    adcFilmeseUsuarios();

    apresentacao();
    return 0;
}
