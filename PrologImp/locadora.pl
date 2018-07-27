:- initialization(main).

:- dynamic
	alugado(filme(_,_,_,_,_)),
	sugestao(_).

% filme(cod, nome, genero, ano, descrição).
filme(1, "Vingadores: Guerra do Infinito", 'fantasia', "2018", "Homem de Ferro, Thor, Hulk e os Vingadores se unem para combater seu inimigo mais poderoso, o maligno Thanos. Em uma missão para coletar todas as seis pedras infinitas, Thanos planeja usá-las para infligir sua vontade maléfica sobre a realidade.").
filme(2, "Black Panther", 'fantasia', "2018",  "Conheça a história de T'Challa, príncipe do reino de Wakanda, que perde o seu pai e viaja para os Estados Unidos, onde tem contato com os Vingadores. Entre as suas habilidades estão a velocidade, inteligência e os sentidos apurados.").
filme(3, "Deadpool 2", 'fantasia', "2018", "Sequência das aventuras do Mercenário Tagarela, interpretado por Ryan Reynolds. Na história original, o herói adquire superpoderes após uma experiência científica, e decide se vingar da pessoa responsável por sequestrar sua namorada." ).
filme(4, "Oito Mulheres e um Segredo", 'thriller', "2018", "Recém-saída da prisão, Debbie Ocean planeja executar o assalto do século em pleno Met Gala, em Nova York, com o apoio de Lou, Nine Ball, Amita, Constance, Rose, Daphne Kluger e Tammy.").
filme(5, "A Origem", 'ficção', "2010", "Don Cobb é um ladrão que invade os sonhos das pessoas e rouba segredos do subconsciente. As habilidades especiais de Cobb fazem com que ele seja procurado pelo mundo da espionagem empresarial, mas lhe custa tudo que ama. Cobb recebe uma missão impossível: plantar uma ideia na mente de uma pessoa. Se for bem-sucedido, será o crime perfeito, mas um amigo prevê todos os passos de Cobb.").
filme(6, "Moulin Rouge: Amor em Vermelho",'romance', "2001", "Don Cobb é um ladrão que invade os sonhos das pessoas e rouba segredos do subconsciente. As habilidades especiais de Cobb fazem com que ele seja procurado pelo mundo da espionagem empresarial, mas lhe custa tudo que ama. Cobb recebe uma missão impossível: plantar uma ideia na mente de uma pessoa. Se for bem-sucedido, será o crime perfeito, mas um amigo prevê todos os passos de Cobb.").
filme(7, "Brilho eterno de uma mente sem lembranças", 'drama', "2004", "Joel se surpreende ao saber que seu amor verdadeiro, Clementine, o apagou completamente de sua memória. Ele decide fazer o mesmo, mas muda de ideia. Preso dentro da própria mente enquanto os especialistas se mantêm ocupados em seu apartamento, Joel precisa avisá-los para parar.").
filme(8, "Donnie Darko", 'drama', "2001", "Donnie é um jovem excêntrico que despreza a grande maioria de seus colegas de escola. Ele tem visões, em especial de Frank, um coelho gigante que só ele consegue ver e que o encoraja a fazer brincadeiras humilhantes com quem o cerca. Um dia, uma de suas visões o atrai para fora de casa e lhe diz q'ue o mundo acabará dentro de um mês. Donnie inicialmente não acredita, mas, momentos depois, a turbina de um avião cai em sua casa e ele começa a se perguntar qual é o fundo de verdade dessa previsão.").

menu() :- 
	writeln("██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ "),
	writeln("██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗"),
	writeln("██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║"),
	writeln("██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║"),
	writeln("██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝"),
	writeln("╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ ").       

opcao(0) :- halt.
	
opcao(1) :- imprimeFilmes(),
			writeln("Voce deseja ver mais informacoes sobre um filme?"),
			writeln("1 - Sim"),
			writeln("2 - Não"),
			read(Op),
			Op == 1 -> 	writeln("Digite o codigo do Filme que deseja saber mais sobre:"),
			read(Codigo),
			filmeInfo(Codigo) ; 
			menuOpcoes().

opcao(2) :- listaDisponiveis().
					
opcao(3) :- listaAlugados().
	
opcao(4) :- writeln("Digite o codigo do Filme que deseja alugar:"),
			read(Codigo),
			realizaAluguel(Codigo).
		
opcao(5) :- writeln("Digite o codigo do Filme que deseja devolver:"),
			read(Codigo),                         
			realizaDevolucao(Codigo).

opcao(6) :- writeln("Digite o nome do genero que voce deseja filtrar com o formato <'genero'.>:"),
			read(Genero),
			listarPorGenero(Genero).
	
opcao(7) :- writeln("Escreva sua sugestão com o formato <'nome do filme'.>:"),
			read(S),
			enviarSugestao(S).
		
opcao(8) :- listaSugestoes().
	
opcao(X) :- write(X), write(" não é uma opção válida, tente outra!").
				
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

filmeInfo(Codigo):-
	call(filme(Codigo, Nome, Genero, Ano, Sinopse)),
	write("Nome: "),
	writeln(Nome),
	write("Gênero: "),
	writeln(Genero),
	write("Ano: "),
	writeln(Ano),
	write("Sinopse: "),
	writeln(Sinopse).

