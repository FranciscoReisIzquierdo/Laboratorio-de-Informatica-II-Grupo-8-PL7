/**
@file ListasLigadas.h
Definição das Listas Ligadas e das suas funções
*/

#ifndef PROJETOLI2_LISTASLIGADAS_H
#define PROJETOLI2_LISTASLIGADAS_H
#include "Camada de Dados.h"

/**
\brief Tipo de dados para uma lista ligada
 */
typedef struct LISTALIG{
    void *valor;
    struct LISTALIG *proxCoord;
} NodoLista, *LISTA;

/**
\brief Cria uma lista vazia
 * @return Lista criada
 */
LISTA criar_lista();

/**
\brief Insere um valor na cabeça da lista
 * @param L Lista na qual vai ser introduzida o valor
 * @param coord Valor a introdzir
 * @return Lista resusltante da inserção do valor na lista inicial
 */
LISTA insere_cabeca(LISTA L, void *valor);

/**
\brief Devolve a cabeça da lista
 * @param L Lista da qual se pretende devolver a cabeça
 * @return Valor da cabeça da lista
 */
void *devolve_cabeca(LISTA L);

/**
\brief Devolve a cauda da lista
 * @param L Lista da qual se quer apenas a cauda
 * @return Cauda da lista
 */
LISTA proximo(LISTA L);

/**
\brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
 * @param L Lista que s pertende remover a cabeça
 * @return Lista resultante da remoção da cabeça da lista anterior
 */ 
LISTA remove_cabeca(LISTA L);

/**
\brief Devolve verdareiro se a lista é vazia
 * @param L Lista que vai ser analisada se está vazia ou não
 * @return Retorna 1 se a lista estiver vazia e retorna 0 caso contrário
 */
int lista_esta_vazia(LISTA L);

/**
\brief Conta o número de elemtentos que uma lista tem
 * @param L Lista que vai ser analisada
 * @return Número de elementos da lista
 */
int numElementos(LISTA L);

#endif //PROJETOLI2_LISTASLIGADAS_H
