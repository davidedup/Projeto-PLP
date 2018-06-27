import Data.List
import System.IO
import System.Directory

-- //////////////////////////////////////  DATA  //////////////////////////////////////

data Filme = Filme {
	indice :: Integer,
	nome :: String,
	genero :: String,
	ano :: String,
    descricao :: String
} deriving (Show)

-- //////////////////////////////////////  FILMES INICIAIS  //////////////////////////////////////

filmesCadastrados = [Filme {indice = 1, nome = "Vingadores: Guerra do Infinito", genero = "fantasia", ano = "2018", descricao = "Homem de Ferro, Thor, Hulk e os Vingadores se unem para combater seu inimigo mais poderoso, o maligno Thanos. Em uma missão para coletar todas as seis pedras infinitas, Thanos planeja usá-las para infligir sua vontade maléfica sobre a realidade."},
					 Filme {indice = 2, nome = "Black Panther", genero = "fantasia", ano = "2018", descricao = "Conheça a história de T'Challa, príncipe do reino de Wakanda, que perde o seu pai e viaja para os Estados Unidos, onde tem contato com os Vingadores. Entre as suas habilidades estão a velocidade, inteligência e os sentidos apurados."},
					 Filme {indice = 3, nome = "Deadpool 2", genero = "fantasia", ano = "2018", descricao = "Sequência das aventuras do Mercenário Tagarela, interpretado por Ryan Reynolds. Na história original, o herói adquire superpoderes após uma experiência científica, e decide se vingar da pessoa responsável por sequestrar sua namorada."},
					 Filme {indice = 4, nome = "Oito Mulheres e um Segredo", genero = "thriller", ano = "2018", descricao = "Recém-saída da prisão, Debbie Ocean planeja executar o assalto do século em pleno Met Gala, em Nova York, com o apoio de Lou, Nine Ball, Amita, Constance, Rose, Daphne Kluger e Tammy."},
					 Filme {indice = 5, nome = "A Origem", genero = "ficção", ano = "2010", descricao = "Don Cobb é um ladrão que invade os sonhos das pessoas e rouba segredos do subconsciente. As habilidades especiais de Cobb fazem com que ele seja procurado pelo mundo da espionagem empresarial, mas lhe custa tudo que ama. Cobb recebe uma missão impossível: plantar uma ideia na mente de uma pessoa. Se for bem-sucedido, será o crime perfeito, mas um amigo prevê todos os passos de Cobb."},
					 Filme {indice = 6, nome = "Moulin Rouge: Amor em Vermelho", genero = "romance", ano = "2001", descricao = "O idealista e inocente poeta Christian se vê seduzido pelo fantástico e obscuro submundo de uma boate parisiense, a Moulin Rouge. Neste glamoroso refúgio do sexo, drogas e farra, ele acaba se apaixonando por Satin, a estrela da casa."},
					 Filme {indice = 7, nome = "Brilho eterno de uma mente sem lembranças", genero = "drama", ano = "2004", descricao = "Joel se surpreende ao saber que seu amor verdadeiro, Clementine, o apagou completamente de sua memória. Ele decide fazer o mesmo, mas muda de ideia. Preso dentro da própria mente enquanto os especialistas se mantêm ocupados em seu apartamento, Joel precisa avisá-los para parar."},
					 Filme {indice = 8, nome = "Donnie Darko", genero = "drama", ano = "2001", descricao = "Donnie é um jovem excêntrico que despreza a grande maioria de seus colegas de escola. Ele tem visões, em especial de Frank, um coelho gigante que só ele consegue ver e que o encoraja a fazer brincadeiras humilhantes com quem o cerca. Um dia, uma de suas visões o atrai para fora de casa e lhe diz que o mundo acabará dentro de um mês. Donnie inicialmente não acredita, mas, momentos depois, a turbina de um avião cai em sua casa e ele começa a se perguntar qual é o fundo de verdade dessa previsão."}]

-- //////////////////////////////////////  MENU  //////////////////////////////////////

main :: IO ()
main = do
    menuPrint
    menuOpcao


menuPrint :: IO ()
menuPrint = do
	putStrLn "██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ " 
	putStrLn "██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗" 
	putStrLn "██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║" 
	putStrLn "██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║" 
	putStrLn "██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝" 
	putStrLn "╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ "


menuOpcao :: IO ()
menuOpcao = do
    putStrLn "0 - Sair" 
    putStrLn "1 - Listar todos filmes"
    putStrLn "2 - Listar filmes disponiveis"
    putStrLn "3 - Listar os seus filmes alugados"
    putStrLn "4 - Realizar Aluguel"
    putStrLn "5 - Realizar Devolução"
    putStrLn "6 - Listar filmes por genero"
    putStrLn "7 - Enviar sugestão de filme"
    putStrLn "8 - Visuzalizar suas sugestões de filmes"
    putStrLn "\nOpcao: "
    opcao <- getLine
    if (read opcao) == 0 then putStrLn("Fim") else do opcaoEscolhida (read opcao)


