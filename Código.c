#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO 1000
#define false 0
#define true 1

typedef int bool;
typedef char *string; // abreviando o tipo string

/* Implementacao da estrutura de dados que vai guardar a lista de linhas */

// representa o registro da linha => noh
typedef struct {
  string linha;
  int indice;
  struct LINHA *proximo; // proximo noh
} LINHA;

// representa a lista de linhas => lista ligada
typedef struct {
  LINHA *primeiro; // comeco das linhas
} LISTA_DAS_LINHAS;

// cria uma nova lista
LISTA_DAS_LINHAS *CriarListaDasLinhas() {
  LISTA_DAS_LINHAS *lista =
      (LISTA_DAS_LINHAS *)malloc(sizeof(LISTA_DAS_LINHAS));

  lista->primeiro = NULL;

  return lista;
}

// cria uma novo estrutura LINHA
LINHA *CriarLinha(string linhaNova, int indiceNovo) {

  LINHA *novo = (LINHA *)malloc(sizeof(LINHA));

  novo->indice = indiceNovo;
  novo->proximo = NULL;
  novo->linha = (string)malloc((TAMANHO + 1) * sizeof(char));

  novo->linha = linhaNova;

  return novo;
}

// funcao para inserir uma linha na lista
void InserirLinha(LISTA_DAS_LINHAS *lista, LINHA *linha) {
  LINHA *corrente = lista->primeiro;

  if (corrente == NULL)
    lista->primeiro = linha;
  else {
    while (corrente->proximo != NULL) {
      corrente = corrente->proximo;
    }

    corrente->proximo = linha;
  }
}

// funcao para medir o tamanho de uma lista de indices
int TamanhoLinhas(LISTA_DAS_LINHAS *lista) {
  LINHA *corrente = lista->primeiro;
  int i = 0;

  while (corrente != NULL) {
    corrente = corrente->proximo;
    i++;
  }

  return i;
}

// Função para buscar uma linha pelo indice
LINHA *BuscarLinha(LISTA_DAS_LINHAS *lista, int indiceBuscado) {
  LINHA *atual = lista->primeiro;

  while (atual != NULL) {
    if (atual->indice == indiceBuscado) {
      // Linha encontrada
      return atual;
    }
    // Busca proximo elemento
    atual = atual->proximo;
  }

  // Linha não encontrada
  return NULL;
}

/* Implementacao da estrutura de dados que vai guardar os indices */

typedef struct {
  int indice;
  struct INDICE *proximo;
} INDICE;

typedef struct {
  INDICE *primeiro;
} LISTA_INDICE;

// cria uma nova lista
LISTA_INDICE *CriarListaDeIndices() {
  LISTA_INDICE *lista = (LISTA_INDICE *)malloc(sizeof(LISTA_INDICE));

  lista->primeiro = NULL;

  return lista;
}

// cria uma novo estrutura INDICE
INDICE *CriarIndice(int indiceNovo) {

  INDICE *novo = (INDICE *)malloc(sizeof(INDICE));

  novo->indice = indiceNovo;
  novo->proximo = NULL;

  return novo;
}

// funcao para inserir um indice na lista
void InserirIndice(LISTA_INDICE *lista, INDICE *linha) {
  INDICE *corrente = lista->primeiro;

  if (corrente == NULL)
    lista->primeiro = linha;
  else {
    while (corrente->proximo != NULL) {
      corrente = corrente->proximo;
    }

    corrente->proximo = linha;
  }
}

// funcao para medir tamanho de lista de indices
int TamanhoIndice(LISTA_INDICE *lista) {
  INDICE *corrente = lista->primeiro;
  int i = 0;

  while (corrente != NULL) {
    corrente = corrente->proximo;
    i++;
  }

  return i;
}

// Função para buscar um indice
INDICE *BuscarIndice(LISTA_INDICE *lista, int indiceBuscado) {
  INDICE *atual = lista->primeiro;

  while (atual != NULL) {
    if (atual->indice == indiceBuscado) {
      // Linha encontrada
      return atual;
    }
    // Busca proximo elemento
    atual = atual->proximo;
  }

  // Linha não encontrada
  return NULL;
}

