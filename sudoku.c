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
  for(int i = 0; i < 9; i++){
    int fila[10] = {0};
    int colum[10] = {0};
    for(int j = 0; j < 9; j++){
      if(n -> sudo[i][j] != 0){
        if(fila[n -> sudo[i][j]] == 1) return 0;
        else fila[n -> sudo[i][j]] = 1;
      }
      if(n -> sudo[j][i] != 0 && i != j){
        if(colum[n -> sudo[j][i]] == 1) return 0;
        else colum[n -> sudo[j][i]] = 1;
      }    
    }
    for(int v = 0; v < 9; v+=3){
      for(int w = 0 ; w < 9; w+=3){
        int matris[10] = {0};
        for(int p = 0; p < 9; p++){
          int x = v + (p/3);
          int y = w + (p%3);
          if(n -> sudo[x][y] != 0){
            if(matris[n -> sudo[x][y]] == 1) return 0;
            else matris[n -> sudo[x][y]] = 1;
          }
        }
      }
    }
  }
  return 1;
}
List* get_adj_nodes(Node* n){
    List* list=createList();
    for (int i = 0; i < 9; i++){      
      for (int j = 0; j < 9; j++){        
        if (n -> sudo[i][j] == 0){
          for (int k = 1; k <= 9; k++){
            Node* cop =copy(n);
            cop -> sudo[i][j]=k;
            if(is_valid(cop))pushBack(list, cop);
          }
          return list;
        }
      }
    }
  return list;  
}



int is_final(Node* n){
  for(int i = 0; i < 9; i++ ){
    for (int j = 0; j < 9; j++){
      if(n->sudo[i][j] == 0){
        return 0;
      }
    }
  }
  return 1;
}

Node* DFS(Node* initial, int* cont){
  Stack* stack = createStack();
  push(stack, initial);
  while (is_empty(stack) == 0){
    Node* nodo1 = top(stack);
    pop(stack);
    if (is_final(nodo1) == 1) return nodo1;
    else{
      List* nodos = get_adj_nodes(nodo1);
      Node* nodoL = first(nodos);
      while (nodoL != NULL){
        push(stack, nodoL);
        nodoL = next(nodos);
      }
    }
    (*cont)++;
  }
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