#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include "estruturas.cpp"
#include "variaveis.cpp"
#include "util.cpp"
#include "opcoesGerente.cpp"
#include "opcoesUsuario.cpp"


void apresentacao() {

    while (true) {
        limparTela();
        cout<<"██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ "<<endl;
        cout<<"██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗"<<endl;
        cout<<"██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║"<<endl;
        cout<<"██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║"<<endl;
        cout<<"██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝"<<endl;
        cout<<"╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ "<<endl;

        cout<<"À LOCADORA DE FILMES"<<endl;
        cout<<"COMO VOCÊ DESEJA SEGUIR?"<<endl;
        cout<<"(1) GERENTE"<<endl;
        cout<<"(2) USUÁRIO"<<endl;
        cout<<"(3) SAIR"<<endl;

        int opcao;

        cin>>opcao;

        if(opcao == 3) {
            break;
        }
        else if(opcao == 1) {
            menuGerente();
        } else if(opcao == 2){
            menuUsuario();
        } else {
            cout<<"SELECIONE UMA OPÇAO VALIDA!"<<endl;
        }
    }
}


void adcFilmeseUsuarios(){

    Filme filme1;
    filme1.nome = "Frozen";
    filme1.quantidade = 2;
    filme1.quantidadeDisponivel = 2;
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

    filmesCadastrados[contadorFilmes] = filme1;
    contadorFilmes++;
    filmesCadastrados[contadorFilmes] = filme2;
    contadorFilmes++;

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


int main(){

    // METODO TESTE PARA POPULAR SISTEMA.
    adcFilmeseUsuarios();

    apresentacao();
    return 0;
}
