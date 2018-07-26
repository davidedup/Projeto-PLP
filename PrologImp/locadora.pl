:- initialization(main).

:- dynamic
	alugado(filme(_,_,_,_,_)).

% filme(cod, nome, genero, ano, descrição).
filme(1, "Vingadores: Guerra do Infinito", 'fantasia', "2018", "Homem de Ferro, Thor, Hulk e os Vingadores se unem para combater seu inimigo mais poderoso, o maligno Thanos. Em uma missão para coletar todas as seis pedras infinitas, Thanos planeja usá-las para infligir sua vontade maléfica sobre a realidade.").
filme(2, "Black Panther", 'fantasia', "2018",  "Conheça a história de T'Challa, príncipe do reino de Wakanda, que perde o seu pai e viaja para os Estados Unidos, onde tem contato com os Vingadores. Entre as suas habilidades estão a velocidade, inteligência e os sentidos apurados.").
filme(3, "Deadpool 2", 'fantasia', "2018", "Sequência das aventuras do Mercenário Tagarela, interpretado por Ryan Reynolds. Na história original, o herói adquire superpoderes após uma experiência científica, e decide se vingar da pessoa responsável por sequestrar sua namorada." ).
filme(4, "Oito Mulheres e um Segredo", 'thriller', "2018", "Recém-saída da prisão, Debbie Ocean planeja executar o assalto do século em pleno Met Gala, em Nova York, com o apoio de Lou, Nine Ball, Amita, Constance, Rose, Daphne Kluger e Tammy.").
filme(5, "A Origem", 'ficção', "2010", "Don Cobb é um ladrão que invade os sonhos das pessoas e rouba segredos do subconsciente. As habilidades especiais de Cobb fazem com que ele seja procurado pelo mundo da espionagem empresarial, mas lhe custa tudo que ama. Cobb recebe uma missão impossível: plantar uma ideia na mente de uma pessoa. Se for bem-sucedido, será o crime perfeito, mas um amigo prevê todos os passos de Cobb.").
filme(6, "Moulin Rouge: Amor em Vermelho",'romance', "2001", "Don Cobb é um ladrão que invade os sonhos das pessoas e rouba segredos do subconsciente. As habilidades especiais de Cobb fazem com que ele seja procurado pelo mundo da espionagem empresarial, mas lhe custa tudo que ama. Cobb recebe uma missão impossível: plantar uma ideia na mente de uma pessoa. Se for bem-sucedido, será o crime perfeito, mas um amigo prevê todos os passos de Cobb.").
filme(7, "Brilho eterno de uma mente sem lembranças", 'drama', "2004", "Joel se surpreende ao saber que seu amor verdadeiro, Clementine, o apagou completamente de sua memória. Ele decide fazer o mesmo, mas muda de ideia. Preso dentro da própria mente enquanto os especialistas se mantêm ocupados em seu apartamento, Joel precisa avisá-los para parar.").
filme(8, "Donnie Darko", 'drama', "2001", "Donnie é um jovem excêntrico que despreza a grande maioria de seus colegas de escola. Ele tem visões, em especial de Frank, um coelho gigante que só ele consegue ver e que o encoraja a fazer brincadeiras humilhantes com quem o cerca. Um dia, uma de suas visões o atrai para fora de casa e lhe diz q'ue o mundo acabará dentro de um mês. Donnie inicialmente não acredita, mas, momentos depois, a turbina de um avião cai em sua casa e ele começa a se perguntar qual é o fundo de verdade dessa previsão.").
% colocar resto dos filmes...zzzz

sugestao(""). %sugestao("Sugestes para a locadora2").     

menu() :- 
	writeln("██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ "),
	writeln("██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗"),
	writeln("██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║"),
	writeln("██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║"),
	writeln("██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝"),
	writeln("╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ ").       

opcao(0) :- halt.

opcao(1) :- imprimeFilmes().

opcao(2) :- writeln("Abaixo estao os filmes disponiveis para aluguel:"),
			listaDisponiveis().
					
opcao(3) :- listaAlugados().
	
opcao(4) :- write("Digite o codigo do Filme que deseja alugar:"),
			read(Cod),
			verificaFilme(Cod),
			filme(Cod, Nome, Ano, Genero, Descricao),                                  
			realizaAluguel(Cod, Nome, Ano, Genero, Descricao).
		
opcao(5) :- write("Realiza devolução").

opcao(6) :- write("Digite o nome do genero que voce deseja filtrar:"),
			read(Genero),
			listarPorGenero(Genero).
	
