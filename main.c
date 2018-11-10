#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "arvore.h"

Arvore* carregar_candidatos() {
  char linha[1024];
  FILE *arquivo = fopen("candidatos.csv", "r");
  
  //Descartar cabeÃ§alho do arquivo:
  fgets(linha, 1024, arquivo);
  
  //NÃºmero da coluna que contÃ©m cada informaÃ§Ã£o (0 Ã© a primeira):
  int campoNome = 18;
  int campoNumero = 16;
  int campoCargo = 14;
  int totalCampos = 57;
  
  //Arvore que serÃ¡ preenchida;
  Arvore *a = NULL;
  
  //Ler enquanto houver linhas:
  while(!feof(arquivo)) {
    //Ler uma linha do arquivo:
    if(fgets(linha, 1024, arquivo) == 0) {
      break;
    }
    
    //Estrutura que iremos preencher:
    Candidato c;
    
    //Inicializar busca por tokens:
    char *delimitadores = "\";";
    char *token = strtok(linha, delimitadores);
    
    int i;
    for(i = 0; i < totalCampos; i++) {
      //Verificar se o campo atual Ã© algum dos que nos interessa:
      if(i == campoNome) {
        strcpy(c.nome, token);
      } else if(i == campoNumero) {
        sscanf(token, "%d", &(c.numero));
      } else if(i == campoCargo) {
        strcpy(c.cargo, token);
      }
      
      //AvanÃ§ar para o prÃ³ximo token:
      token = strtok(NULL, delimitadores);
    }
    
    //Os campos do candidato foram preenchidos, vamos adicionÃ¡-lo Ã  Ã¡rvore:
    a = arvore_inserir(a, c);
  }
  
  //Retornar Ã¡rvore construÃ­da:
  return a;
}

void buscar_por_numero(Arvore *candidatos) {
	
	setlocale(LC_ALL, "Portuguese");
	int candNumero;
	printf("Digite o numero de seu candidato: ");
	scanf("%d", &candNumero);
	printf("\n");
	if ((arvore_buscar(candidatos, candNumero))==NULL) {
		printf("Candidato não registrado! \n\n");
	}
	//Implemente
}

void imprimir_todos(Arvore *candidatos) {

	printf("\n");
	arvore_imprime_em_ordem(candidatos);
  //Implemente
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	Arvore *candidatos = carregar_candidatos();
	while(1) {
	    printf("O que deseja fazer?\n[1] Procurar candidato pelo numero de canditadura\n[2] Mostrar candidatos em ordem numerica\n[3] Sair\n\n>> ");
	    int opcao;
	    scanf("%d", &opcao);
    
	    if(opcao == 1) {
	      buscar_por_numero(candidatos);
	    } else if(opcao == 2) {
	      imprimir_todos(candidatos);
	    } else if(opcao == 3) {
	      return 0;
	    } else {
	      printf("Opção invalida!\n");
    	}
  	}
}
