import Data.List

data Filme = Filme {
	indice :: Integer,
	nome :: String,
	genero :: String,
	ano :: String,
    descricao :: String,
    disponivel :: Bool 
} deriving (Show)

filmesCadastrados = [Filme {indice = 1, nome = "Vingadores: Guerra do Infinito", genero = "Fantasia", ano = "2018", descricao = "Homem de Ferro, Thor, Hulk e os Vingadores se unem para combater seu inimigo mais poderoso, o maligno Thanos. Em uma missão para coletar todas as seis pedras infinitas, Thanos planeja usá-las para infligir sua vontade maléfica sobre a realidade.", disponivel = False },
					 Filme {indice = 2, nome = "Black Panther", genero = "Fantasia", ano = "2018", descricao = "Conheça a história de T'Challa, príncipe do reino de Wakanda, que perde o seu pai e viaja para os Estados Unidos, onde tem contato com os Vingadores. Entre as suas habilidades estão a velocidade, inteligência e os sentidos apurados.", disponivel = True  },
					 Filme {indice = 3, nome = "Deadpool 2", genero = "Fantasia", ano = "2018", descricao = "Sequência das aventuras do Mercenário Tagarela, interpretado por Ryan Reynolds. Na história original, o herói adquire superpoderes após uma experiência científica, e decide se vingar da pessoa responsável por sequestrar sua namorada.", disponivel = True  },
					 Filme {indice = 4, nome = "Oito Mulheres e um Segredo", genero = "Thriller", ano = "2018", descricao = "Recém-saída da prisão, Debbie Ocean planeja executar o assalto do século em pleno Met Gala, em Nova York, com o apoio de Lou, Nine Ball, Amita, Constance, Rose, Daphne Kluger e Tammy.", disponivel = True  }]

main :: IO ()
main = do
    menuPrint
    menuOpcao
	

toStringFilme :: Filme -> String  
toStringFilme (Filme {indice = i, nome = n, genero = g, ano = a, descricao = d, disponivel = dis }) = show i ++ " - " ++ n ++ "- Disponivel: " ++ show dis    
    

listarFilmes :: [Filme] -> String
listarFilmes [] = ""
listarFilmes (x:xs) = toStringFilme x ++ ['\n'] ++ listarFilmes xs

estaDisponivel :: Filme -> Bool
estaDisponivel (Filme {indice = i, nome = n, genero = g, ano = a, descricao = d, disponivel = dis }) = if dis == True then True else False

listarFilmesDisponiveis :: [Filme] -> String
listarFilmesDisponiveis [] = ""
listarFilmesDisponiveis (x:xs) = if estaDisponivel x then toStringFilme x ++ ['\n'] ++ listarFilmesDisponiveis xs else listarFilmesDisponiveis xs

opcaoEscolhida :: Int -> String
opcaoEscolhida opcao | opcao == 1 = listarFilmes filmesCadastrados
                     | opcao == 2 = listarFilmesDisponiveis filmesCadastrados
                     | opcao == 3 = "listarAlugados"
                     | otherwise =  "opcao invalida"

menuOpcao :: IO ()
menuOpcao = do
    putStrLn "0 - sair" 
    putStrLn "1 - listar filmes"
    putStrLn "2 - listar filmes disponiveis"
    putStrLn "3 - listar os alugados"
    opcao <- getLine
    if (read opcao) == 0 then putStrLn("Fim") else putStrLn (opcaoEscolhida (read opcao))
    
    
menuPrint :: IO ()
menuPrint = do
	putStrLn "██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ " 
	putStrLn "██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗" 
	putStrLn "██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║" 
	putStrLn "██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║" 
	putStrLn "██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝" 
	putStrLn "╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ "
