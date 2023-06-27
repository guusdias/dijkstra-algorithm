#include <stdio.h>
#include <stdlib.h>

void main(){
	int valor[10][10], distancia[10], caminho[10][10], n,v,p, linha, col, min, index = 1, i, j;
	
	//usuario coloca o nº de nodos inseridos
	printf("Coloque o numero de nodos: ");
	scanf("%d", &n);
	
	//usuario coloca os valores da matriz
	printf("Coloque os valores da matriz ");
	for(i=1; i<=n;i++){
		
		for(j=1; j<=n;j++){
			scanf("%d", &valor[i][j]);
		}
	}
	
	//usuário insere o nodo que ele quer visitar
	printf("Coloque o nodo que vc quer visitar: ");
	scanf("%d", &v);
	
	//usuario insere os caminhos para determinado nodo
	printf("Coloque os caminhos para o nodo selecionado: ");
	scanf("%d", &p);
	
	//caminho matrix
	printf("Coloque o caminho matriz \n");
	for(i=1; i<=p;i++){
		for(j=1;j<=n;j++){
			scanf("%d", &caminho[i][j]);
		}
	}
	for(i=1;i<=p;i++){
		distancia[i]=0;
		linha=1;
		for(j=1; j<n;j++){
			if(linha!=v){
				//até o ultimo nodo visitado
				col = caminho[i][j+1];
				distancia[i] = distancia[i] + valor[linha][col];
			}
			linha = col;
		}
	}
	
	min = distancia[1];
	for(i=1;i<= p; i++){
		if(distancia[i] <= min){
			min = distancia[i];
			index = i;
		}
	}
	
	printf("minima distancia eh %d\n", min);
	printf("menor caminho e \n");
	for(i=1; i<=n;i++){
		if(caminho[index][i]!=0){
			printf("-->%d", caminho[index][i]);
		}
		
	}
}
