#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct _arvore {
  struct _arvore *esquerda;
  struct _arvore *direita;
  Candidato cand;
};

Arvore* arvore_inserir(Arvore *a, Candidato cand.numero) {
	if(a == NULL) {
		Arvore *novo = (Arvore*) malloc(sizeof(Arvore));
		novo->cand = cand;
		novo->esquerda = NULL;
		novo->direita = NULL;
	return novo;
	}
	if(cand.numero < a->cand.numero) {
		a->esquerda = arv_inserir(a->esquerda, cand);
	} else {
		a->direita = arv_inserir(a->direita, cand);
	}
	return a;
}

Candidato* arvore_buscar(Arvore *a, int cand.numero) {
	if(a == NULL || a->cand.numero == cand.numero) {
		return a;
	}
	if(cand.numero < a->cand.numero) {
		return arv_buscar(a->esquerda, cand.numero);
	} else {
		return arv_buscar(a->direita, cand.numero);
	}
}

void arvore_imprime_em_ordem(Arvore *a) {
	if(a->direita != NULL) {
		arv_imprimir(a->direita);
	}
	printf("%lf\n", a->cand.numero);
	printf("%lf\n", a->cand.nome);
	printf("lf\n", a->cand.cargo);
	
	if(a->esquerda != NULL) {
		arv_imprimir(a->esquerda);
	}
}
