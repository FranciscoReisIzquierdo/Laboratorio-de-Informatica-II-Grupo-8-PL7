/**
@file Interface.h
Definição dos vários comandos (gr, ler, movs, pos, jog e jog2) e da parte gráfica do jogo Rastros
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Logica.h"
#include "ListasLigadas.h"

/**
\brief Esta função é responsável por mostrar o estado atual do jogo
 * @param e Apontador para o estado (atual)
 */
void mostrar_tabuleiro(ESTADO *e);

/**
\brief Função que permite ao jogador interagir com o programa (efectuando jogadas ou comandos), analisando o que o jogador efectua
 * @param e Apontador para o estado
 * @return Retorna 1 caso o jogo acabe, de forma a terminar o programa
 */
int interpretador(ESTADO *e);

/**
\brief Função responsável por em cada iteração, chamar a função que mostra o tabuleiro do jogo, as informações do jogo e o interpretador de comandos
 * @param e Apontador para o estado
 */
void prompt(ESTADO *e);

/**
\brief Função que dado a execução do comando gr, guarda num ficheiro de texto o estado em que se encontra o jogo
 * @param e Apontador para o estado
 * @param file Ficheiro de texto que foi anteriormente aberto aquando da execução do comando gr
 */
void guarda_tabuleiro(ESTADO *e, FILE *file);

/**
\brief Função que dado a execução do comando ler, lê de um ficheiro de texto o estado em que se encontrava o jogo quando foi guardado, atualizando o estado atual para o que fora guardado
 * @param e Apontador para o estado atual
 * @param file Ficheiro texto que contém o estado que foi guardado, bem como a lista de movimentos feito até à execução do comando gr
 */
void le_Tabuleiro(ESTADO *e, FILE *file);

/**
\brief Função que após cada jogada efectuada, guarda a coordenada correspondente na array de jogadas disponível na camada de dados do programa
 * @param e Apontador para o estado
 * @param c Coordenada a guardar pela função
 */
void guarda_jogada(ESTADO *e, COORDENADA c);

/**
\brief Função que ao executar o comando movs, imprime no ecrã a lista de todas as jogadas efectuadas por ambos os jogadores até ao momento
 * @param e Apontador para o estado
 */
void imprime_lista_jogadas(ESTADO *e);

/**
\brief Função que imprime na parte superior do ecrã, as informações relevantes aos jogadores, como qual o jogador a jogar (jogador atual), qual a coordenada atual (última jogada) e quantas jogadas foram efectuadas
 * @param e Apontador para o estado
 */
void infoDoJogo(ESTADO *e);

/**
\brief Função responsável por executar o comando pos, de forma a retornar a uma posição anterior e jogar a partir desta, avaliando se o núemro da jogada à qual se quer regressar é possível (caso seja igual ou maior não irá regressar), sendo o jogador 1 sempre o 1º a jogar após a execução do comando pos
 * @param e Apontador para o estado
 * @param numero Numero de jogadas efectuadas até então
 * @return Retorna 0 quando concluir a atualização do estado atual para um estado anterior
 */
int comandoPos(ESTADO *e, int numero);

/**
\brief Função auxiliar da função supramencionada, que verifica se o número da jogada à qual se pretende regressar é possível ou não, isto é se o número for maior ou igual qu o número de jogadas até então efectuadas é impossível
 * @param e Apontador para o estado
 * @param numero Número introduzido pelo jogador aquando da execução do comando pos
 * @return Retorna 1 caso dê para retornar à jogada pretendida e 0 caso contrário
 */
int numeroValido(ESTADO *e, int numero);

#ifndef PROJETOLI2_INTERFACE_H
#define PROJETOLI2_INTERFACE_H

#endif //PROJETOLI2_INTERFACE_H
