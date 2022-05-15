#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  /*for(int i = 0; i < 9; i++ ){
    int matris[10] = {0};
    int k = i;
    for(int x = 0; x < 9; x++){
      int l= 3 *(k / 3) + (x / 3);
      int j= 3 *(k % 3) + (x % 3);
      if(matris[n->sudo[l][j]] == 0 && n->sudo[l][j] != 0) matris[n->sudo[l][j]] = 1;
      else if(matris[n->sudo[l][l]] != 0) return 0;
    }
  }
  for(int i = 0; i < 9; i++ ){
    int fila[10] = {0};
    for(int j = 0 ; j <9;j++){
      if(fila[n->sudo[i][j]] == 0 && n->sudo[i][j] != 0) fila[n->sudo[i][j]] = 1;
      else if(fila[n->sudo[i][j]]) return 0;
    }
  }
  for(int m = 0; m < 9 ; m++ ){
    int columna[10] = {0};
    for(int o = 0; o < 9; o++){
      if(columna[n->sudo[m][o]] == 0 && n->sudo[m][o] != 0) columna[n->sudo[m][o]] = 1;
      else if(columna[n->sudo[m][o]] != 0) return 0;
    }
  }*/
  return 1;
}

List* get_adj_nodes(Node* n){
  List* list=createList();
  int val;
  for (int i = 0; i < 9; i++){
    for(int x = 0; x < 9; x++){
      if(n->sudo[i][x] == 0){
        for(int k = 0; k < 9; k++){
          Node* nodo=createNode();
          n->sudo[i][x]++;
          nodo=copy(n);
          val=is_valid(nodo);
          if(val == 1){
            pushBack(list,nodo);
          } 
        }
      } 
    }
  }
  return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/