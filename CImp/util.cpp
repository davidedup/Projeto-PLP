#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctime>

void limparTela()
{
    cout << string(100, '\n');
}

time_t pegarData()
{
    time_t dataAtual = time(0);
    return dataAtual;
}