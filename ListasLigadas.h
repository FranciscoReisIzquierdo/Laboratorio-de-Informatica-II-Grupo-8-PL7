#ifndef PROJETOLI2_LISTASLIGADAS_H
#define PROJETOLI2_LISTASLIGADAS_H
#include "Camada de Dados.h"

typedef struct LISTALIG{
        COORDENADA coord;
    struct LISTALIG *proxCoord;
} NodoLista, *LISTA;

// Cria uma lista vazia
LISTA criar_lista();
// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, COORDENADA coord);
// Devolve a cabeça da lista
void *devolve_cabeca(LISTA L);
// Devolve a cauda da lista
LISTA proximo(LISTA L);
// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L);
// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L);
int numElementos(LISTA L);
void showLista(LISTA L);

#endif //PROJETOLI2_LISTASLIGADAS_H
