#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctime>

void listarAlugados()
{
    int opcao = 0;
    while (opcao != 1)
    {
        limparTela();
        if (logadoAgora.filmesAlugados.size() > 0)
        {
            cout << "Seus filmes alugados são: " << endl;
            for (int i = 0; i < logadoAgora.filmesAlugados.size(); i++)
            {
                int filmeId = logadoAgora.filmesAlugados[i].filmeId;
                cout << i << " - " << filmesCadastrados[filmeId].nome << endl;
            }
        }
        else
        {
            cout << "Você não tem nenhum filme alugado" << endl;
        }

        cout << "(1) VOLTAR AO MENU" << endl;
        cin >> opcao;
    }
}

void listarReservados()
{
    int opcao = 0;
    while (opcao != 1)
    {
        limparTela();
        if (logadoAgora.filmesReservados.size() > 0)
        {
            cout << "Seus filmes alugados são: " << endl;
            for (int i = 0; i < logadoAgora.filmesReservados.size(); i++)
            {
                int filmeId = logadoAgora.filmesReservados[i];
                cout << i << " - " << filmesCadastrados[filmeId].nome << endl;
            }
        }
        else
        {
            cout << "Você não tem nenhum filme reservado" << endl;
        }

        cout << "(1) VOLTAR AO MENU" << endl;
        cin >> opcao;
    }
}

void imprimeDescricaoFilme(int filmeIndex)
{
    cout << "Nome: " << filmesCadastrados[filmeIndex].nome << endl;
    cout << "Quantidade: " << filmesCadastrados[filmeIndex].quantidade << endl;
    cout << "Quantidade Disponivel: " << filmesCadastrados[filmeIndex].quantidadeDisponivel << endl;
    cout << "Descrição: " << filmesCadastrados[filmeIndex].descricao << endl;
    cout << "Ano: " << filmesCadastrados[filmeIndex].ano << endl;
    cout << "Gênero: " << filmesCadastrados[filmeIndex].genero << endl;
}

void cadastrarUsuario()
{
    limparTela();
    Usuario usuario;

    cout << "Insira o seu nome de usuario: ";
    cin.ignore();
    getline(cin, usuario.nome);
    cout << "Insira o seu cpf: ";
    cin >> usuario.cpf;

    if (usuariosCadastrados.find(usuario.cpf) == usuariosCadastrados.end())
    {
        usuariosCadastrados[usuario.cpf] = usuario;
        cout << "Usuario cadastrado com sucesso!" << endl;
    }
    else
    {
        cout << "ERRO: Usuario já existe, tente outro!" << endl;
    }

    int opcao = 0;
    while (opcao != 1)
    {
        cout << "(1) VOLTAR PARA O MENU" << endl;
        cin >> opcao;
    }
}

int estahAlugado(int filmeId)
{
    for (int i = 0; i < logadoAgora.filmesReservados.size(); i++)
    {
        if (logadoAgora.filmesReservados[i] == filmeId)
        {
            logadoAgora.filmesReservados.erase(logadoAgora.filmesReservados.begin() + i);
            return 1;
        }
    }
    return 0;
}

void alugarFilmeReservado(Filme filme, int filmeId, Aluguel aluguel)
{
    int opcao = 0;
    while (opcao != 1)
    {
        if (estahAlugado(filmeId) == 1)
        {
            filmesCadastrados[filmeId].quantidadeReservado--;
            logadoAgora.filmesAlugados.push_back(aluguel);
            cout << "Filme: " + filme.nome + " foi alugado!" << endl;
        }
        else
        {
            cout << filme.nome + " não estava reservado para você" << endl;
        }
        cout << "(1) VOLTAR PARA O MENU" << endl;
        cin >> opcao;
    }
}

void realizarAluguel(Filme filme, int filmeId, Aluguel aluguel)
{
    int opcao = 0;
    while (opcao != 1)
    {
        if (filme.quantidadeDisponivel > 0)
        {
            filmesCadastrados[filmeId].quantidadeDisponivel--;
            logadoAgora.filmesAlugados.push_back(aluguel);
            cout << "Filme: " + filme.nome + " foi alugado!" << endl;
        }
        else
        {
            cout << "Filme indisponível para alugar" << endl;
        }
        cout << "(1) VOLTAR PARA O MENU" << endl;
        cin >> opcao;
    }
}

