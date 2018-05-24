#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctime>

using std::string;
using namespace std;


void imprimeFilmesDoSistema() {
    cout<<"----> ABAIXO ESTÃO OS FILMES CADASTRADOS NO SISTEMA <----"<<endl;

    for(int i = 0; i < contadorFilmes; i++) {
        if (filmesCadastrados.find(i) != filmesCadastrados.end()) {
            cout<<"(" << i << ") " << filmesCadastrados[i].nome << endl;
        }
    }
}


Filme pegaInfoFilme() {
    Filme filme;
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
    filme.id = contadorFilmes;

    return filme;
}


void cadastrarFilme(){
    try {
        int opcao = 1;
        while (opcao != 2) {
            limparTela();
            Filme filme;
            filme = pegaInfoFilme();

            filmesCadastrados[contadorFilmes] = filme;
            contadorFilmes++;

            int op;
            cout<<"Deseja cadastrar outro filme?"<<endl;
            cout<<"(1) SIM"<<endl;
            cout<<"(2) NÃO"<<endl;

            cin>>opcao;
        }
    } catch(exception e) {
        cout<<"Erro no cadastro de filme"<<endl;
    }
}


int imprimeOpcoesDeEdicao(int opcaoFilme) {
    int opcao;
    cout<<"====> VOCÊ ESTÁ EDITANDO O FILME " +  filmesCadastrados[opcaoFilme].nome + " <===="<<endl;
    cout<<"-> Qual atributo você deseja editar?"<<endl;
    cout<<"(1) NOME"<<endl;
    cout<<"(2) ANO DE LANÇAMENTO"<<endl;
    cout<<"(3) DESCRIÇÃO"<<endl;
    cout<<"(4) QUANTIDADE"<<endl;
    cout<<"Indique com o número: ";

    cin>>opcao;
    return opcao;
}


void editarNomeFilme(int opcaoFilme) {
    string novoNome;
    cout<<"Indique o novo nome para o filme '" +  filmesCadastrados[opcaoFilme].nome + "': ";
    cin>>novoNome;
    filmesCadastrados[opcaoFilme].nome = novoNome;
    cout<<"Filme editado com sucesso!"<<endl;
}


void editarAnoDeLancFilme(int opcaoFilme) {
    int novoAno;
    cout<<"Indique o novo ano de lançamento para o filme '" +  filmesCadastrados[opcaoFilme].nome + "': ";
    cin>>novoAno;
    filmesCadastrados[opcaoFilme].ano = novoAno;
    cout<<"Filme editado com sucesso!"<<endl;
}


void editarDescricaoFilme(int opcaoFilme) {
    string novaDescricao;
    cout<<"Indique uma nova descrição para o filme '" +  filmesCadastrados[opcaoFilme].nome + "': ";
    cin>>novaDescricao;
    filmesCadastrados[opcaoFilme].descricao = novaDescricao;
    cout<<"Filme editado com sucesso!"<<endl;
}


void editarQuantFilme(int opcaoFilme) {
    int novaQtd;
    cout<<"Indique a nova quantidade para o filme '" +  filmesCadastrados[opcaoFilme].nome + "': ";
    cin>>novaQtd;
    filmesCadastrados[opcaoFilme].quantidade = novaQtd;
    cout<<"Filme editado com sucesso!"<<endl;
}


void editarFilme(){
    int opcaoMenu = 1;
    while (opcaoMenu != 2) {
        limparTela();
        int opcao;
        int opcaoFilme;

        imprimeFilmesDoSistema();

        cout<<"Indique o numero do filme você deseja editar: ";
        cin >> opcaoFilme;
        opcao = imprimeOpcoesDeEdicao(opcaoFilme);

        if(opcao == 1) {
            editarNomeFilme(opcaoFilme);
        } else if(opcao == 2) {
            editarAnoDeLancFilme(opcaoFilme);
        } else if(opcao == 3) {
            editarDescricaoFilme(opcaoFilme);
        } else if(opcao == 4) {
            editarQuantFilme(opcaoFilme);
        } else {
            cout<<"OPCAO INVALIDA!"<<endl;
        }

        cout<<"DESEJA EDITAR OUTRO FILME?"<<endl;
        cout<<"(1) SIM"<<endl;
        cout<<"(2) NÃO"<<endl;
        cin>> opcaoMenu;
    }
}


void listarFilmesAlugados() {
    int opcao = 0;
    while (opcao != 1) {
        limparTela();
        int filmesAlugados = 0;

        for(int i = 0; i < contadorFilmes; i++){
            if(filmesCadastrados.find(i) != filmesCadastrados.end()) {
                Filme filme = filmesCadastrados[i];
                if (filme.quantidade > filme.quantidadeDisponivel + filme.quantidadeReservado){
                    filmesAlugados += 1;
                    cout << i << "-" << filmesCadastrados[i].nome << " - " << filmesCadastrados[i].ano << " - " << filmesCadastrados[i].genero << endl;
                }
            }
        }

        if (filmesAlugados == 0) {
            cout << "NENHUM FILME ESTA ALUGADO NO MOMENTO" << endl;
        }

        cout << "(1) VOLTAR AO MENU" << endl;
        cin >> opcao;
    }
}


void listarSugestoes() {
    int opcao = 0;
    while (opcao != 1) {
        limparTela();

        for(int i = 0; i < sugestoes.size(); i++) {
            cout<<"- " + sugestoes[i]<<endl;
        }

        if (sugestoes.size() == 0) {
            cout << "NÃO HÁ SUGESTÕES DE USUÁRIOS." << endl;
        }
        
        cout << "(1) VOLTAR AO MENU" << endl;
        cin >> opcao;
    }
}


void deletarFilme() {
    limparTela();
    int indexFilme;

    imprimeFilmesDoSistema();

    cout << "Insira o número do filme que deseja deletar do sistema:" << endl;
    cin >> indexFilme;

    if (filmesCadastrados.find(indexFilme) == filmesCadastrados.end()) {
        cout << "Filme não existente no sistema." << endl;
    } else {
        filmesCadastrados.erase(indexFilme);
        cout << "Filme deletado com sucesso." << endl;
    }
}


void opcoesGerente() {
    while(true) {
        limparTela();
        int opcao;
        cout<<"Informe uma opçao para seguir:"<<endl;
        cout<<"(1) CADASTRAR FILME NO SISTEMA"<<endl;
        cout<<"(2) EDITAR FILME DO SISTEMA"<<endl;
        cout<<"(3) LISTAR FILMES ALUGADOS"<<endl;
        cout<<"(4) LISTAR SUGESTÕES DOS USUÁRIOS"<<endl;
        cout<<"(5) DELETAR FILME DO SISTEMA"<<endl;
        cout<<"(6) VOLTAR PARA O MENU PRINCIPAL"<<endl;

        cin>>opcao;

        if(opcao == 1) {
            cadastrarFilme();
        } else if (opcao == 2) {
            editarFilme();
        } else if(opcao == 3) {
            listarFilmesAlugados();
        } else if(opcao == 4){
            listarSugestoes();
        } else if (opcao == 5) {
            deletarFilme();
        } else if(opcao == 6) {
            break;
        } else {
             cout<<"Opcao invalida"<<endl;
        }
    }
}


void menuGerente(){
    limparTela();
    string codigo;
    cout<<"Bem-vindo a sessão de gerência do sistema"<<endl;
    cout<<"Informe o codigo de permissao para continuar"<<endl;
    cin>>codigo;

    if(codigo == "admin") {
        opcoesGerente();
    } else {
        cout<<"Código incorreto!"<<endl;
    }
}