listaFilmes([], _).
listaFilmes([Head|Tail], Codigo) :-
	write(Codigo), % Printa o codigo
	write(" - "), % Printa o ajuste
	writeln(Head), % Printa o nome do filme
	Codigo1 is Codigo + 1, % Aumenta o número do código
	listaFilmes(Tail, Codigo1). % Chama recursivamente passando o tail

listarPorGenero(Genero) :- 
	writeln("Aqui estão todos os filmes do sistema com o genero:"), % Print da frase inicial
	writeln(Genero), % Print do genero
	findall(Nome, filme(_,Nome,Genero,_,_), Filmes), % Retorna uma Lista com todos os filmes que possuem o genero recebido como parametro
	imprimePorGenero(Filmes). % Vai para o metodo de imprimir passando a lista de filmes filtrada

imprimePorGenero([]).
imprimePorGenero([Head|Tail]):-
	filme(Codigo,Head,_,_,_), % Recupera o codigo do filme
	write(Codigo), % Printa o codigo
	write(" - "), % Printa ajuste
	writeln(Head), % Printa o nome do filme
	imprimePorGenero(Tail). % Chama recursivamente passando o tail

listaDisponiveis():-
	findall(Nome, alugado(filme(_, Nome,_,_,_)), Alugados),
	length(Alugados, Tamanho),
	Tamanho =:= 8,
	writeln("Nao ha filmes disponiveis para alugar.").
listaDisponiveis():-
	findall(Nome, filme(_, Nome,_,_,_), Filmes), % Gera uma lista com os nomes de todos os filmes do sistema
	writeln("Abaixo estao os filmes disponiveis para aluguel:"),
	imprimeDisponiveis(Filmes). % Repassa pra regra imprimeDisponiveis a lista com todos os filmes

imprimeDisponiveis([]).		  
imprimeDisponiveis([Head|Tail]):-
	not(alugado(filme(_,Head,_,_,_))) -> % Se o filme nao estiver alugado
	filme(Codigo,Head,_,_,_), % Recupera o codigo do filme
	write(Codigo), % Printa o codigo
	write(" - "), % Printa ajuste
	writeln(Head), % Printa o nome do filme
	imprimeDisponiveis(Tail) ; % Chama recursivamente passando o tail
	imprimeDisponiveis(Tail) .	% Se estiver alugado apenas chama recursivamente passando o tail	  

imprimeFilmes() :-
	writeln("Os filmes são:"), % Printa um enunciado para os filmes listados
	findall(Nome, filme(_, Nome,_,_,_), Filmes), % Encontra todos os filmes
	listaFilmes(Filmes, 1). % Chama os filmes recursivamente

realizaAluguel(Codigo) :-
	not(filme(Codigo, _, _, _, _)),
	writeln("Filme inexistente.").
realizaAluguel(Codigo) :-
	alugado(filme(Codigo, _, _, _, _)),
	writeln("Não foi possível alugar o filme pois ele já está alugado.").
realizaAluguel(Codigo) :-
	filme(Codigo, Nome, Ano, Genero, Descricao),
	assertz(alugado(filme(Codigo, Nome, Ano, Genero, Descricao))),
	writeln("Filme alugado com sucesso.").

realizaDevolucao(Codigo) :- 
	not(filme(Codigo,_,_,_,_)),
	writeln("Filme inexistente.").
realizaDevolucao(Codigo) :-
	not(alugado(filme(Codigo,_,_,_,_))),
	writeln("Nao e possivel devolver um filme nao alugado.").
realizaDevolucao(Codigo) :-
	filme(Codigo, Nome, Ano, Genero, Descricao),
	retract(alugado(filme(Codigo, Nome, Ano, Genero, Descricao))),
	writeln("Filme devolvido com sucesso.").

listaAlugados() :-
	not(alugado(filme(_,_,_,_,_))),
	writeln("Nao ha filmes alugados").
listaAlugados() :-
	findall(Nome, alugado(filme(_, Nome,_,_,_)), Alugados), % Lista filmes alugados
	writeln("Os filmes alugaos são:"),
	imprimeAlugados(Alugados).

imprimeAlugados([]).
imprimeAlugados([Head|Tail]):-
	alugado(filme(_,Head,_,_,_)) -> % Se o filme estiver alugado
	filme(Codigo,Head,_,_,_), % Recupera o codigo do filme
	write(Codigo), % Printa o codigo
	write(" - "), % Printa ajuste
	writeln(Head), % Printa o nome do filme
	imprimeAlugados(Tail) ; % Chama recursivamente passando o tail
	imprimeAlugados(Tail) .	% Se estiver nao alugado apenas chama recursivamente passando o tail	  

toStringLista([]).
toStringLista([filmes(Codigo, Nome, _,_,_)|Tail]) :-
	write(Codigo), % Printa código
	write(" - "), % Printa ajuste
	writeln(Nome), % Printa o nome do filme
	toStringLista(Tail). % Chama recursivamente passando o tail

listaSugestoes() :-
	not(sugestao(_)),
	writeln("Voce ainda nao deu sugestoes.").
listaSugestoes() :-
	writeln("Suas sugestoes sao:"),
	forall(sugestao(Sugestao), % Passa pelas sugestões
	writeln(Sugestao)).% Printa sugestão

enviarSugestao(Sugestao) :- assertz(sugestao(Sugestao)). % Envia sugestão