menuListagem :: IO()
menuListagem = do
    putStrLn "0 - Voltar para o menu principal" 
    putStrLn "1 - Descobrir mais informações sobre um filme"
    putStr "\nOpção: "
    opcao <- getLine
    if (read opcao) == 1
        then do
            visualizarInfoFilme
    else if (read opcao) /= 0 
        then do
            putStrLn "==> Opção inválida"
    else
        putStr ""
    printEspaco
    
-- //////////////////////////////////////  ESCOLHER OPÇÃO  //////////////////////////////////////

opcaoEscolhida :: Int -> IO()
opcaoEscolhida opcao | opcao == 1 = do {imprimeFilmes ; menuListagem; menuOpcao} 
                     | opcao == 2 = do {imprimeDisponiveis ; menuOpcao}
                     | opcao == 3 = do {imprimeAlugados ; menuOpcao}
                     | opcao == 4 = do {realizarAluguel ; menuOpcao}
                     | opcao == 5 = do {realizarDevolucao ; menuOpcao}
                     | opcao == 6 = do {imprimeListarFilmesPorGenero; menuOpcao}    
                     | opcao == 7 = do {enviarSugestao; menuOpcao}  
                     | opcao == 8 = do {visualizarSugetoes; menuOpcao}  
                     | otherwise =  do {putStrLn "Opcao invalida, Porfavor escolha uma opcao valida" ; menuOpcao}

-- //////////////////////////////////////  PRINTS  //////////////////////////////////////

imprimeFilmes :: IO()
imprimeFilmes = putStrLn ("\n\n\n" ++ (listarFilmes filmesCadastrados) ++ "\n\n")


imprimeDisponiveis :: IO()
imprimeDisponiveis = do
    let todos = [1..toInteger(length filmesCadastrados)]
    alugados <- alugueis
    let disponiveis = todos \\ alugados
    printEspaco
    if disponiveis == []
        then putStrLn "Nao há filmes disponíveis."
    else putStrLn (listarFilmes (listarInteiroParaFilme disponiveis))
    printEspaco


imprimeAlugados :: IO()
imprimeAlugados = do
    let todos = [1..toInteger(length filmesCadastrados)]
    alugados <- alugueis
    printEspaco
    if alugados == []
        then putStrLn "Você não tem filmes alugados."
    else putStrLn (listarFilmes (listarInteiroParaFilme alugados))
    printEspaco


imprimeListarFilmesPorGenero :: IO()
imprimeListarFilmesPorGenero = do
    printEspaco
    putStrLn "==> Insira o nome do genero na qual você deseja filtrar: "
    genero <- getLine
    let filmesDoGenero = "\n==> Os filmes que possuem esse genero são:\n" ++ unlines(listarFilmesPorGenero ( filmesCadastrados ) ([]) ( genero ))
    if filmesDoGenero == "\n==> Os filmes que possuem esse genero são:\n"
		then putStrLn "\nNão há filmes desse gênero na biblioteca.\n"
	else
		putStrLn filmesDoGenero
    printEspaco


visualizarSugetoes :: IO()
visualizarSugetoes = do
    printEspaco
    putStrLn "==> Suas sugetões de filmes:\n"
    sugetoes <- readFile "sugetoes.txt"
    putStrLn sugetoes
    printEspaco

-- //////////////////////////////////////  OPERAÇÕES  //////////////////////////////////////

realizarAluguel :: IO()
realizarAluguel = do
    printEspaco
    putStrLn "==> Digite o codigo do filme que deseja alugar: "
    indice <- getLine
    disponivel <- estaDisponivel (read indice)
    if (disponivel && ((read indice) > 0) && ((read indice) < length filmesCadastrados))
        then do 
            adicionaAluguel (read indice)
            putStrLn "==> Filme alugado com sucesso"
    else putStrLn "==> Filme não disponível para aluguel"
    printEspaco
    

realizarDevolucao :: IO()
realizarDevolucao = do
    printEspaco
    putStrLn "==> Digite o codigo do filme que deseja devolver: "
    indice <- getLine
    disponivel <- estaDisponivel (read indice)
    if ((not disponivel) && ((read indice) > 0) && ((read indice) < length filmesCadastrados))
        then do
            removerAluguel (read indice)
            putStrLn "==> Filmes devolvido com sucesso."
    else
        putStrLn "==> Este filme não foi alugado por você."
    printEspaco


