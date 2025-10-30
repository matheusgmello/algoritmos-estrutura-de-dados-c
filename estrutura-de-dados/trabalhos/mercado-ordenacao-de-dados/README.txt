Tudo bem professor!!

Optei por usar um #define para controlar o tamanho do vetor, no caso ainda possui os valores originais estabelecidos,
ai dentro do main usei um rand para gerar numeros aleatorios, mantendo os 20 valores originais.

Também usei um system clear para limpar a tela, pois quando são muitos numeros fica dificil de ver o terminal

Um dos problemas é usar o valor muito pequeno de elementos, pois acaba que o algoritmo faz em um tempo muito curto e sempre acaba aparecendo 00.00 ms, entao já deixei pré estabelido um alto valor para o vetor como "50 000"

Sobre os algoritmos mais dificeis de estruturar optei por essa forma.

O Quick Sort e Merge Sort foi dividido em três funções:

particiona() → separa o vetor em duas partes com base em um pivo, contando comparacoes e trocas.

quickSortRecursivo() → aplica a recusao para particao nas subpartes.

ordenaQuick() → funcao principal que inicia o processo, mede o tempo e exibe os resultados.

Merge Sort: 

merge() → junta duas metades ordenadas em um umnico vetor.

mergeSortRecursivo() → divide o vetor em partes menores e chama merge() para combinar.

ordenaMerge() → controla o processo completo, cria o vetor auxiliar, mede o tempo e exibe os resultados.