//////////////////////////
//	Matrizes esparsas  // 
////////////////////////

////////////////////////////////////
//	Cache de memória secundária  // 
//////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// Declaracao de constantes

const int MODULO = 5;

// Matriz esparsa = diretores são linhas, que contém vários elementos (em colunas)

// Matriz de modulo 5, ouseja trabalha com os restos (%) de 0 a 4

struct no {	
	
	int numero;
	struct no *proximoNo;

};

struct diretor {	
	
	int resto;  // valor de numero % MODUlO
	struct no *proximoNo;
	struct diretor *proximoDiretor;
	
}; 

struct diretor *cabeca = NULL;

// Funcao que procura ou cria um diretor

struct diretor *procurarDiretor(int resto) {
	
	struct diretor *ponteiro = cabeca; 

	while ((ponteiro != NULL) && 
			(ponteiro -> resto != resto)) {  // vai parar quando acabar os diretores, ou quando achar o certo
		
		ponteiro = ponteiro -> proximoDiretor;
		
	}
	
	if (ponteiro == NULL) { // SE não achar o diretor, criar um novo
		
		ponteiro = (struct diretor*) malloc(sizeof (struct diretor));
		
		ponteiro -> resto = resto;
		ponteiro -> proximoDiretor = cabeca;
		ponteiro -> proximoNo = NULL;
		cabeca = ponteiro; // insere o novo diretor no comeco (semelhante a pilha)
		
		
	} 
	
	return ponteiro;
	
}

void inserir (int numero) {
	
	struct diretor *diretorCerto = procurarDiretor(numero % MODULO);
	
	struct no *novoNo = (struct no*) malloc(sizeof (struct no));
	novoNo -> numero = numero;
	novoNo -> proximoNo = diretorCerto -> proximoNo;
	diretorCerto -> proximoNo = novoNo; // colunas também organizadas em forma de pilha
	
	
}

void imprimir () {
	
	struct diretor *ponteiroDiretor = cabeca;
	
	printf("==============\nResto\n");
	
	while (ponteiroDiretor != NULL) {
		
		printf("%d ->\t", ponteiroDiretor -> resto); // \n = tab
	
		struct no *ponteiroNo = ponteiroDiretor -> proximoNo;
	
		while (ponteiroNo != NULL) {
		
			printf("%d\t", ponteiroNo -> numero);
			ponteiroNo = ponteiroNo -> proximoNo;
		
		}
	
		printf("\n");
	
		ponteiroDiretor = ponteiroDiretor -> proximoDiretor;

	}
}

int main () {

	int i;

	for (i = 0; i < 10; i++) {
		
		inserir(i);
		
	}
	
	imprimir();

}