enviarSugestao :: IO()
enviarSugestao = do
    printEspaco
    putStr "==> Digite o nome do filme que deseja sugerir: "
    nomeFilme <- getLine
    appendFile "sugetoes.txt" (nomeFilme ++ "\n")
    printEspaco

-- //////////////////////////////////////  AUXILIARES  //////////////////////////////////////

toStringFilme :: Filme -> String
toStringFilme (Filme {indice = i, nome = n, genero = g, ano = a, descricao = d}) = show i ++ " - " ++ n     


listarFilmes :: [Filme] -> String
listarFilmes [] = ""
listarFilmes (x:xs) = toStringFilme x ++ ['\n'] ++ listarFilmes xs


alugueis :: IO [Integer]
alugueis = do
  conteudo <- readFile "alugueis.txt"
  let linhas = lines conteudo
  let numeros = fmap (read::String->Integer) linhas
  return numeros


adicionaAluguel :: Integer -> IO()
adicionaAluguel numero = do
    let conteudo = conteudoAdicionar numero
    appendFile "alugueis.txt" (conteudo)
    where
        conteudoAdicionar :: Integer -> String
        conteudoAdicionar numero
            | numero == (-1) = ""
            | otherwise = ((show numero) ++ "\n")


estaDisponivel :: Integer -> IO Bool
estaDisponivel indice = do
    alugados <- alugueis
    return $ estaDisponivel' indice alugados
    where
        estaDisponivel' :: Integer -> [Integer] -> Bool
        estaDisponivel' indice [] = True
        estaDisponivel' indice (a:as)  
            | indice == a = False           
            | otherwise = True && estaDisponivel' indice as


removerAluguel :: Integer -> IO()
removerAluguel numero = do
    listaNova <- removeElemento numero
    removeFile "alugueis.txt"
    refazArquivo listaNova
    where
        refazArquivo :: [Integer] -> IO()
        refazArquivo [] = adicionaAluguel (-1)
        refazArquivo (a:as) = do
            adicionaAluguel a
            refazArquivo as


removeElemento :: Integer -> IO [Integer]
removeElemento numero = do
    numeros <- alugueis
    return $ removeElemento' numeros numero
    where
        removeElemento' :: [Integer] -> Integer -> [Integer]
        removeElemento' [] numero = []
        removeElemento' (a:as) numero
            | a == numero = [] ++ removeElemento' as numero
            | otherwise = [a] ++ removeElemento' as numero


listarInteiroParaFilme :: [Integer] -> [Filme]
listarInteiroParaFilme lista = do
    let disponiveis = sort lista
    listarInteiroParaFilme' disponiveis filmesCadastrados
    where
        listarInteiroParaFilme' :: [Integer] -> [Filme] -> [Filme]
        listarInteiroParaFilme' [] _ = []
        listarInteiroParaFilme' (a:as) (b:bs)
            | a == (indice b) = [b] ++ listarInteiroParaFilme' as bs
            | otherwise = [] ++ listarInteiroParaFilme' (a:as) bs


ehDoGenero:: Filme -> String -> Bool
ehDoGenero (Filme {indice = i, nome = n, genero = g, ano = a, descricao = d}) gen = if g == gen then True else False


listarFilmesPorGenero:: [Filme] -> [String] -> String -> [String]
listarFilmesPorGenero [] arrayDoGenero _ = arrayDoGenero
listarFilmesPorGenero (cabeca:cauda) arrayDoGenero genero
	| ehDoGenero cabeca genero = arrayDoGenero ++ [toStringFilme cabeca] ++ listarFilmesPorGenero cauda arrayDoGenero genero
	| otherwise = listarFilmesPorGenero cauda arrayDoGenero genero

infoFilme :: Filme -> String  
infoFilme filme = "- Nome: " ++ (nome filme) ++ ['\n'] ++ "- Genero: " ++ (genero filme) ++ ['\n'] ++ "- Ano de Lançamento: " ++ (ano filme) ++ ['\n'] ++ "- Descrição: " ++ (descricao filme) 


visualizarInfoFilme:: IO()
visualizarInfoFilme = do
    putStrLn "==> Escolha o indice do filme que você deseja visualizar:"
    indice <- getLine
    let parseIndice = read (indice)
    let indiceNaLista = parseIndice-1

    if parseIndice > 0 && parseIndice < ( length filmesCadastrados )+1
        then putStrLn ( infoFilme ( filmesCadastrados !!  indiceNaLista  ) ) 
    else putStrLn "Filme não existente."


printEspaco :: IO()
printEspaco = putStrLn "\n\n\n"
