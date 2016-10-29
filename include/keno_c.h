/*!
 *  @file keno_c.h
 *  @brief Arquivo com as assinaturas das funcoes utilizadas no programa.
 *
 *  Arquivo com as assinaturas das funcoes tanto da classe, quanto das funcoes auxiliares no processo de desenvolvimento do jogo.
 */
#ifndef _keno_hpp_
#define _keno_hpp_

#include <cstdlib>      // std::stoi
#include <vector>       // std::vector
#include <fstream>      // operator >>
#include <sstream>      // std::getline
#include <string>       // std::string
#include <chrono>       // std::chrono::system_clock
#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine

//! Funcao usada para verificar se um determinado numero ja esta no vetor.
//! @param candidate Valor a ser verificado.
//! @param actualVec Vetor do tipo vector com os numeros que se encontram na linha da aposta.
bool InArray(const int &candidate, std::vector<int>& actualVec );

//! A estratégia consiste em rearranjar as chaves 'q' de modo que as chaves "menores" precedam as chaves "maiores". 
//! Em seguida o quicksort ordena as duas sublistas de chaves menores e maiores ate que o vetor se encontre ordenado.
//! @param vetor Vetor passado por referencia para ser ordenado.
//! @param ini Valor inicial do vetor mais a esquerda.
//! @param fim Valor final do vetor mais a direita.
void quicksort(std::vector<int>& vetor,int ini, int fim);


class KenoBet
{
  public:
    // ----------------------------------------------------------------------------------------
    // Constructor
    // ----------------------------------------------------------------------------------------
    // Criar um construtor KenoBet e definir o número máximo de valores a serem apostados possíveis.
    explicit KenoBet (unsigned int _maxNumSpots = 15);


    // ----------------------------------------------------------------------------------------
    // Getters
    // ----------------------------------------------------------------------------------------
    //! Retorna o valor do investimento nessa aposta.
    //! @return o valor investido.
    float getWage(void) const;
    //! Determina quantos valores apostados combinam com os valores de resultado passados como parâmetro.
    //! @param _hits Lista de resultados aleatoriamente gerados pelo computador.
    //! @return Um vector com a lista de acertos.
    std::vector<int> getHits(const std::vector<int> &_hits) const;
    //! Retorna um vector<int> com os valores apostados que o jogador escolheu até então.
    //! @return O vector<int> com os valores apostados que o jogador escolheu até então.
    std::vector<int> getSpots(void) const;

    // ----------------------------------------------------------------------------------------
    // Setters
    // ----------------------------------------------------------------------------------------
    //! Sets Define a quantidade de dinheiro que o jogador está investindo.
    //! @param _wage O investimento
    //! @return True se existir um valor acima de zero; false caso contrário.
    bool setWage(const float & = 0.0);

    // ----------------------------------------------------------------------------------------
    // Methods
    // ----------------------------------------------------------------------------------------
    //! Reinicie a aposta para um estado vazio
    //! @return nada
    void reset(void);
    //! Adiciona um numero aos valores apostados somente se o valor não estiver lá.
    //! @param _spot O valor que desejamos incluir na aposta
    //! @return T Se o número escolhido é inserido com sucesso; F caso contrário.
    bool addNumber(const int & _spot);
    //! Retorna o número atual de valores na aposta do jogador.
    //! @return número atual de valores na aposta do jogador.
    std::size_t numChosen(void) const;

  private:
    std::vector<int> m_spots;  // <! The player's bet.
    float m_wage;              // <! The player's wage.
    unsigned int m_maxSpots;   // <! Max # of spots allowed for this bet.
};

#endif
