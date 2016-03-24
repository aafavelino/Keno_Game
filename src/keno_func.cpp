/*!
 *  @file keno_func.cpp
 *  @brief Arquivo com as funcoes utilizadas no programa.
 *
 *  Arquivo com as funcoes auxiliares utilizadas no programa, para verificacoes ou organizacao do codigo.
 */	

#include "keno_c.h"

    // Funcao usada para verificar se um determinado numero ja esta no vetor.
    // @param candidate Valor a ser verificado.
    // @param actualVec Vetor do tipo vector com os numeros que se encontram na linha da aposta.
	bool InArray( int candidate, std::vector<int>& actualVec )
	{
	    for(auto i (0u); i < actualVec.size(); ++i)
    	{
        	    if(candidate == actualVec[i])
            	    return true;
    	}
    	return false;
	}

    // A estratégia consiste em rearranjar as chaves 'q' de modo que as chaves "menores" precedam as chaves "maiores". 
    // Em seguida o quicksort ordena as duas sublistas de chaves menores e maiores ate que o vetor se encontre ordenado.
    // @param vetor Vetor passado por referencia para ser ordenado.
    // @param ini Valor inicial do vetor mais a esquerda.
    // @param fim Valor final do vetor mais a direita.
	void quicksort(std::vector<int>& vetor,int ini, int fim){
	    int q = ini,i,aux,j;
	    
	    for(i = ini+1 ; i <= fim ; i++)
	    {
	        j = i;
	        if(vetor[j] < vetor[q])
	        {
	         aux = vetor[j];
	         for(j = i; j > q ; j-- )
	         {    
	            vetor[j] = vetor[j-1];
	            
	         }
	         vetor[j] = aux;
	         q++;        
	        }  
	    }
	    if(q-1 > ini)
	    {
	        quicksort(vetor, ini, q-1);
	    }
	    if(q+1 < fim)
	    {
	        quicksort(vetor, q+1, fim);
	    }
	 }

































