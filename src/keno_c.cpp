/*!
 *  @file keno_c.cpp
 *  @brief Arquivo com as funcoes da classe utilizadas no programa
 *
 *  Arquivo com as funcoes da classe.
 */
#include "keno_c.h"
    // ----------------------------------------------------------------------------------------
    // Constructor
    // ----------------------------------------------------------------------------------------
    // Criar um construtor KenoBet e definir o número máximo de valores a serem apostados possíveis. 
    KenoBet::KenoBet(unsigned  _maxNumSpots)
    {
    		if(_maxNumSpots > 15 || _maxNumSpots < 1)
    		{
    			_maxNumSpots = 15;
    		}
    		m_maxSpots = _maxNumSpots;
    }
    // ----------------------------------------------------------------------------------------
    // Getters
    // ----------------------------------------------------------------------------------------
    // Retorna o valor do investimento nessa aposta.
    // @return o valor investido.
    float KenoBet::getWage(void) const
	{
		return m_wage;
	}
    // Determina quantos valores apostados combinam com os valores de resultado passados como parâmetro.
    // @param _hits Lista de resultados aleatoriamente gerados pelo computador.
    // @return Um vector com a lista de acertos.
    std::vector<int> KenoBet::getSpots(void) const
	{
		return m_spots;
	}
    // Retorna um vector<int> com os valores apostados que o jogador escolheu até então.
    // @return O vector<int> com os valores apostados que o jogador escolheu até então.
    std::vector<int> KenoBet::getHits(const std::vector<int> &_hits) const
	{
		std::vector<int> acertos;

		for (int i = 0; i < 20; ++i)
		{
			for (auto j (0u); j < m_spots.size(); ++j)
			{
				if(_hits[i] == m_spots[j])
                {
					acertos.push_back(_hits[i]);
				}
			}
		}
		
		return acertos;
	}
    // ----------------------------------------------------------------------------------------
    // Setters
    // ----------------------------------------------------------------------------------------
    // Sets Define a quantidade de dinheiro que o jogador está investindo.
    // @param _wage Investimento.
    // @return True se existir um valor acima de zero; false caso contrário.
	bool KenoBet::setWage(float _wage)
	{
		m_wage = _wage;
		return m_wage;

	}
    // ----------------------------------------------------------------------------------------
    // Methods
    // ----------------------------------------------------------------------------------------
    //Reinicie a aposta para um estado vazio.
	void KenoBet::reset(void)
    {
        m_spots.clear();
	}
    // Adiciona um numero aos valores apostados somente se o valor não estiver lá.
    // @param _spot O valor que desejamos incluir na aposta.
    // @return T Se o número escolhido é inserido com sucesso; F caso contrário.
    bool KenoBet::addNumber(int _spot)
	{
	    if(_spot >= 1 && _spot <= 80 && !InArray(_spot, m_spots ))
        {
            m_spots.push_back(_spot);
            return true;
	    }
	    else{
            return false;
		}	
	}
    // Retorna o número atual de valores na aposta do jogador.
    // @return Número atual de valores na aposta do jogador.
    std::size_t KenoBet::numChosen(void) const
    {
        return m_spots.size();
    }