void alugarFilme()
{
    while (true)
    {
        limparTela();
        cout << "Digite o número do filme que você deseja alugar: ";

        int filmeId;
        Aluguel aluguel;
        cin >> filmeId;

        aluguel.filmeId = filmeId;
        aluguel.data = pegarData();

        Filme filme = filmesCadastrados[aluguel.filmeId];

        cout << "Esse filme estava reservado por você?" << endl;
        cout << "(1) SIM" << endl;
        cout << "(2) NÃO" << endl;

        int opcaoReservado;
        cin >> opcaoReservado;

        if (filmesCadastrados.find(filmeId) != filmesCadastrados.end())
        {
            if (opcaoReservado == 1)
            {
                alugarFilmeReservado(filme, filmeId, aluguel);
            }
            else
            {
                realizarAluguel(filme, filmeId, aluguel);
            }
            break;
        }
        else
        {
            cout << "Digite um filme válido" << endl;
        }
    }
}

void realizarReserva()
{
    limparTela();

    int opcao = 0;
    while (opcao != 2)
    {
        int filmeId;

        cout << "Digite o número do filme que deseja reservar: ";
        cin >> filmeId;

        if (filmesCadastrados[filmeId].quantidadeDisponivel > 0)
        {
            filmesCadastrados[filmeId].quantidadeReservado++;
            filmesCadastrados[filmeId].quantidadeDisponivel--;
            logadoAgora.filmesReservados.push_back(filmeId);
            cout << "Filme reservado com sucesso!" << endl;
        }
        else
        {
            cout << "Não é possível reservar o filme, pois não há quantidade suficiente." << endl;
        }

        cout << "(1) REALIZAR OUTRA RESERVA" << endl;
        cout << "(2) VOLTAR PARA O MENU" << endl;
        cin >> opcao;
    }
}

void descreverFilme()
{
    int opcao = 1;
    while (opcao != 2)
    {
        cout << "Deseja saber mais sobre algum filme? " << endl;
        cout << "(1) SIM" << endl;
        cout << "(2) NÃO" << endl;
        cin >> opcao;

        if (opcao == 1)
        {
            int filmeIndex;
            cout << "Qual o número do filme deseja saber mais sobre? ";
            cin >> filmeIndex;

            if (filmeIndex < contadorFilmes)
            {
                imprimeDescricaoFilme(filmeIndex);
            }
            else
            {
                cout << "Filme inexistente" << endl;
            }
        }
    }
}

void imprimeFilmesDisponiveis()
{
    limparTela();
    cout << "Filmes disponíveis:" << endl;
    for (int i = 0; i < contadorFilmes; i++)
    {
        if (filmesCadastrados.find(i) != filmesCadastrados.end() and
            filmesCadastrados[i].quantidadeDisponivel > 0)
        {
            cout << i << " - " << filmesCadastrados[i].nome << endl;
            cout << "-> Quantidade de copias disponiveis: " << filmesCadastrados[i].quantidadeDisponivel << endl;
        }
    }

    if (filmesCadastrados.size() == 0)
    {
        cout << "A LOCADORA NÃO TEM FILMES NO MOMENTO." << endl;
    }
    else
    {
        descreverFilme();
    }
}

void deixarSugestao()
{
    while (true)
    {
        limparTela();
        string comentario = "";
        cout << "Escreva abaixo sua sugestão: " << endl;

        cin.ignore();
        getline(cin, comentario);

        sugestoes.push_back(comentario);

        cout << "Obrigado por sua sugestão! Ela será avaliada pelos gerentes!" << endl;

        int opcao;
        cout << "Deseja deixar outra sugestão?" << endl;
        cout << "(1) SIM" << endl;
        cout << "(2) NÃO" << endl;

        cin >> opcao;

        if (opcao == 2)
        {
            break;
        }
        else
        {
            limparTela();
            cout << "OPÇÃO INVÁLIDA" << endl;
        }
    }
}

