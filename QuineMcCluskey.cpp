/*Lê o numero de variáveis
 * 
 * 
 * 
 * 
 * 
 */ 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

short **table;
short *pos;
short indice;
void contauns (short linhas, short colunas);

int main(void){
	short i=0, colunas=0, linhas=0;
	printf("Digite o número de variáveis:");
	scanf("%hu", &colunas);
	linhas=exp2(colunas);
	pos = (short*)calloc(colunas, sizeof(short));
	printf("Digite as posições na tabela em que possui 1's:\nDigite 4096 para finalizar:\n");
	while(pos[i]!=4096){
		i++;
		scanf("%hu\n", &pos[i]);		
	}
	table = (short**)calloc(colunas*i, sizeof(short));
	contauns(linhas, colunas);	
	return 0;	
}

void contauns (short linhas, short colunas){
	//table = (short**)calloc(elementos*(var+1), sizeof(short));
	for (short i=0; i<(short)(sizeof(unsigned short int)) ; i++){
		
	}	
}		