opcao(7) :- writeln("Escreva sua sugestão:"),
			read(S),
			enviarSugestao(S).
		
opcao(8) :- listaSugestoes().
	
opcao(X) :- writeln("Opcao invalida, tente outra!").
				
menuOpcoes() :- 
	writeln("\nUse sempre um ponto no final de cada instrucao"), 
	writeln("0 - Sair"), 
	writeln("1 - Listar todos filmes"),
	writeln("2 - Listar filmes disponiveis"),
	writeln("3 - Listar os seus filmes alugados"),
	writeln("4 - Realizar Aluguel"),
	writeln("5 - Realizar Devolução"),
	writeln("6 - Listar filmes por genero"),
	writeln("7 - Enviar sugestão de filme"),
	writeln("8 - Visualizar suas sugestões de filmes"),
	writeln("\nOpcao: "),
	writeln("\n"),
	read(A),
	opcao(A),
	menuOpcoes().
		
main :-
	menu(),
	menuOpcoes().


listaFilmes([], _).
listaFilmes([Head|Tail], Codigo) :- write(Codigo), % Printa o codigo
									write(" - "), % Printa o ajuste
									writeln(Head), % Printa o nome do filme
									Codigo1 is Codigo + 1, % Aumenta o número do código
									listaFilmes(Tail, Codigo1). % Chama recursivamente passando o tail

listarPorGenero(Genero) :- 	write("Aqui estão todos os filmes do sistema com o genero "), % Print da frase inicial
							writeln(Genero), % Print do genero
							findall(Nome, filme(_,Nome,Genero,_,_), Filmes), % Retorna uma Lista com todos os filmes que possuem o genero recebido como parametro
							imprimePorGenero(Filmes). % Vai para o metodo de imprimir passando a lista de filmes filtrada

imprimePorGenero([]).
imprimePorGenero([Head|Tail]):-	filme(Codigo,Head,_,_,_), % Recupera o codigo do filme
								write(Codigo), % Printa o codigo
								write(" - "), % Printa ajuste
								writeln(Head), % Printa o nome do filme
								imprimePorGenero(Tail). % Chama recursivamente passando o tail



listaDisponiveis():- findall(Nome, filme(_, Nome,_,_,_), Filmes), % Gera uma lista com os nomes de todos os filmes do sistema
					 imprimeDisponiveis(Filmes). % Repassa pra regra imprimeDisponiveis a lista com todos os filmes
		  
imprimeDisponiveis([]).		  
imprimeDisponiveis([Head|Tail]):-	not(alugado(filme(_,Head,_,_,_))) -> % Se o filme nao estiver alugado
									filme(Codigo,Head,_,_,_), % Recupera o codigo do filme
									write(Codigo), % Printa o codigo
									write(" - "), % Printa ajuste
									writeln(Head), % Printa o nome do filme
									imprimeDisponiveis(Tail) ; % Chama recursivamente passando o tail
									imprimeDisponiveis(Tail) .	% Se estiver alugado apenas chama recursivamente passando o tail	  
		  

imprimeFilmes() :- writeln("Os filmes são:"), % Printa um enunciado para os filmes listados
    			   findall(Nome, filme(_, Nome,_,_,_), Filmes), % Encontra todos os filmes
    			   listaFilmes(Filmes, 1). % Chama os filmes recursivamente

realizaAluguel(Codigo, Nome, Ano, Genero, Descricao) :- assertz(alugado(filme(Codigo, Nome, Ano, Genero, Descricao))), % Realiza aluguel
    													write("Filme alugado com sucesso"). % Passa a mensagem de aluguel 

verificaFilme(Codigo) :- 	call(filme(Codigo,_,_,_,_)), !; % Procura filme com determinado código
							not(alugado(filme(Codigo,_,_,_,_))), !; % Verifica se não está alugado
                      		writeln("Filme nao existe ou esta indisponivel!"). % Printa mensagem

listaAlugados() :- writeln("Os filmes alugaos são:"), % Printa mensagem
    			   forall(alugado(Filme), writeln(Filme)). % Lista filmes alugados

toStringLista([]).
toStringLista([filmes(Codigo, Nome, _,_,_)|Tail]) :-	write(Codigo), % Printa código
														write(" - "), % Printa ajuste
														writeln(Nome), % Printa o nome do filme
														toStringLista(Tail). % Chama recursivamente passando o tail

listaSugestoes() :- forall(sugestao(Sugestao), % Passa pelas sugestões
					writeln(Sugestao)).% Printa sugestão

enviarSugestao(Sugestao) :- assertz(sugestao(Sugestao)). % Envia sugestão
