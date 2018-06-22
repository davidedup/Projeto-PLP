import Data.List

data Filme = Filme {
	indice :: Integer,
	nome :: String,
	genero :: String,
	ano :: String,
	descricao :: String
} deriving (Show)

filmesCadastrados = [Filme {indice = 1, nome = "Vingadores: Guerra do Infinito", genero = "Fantasia", ano = "2018", descricao = "Homem de Ferro, Thor, Hulk e os Vingadores se unem para combater seu inimigo mais poderoso, o maligno Thanos. Em uma missão para coletar todas as seis pedras infinitas, Thanos planeja usá-las para infligir sua vontade maléfica sobre a realidade." },
					 Filme {indice = 2, nome = "Black Panther", genero = "Fantasia", ano = "2018", descricao = "Conheça a história de T'Challa, príncipe do reino de Wakanda, que perde o seu pai e viaja para os Estados Unidos, onde tem contato com os Vingadores. Entre as suas habilidades estão a velocidade, inteligência e os sentidos apurados." },
					 Filme {indice = 3, nome = "Deadpool 2", genero = "Fantasia", ano = "2018", descricao = "Sequência das aventuras do Mercenário Tagarela, interpretado por Ryan Reynolds. Na história original, o herói adquire superpoderes após uma experiência científica, e decide se vingar da pessoa responsável por sequestrar sua namorada." },
					 Filme {indice = 4, nome = "Oito Mulheres e um Segredo", genero = "Thriller", ano = "2018", descricao = "Recém-saída da prisão, Debbie Ocean planeja executar o assalto do século em pleno Met Gala, em Nova York, com o apoio de Lou, Nine Ball, Amita, Constance, Rose, Daphne Kluger e Tammy." }]

filmesAlugados = [1]

main:: IO ()
main = do
	let sugestoes = []
	let filmesCadastrados = [Filme {indice = 1, nome = "Vingadores: Guerra do Infinito", genero = "Fantasia", ano = "2018", descricao = "Homem de Ferro, Thor, Hulk e os Vingadores se unem para combater seu inimigo mais poderoso, o maligno Thanos. Em uma missão para coletar todas as seis pedras infinitas, Thanos planeja usá-las para infligir sua vontade maléfica sobre a realidade." },
							 Filme {indice = 2, nome = "Black Panther", genero = "Fantasia", ano = "2018", descricao = "Conheça a história de T'Challa, príncipe do reino de Wakanda, que perde o seu pai e viaja para os Estados Unidos, onde tem contato com os Vingadores. Entre as suas habilidades estão a velocidade, inteligência e os sentidos apurados." },
							 Filme {indice = 3, nome = "Deadpool 2", genero = "Fantasia", ano = "2018", descricao = "Sequência das aventuras do Mercenário Tagarela, interpretado por Ryan Reynolds. Na história original, o herói adquire superpoderes após uma experiência científica, e decide se vingar da pessoa responsável por sequestrar sua namorada." },
							 Filme {indice = 4, nome = "Oito Mulheres e um Segredo", genero = "Thriller", ano = "2018", descricao = "Recém-saída da prisão, Debbie Ocean planeja executar o assalto do século em pleno Met Gala, em Nova York, com o apoio de Lou, Nine Ball, Amita, Constance, Rose, Daphne Kluger e Tammy." }]
	let filmes = ["Vingadores: Guerra do Infinito", "Black Panther", "Deadpool 2"]
	let filmesAlugados = ["Vingadores: Guerra do Infinito"]
	menuPrint
	menuOpcao sugestoes filmesCadastrados filmesAlugados
	

menuOpcao:: [String] -> [Filme] -> [String] -> IO ()
menuOpcao a b c = do
	putStrLn "0 - sair"
	putStrLn "1 - listar filmes"
	putStrLn "2 - listar filmes disponiveis"
	putStrLn "3 - listar alugados"
   	opcao <- getLine
  	menu (read opcao) a b c
  	if (read opcao) == 0 then putStrLn("Fim") else menuOpcao a b c

menu :: Int -> [String] -> [Filme] -> [String] -> IO ()
-- menu 1 a b c = listarFilmes b
-- menu 2 a b c = listarFilmesDisponiveis b c
-- menu 3 a b c = listarFilmesAlugados c 
menu _ a b c = putStr ""

listarFilmes:: IO ()
listarFilmes = listarFilmes' filmesCadastrados
	where
		listarFilmes' :: [Filme] -> IO()
		listarFilmes' [] = putStrLn ""
		listarFilmes' (a:as) = do
			putStrLn (show(indice a) ++ " - " ++ (nome a))
			listarFilmes' as

indiceFilmes:: [Integer]
indiceFilmes = indiceFilmes' filmesCadastrados
	where
		indiceFilmes' :: [Filme] -> [Integer]
		indiceFilmes' [] = []
		indiceFilmes' (a:as) = [indice a] ++ indiceFilmes' as


listarFilmesDisponiveis:: [Integer]
listarFilmesDisponiveis = filmesDisponiveis' indiceFilmes filmesAlugados
	where
		filmesDisponiveis' :: [Integer] -> [Integer] -> [Integer]
		filmesDisponiveis' a b = (a \\ b)



-- listarFilmes [] = putStrLn ""
-- listarFilmes a:as = do
-- 	putStrLn (show(indice a))
-- 	listarFilmes

-- listarFilmes [] = putStrLn ""
-- listarFilmes (a:as) = do
-- 	putStrLn (show(indice a) ++ " - " ++ (nome a))
-- 	listarFilmes as

-- listarFilmesDisponiveis:: [String] -> [String] -> IO ()
-- listarFilmesDisponiveis a b = do mapM_ print (a \\ b)

-- listarFilmesAlugados:: [String] -> IO ()
-- listarFilmesAlugados a = do mapM_ print a

menuPrint:: IO ()
menuPrint = do
	putStrLn "██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ " 
	putStrLn "██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗" 
	putStrLn "██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║" 
	putStrLn "██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║" 
	putStrLn "██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝" 
	putStrLn "╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ "
