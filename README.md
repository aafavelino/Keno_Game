Keno Game
=====================================================================================

Versão 1.0.0 - Quarta-Feira 23 de março de 2016

por Adelino Afonso Avelino Fernandes e Yuri Reinaldo da Silva  


Introdução
--------------------------------------------------------------------------------------

O Keno Game é um jogo de apostas comumente encontrado em cassinos. 
O programa lhe permite engajar em várias rodadas de jogatina, nas quais 
o participante pode testar a sua sorte e aumentar os seus ganhos.

Escrito em C++, o software é executado através do terminal aonde são 
exibidas todas as informações pertinentes ao jogo. 


Instalação
--------------------------------------------------------------------------------------

Para executar o programa deve-se extrair o arquivo "Projeto Keno-Game.
zip", através do terminal navegar até a pasta principal (a que contém 
as pastas "bin", "data", "include" e "src") e compilar o programa 
através do seguinte comando:

	g++ -Wall -std=c++11 -I include/ src/drive_keno.cpp src/keno_func.cpp  src/keno_c.cpp -o bin/exe

Logo após basta executar o jogo usando o comando:
	
	./bin/exe /data/*nome_do_arquivo.txt*

É importante que "nome_do_arquivo.txt" seja substituido pelo nome do
arquivo da sua aposta no tipo ".txt" ou similar.

O arquivo da aposta deverá conter, _em linhas separadas_, o valor de 
sua aposta, o número de rodadas que se deseja jogar e os valores 
inteiros entre 1 e 80 nos quais você deseja apostar. Esses valores 
devem estar em uma única linha e devem ser separados por espaço.

Pronto! O Keno Game será executado e os resultados do jogo serão 
exibidos na tela.


Como Jogar
--------------------------------------------------------------------------------------

O Keno Game é um jogo de apostas em que são escolhidos até 15
números entre 1 e 80, logo após o jogo irá gerar um total de
20 valores no mesmo intervalo e então será calculada a quantidade
de acertos e o valor a ser recebido.

É possível apostar entre 1 e 15 números, e para cada quantidade
há uma tabela de pagamentos correspondente que será exibida.

Também é permitido que o jogador distribua seus créditos em várias
apostas. Para tal, basta aumentar o número de rodadas que os seus
créditos passarão a ser divididos igualmente para cada jogo. 


Bugs e limitações
--------------------------------------------------------------------------------------

Caso os valores de créditos, rodadas e números apostados sejam
inseridos na mesma linha, é possível que não seja feita a leitura de 
todos. Portanto, é imprescindível que estas três características 
estejam em linhas diferentes.
