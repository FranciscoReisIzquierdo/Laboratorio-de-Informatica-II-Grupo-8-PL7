#include "ListasLigadas.h"
#include <stdlib.h>

LISTA criar_lista(){
    LISTA l= NULL;
    return l;
}

LISTA insere_cabeca(LISTA L, void *valor){
    if(L== NULL){
        LISTA l= malloc(sizeof(NodoLista));
        l->valor= valor;
        l->proxCoord= NULL;
        L= l;
    }
    else {
        LISTA aux = L;
        LISTA l = malloc(sizeof(NodoLista));
        l->valor = valor;
        l->proxCoord = aux;
        L = l;
    }
    return L;
}

void *devolve_cabeca(LISTA L){
    if(L != NULL) return L-> valor;
}

LISTA proximo(LISTA L){
    if(L== NULL) return EXIT_SUCCESS;
    L= L->proxCoord;
    return L;
}

LISTA remove_cabeca(LISTA L){
    if(L== NULL) return EXIT_SUCCESS;
    else{
        LISTA Aux= L;
        L= L-> proxCoord;
        free(Aux-> valor);
    }
    return L;
}

int lista_esta_vazia(LISTA L){
    if(L== NULL) return 0;
    else return 1;
}

int numElementos(LISTA L){
    int num= 0;
    while(lista_esta_vazia(L)!= 0){
        num++;
        L= L->proxCoord;
    }
    return num;
}


