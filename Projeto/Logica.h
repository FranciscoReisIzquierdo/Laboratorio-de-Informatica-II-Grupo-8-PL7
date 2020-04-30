/**
@file Logica.h
Definição da lógica do jogo Rastros e do bot
*/

#ifndef PROJETOLI2_LOGICA_H
#define PROJETOLI2_LOGICA_H
#include "Camada de Dados.h"
#include "Interface.h"
#include "ListasLigadas.h"

/**
\brief Esta função é responsável por realizar as jogadas pretendidas pelos jogadores, bem como atualizar o estado do jogo, isto é atualizar o número de jogadas e o jogador atual
 * @param e Apontador para o estado
 * @param c Coordenada efectuada pelo jogador
 * @return Retorna um inteiro de forma a garantir a conclusão da jogada pretendida
 */
int jogar(ESTADO *e, COORDENADA c);

/**
\brief Esta função verifica se a coordenada pretendida pelo jogador é válida, avaliando todos os casos possíveis dado o estado atual do jogo
 * @param e Apontador para o estado
 * @param c Coordenada pretendida pelo jogador
 * @return Retorna 1 no caso de a jogada for válida e retorna 0 caso contrário
 */
int jogadaValida(ESTADO *e, COORDENADA c);

/**
\brief Esta função verifica, após uma jogada ser efectuada, se é possível continuar a jogar, (se o jogo acabou) avaliando todos os casos dado o estado atual do jogo
 * @param e Apontador para o estado
 * @return Retorna 1 caso o jogo tenha acabado (parabenizando o jogador vencedor), e retorna 0 caso contrário
 */
int jogoAcabou(ESTADO *e);

/**
\ Esta função (das mais importantes na implementação do bot) acumula numa lista ligada, todas as coordenadas vizinhas da coordenada atual e que não se encontram preenchidas
 * @param e Apontador para o estado
 * @return Lista com as várias coordenadas vizinhas e que estão livres
 */
LISTA vizinhas(ESTADO *e);

/**
\brief Esta função é responsável por fazer jogar aleatoriamente o bot para umas das coordenadas possíveis
 * @param vizinhasVazias Lista de coordenadas vizinhas da coordenada atual e que estão livres
 * @return Coordenada aleatória que o bot irá efectuar
 */
COORDENADA jogadaAleatoria(LISTA vizinhasVazias);

/**
\brief Esta é das funções que nos deu mais trabalho e que assenta na heurística de Monte Carlo Tree Search e que permite através de simulações de estados futuros escolher a melhor coordenada para o bot efectuar
 * @param e Apontador para o estado
 * @param L Lista de coordenadas possíveis que o bot pode fazer, avaliando uma a uma qual ou quais são as melhores a efectuar
 * @return Coordenada a efectuar pelo bot
 */
COORDENADA mcts(ESTADO *e, LISTA L);

/**
\brief Esta é uma função auxiliar que através de um simulação do próximo estado dada uma das coordenadas possíveis ao bot efectuar, verifica se o jogo vai acabar após o bot ter jogado
 * @param e Apontador para o estado
 * @param c Coordenada que o bot vai usar na simulação do próximo estado e vai avaliar se lhe permite ganhar
 * @return Número de casas preenchidas, sendo que este número vai ser usado para avaliar os vários casos se o jogo acaba ou não
 */
int jogoAcabouMCTS(ESTADO *e, COORDENADA c);

/**
\brief Esta função verifica quais as coordenadas da lista de coordenadas possíveis a efectuar, que lhe permitem perder, removendo-as da lista de jogadas
 * @param e Apontador para o estado
 * @param tmp Coordenada que o bot vai usar na simulação do próximo estado e vai avaliar se o faz perder
 * @return Retorna 1 se a coordenada o faz perder e retorna 0 caso contrário
 */
int verificaErro(ESTADO *e, COORDENADA tmp);

/**
\brief Esta função apenas serve para o bot ter em conta que se (por exemplo) for o jogador 1, então não irá querer jogar para as coordenadas vizinhas da casa vencedora do adversário
 * @param c Coordenada que o bot irá comparar com as casas vizinhas da casa vencedora do adversário
 * @return Retorna 2 caso a coordenada avaliada for uma das casas vizinhas da casa vencedora do jogador 1 e retorna 1 caso seja uma das casas vizinhas da casa vencedora do jogador 2
 */
int vizinhasDaCasaVencedora(COORDENADA c);

/**
\Esta função é capaz de simular até 2 estado futuros de forma a armazenar as coordenadas na lista de coordenadas possíveis que dão ao bot maior chance de não perder
 * @param e Apontador para o 1º estado futuro
 * @param melhoresJogadas Lista de jogadas que (após o bot ver que não existe nenhuma que o faz vencer) lhe permitem não perder
 * @return Lista de jogadas que dão ao bot maior chance de não perder para o adversário (caso o adversário esteja a preparar para o encurralar)
 */
LISTA mctsSearcing(ESTADO *e, LISTA melhoresJogadas);

int imprimeLista(LISTA L);

/**
\ Esta função, quando o jogo está "mais aberto", ou seja é impossível prever qual a melhor jogada a efectuar (pois tudo depende de como joga o adversário), faz com que o bot se aproxime da sua casa vencedora usando a heurística da Distância menor usando a distância Euclidiana
 * @param e Apontador para o estado
 * @param L Lista de jogadas que o bot pode fazer sem perder, mas também sem ganhar (pois nesta fase é impossível prever como o jogo pode desenrolar-se)
 * @return Coordenada mais próxima da casa vencedora do bot
 */
COORDENADA distancia_euclidiana(ESTADO *e, LISTA L);

#endif //PROJETOLI2_LOGICA_H
