#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>

using std::vector;
using std::string;
using std::map;
using namespace std;

struct Filme {
    int id;
    string nome;
    int ano;
    string genero;
    string descricao;
    int quantidade;
    int quantidadeDisponivel;
    int quantidadeReservado;
};

struct Aluguel{
    int filmeId;
    int data;
};

struct Usuario {
    string cpf;
    string nome;
    vector<Aluguel> filmesAlugados;
    vector<int> filmesReservados;
};

void apresentacao();
void deixarSugestao();
void adcFilmeseUsuarios();
void listarRecomendacoes();
void cadastrarFilme();
void editarFilme();
void listarFilmesAlugados();
void imprimeFilmesDisponiveis();
void descreverFilme();
void alugarFilme();
int getData();
void devolverFilme();
void listarAlugadosDevolver();
void realizarReserva();

void cadastrarUsuario();
void logarUsuario();
void menuUsuario();
void menuUsuarioLogado();

void opcoesGerente();
void menuGerente();
void limparTela();


vector<Filme> filmesCadastrados;
map<string,Usuario> usuariosCadastrados;
Usuario logadoAgora;
vector<string> sugestoes;


int main(){

    // METODO TESTE PARA POPULAR SISTEMA.
    adcFilmeseUsuarios();

    apresentacao();
    return 0;
}

//tava dando erro ai eu comentei :s
// int getData(){
 //    time_t now;
 //    struct tm nowLocal;
 //    now=time(NULL);
 //    nowLocal=*localtime(&now);
 //    return nowLocal.tm_mday;
 //}