/* Implementacao da estrutura de dados que vai indexar as palavras - LISTA
 * LIGADA */

typedef struct {
  string palavra;
  LISTA_INDICE *indice;
  struct ELEMENTO_PALAVRA *proximo;
} ELEMENTO_PALAVRA;

typedef struct {
  ELEMENTO_PALAVRA *primeiro;
} LISTA_ELEMENTO_PALAVRAS;

// cria uma nova lista
LISTA_ELEMENTO_PALAVRAS *CriarListaDePalavras() {
  LISTA_ELEMENTO_PALAVRAS *lista =
      (LISTA_ELEMENTO_PALAVRAS *)malloc(sizeof(LISTA_ELEMENTO_PALAVRAS));

  lista->primeiro = NULL;

  return lista;
}

// cria uma novo estrutura ELEMENTO_PALAVRA
ELEMENTO_PALAVRA *CriarPalavra(string palavraNova, LISTA_INDICE *indiceNovo) {
  ELEMENTO_PALAVRA *novo = (ELEMENTO_PALAVRA *)malloc(sizeof(ELEMENTO_PALAVRA));

  novo->palavra = palavraNova;
  novo->indice = indiceNovo;
  novo->proximo = NULL;

  return novo;
}

// funcao para inserir uma palavra na lista
void InserirPalavra(LISTA_ELEMENTO_PALAVRAS *lista, ELEMENTO_PALAVRA *palavra) {
  ELEMENTO_PALAVRA *corrente = lista->primeiro;

  if (corrente == NULL)
    lista->primeiro = palavra;
  else {
    while (corrente->proximo != NULL) {
      corrente = corrente->proximo;
    }

    corrente->proximo = palavra;
  }
}

// funcao para medir tamanho de lista de palavras
int TamanhoListaDePalavras(LISTA_ELEMENTO_PALAVRAS *lista) {
  ELEMENTO_PALAVRA *corrente = lista->primeiro;
  int i = 0;

  while (corrente != NULL) {
    corrente = corrente->proximo;
    i++;
  }

  return i;
}

// Função para buscar uma palavra
ELEMENTO_PALAVRA *BuscarPalavra(LISTA_ELEMENTO_PALAVRAS *lista,
                                string palavraBuscada) {
  ELEMENTO_PALAVRA *atual = lista->primeiro;

  while (atual != NULL) {
    if (strcmp(atual->palavra, palavraBuscada) == 0) {
      // Palavra encontrada
      return atual;
    }
    // Busca proximo elemento
    atual = atual->proximo;
  }

  // Palavra não encontrada
  return NULL;
}

/* Implementacao da estrutura de dados que vai indexar as palavras - ARVORE
 * BINARIA */

typedef struct {
  string palavra;
  LISTA_INDICE *indice;
  struct NO_PALAVRA *esquerda;
  struct NO_PALAVRA *direita;
} NO_PALAVRA;

typedef struct {
  NO_PALAVRA *raiz;
} ARVORE_NO_PALAVRAS;

// cria uma nova arvore
ARVORE_NO_PALAVRAS *CriarArvoreDePalavras() {
  ARVORE_NO_PALAVRAS *arvore =
      (ARVORE_NO_PALAVRAS *)malloc(sizeof(ARVORE_NO_PALAVRAS));

  arvore->raiz = NULL;

  return arvore;
}

// cria uma novo estrutura NO_PALAVRA
NO_PALAVRA *CriarNoPalavra(string palavraNova, LISTA_INDICE *indiceNovo) {
  NO_PALAVRA *novo = (NO_PALAVRA *)malloc(sizeof(NO_PALAVRA));

  novo->palavra = palavraNova;
  novo->indice = indiceNovo;
  novo->esquerda = NULL;
  novo->direita = NULL;

  return novo;
}

