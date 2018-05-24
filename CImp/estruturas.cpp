#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <ctime>

using std::string;
using std::vector;
using namespace std;

struct Filme
{
    int id;
    string nome;
    int ano;
    string genero;
    string descricao;
    int quantidade;
    int quantidadeDisponivel;
    int quantidadeReservado;
};

struct Aluguel
{
    int filmeId;
    time_t data;
};

struct Usuario
{
    string cpf;
    string nome;
    vector<Aluguel> filmesAlugados;
    vector<int> filmesReservados;
};