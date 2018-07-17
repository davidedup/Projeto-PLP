:- initialization(main).

% filme(cod, nome, genero, ano, descrição).
filmes( [filme(1, "Vingadores: Guerra do Infinito", "fantasia", "2018", "Homem de Ferro, Thor, Hulk e os Vingadores se unem para combater seu inimigo mais poderoso, o maligno Thanos. Em uma missão para coletar todas as seis pedras infinitas, Thanos planeja usá-las para infligir sua vontade maléfica sobre a realidade."),
filme(2, "Black Panther", "fantasia", "2018",  "Conheça a história de T'Challa, príncipe do reino de Wakanda, que perde o seu pai e viaja para os Estados Unidos, onde tem contato com os Vingadores. Entre as suas habilidades estão a velocidade, inteligência e os sentidos apurados."),
filme(3, "Deadpool 2", "fantasia", "2018", "Sequência das aventuras do Mercenário Tagarela, interpretado por Ryan Reynolds. Na história original, o herói adquire superpoderes após uma experiência científica, e decide se vingar da pessoa responsável por sequestrar sua namorada." ),
filme(4, "Oito Mulheres e um Segredo", "thriller", "2018", "Recém-saída da prisão, Debbie Ocean planeja executar o assalto do século em pleno Met Gala, em Nova York, com o apoio de Lou, Nine Ball, Amita, Constance, Rose, Daphne Kluger e Tammy."),
filme(5, "A Origem", "ficção", "2010", "Don Cobb é um ladrão que invade os sonhos das pessoas e rouba segredos do subconsciente. As habilidades especiais de Cobb fazem com que ele seja procurado pelo mundo da espionagem empresarial, mas lhe custa tudo que ama. Cobb recebe uma missão impossível: plantar uma ideia na mente de uma pessoa. Se for bem-sucedido, será o crime perfeito, mas um amigo prevê todos os passos de Cobb."),
filme(6, "Moulin Rouge: Amor em Vermelho","romance", "2001", "Don Cobb é um ladrão que invade os sonhos das pessoas e rouba segredos do subconsciente. As habilidades especiais de Cobb fazem com que ele seja procurado pelo mundo da espionagem empresarial, mas lhe custa tudo que ama. Cobb recebe uma missão impossível: plantar uma ideia na mente de uma pessoa. Se for bem-sucedido, será o crime perfeito, mas um amigo prevê todos os passos de Cobb.")]  ).

% colocar resto dos filmes...zzzz

menu() :- 
    writeln("██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ "),
	writeln("██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗"),
	writeln("██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║"),
	writeln("██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║"),
	writeln("██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝"),
	writeln("╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ ").                    

imprimeFilmes() :- filmes([H|T]), writeln(H), imprimeFilmes(T).
imprimeFilmes([H|T]) :- writeln(H), imprimeFilmes(T).

opcao(1) :- imprimeFilmes().
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