// funcao para inserir um no na arvore
void *InserirNaArvore(NO_PALAVRA **raiz, NO_PALAVRA *palavra) {
  if (*raiz == NULL) {
    *raiz = palavra;
  } else {
    int comparacao = strcmp(palavra->palavra, (*raiz)->palavra);

    if (comparacao < 0)
      InserirNaArvore(&((*raiz)->esquerda), palavra);
    else if (comparacao > 0)
      InserirNaArvore(&((*raiz)->direita), palavra);
  }
}

// funcao para buscar uma palavra na arvore
NO_PALAVRA *BuscarNaArvore(NO_PALAVRA *raiz, string alvo) {
  if (raiz == NULL)
    return NULL;

  int comparacao = strcmp(alvo, raiz->palavra);

  if (comparacao == 0)
    return raiz;

  if (comparacao < 0)
    return BuscarNaArvore(raiz->esquerda, alvo);
  else
    return BuscarNaArvore(raiz->direita, alvo);
}

/* Substituindo strsep do codigo */
char *strsep2(char **stringp, const char *delim) {
  char *rv = *stringp;
  if (rv) {
    *stringp += strcspn(*stringp, delim);
    if (**stringp)
      *(*stringp)++ = '\0';
    else
      *stringp = 0;
  }
  return rv;
}

