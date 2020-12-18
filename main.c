#include <stdio.h>
#include <stdbool.h>
#define numVertices 10 


int graus[numVertices];
int colorir = 1;
int cor[numVertices];
char vertices[numVertices] = {'A','B','C','D','E','F','G','H','I','J'}; //vertices
int matrix[numVertices][numVertices] = { 
  {0,1,0,0,0,0,0,1,0,0},
  {1,0,0,1,0,0,0,0,0,0},
  {0,0,0,1,0,0,0,0,0,0},
  {0,1,1,0,0,0,0,0,1,0},
  {0,0,0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,1,0,0,0},
  {0,0,0,0,0,1,0,1,0,0},
  {1,0,0,0,0,0,1,0,1,1},
  {0,0,0,1,0,0,0,1,0,1},
  {0,0,0,0,0,0,0,1,1,0}
};


int colore(int pColore){
  for(int j = 0; j < numVertices; j++)
    if(matrix[pColore][j])
      if(cor[j] == colorir)
        return colorir + 1;
  return colorir;
}

void grau(){ //função para achar grau do vertice
  for(int a = 0; a < numVertices; a++)
    for(int k = 0; k < numVertices; k++)
      if(matrix[a][k] == 1)
        graus[a]++;
}
void welshPowell(){ //algoritmo de welsPowell
  int v, aux;
  do{
    aux = 0;
    for(int a = 0; a < numVertices; a++) // Buscando vertice com menor total e que não foi visitado ainda
      if(cor[a] == 0) // se cor igual a 0
        if(graus[a] > aux) {
          v = a;
          aux = graus[a];
        }
    if(cor[v] == 0)
      cor[v] = colorir; //colore
    else break; //caso vertics ja foram pintados
    for(int y = 0; y < numVertices; y++)
      if(matrix[v][y] == 0 && cor[y] == 0)
        cor[y] = colore(y);
    colorir++; //contador
  } while(true);
}


int main(){
  for(int g = 0; g < numVertices; g++)
    cor[g] = graus[g] = 0;
  grau(); 
  welshPowell();
  for(int a = 0; a < numVertices; a++){
    printf("vertice(%c), ", vertices[a]);
    if(cor[a] == 1) printf("cor: azul\n");
    else if(cor[a] == 2) printf("cor: cinza\n");
    else if(cor[a] == 3) printf("cor: amarelo\n");
    else printf("cor: vermelho\n");
  }
  return 0;
}
