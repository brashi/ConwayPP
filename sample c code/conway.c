#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define h 100
#define w 50
//h são linhas
//w são colunas
int contagem(int **campo, int x, int y)
{
	int celulas = 0;
	if(campo[x-1][y-1] == 1) celulas++; //Canto superior esquerdo
  	if(campo[x-1][y] == 1) celulas++; //Encima
  	if(campo[x-1][y+1] == 1) celulas++; //Canto superior direito
  	if(campo[x][y-1] == 1) celulas++; //Esquerda
  	if(campo[x][y+1] == 1) celulas++; //Direita
  	if(campo[x+1][y-1] == 1) celulas++; //Canto inferior esquerdo
  	if(campo[x+1][y] == 1) celulas++; //Abaixo
  	if(campo[x+1][y+1] == 1) celulas++; //Canto inferior direito

	return celulas;
}
void imprimir(int **campo)
{
	printf("\033[H");
	for(int i = 1; i < w+1; i++){
		for(int j = 1; j < h+1; j++)
			printf("%d", campo[i][j]);
		printf("\n");
	}
	//printf("\033[E");
	fflush(stdout);

}
void jogar(int **campo)
{
	int **buffer = (int**)calloc(w+2, sizeof(int*));
	for(int i = 0; i < w+2; i++)
		buffer[i] = (int*)calloc(h+2, sizeof(int));

	while (1){
		for(int i = 0; i < w+2; i++){
       			for(int j = 0; j < h+2; j++)
				buffer[i][j] = campo[i][j];
		}
	
		for(int i = 1; i < w+1; i++){
			for(int j = 1; j < h+1; j++){
				int n = contagem(buffer, i, j);
				if(buffer[i][j] == 1){	
					if(n < 2)
					{
						campo[i][j] = 0;
					} else if(n > 3)
					{
						campo[i][j] = 0;
					}
				} else
				{
					if(n == 3 && buffer[i][j] == 0)
						campo[i][j] = 1;
				}
			}
		}
		imprimir(campo);
		//usleep(200000);
	}

}
int main()
{
	int **campo = (int**)calloc(w+2, sizeof(int*));
	for(int i = 0; i < w+2; i++)
		campo[i] = (int*)calloc(h+2, sizeof(int));

       	for(int i = 1; i < w+1; i++){
       		for(int j = 1; j < h-25; j++)
			campo[i][j] = 1;
	}
	campo[1][2] = 1;
	campo[2][2] = 1;
	campo[3][2] = 1;
	imprimir(campo);
        //usleep(200000);
	//for(int i = 1; i < w+1; i++){
       	//	for(int j = 1; j < h+1; j++)
	//		printf("%d", campo[i][j]);
	//	printf("\n");
	//}
	
	jogar(campo);	
}
