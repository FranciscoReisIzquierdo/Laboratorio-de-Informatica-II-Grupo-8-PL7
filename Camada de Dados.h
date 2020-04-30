/**
@file Camada_de_Dados.h
Definição do estado e das funções que o manipulam
*/

#ifndef PROJETOLI2_CAMADA_DE_DADOS_H
#define PROJETOLI2_CAMADA_DE_DADOS_H

/**
\brief Tipo de dados para a casa
*/
typedef enum {VAZIO, BRANCA, PRETA, POS1, POS2} CASA;

/**
\brief Tipo de dados para as coordenadas
*/
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

/**
\brief Tipo de dados para a jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
\brief Tipo de dados para as jogadas
*/
typedef JOGADA JOGADAS[32];


/**
\brief Tipo de dados para o estado
*/
typedef struct {
    /** O tabuleiro */
    CASA tab[8][8];
    /** Coordenada da última jogada efectuada */
    COORDENADA ultima_jogada;
    /** As jogadas */
    JOGADAS jogadas;
    /** O número de jogadas efectuadas */
    int num_jogadas;
    /** Jogador atual */
    int jogador_atual;
} ESTADO;

/**
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
@returns O novo estado
*/
ESTADO *inicializar_estado();

/**
\brief Retorna a coluna da última coordenada
 * @param e Apontador para o estado
 * @return Coluna da última coordenada
 */
int giveUltColuna(ESTADO *e);

/**
\brief Retorna a linha da última coordenada
 * @param e Apontador para o estado
 * @return Linha da última coordenada
 */
int giveUltLinha(ESTADO *e);

/**
\brief Incrementa o valor do número de jogadas efectuadas, isto implica aceder ao número de jogadas atual
 * @param e Apontador para o estado
 */
void incrJogada(ESTADO *e);

/**
\brief Muda o jogador atual após realizar-se uma jogada válida, isto implica aceder ao jogador atual
 * @param e Apontador para o estado
 */
void changePlayer(ESTADO *e);

/**
\brief Devolve o número do jogador que venceu o jogo
 * @param e Apontador para o estado
 * @return Número do jogador vencedor
 */
int winner(ESTADO *e);

/**
\brief Retorna a linha da última coordenada, mas do ponto de vista do tabuleiro
 * @param e Apontador para o estado
 * @return Linha da última coordenada
 */
int linhaAnterior(ESTADO *e);

/**
\brief Retorna a coluna da última coordenada, mas do ponto de vista do tabuleiro
 * @param e Apontador para o estado
 * @return Coluna da última coordenada
 */
char colunaAnterior(ESTADO *e);

/**
\brief Retorna a linha de uma coordenada pretendida
 * @param line Linha do tabuleiro
 * @return Linha convertida (do ponto de vista dos jogadores e não do array)
 */
int linhaaa(int line);

/**
\brief Retorna a coluna de uma coordenada pretendida
 * @param column Coluna do tabuleiro
 * @return Coluna convertida (do ponto de vista dos jogadores e não do array)
 */
char colunaaa(int column);

/**
\brief Informa sobre qual é o jogador a jogar
 * @param e Apontador para o estado
 * @return Número do jogador atual
 */
int jogAtual(ESTADO *e);

/**
\brief Informa sobre quantas jogadas já foram realizadas
 * @param e Apontador para o estado
 * @return Número total de jogadas realizadas até ao momento
 */
int numJogada(ESTADO*e);

#endif //PROJETOLI2_CAMADA_DE_DADOS_H