int getData(){
    return 0;
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
    cout<<"(1) GERENTE"<<endl;
    cout<<"(2) USUÁRIO"<<endl;
    cout<<"(3) SAIR"<<endl;

    int opcao;

    cin>>opcao;

    if(opcao == 3) {}
    else if(opcao == 1) {
        limparTela();
        menuGerente();
    } else if(opcao == 2){
        limparTela();
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

void setBusinessName();

void opcoesGerente() {
        int opcao;
        cout<<"Informe uma opçao para seguir:"<<endl;
        cout<<"(1) CADASTRAR FILME NO SISTEMA"<<endl;
        cout<<"(2) EDITAR FILME DO SISTEMA"<<endl;
        cout<<"(3) LISTAR FILMES ALUGADOS"<<endl;
        cout<<"(4) LISTAR SUGESTÕES DOS USUÁRIOS"<<endl;
        cout<<"(5) VOLTAR PARA O MENU PRINCIPAL"<<endl;

        cin>>opcao;

        if(opcao == 1) {
            cadastrarFilme();
        } else if (opcao == 2) {
            editarFilme();
        } else if(opcao == 3) {
            listarFilmesAlugados();
        } else if(opcao == 4){
            listarRecomendacoes();
            opcoesGerente();

        }else if(opcao == 5) {
            apresentacao();
        } else {
             cout<<"Opcao invalida"<<endl;
             opcoesGerente();
        }
}

void listarRecomendacoes() {
    for(int i = 0; i < sugestoes.size(); i++) {
        cout<<"- " + sugestoes[i]<<endl;
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
       cout << "ERRO: Usuario já existe, tente outro!" << endl;
       menuUsuario();
    }
}


void logarUsuario(){
    cout << "Insira seu CPF: " << endl;
    string cpf;
    cin >> cpf;

    if (usuariosCadastrados.find(cpf) != usuariosCadastrados.end()) {
        cout << "Usuario encontrado!" << endl;
        cout << "Você esta logado(a)!" << endl;
        logadoAgora = usuariosCadastrados[cpf];
        cout << "Bem-vindo(a) " +  logadoAgora.nome << endl;
        menuUsuarioLogado();
    } else {
        cout << "Usuario não encontrado!" << endl;
        menuUsuario();
    }
}

void listarAlugados(){
    if (logadoAgora.filmesAlugados.size() > 0){
        cout << "Seus filmes alugados são: " << endl;
        for(int i = 0; i < logadoAgora.filmesAlugados.size(); i++){
            int filmeIndex = logadoAgora.filmesAlugados[i].filmeId;
            cout << i  << " " << filmesCadastrados[filmeIndex].nome << endl;
            // TODO:  colocar para imprimir data de devolução
        }
    } else {
        cout << "Você não tem nenhum filme alugado" << endl;
    }
    menuUsuarioLogado();
}

void listarAlugadosDevolver(){
    if(logadoAgora.filmesAlugados.size() > 0){
        for(int i = 0; i < logadoAgora.filmesAlugados.size(); i++){
            int filmeIndex = logadoAgora.filmesAlugados[i].filmeId;
            cout << i  << " " << filmesCadastrados[filmeIndex].nome << endl;
            // TODO:  colocar para imprimir data de devolução
        }
    } else {
        cout << "Você não tem nenhum filme alugado" << endl;
    }
}

void menuUsuarioLogado(){
    int opcao;
    cout << "Selecione uma opção: " << endl;
    cout << "(1) REALIZAR ALUGUEL" << endl;
    cout << "(2) REALIZAR RESERVA" << endl;
    cout << "(3) LISTAR FILMES DISPONIVEIS" << endl;
    cout << "(4) LISTAR MEUS ALUGUEIS" << endl;
    cout << "(5) DEIXAR UMA SUGESTÃO"<<endl;
    cout << "(6) DEVOLVER FILME"<<endl;
    cout << "(7) SAIR E VOLTAR AO MENU PRINCIPAL" << endl;

    cin >> opcao;

    if (opcao == 1){
        alugarFilme();
    } else if(opcao == 2) {
        realizarReserva();
    } else if (opcao == 3) {
        imprimeFilmesDisponiveis();
    } else if (opcao == 4) {
        listarAlugados();
    } else if (opcao == 5) {
        deixarSugestao();
    } else if(opcao == 6) {
        devolverFilme();
    } else if (opcao == 7) {
        //logadoAgora = NULL;
        apresentacao();
    } else {
        cout << "DIGITE UMA OPÇÃO VALIDA";
        menuUsuarioLogado();
    }
}

void realizarReserva() {
    int filmeId;

    cout << "Digite o número do filme que deseja reservar: " << endl;
    cin >> filmeId;

    if (filmesCadastrados[filmeId].quantidadeDisponivel > 0) {
        filmesCadastrados[filmeId].quantidadeReservado--;
        logadoAgora.filmesReservados.push_back(filmeId);   
        cout << "Filme reservado com sucesso!" << endl;
    } else {
        cout << "Não é possível reservar o filmes, pois não há quantidade suficiente.";       
    }

    // CONTINUAR
}

void devolverFilme(){
    int filmeIndexDevolver;

    cout << "Seus filmes alugados agora são: " << endl;
    listarAlugadosDevolver();
    
    cout << "Digite o numero do filme que deseja devolver: " << endl;
    cin >> filmeIndexDevolver;

    if(filmeIndexDevolver < logadoAgora.filmesAlugados.size()){
         int filmeId =  logadoAgora.filmesAlugados[filmeIndexDevolver].filmeId;
         filmesCadastrados[filmeId].quantidadeDisponivel++;
         logadoAgora.filmesAlugados.erase(logadoAgora.filmesAlugados.begin() + filmeIndexDevolver);
         cout << "Filme devolvido com sucesso" << endl;
    } else {
        cout << "ERRO: Digite um filme valido";
        devolverFilme();
    }

    menuUsuarioLogado();
}


void deixarSugestao() {
    string comentario = "";
    cout << "Escreva abaixo sua sugestão: " << endl;
   
    cin.ignore();
    getline(cin, comentario);

    sugestoes.push_back(comentario);

    cout<< "Obrigado por sua sugestão! Ela será avaliada pelos gerentes!" <<endl;

    int opcao;
    cout<<"Deseja deixar outra sugestão?"<<endl;
    cout<<"(1) SIM"<<endl;
    cout<<"(2) NÃO"<<endl;

    cin>>opcao;

    if(opcao == 1) {
        deixarSugestao();
    } else if(opcao == 2) {
        menuUsuarioLogado();
    } else {
        limparTela();
        cout<<"OPÇÃO INVÁLIDA"<<endl;
        menuUsuarioLogado();
    }

}

void alugarFilme(){
    cout << "Digite o número do filme que você deseja alugar:" << endl;

    Aluguel aluguel;
    cin >> aluguel.filmeId;
    aluguel.data = getData();

    Filme filme = filmesCadastrados[aluguel.filmeId];

    if(aluguel.filmeId < filmesCadastrados.size()){
        if(filme.quantidadeDisponivel > 0){
            filmesCadastrados[aluguel.filmeId].quantidadeDisponivel--;
            logadoAgora.filmesAlugados.push_back(aluguel);
            cout << "Filme: " + filme.nome + " foi alugado!" << endl;
            menuUsuarioLogado();
        }else{
            cout << "Filme indisponível para alugar" << endl; ;
            alugarFilme();
        }
    }else{
        cout << "Digite um filme válido" << endl;
        alugarFilme();
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

        filme.id = filmesCadastrados.size();
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
    cout<<"Filmes disponíveis:"<<endl;
    for(int i = 0; i < filmesCadastrados.size(); i++){
        if(filmesCadastrados[i].quantidadeDisponivel > 0){
            cout << i << " - " << filmesCadastrados[i].nome<<endl;
            cout << "Quantidade de copias disponiveis: " << filmesCadastrados[i].quantidadeDisponivel << endl;
        }
    }
    descreverFilme();
}

void descreverFilme(){
    int opcao;

    cout<<"Deseja saber mais sobre algum filme?"<<endl;
        cout<<"(1) SIM"<<endl;
        cout<<"(2) NÃO"<<endl;

    cin >> opcao;

    if(opcao == 1) {
        int filme;

        cout<<"Qual o número do filme deseja saber mais sobre?"<<endl;
        cin >> filme;

        if(filme<filmesCadastrados.size()){
            cout<<"Nome: "<<filmesCadastrados[filme].nome<<endl;
            cout<<"Quantidade: "<<filmesCadastrados[filme].quantidade<<endl;
            cout<<"Quantidade Disponivel: "<<filmesCadastrados[filme].quantidadeDisponivel<<endl;
            cout<<"Descrição: "<<filmesCadastrados[filme].descricao<<endl;
            cout<<"Ano: "<<filmesCadastrados[filme].ano<<endl;
            cout<<"Gênero: "<<filmesCadastrados[filme].genero<<endl;
        }else{
            cout<<"Filme inexistente"<<endl;
        }

        descreverFilme();
    } else if(opcao == 2) {
        menuUsuarioLogado();
    }
}

void listarFilmesAlugados() {
    int filmesAlugados = 0;

    for(int i = 0; i < filmesCadastrados.size(); i++){
        if(filmesCadastrados[i].quantidade > filmesCadastrados[i].quantidadeDisponivel){
            filmesAlugados += 1;
            cout << i << "-" << filmesCadastrados[i].nome << " - " << filmesCadastrados[i].ano << " - " << filmesCadastrados[i].genero << endl;
        }
    }

    if (filmesAlugados == 0) {
        cout << "NENHUM FILME ESTA ALUGADO NO MOMENTO" << endl;
    }

    opcoesGerente();
}

void editarFilme(){

    cout<<"----> ABAIXO ESTÃO OS FILMES CADASTRADOS NO SISTEMA <----"<<endl;
    cout<<"----> ESCOLHA O FILME NA QUAL VOCÊ DESEJA EDITAR <----"<<endl;

    int opcao;
    int opcaoFilme;
    for(int i = 0; i < filmesCadastrados.size(); i++) {
        cout<<"(";
        cout<<i;
        cout<<") ";
        cout<<filmesCadastrados[i].nome<<endl;
    }

    cout<<"Indique o numero do filme você deseja editar: ";
    cin>>opcaoFilme;


    cout<<"====> VOCÊ ESTÁ EDITANDO O FILME " +  filmesCadastrados[opcaoFilme].nome + " <==="<<endl;
    cout<<"-> Qual atributo você deseja editar?"<<endl;
    cout<<"(1) NOME"<<endl;
    cout<<"(2) ANO DE LANÇAMENTO"<<endl;
    cout<<"(3) DESCRIÇÃO"<<endl;
    cout<<"(4) QUANTIDADE"<<endl;
    cout<<"Indique com o número: ";
    cin>>opcao;


    if(opcao == 1) {
        string novoNome;
        cout<<"Indique o novo nome para o filme " +  filmesCadastrados[opcaoFilme].nome + " ";
        cin>>novoNome;
         filmesCadastrados[opcaoFilme].nome = novoNome;
        cout<<"Filme editado com sucesso!"<<endl;
    } else if(opcao == 2) {
        int novoAno;
        cout<<"Indique o novo ano de lançamento para o filme " +  filmesCadastrados[opcaoFilme].nome + " ";
        cin>>novoAno;
         filmesCadastrados[opcaoFilme].ano = novoAno;
        cout<<"Filme editado com sucesso!"<<endl;
    } else if(opcao == 3) {
        string novaDescricao;
        cout<<"Indique uma nova descrição para o filme " +  filmesCadastrados[opcaoFilme].nome + " ";
        cin>>novaDescricao;
         filmesCadastrados[opcaoFilme].descricao = novaDescricao;
        cout<<"Filme editado com sucesso!"<<endl;
    } else if(opcao == 4) {
        int novaQtd;
        cout<<"Indique a nova quantidade para o filme " +  filmesCadastrados[opcaoFilme].nome + " ";
        cin>>novaQtd;
         filmesCadastrados[opcaoFilme].quantidade = novaQtd;
        cout<<"Filme editado com sucesso!"<<endl;;
    } else {
        limparTela();
        cout<<"OPCAO INVALIDA!"<<endl;
        editarFilme();
    }

    cout<<"DESEJA EDITAR OUTRO FILME?"<<endl;
    cout<<"(1) SIM"<<endl;
    cout<<"(2) NÃO"<<endl;
    cin>>opcao;

    if(opcao == 1) {
        limparTela();
        editarFilme();
    } else {
        limparTela();
        opcoesGerente();
    }

}

  void limparTela(){
    cout << string( 100, '\n' );
    }


void selecionaUsuario(string nome){};
