#include <stdio.h>
#include <stdlib.h>

void main(){
	int valor[10][10], distancia[10], caminho[10][10], n,v,p, linha, col, min, index = 1, i, j;
	
	//usuario coloca o nº de nodos inseridos
	// ou seja, aqui será o numero total de possibilidades que teremos pra visitar
	printf("Coloque o numero de nodos: ");
	scanf("%d", &n);
	
	//usuario coloca os valores da matriz
	printf("Coloque os valores da matriz ");
	
	// aqui se insere os valores da matriz base
	// esse é o nosso mapa original, a matriz representa a distancia entre os lugares inseridos
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
	
	//caminho matriz
	// isso é como colocar os caminhos possíveis do 1 até o lugar que vc quer vistar
	// para isso vc faz outro pequeno mapa com os valores dos caminhos
	printf("Coloque o caminho matriz \n");
	for(i=1; i<=p;i++){
		for(j=1;j<=n;j++){
			scanf("%d", &caminho[i][j]);
		}-
	}
	
	// agora é o momento de calcular a distancia minima e o menor caminho para chegar no lugar desejado
	// ele percorre cada caminho informado anteriormente e calcula essa distancia somando elas ao longo do caminho

	for(i=1;i<=p;i++){
		distancia[i]=0;
		linha=1;
		for(j=1; j<n;j++){
			// se a linha for diferente do nodo que vc quer visitar então faça isso
			if(linha!=v){
				//até o ultimo nodo visitado
				//some uma coluna pra cada linha
				col = caminho[i][j+1];
				// soma a distancia para cada valor na matriz percorrido
				distancia[i] = distancia[i] + valor[linha][col];
			}
			linha = col;
		}
	}
	
	// feito isso pora cada caminho, ele armazena cada distancia respectivamente
	//aqui se faz a comparação de cada distancia percorrida e econtra o minimo
	// o index se transforma no indice do caminho da menor distancia
	min = distancia[1];
	for(i=1;i<= p; i++){
		if(distancia[i] <= min){
			min = distancia[i];
			index = i;
		}
	}
	
	
	//aqui o programa percorre e caminho correspondente ao caminho minimo a se percorrer
	// o valor 0 indica o final do caminho 
	printf("minima distancia eh %d\n", min);
	printf("menor caminho e \n");
	for(i=1; i<=n;i++){
		if(caminho[index][i]!=0){
			printf("-->%d", caminho[index][i]);
		}
		
	}
}