void devolverFilme(int filmeIndexDevolver)
{
    time_t data_entrega = pegarData();
    int filmeId = logadoAgora.filmesAlugados[filmeIndexDevolver].filmeId;
    filmesCadastrados[filmeId].quantidadeDisponivel++;

    int doisDiasEmSegundos = 172800;
    if (logadoAgora.filmesAlugados[filmeIndexDevolver].data + doisDiasEmSegundos < data_entrega)
    {
        cout << "Você precisará pagar uma multa pois atrasou a devolução do filme (limite de 2 dias)." << endl;
    }

    cout << "Filme devolvido com sucesso" << endl;
    logadoAgora.filmesAlugados.erase(logadoAgora.filmesAlugados.begin() + filmeIndexDevolver);
}

void listarAlugadosDevolver()
{
    cout << "Seus filmes alugados agora são: " << endl;
    for (int i = 0; i < logadoAgora.filmesAlugados.size(); i++)
    {
        int filmeId = logadoAgora.filmesAlugados[i].filmeId;
        cout << i << " - " << filmesCadastrados[filmeId].nome << endl;
    }
}

void devolverFilme()
{
    int opcao = 0;
    while (opcao != 1)
    {
        limparTela();
        int filmeIndexDevolver;

        if (logadoAgora.filmesAlugados.size() == 0)
        {
            cout << "Você não tem nenhum filme alugado" << endl;
        }
        else
        {
            listarAlugadosDevolver();

            cout << "Digite o numero do filme que deseja devolver: ";
            cin >> filmeIndexDevolver;

            if (filmeIndexDevolver < logadoAgora.filmesAlugados.size())
            {
                devolverFilme(filmeIndexDevolver);
            }
            else
            {
                cout << "ERRO: Digite um filme valido";
            }
        }

        cout << "(1) VOLTAR AO MENU" << endl;
        cin >> opcao;
    }
}

void menuUsuarioLogado()
{
    while (true)
    {
        limparTela();
        int opcao;
        cout << "Selecione uma opção: " << endl;
        cout << "(1) REALIZAR ALUGUEL" << endl;
        cout << "(2) REALIZAR RESERVA" << endl;
        cout << "(3) LISTAR FILMES DISPONIVEIS" << endl;
        cout << "(4) LISTAR MEUS ALUGUEIS" << endl;
        cout << "(5) LISTAR MEUS RESERVADOS" << endl;
        cout << "(6) DEIXAR UMA SUGESTÃO" << endl;
        cout << "(7) DEVOLVER FILME" << endl;
        cout << "(8) SAIR E VOLTAR AO MENU PRINCIPAL" << endl;

        cin >> opcao;

        if (opcao == 1)
        {
            alugarFilme();
        }
        else if (opcao == 2)
        {
            realizarReserva();
        }
        else if (opcao == 3)
        {
            imprimeFilmesDisponiveis();
        }
        else if (opcao == 4)
        {
            listarAlugados();
        }
        else if (opcao == 5)
        {
            listarReservados();
        }
        else if (opcao == 6)
        {
            deixarSugestao();
        }
        else if (opcao == 7)
        {
            devolverFilme();
        }
        else if (opcao == 8)
        {
            break;
        }
        else
        {
            cout << "DIGITE UMA OPÇÃO VALIDA";
        }
    }
}

void logarUsuario()
{
    limparTela();
    cout << "Insira seu CPF: " << endl;
    string cpf;
    cin >> cpf;

    if (usuariosCadastrados.find(cpf) != usuariosCadastrados.end())
    {
        cout << "Usuario encontrado!" << endl;
        cout << "Você esta logado(a)!" << endl;
        logadoAgora = usuariosCadastrados[cpf];
        cout << "Bem-vindo(a) " + logadoAgora.nome << endl;
        menuUsuarioLogado();
    }
    else
    {
        cout << "Usuario não encontrado!" << endl;
    }
}

void menuUsuario()
{
    while (true)
    {
        limparTela();
        cout << "Olá, Usuário!" << endl;

        int opcao;
        cout << "Selecione uma opção: " << endl;
        cout << "(1) CADASTRAR-SE" << endl;
        cout << "(2) LOGAR-SE" << endl;
        cout << "(3) VOLTAR AO MENU PRINCIPAL" << endl;

        cin >> opcao;
        if (opcao == 1)
        {
            cadastrarUsuario();
        }
        else if (opcao == 2)
        {
            logarUsuario();
        }
        else if (opcao == 3)
        {
            break;
        }
    }
}
