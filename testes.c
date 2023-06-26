#include "chamadas.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

void testes(void) {
  int erro = OK;
  // ---- FUNÇÃO DE CRIAR JOGO ----
  Jogo *resultado;
  printf("\n----TESTE FUNÇÃO DE CRIAR JOGO----\n");
  printf("Teste 1: Criar jogo com parâmetros válidos\n");
  resultado = criaJogo("Doom", 10.0);
  printf("RESULTADO ESPERADO: SUCESSO!\n");
  printf("RESULTADO OBTIDO:");
  if (resultado && strcmp(resultado->nome, "Doom") == 0 &&
      resultado->preco < 10.1 && resultado->preco > 9.9) {
    printf("SUCESSO!\n");
  } else {
    printf("FALHA!\n");
  }
  printf("\n----FIM TESTE FUNÇÃO CRIAR JOGO----\n");

  // ---- FUNÇÃO DE CRIAR ITEM ----
  Item *itemCriado;
  printf("\n----TESTE FUNÇÃO DE CRIAR ITEM----\n");
  printf("\nTeste 1: Criar jogo com parâmetros válidos\n");
  resultado = criaJogo("Doom", 10.0);
  printf("RESULTADO ESPERADO: SUCESSO!\n");
  printf("RESULTADO OBTIDO:");
  if (resultado && strcmp(resultado->nome, "Doom") == 0 &&
      resultado->preco < 10.1 && resultado->preco > 9.9) {
    printf("SUCESSO!\n");
  } else {
    printf("FALHA!\n");
  }
  printf("\n----FIM TESTE FUNÇÃO CRIAR JOGO----\n");

  // ---- FUNÇÃO DE INSERIR JOGO ----
  printf("\n----TESTE FUNÇÃO DE INSERIR JOGO----\n");
  Item *cat = criaCatalogo();
  printf("Teste 1: Inserir jogo não existente no catálogo\n");
  cat = inserirJogo(cat, "Doom", 10, &erro);
  printf("RESULTADO ESPERADO: SUCESSO!\t");
  printf("RESULTADO OBTIDO:");
  trataErros(&erro);
  printf("\nTeste 2: Inserir jogo já existente no catálogo\n");
  cat = inserirJogo(cat, "Doom", 12, &erro);
  printf("RESULTADO ESPERADO: ERRO: O JOGO JÁ EXISTE NO CATÁLOGO!\n");
  printf("RESULTADO OBTIDO:");
  trataErros(&erro);
  printf("\nTeste 3: Inserir jogo com dado inválido\n");
  cat = inserirJogo(cat, "Botw", -1, &erro);
  printf("RESULTADO ESPERADO: ERRO: DADO INSERIDO INVÁLIDO\n");
  printf("RESULTADO OBTIDO:");
  trataErros(&erro);
  printf("\n----FIM TESTE FUNÇÃO INSERIR JOGOS----\n");

  // ---- FUNÇÃO DE BUSCAR JOGO ----
  printf("\n----TESTE FUNÇÃO DE BUSCAR JOGOS----\n");
  printf("\nTeste 1: buscar jogo existente\n");
  Item *encontrado = buscaJogo(cat, "Doom");
  printf("RESULTADO ESPERADO: Doom\n");
  printf("RESULTADO OBTIDO: %s\n", encontrado->jogo->nome);

  printf("\nTeste 2: buscar jogo não existente\n");
  encontrado = buscaJogo(cat, "Battlefield");
  printf("RESULTADO ESPERADO: jogo fora do catalogo\n");
  printf("RESULTADO OBTIDO: ");
  if (!encontrado) {
    printf("jogo fora do catalogo\n");
  } // conferir

  printf("----FIM DO TESTE BUSCAR JOGOS----\n");

  printf("\n----INICIO TESTE ALTERA NOME----\n");
  printf("\nTeste 1: alterar nome de jogo existente\n");
  char nome[30] = "Doom";
  char novoNome[30] = "DM";
  char *naoExiste = "lotr";
  Item *modificado = alteraNome(cat, nome, novoNome, &erro);
  printf("RESULTADO ESPERADO: SUCESSO!\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);

  printf("\nTeste 2: alterar nome de jogo não existente\n");
  modificado = alteraNome(cat, naoExiste, novoNome, &erro);
  printf("RESULTADO ESPERADO: ERRO: O JOGO NÃO EXISTE NO CATÁLOGO\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);

  printf("\n----FIM TESTE ALTERA NOME----\n");

  printf("\n----INICIO TESTE ALTERA PREÇO----\n");
  float newprice;
  newprice = 12.5;

  modificado = alteraPreco(cat, novoNome, &newprice, &erro);
  printf("\nTeste 1: alterar preço de jogo existente\n");
  printf("RESULTADO ESPERADO: SUCESSO!\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);

  printf("\nTeste 2: alterar preço de jogo não existente\n");
  modificado = alteraPreco(cat, naoExiste, &newprice, &erro);
  printf("RESULTADO ESPERADO: ERRO: O JOGO NÃO EXISTE NO CATÁLOGO\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);

  strcpy(novoNome, "DM");
  newprice = -10.0;
  printf("\nTeste 3: alterar preço de jogo com dado invalido\n");
  modificado = alteraPreco(cat, novoNome, &newprice, &erro);
  printf("RESULTADO ESPERADO: ERRO: DADO INVALIDO\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);

  printf("----FIM TESTE ALTERA PREÇO----\n");

  printf("\n----INICIO TESTE ALTERA QUANTIDADE----");
  int des;
  des = 10;
  printf("\nTeste 1: alterar quantidade com dados validos\n");
  modificado = alteraQuantidade(cat, novoNome, &des, &erro);
  printf("RESULTADO ESPERADO: SUCESSO!\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);

  des = -100;
  printf("\nTeste 2: alterar quantidade com dados invalidos\n");
  modificado = alteraQuantidade(cat, novoNome, &des, &erro);
  printf("RESULTADO ESPERADO: ERRO: DADO INVALIDO\n");
  printf("RESULTADO OBTIDO: "); // conferir
  trataErros(&erro);

  printf("\n----FIM TESTE ALTERA QUANTIDADE----\n");

  printf("\n----INÍCIO TESTE ALTERAR ESTOQUE----\n");
  Estoque *estoque = cat->estoque;
  des = 10;
  printf("\nTeste 1: alterar estoque com dado valido\n");
  estoque = alteraEstoque(estoque, 10, &erro);
  printf("RESULTADO ESPERADO: SUCESSO!\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);

  printf("\n----FIM TESTE ALTERA ESTOQUE----\n");

  // ---- FUNÇÃO DE REMOVER JOGO ----
  printf("\n----INÍCIO TESTE REMOVER JOGO----\n");

  printf("\nTeste 1: remover jogo existente no catálogo\n");
  cat = removeJogo(cat, novoNome, &erro);
  printf("RESULTADO ESPERADO: SUCESSO!\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);

  printf("\nTeste 2: remover jogo não existente\n");
  cat = removeJogo(cat, "blabla", &erro);
  printf("RESULTADO ESPERADO: ERRO: O JOGO NÃO EXISTE NO CATÁLOGO\n");
  printf("RESULTADO OBTIDO: ");
  trataErros(&erro);

  printf("\n--------FIM DOS TESTES---------\n\n");

  printf("\n----TESTES DE COMUNICACAO----\n");

  FILE* teste1 = fopen("teste1.xml","r");
}