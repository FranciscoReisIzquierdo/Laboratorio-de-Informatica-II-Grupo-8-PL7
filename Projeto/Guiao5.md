## Relatório do Guião 5

### Camada de Dados
Este módulo é com certeza um dos mais importantes do programa, uma vez que é nele onde estão definidas todas as estruturas a serem usadas ao longo do jogo como *CASA*, *COORDENADAS*, etc. Em baixo seguem as definições das várias estruturas definidas neste módulo.

**tab**: Armazena informação sobre o tabuleiro.
 
**ultima_jogada**: Indica a coordenada da última jogada.

**jogadas armazena**: Informação sobre as jogadas.

**num_jogadas**: Indica quantas jogadas foram efetuadas.

**jogador_atual**: Indica qual é o jogador a jogar.

**inicializar_estado**: Esta função cria um estado vazio (com o tabuleiro
inicializado), onde é identificado a posição vencedora do jogador 1 (*POS1*), a posição vencedora do jogador 2 (*POS2*) e onde se começa a jogar no tabuleiro (*BRANCA*).
As referências em itálico supramencionadas dizem respeito a uma das estruturas pré-definidas pelos docentes no *header file* da **Camada de Dados** onde correspondem aos tipos de casas, sendo que as restantes após uma jogada, a casa anterior fica preenchida por '#' (*PRETA*).

---

### Lógica do programa
Neste módulo é implementada a função que incrementa uma jogada, tal como o título refere, nste módulo é tratada a lógica do jogo em si. Assim, é criada a função **jogar**.
 
**jogar**: Esta função recebe o estado atual e uma coordenada e modifica
o estado ao jogar na casa correta se a jogada for válida. A função devolve
verdadeiro (valor diferente de zero) se for possível jogar e falso (zero) caso
não seja possível. 
Ao fim de realizar a jogada, a função mostra o tabuleiro com a jogada efectuada com a função **mostrar_tabuleiro** do módulo seguidamente explicado

---
### Interface do Programa
Neste módulo seguem duas tarefas a implementar: 
1. Mostrar o tabuleiro
2. Criar um interpretador de comandos. Neste guião é de salientar que iremos usar a função pré-definida do intrepretador de comandos sem a alterar.

 Para tal, segue-se a descrição de cada uma dessas tarefas.

##### Mostrar o tabuleiro
**mostrar_tabuleiro**: Função que recebe o estado do jogo e imprime o tabuleiro com esse dado estado.

##### Interpretador de comandos
O interpretador de comandos deverá funcionar da seguinte maneira:
  1. Ler uma linha (usando fgets)
  2. Separar a linha por espaços (por exemplo utilizando sscanf ou strtok)
  3. Conforme o comando a executar, chamar a função correspondente do
  interface ou da lógica do programa e depois do interface. 

**interpretador**: Função que recebe o estado atual do jogo e conforme os argumentos (neste caso *COORDENADAS*) da função **jogar**, aplica o comando da jogada a efectuar.

---
### Main
Módulo com a função main.

**main**: Como não podia faltar, a função main é a função principal onde se faz correr todo o processo em conjunto.
Desta forma, esta função recebe as funções principais de cada módulo supramencionada (**inicializar_estado**, **mostrar_tabuleiro** e **interpretador**).



