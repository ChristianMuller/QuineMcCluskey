/*Lê o numero de variáveis
 * 
 */
#include <iostream> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

unsigned long int *table;
unsigned long int *pos;
unsigned long int indice;
void contauns (unsigned long int linhas, unsigned long int colunas, unsigned long int tamanho);
int compara(const void *a, const void *b);
void numerodeuns (unsigned long int ones, unsigned long int posicao);
void imprime (unsigned long int *x,unsigned long int u, unsigned long int j);
unsigned long int removeiguais(unsigned long int linhas);

int main(void){
	unsigned long int i=0, colunas=0, linhas=0;
	printf("Digite o número de variáveis:");
	scanf("%lu", &colunas);
	linhas=exp2(colunas);
	pos = (unsigned long int*)calloc(linhas, sizeof(unsigned long int));
	printf("Digite as posições na tabela em que possui 1's:\nDigite duas linhas inválidas para finalizar:\n");
	scanf("%lu\n", &pos[i]);
	while((pos[i]<linhas)&&(i<linhas)){
		i++;
		scanf("%lu\n", &pos[i]);		
	}
	pos[i]=0;
	printf("%lu", i);
	qsort(pos, i, sizeof *pos, &compara);
	imprime(pos, 0, linhas-1);
	i=i-removeiguais(i);
	imprime(pos, 0, linhas-1);
	table = (unsigned long int*)calloc(i, sizeof(unsigned long int));
	contauns(linhas, colunas, i);
	delete pos;
	//qsort(pos, i, sizeof *pos, &compara);
	imprime(table, 0, i-1);	
	return 0;	
}

int compara(const void *a, const void *b){
return *(unsigned long int *)a - *(unsigned long int *)b;
}

void contauns (unsigned long int linhas, unsigned long int colunas, unsigned long int tamanho){
	unsigned long int aux=0, mask=1, ok=0, conta=0;
	for (unsigned long int j=0; j<tamanho; j++){
		aux=pos[j];
		for (unsigned long int i=0; i<(colunas); i++){
				ok=aux&mask;
				printf ("%lu", ok);
				conta=conta+ok;
				ok=aux;
				aux=(ok>>1);							
		}
		numerodeuns(conta, j);
		printf ("\n%lu\n", conta);
		conta=0;	
	}	
}
void numerodeuns (unsigned long int ones, unsigned long int posicao){
	unsigned long int mask;
	mask=ones<<27;
	printf("\nMASK:%lu", mask);
	table[posicao]=pos[posicao]|mask;
}	
void imprime (unsigned long int *x,unsigned long int u, unsigned long int j){
	unsigned long int i;
	printf(" {");
	for (i=u; i<=j; i++){
		printf("%lu", x[i]);
		if (i<j){
			printf(", ");
		}	
	}	
	printf ("}\n");	
}
unsigned long int removeiguais(unsigned long int linhas){
	unsigned long int j=0, aux=0, conta;
	for(unsigned long int i=0; i<linhas; i++){
		if(pos[aux]==pos[aux+1]){
			for(j=aux; j<linhas;j++){
				pos[j]=pos[j+1];
			 }
			 conta+=1;
		}else{
			aux++;
		}		 
	}
	return conta;	
}			
