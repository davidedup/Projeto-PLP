#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <ctime>

using std::vector;
using std::string;
using std::map;
using namespace std;


int contadorFilmes = 0;
map<int, Filme> filmesCadastrados;
map<string,Usuario> usuariosCadastrados;
Usuario logadoAgora;
vector<string> sugestoes;