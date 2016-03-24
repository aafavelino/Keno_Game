/*!
 *  @mainpage Keno-Game
 *  @authors Adelino Afonso Fernandes Avelino
 *  @authors Yuri Reinaldo da Silva
 *  @date Março, 2016
 *  @version 1.0.0
 *
 *  @file drive_keno.cpp
 *  @brief Driver do Programa.
 *
 *  Arquivo com o metodo main, onde esta funcionando toda a mecanica do jogo, validando as apostas, bem como, 
 *  analisando os lucros e prejuizos no decorrer do jogo. 
 */

//Inclui o arquivo com assinaturas e bibliotecas
#include "keno_c.h"

	//! Metodo main
	//! @param argc contador de parametros 
	//! @param argv usado para ler o nome do arquivo passado por linha de comando.
	//! @return EXIT_SUCCESS se ocorrer tudo corretamente, EXIT_FAILURE se nao funcionar corretamente.
	int main(int argc, char const *argv[])
	{
		std::ifstream betfile;//Define um fluxo a ser usado para ler dados de caracteres de byte único em série de um arquivo como um typedef
		KenoBet actualBet;//Objeto da classe
		std::string linha;//Variavel para pegar a linha inteira do aquivo aposta
		bool valido = false;//Variavel para fazer os testes se realmente e verdadeira a leitura da linha
		float apostaNaRodada = 0.0; //Variavel para guardar o lucro
		float apostaPorRodada;//Divisao de quanto vale cada rodada
		int rodadas = 0; // ver pra que serve depois
		int aux;//Variavel usada como auxiliar na leitura dos demais numeros inteiros da aposta
		float aux_f; //Variavel usada como auxiliar na leitura do valor apostado
		float final; //Variavel para fazer os calculos dos resultados finais
		float saldoPorRodada; // variavel para fazer as contas do saldo
		std::vector<int> numerosAcertados;
		std::vector<int> numerosKeno = {
			   1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
			   21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
			   41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
			   61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80
		};//Numeros keno

		std::vector<std::vector<float>> ganhosPorAposta = {
			{0,3},
			{0,1,9},
			{0,1,2,16},
			{0,0.5,2,6,12},
			{0,0.5,1,3,15,50},
			{0,0.5,1,2,3,30,75},
			{0,0.5,0.5,1,6,12,36,100},
			{0,0.5,0.5,1,3,6,19,90,720},
			{0,0.5,0.5,1,2,4,8,20,80,1200},
			{0,0,0.5,1,2,3,5,10,30,600,1800},
			{0,0,0.5,1,1,2,6,15,25,180,1000,3000},
			{0,0,0,0.5,1,2,4,24,72,250,500,2000,4000},
			{0,0,0,0.5,0.5,3,4,5,20,80,240,500,3000,6000},
			{0,0,0,0.5,0.5,2,3,5,12,50,150,500,1000,2000,7500},
			{0,0,0,0.5,0.5,1,2,5,15,50,150,300,600,1200,2500,10000}
		};//Vector com tabela de pagamento

		//Ler o arquivo passado por linha de comando e valida a leitura
		if (argc > 1)
		{
			betfile.open(argv[1], std::fstream::in);
			std::cout << ">> Arquivo aberto com sucesso!" << std::endl;
		}else
		{
			std::cout << ">> O nome do arquivo não foi passado como argumento." << std::endl;
		 	return 0;
		}
			//Se o objeto da classe receber false retorna aquivo inválido
			if (!betfile.is_open())
			{
				std::cout << ">> Arquivo inválido!";
				return EXIT_FAILURE;

			}else
			{

			
				

				std::cout << ">>> Preparando-se para ler o arquivo aposta [" << argv[1] << "], por favor aguarde ..." << std::endl;

				//Neste primeiro while é validado a leitura do caractere referente ao valor da aposta do jogador
				while(!betfile.eof() && !valido)
				{	//copia a linha para o objeto betfile
					std::getline(betfile, linha);
					if(linha.length() != 0)
					{
						std::stringstream b_stream(linha);
						//Enquanto a leitura da stream não estiver no fim do arquivo continua executando 
						while(!b_stream.eof())
						{	//Aqui e feita a comparacao se realmente a stream passada e do tipo float, se for entra no if colhendo as apostas e validando  
							if(b_stream >> aux_f && aux_f > 0)
							{
								actualBet.setWage(aux_f);
								valido = true;
								break;
							}
							//Caso a leitura seja invalida o valor e passado para uma variavel lixo
							if(b_stream.fail()){
								b_stream.clear();
								std::string dump_f;
								b_stream >> dump_f;

							}
						}
					}
				}

				valido = false;
				//Neste primeiro while é validado a leitura do caractere referente a quantidade de rodadas do jogo
				while(!betfile.eof() && !valido)
				{
					std::getline(betfile, linha);
					if(linha.length() != 0)
					{
						std::stringstream r_stream(linha);
						while(!r_stream.eof())
						{	//Aqui e feita a comparacao se realmente a stream passada e do tipo int e maior que 0, se for entra no if colhendo as rodadas
							if(r_stream >> aux && aux > 0)
							{
								rodadas = aux;
								valido = true;
								break;
							}
							//Caso a leitura seja invalida o valor e passado para uma variavel lixo
							if(r_stream.fail())
							{
								r_stream.clear();
								std::string dump_i;
								r_stream >> dump_i;

							}
						}
					}
				}

				valido = false;

				while(!betfile.eof() && !valido)
				{
					
					std::getline(betfile, linha);
					if(linha.length() != 0)
					{
						std::stringstream f_stream(linha);
						//Pega somente os 15 primeiros numeros da aposta no arquivo
						for (int i = 0; i < 15 && !f_stream.eof();)
						{
							//Enquanto a leitura da stream não estiver no fim do arquivo continua executando 
                	        while((f_stream >> aux) && i < 15)
                            {
                                if(actualBet.addNumber(aux))
                                {
                                    ++i;
                                    valido=true;
                                          
                	         	}
                	    	}

                	        //Caso a leitura seja invalida o valor e passado para uma variavel lixo
                	        if(f_stream.fail())
                	        { 
                	               f_stream.clear();
                	               std::string substitute;
                	               f_stream >> substitute;

                	        }
	
						}
					}
				}

		}	//Variavel usada para poder receber o valor da aposta nas rodadas e fazer as operações
			apostaNaRodada = actualBet.getWage(); 
			std::vector<int> teste = actualBet.getSpots();
			if (actualBet.getWage() == 0.0 || rodadas == 0 || teste.size() == 0)
			{
				std::cout <<">>> Aposta inválida, tente um novo arquivo de apostas..." << std::endl;
				return EXIT_FAILURE;
			}

			//Jogo Rodando
			//Recebe os numeros apostados
			std::vector<int> numeros_apostados = actualBet.getSpots();
		
			//Divisão da aposta por rodadas
			apostaPorRodada = actualBet.getWage() / rodadas;
			//Fecha a leitura da classe
			betfile.close();
			//Jogo rodando e mostrando o que esta acontecendo
				std::cout << "---------------------------------------------------------------------------------------"<< std::endl;
				std::cout << ">>> Aposta lida com sucesso!"<< std::endl;
				//Usado para fixar apenas 2 números após a virgula.
				std::cout.precision(2);
				std::cout << std::fixed;
				std::cout << "Você está apostando um total de R$ "<< actualBet.getWage() << " reais" << std::endl;
				std::cout << "Você está indo para um total de "<< rodadas << " rodadas, cada uma valendo R$ " << actualBet.getWage()/rodadas<< " reais" << std::endl;
				std::cout << std::endl;

				//Ordena os números apostados
				quicksort(numeros_apostados,0, numeros_apostados.size()-1);

				std::cout << "Sua aposta tem "<< numeros_apostados.size() << " números. Eles são: [ ";
					for (int i = 0; i < numeros_apostados.size(); ++i) std::cout << numeros_apostados[i] << " ";
				std::cout << "]"<< std::endl;

				std::cout.precision(1);
				std::cout << std::fixed;
				std::cout << std::endl;
				std::cout << "-------+--------"<< std::endl;
				std::cout << "|Hits  | Payout|"<< std::endl;
				std::cout << "-------+--------"<< std::endl;
				for (int i = 0; i <= numeros_apostados.size(); ++i)
				std::cout << i << "\t" << ganhosPorAposta[numeros_apostados.size() - 1][i]<< std::endl;


				//Rodadas...
				std::cout.precision(2);
				std::cout << std::fixed;
				for (int i = 1; i <= rodadas; ++i)
				{
					std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
					std::cout << "Esta é a rodada #"<< i << " de " << rodadas <<", valendo R$ " << apostaPorRodada << ". Boa sorte!" << std::endl;
					std::cout << "Os números sorteados são: [ ";
						unsigned tempo = std::chrono::system_clock::now().time_since_epoch().count();

						//Mistura os números do vetor
						std::shuffle (numerosKeno.begin(), numerosKeno.end(), std::default_random_engine(tempo));
						
						//Ordena os 20 primeiros números da aposta
						quicksort(numerosKeno, 0, 20);

						for (int i = 0; i < 20; ++i)
						{

							std::cout << numerosKeno[i] << " ";
						}
					std::cout << "]" << std::endl;

					//pega e imprime a quantidade de números acertados
					numerosAcertados = actualBet.getHits(numerosKeno);
					std::cout<< "numerosAcertados : " << numerosAcertados.size() << " " << std::endl;




						saldoPorRodada = (ganhosPorAposta[numeros_apostados.size()-1][numerosAcertados.size()] * apostaPorRodada);

						if (saldoPorRodada == 0)
						{
							apostaNaRodada = apostaNaRodada - apostaPorRodada;
						}else{
							apostaNaRodada = apostaNaRodada + saldoPorRodada - apostaPorRodada;
						}

					 	std::cout << ">>> Você acertou o(s) número(s): [ ";
					 		for (int i = 0; i < numerosAcertados.size(); ++i)
					 			std::cout << numerosAcertados[i] << " ";
						std::cout << "], você acertou um total de "<< numerosAcertados.size() << " de um total de " << numeros_apostados.size() << ", a taxa de pagamento é de "<< ganhosPorAposta[numeros_apostados.size()-1][numerosAcertados.size()] << ", assim você saiu com: R$ "<< saldoPorRodada << std::endl;
						std::cout << "Seu saldo líquido até o momento é: R$ " << apostaNaRodada << std::endl;

					std::cout << std::endl;
					std::cout << std::endl;

				}



				// Resumo do Jogo
				
				actualBet.getWage() > apostaNaRodada ? final = apostaNaRodada - actualBet.getWage()  : final = apostaNaRodada - actualBet.getWage();

				std::cout << "============================================================================ Resumo ============================================================================" << std::endl;
				std::cout << ">>> Você apostou neste jogo um total de: " << actualBet.getWage() << std::endl;
				if (final  > 0)
				{
					std::cout << ">> Hooray! Você ganhou R$ " << final << ". Vejo você nas próximas vezes, você está deixando o jogo com R$ " << apostaNaRodada << std::endl;
				}else if(final < 0)
				{
					std::cout << ">> Que pena! Você perdeu R$ " << -final << ". Boa sorte no próximo jogo! Você está deixando o jogo com R$ " << apostaNaRodada << std::endl;
				}else
				{
					std::cout << ">> Hmmmm... Você não ganhou nem perdeu nada. Vejo você nas próximas vezes, você está deixando o jogo com R$ " << apostaNaRodada << std::endl;
				}


		return EXIT_SUCCESS;
	}