/* Metodo que vai executar o programa */
int main(int argc, char **argv) {

  FILE *in; // arquivo de entrada
  char *linha;
  char *copia_ponteiro_linha;
  char *quebra_de_linha;
  char *palavra;
  int contador_linha;

  if (argc == 3) {
    LISTA_DAS_LINHAS *listaDeLinhas = CriarListaDasLinhas();

    if (strcmp(argv[2], "arvore") == 0) {
      printf("Tipo de indice: \'%s\'\n", argv[2]);
      printf("Arquivo texto: \'%s\'\n", argv[1]);

      ARVORE_NO_PALAVRAS *arvoreDePalavras = CriarArvoreDePalavras();

      clock_t timer[2];

      timer[0] = clock();

      in = fopen(argv[1], "r"); // abre o arquivo para ser lido

      contador_linha = 0;
      linha =
          (char *)malloc((TAMANHO + 1) * sizeof(char)); // cria array da linha

      while (in &&
             fgets(linha, TAMANHO, in)) { // atribui a linha a linha do arquivo

        if ((quebra_de_linha = strrchr(linha, '\n')))
          *quebra_de_linha = 0; // retorna o ponteiro para a ocorrência de '\n'
                                // e substitui por '\0'

        char *linhaCopiada = (char *)malloc((TAMANHO + 1) * sizeof(char));
        ;
        strcpy(linhaCopiada, linha);

        LINHA *respectivaLinha = CriarLinha(linhaCopiada, contador_linha + 1);

        InserirLinha(listaDeLinhas, respectivaLinha);

        // fazemos uma copia do endereço que corresponde ao array de chars
        // usado para armazenar cada linha lida do arquivo pois a função
        // 'strsep' modifica o endereço do ponteiro a cada chamada feita a esta
        // função (e não queremos que 'linha' deixe de apontar para o inicio do
        // array).

        copia_ponteiro_linha =
            linha; // copia o endereço de 'linha' para 'copia_ponteiro_linha'

        while ((palavra = strsep2(
                    &copia_ponteiro_linha,
                    " -?.!,:;/[]\\\"\'<>#@$%&()|"))) { // separamos as palavras
                                                       // da linha
          // entre ' ' e armazenamos em palavra

          // antes de guardar a palavra em algum tipo de estrutura usada
          // para implementar o índice, será necessário fazer uma copia
          // da mesma, uma vez que o ponteiro 'palavra' aponta para uma
          // substring dentro da string 'linha', e a cada nova linha lida
          // o conteúdo da linha anterior é sobreescrito.

          for (int i = 0; palavra[i]; ++i)
            palavra[i] = tolower(palavra[i]);

          NO_PALAVRA *palavraJaExiste =
              BuscarNaArvore(arvoreDePalavras->raiz, palavra);

          INDICE *indicePraInserir = CriarIndice(contador_linha + 1);

          if (palavraJaExiste != NULL) {
            InserirIndice(palavraJaExiste->indice, indicePraInserir);
          } else {
            LISTA_INDICE *listaDeIndices = CriarListaDeIndices();

            InserirIndice(listaDeIndices, indicePraInserir);

            NO_PALAVRA *palavraPraInserir =
                CriarNoPalavra(palavra, listaDeIndices);

            InserirNaArvore(&(arvoreDePalavras->raiz), palavraPraInserir);
          }
        }

        contador_linha++;
        linha = (char *)malloc((TAMANHO + 1) * sizeof(char));
      }

      fclose(in);

      timer[1] = clock();

      double tempoDeExecucao = (timer[1] - timer[0]) * 1000.0 / CLOCKS_PER_SEC;

      printf("Numero de linhas no arquivo: %d\n", TamanhoLinhas(listaDeLinhas));

      printf("Tempo para carregar o arquivo e construir o indice: %g ms\n",
             tempoDeExecucao);

      char comando[TAMANHO];
      char palavra[TAMANHO];

      while (true) {
        printf("> ");
        scanf("%s", comando);

        if (strcmp(comando, "fim") == 0)
          break;
        else if (strcmp(comando, "busca") == 0) {

          scanf("%s", palavra);

          clock_t timerBusca[2];

          for (int i = 0; palavra[i]; i++)
            palavra[i] = tolower(palavra[i]);

          timerBusca[0] = clock();

          NO_PALAVRA *palavraAchada =
              BuscarNaArvore(arvoreDePalavras->raiz, palavra);

          timerBusca[1] = clock();

          if (palavraAchada != NULL) {
            printf("Existem %d ocorrências da palavra \'%s\' na(s) "
                   "seguinte(s) linha(s):\n",
                   TamanhoIndice(palavraAchada->indice), palavra);

            INDICE *atual = palavraAchada->indice->primeiro;

            LISTA_INDICE *listaDeIndicesJaRetornados = CriarListaDeIndices();

            while (atual != NULL) {
              LINHA *linhaBuscada = BuscarLinha(listaDeLinhas, atual->indice);

              if (BuscarIndice(listaDeIndicesJaRetornados, atual->indice) ==
                  NULL)
                printf("%05d: %s\n", atual->indice, linhaBuscada->linha);

              INDICE *indiceJaInserido = CriarIndice(atual->indice);
              InserirIndice(listaDeIndicesJaRetornados, indiceJaInserido);
              atual = atual->proximo;
            }

          } else {
            printf("Palavra \'%s\' nao encontrada.\n", palavra);
          }

          double tempoDeBusca =
              (timerBusca[1] - timerBusca[0]) * 1000.0 / CLOCKS_PER_SEC;

          printf("Tempo de busca: %g ms\n", tempoDeBusca);
        } else {
          printf("Opcao invalida!\n");
        }
      }

    } else if (strcmp(argv[2], "lista") == 0) {
      printf("Tipo de indice: \'%s\'\n", argv[2]);
      printf("Arquivo texto: \'%s\'\n", argv[1]);

      LISTA_ELEMENTO_PALAVRAS *listaDePalavras = CriarListaDePalavras();

      clock_t timer[2];

      timer[0] = clock();

      in = fopen(argv[1], "r"); // abre o arquivo para ser lido

      contador_linha = 0;
      linha =
          (char *)malloc((TAMANHO + 1) * sizeof(char)); // cria array da linha

      while (in &&
             fgets(linha, TAMANHO, in)) { // atribui a linha a linha do arquivo

        if ((quebra_de_linha = strrchr(linha, '\n')))
          *quebra_de_linha = 0; // retorna o ponteiro para a ocorrência de '\n'
                                // e substitui por '\0'

        char *linhaCopiada = (char *)malloc((TAMANHO + 1) * sizeof(char));
        ;
        strcpy(linhaCopiada, linha);

        LINHA *respectivaLinha = CriarLinha(linhaCopiada, contador_linha + 1);

        InserirLinha(listaDeLinhas, respectivaLinha);

        // fazemos uma copia do endereço que corresponde ao array de chars
        // usado para armazenar cada linha lida do arquivo pois a função
        // 'strsep' modifica o endereço do ponteiro a cada chamada feita a esta
        // função (e não queremos que 'linha' deixe de apontar para o inicio do
        // array).

        copia_ponteiro_linha =
            linha; // copia o endereço de 'linha' para 'copia_ponteiro_linha'

        while ((palavra = strsep2(
                    &copia_ponteiro_linha,
                    " -?.!,:;/[]\\\"\'<>#@$%&()|"))) { // separamos as palavras
                                                       // da linha
          // entre ' ' e armazenamos em palavra

          // antes de guardar a palavra em algum tipo de estrutura usada
          // para implementar o índice, será necessário fazer uma copia
          // da mesma, uma vez que o ponteiro 'palavra' aponta para uma
          // substring dentro da string 'linha', e a cada nova linha lida
          // o conteúdo da linha anterior é sobreescrito.

          for (int i = 0; palavra[i]; ++i)
            palavra[i] = tolower(palavra[i]);

          ELEMENTO_PALAVRA *palavraJaExiste =
              BuscarPalavra(listaDePalavras, palavra);

          INDICE *indicePraInserir = CriarIndice(contador_linha + 1);

          if (palavraJaExiste != NULL) {
            InserirIndice(palavraJaExiste->indice, indicePraInserir);
          } else {
            LISTA_INDICE *listaDeIndices = CriarListaDeIndices();

            InserirIndice(listaDeIndices, indicePraInserir);

            ELEMENTO_PALAVRA *palavraPraInserir =
                CriarPalavra(palavra, listaDeIndices);

            InserirPalavra(listaDePalavras, palavraPraInserir);
          }
        }

        contador_linha++;
        linha = (char *)malloc((TAMANHO + 1) * sizeof(char));
      }

      fclose(in);

      timer[1] = clock();

      double tempoDeExecucao = (timer[1] - timer[0]) * 1000.0 / CLOCKS_PER_SEC;

      printf("Numero de linhas no arquivo: %d\n", TamanhoLinhas(listaDeLinhas));

      printf("Tempo para carregar o arquivo e construir o indice: %g ms\n",
             tempoDeExecucao);

      char comando[TAMANHO];
      char palavra[TAMANHO];

      while (true) {
        printf("> ");
        scanf("%s", comando);

        if (strcmp(comando, "fim") == 0)
          break;
        else if (strcmp(comando, "busca") == 0) {

          scanf("%s", palavra);

          clock_t timerBusca[2];

          for (int i = 0; palavra[i]; i++)
            palavra[i] = tolower(palavra[i]);

          timerBusca[0] = clock();

          ELEMENTO_PALAVRA *palavraAchada =
              BuscarPalavra(listaDePalavras, palavra);

          timerBusca[1] = clock();

          if (palavraAchada != NULL) {
            printf("Existem %d ocorrências da palavra \'%s\' na(s) "
                   "seguinte(s) linha(s):\n",
                   TamanhoIndice(palavraAchada->indice), palavra);

            INDICE *atual = palavraAchada->indice->primeiro;

            LISTA_INDICE *listaDeIndicesJaRetornados = CriarListaDeIndices();

            while (atual != NULL) {
              LINHA *linhaBuscada = BuscarLinha(listaDeLinhas, atual->indice);

              if (BuscarIndice(listaDeIndicesJaRetornados, atual->indice) ==
                  NULL)
                printf("%05d: %s\n", atual->indice, linhaBuscada->linha);

              INDICE *indiceJaInserido = CriarIndice(atual->indice);
              InserirIndice(listaDeIndicesJaRetornados, indiceJaInserido);
              atual = atual->proximo;
            }

          } else {
            printf("Palavra \'%s\' nao encontrada.\n", palavra);
          }

          double tempoDeBusca =
              (timerBusca[1] - timerBusca[0]) * 1000.0 / CLOCKS_PER_SEC;

          printf("Tempo de busca: %g ms\n", tempoDeBusca);
        } else {
          printf("Opcao invalida!\n");
        }
      }

    } else {
      printf("O tipo de indice escolhido eh inválido.\n ");
    }

    return 0;
  }
  return 1;
}
