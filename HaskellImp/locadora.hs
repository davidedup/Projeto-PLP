contadorDeFilmes = 0
usuariosCadastrados = [(009, "Dummy")]
sugestoes = []
filmesCadastrados = [(1, ["Vingadores: Guerra do Infinito", "Fantasia", "2018", "Homem de Ferro, Thor, Hulk e os Vingadores se unem para combater seu inimigo mais poderoso, o maligno Thanos. Em uma missão para coletar todas as seis pedras infinitas, Thanos planeja usá-las para infligir sua vontade maléfica sobre a realidade."]), (2,["Black Panther", "Fantasia", "2018", "Conheça a história de T'Challa, príncipe do reino de Wakanda, que perde o seu pai e viaja para os Estados Unidos, onde tem contato com os Vingadores. Entre as suas habilidades estão a velocidade, inteligência e os sentidos apurados."]), (3, ["Deadpool 2", "Fantasia", "2018", "Sequência das aventuras do Mercenário Tagarela, interpretado por Ryan Reynolds. Na história original, o herói adquire superpoderes após uma experiência científica, e decide se vingar da pessoa responsável por sequestrar sua namorada."]), (4,["Oito Mulheres e um Segredo", "Thriller", "2018", "Recém-saída da prisão, Debbie Ocean planeja executar o assalto do século em pleno Met Gala, em Nova York, com o apoio de Lou, Nine Ball, Amita, Constance, Rose, Daphne Kluger e Tammy."])]
main:: IO ()
main = do
	menuPrint
	menuOpcao

menuOpcao:: IO ()
menuOpcao = do
   	opcao <- getLine
  	menu (read opcao)
  	if (read opcao) == 0 then putStr("Fim") else menuOpcao

menu :: Int -> IO ()
menu 1 = listarFilmes
menu _ = putStr ""

listarFilmes:: IO ()
listarFilmes = do 
	putStrLn "ola"

menuPrint:: IO ()
menuPrint = do
	putStrLn "██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ " 
	putStrLn "██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗" 
	putStrLn "██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║" 
	putStrLn "██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║" 
	putStrLn "██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝" 
	putStrLn "╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ "