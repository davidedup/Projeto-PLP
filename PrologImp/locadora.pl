:- initialization(main).

% filme(cod, nome, genero, ano, descrição).
filme(1, "Vingadores: Guerra do Infinito", "fantasia", "2018", "Homem de Ferro, Thor, Hulk e os Vingadores se unem para combater seu inimigo mais poderoso, o maligno Thanos. Em uma missão para coletar todas as seis pedras infinitas, Thanos planeja usá-las para infligir sua vontade maléfica sobre a realidade.").
filme(2, "Black Panther", "fantasia", "2018",  "Conheça a história de T'Challa, príncipe do reino de Wakanda, que perde o seu pai e viaja para os Estados Unidos, onde tem contato com os Vingadores. Entre as suas habilidades estão a velocidade, inteligência e os sentidos apurados.").
% colocar resto dos filmes, como não sei se vai ser assim mesmo não coloquei 

menu() :- 
    writeln("██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ "),
	writeln("██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗"),
	writeln("██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║"),
	writeln("██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║"),
	writeln("██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝"),
	writeln("╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ ").                    

opcao(1) :- filme(Codigo, Nome, _, _, _),write(Codigo), write("- "), writeln(Nome).
% Só ta imprimindo o primeiro!!!!
opcao(2) :- write("Lista disponiveis").
opcao(3) :- write("Lisa alugados").
opcao(4) :- write("Realiza aluguel").
opcao(5) :- write("Realiza devolução").
opcao(6) :- write("Lista por genero").
opcao(7) :- write("Enviar sugestão de filmes").
opcao(8) :- write("Vizualizar sugestões").

menuOpcoes() :- 
    writeln("0 - Sair"), 
    writeln("1 - Listar todos filmes"),
    writeln("2 - Listar filmes disponiveis"),
    writeln("3 - Listar os seus filmes alugados"),
    writeln("4 - Realizar Aluguel"),
    writeln("5 - Realizar Devolução"),
    writeln("6 - Listar filmes por genero"),
    writeln("7 - Enviar sugestão de filme"),
    writeln("8 - Visuzalizar suas sugestões de filmes"),
    writeln("\nOpcao: "),
    read(A),
    opcao(A),
    menuOpcoes().

main :-
    menu(),
    menuOpcoes().

