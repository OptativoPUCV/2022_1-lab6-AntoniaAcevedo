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
  int m,l;
  for(int i = 0; i < 9; i++){
    int num1[15] = {0};
    int num2[15] = {0};
    for(int x = 0; x < 9; x++){
      if(n->sudo[x][i] != 0 && i != x){
        if(num2[n->sudo[x][i]] == 1) return 0;
        else num2[n->sudo[x][i]] = 1;
      } 
      else if(n->sudo[i][x] != 0){
        if(num1[n->sudo[i][x]] == 1)return 0;
        else num1[n->sudo[i][x]] = 1;
      }   
    }
    for(int k = 0 ; k < 9 ; k+=3){
      for(int y = 0 ; y < 9 ; y+=3){
        int num3[15] = {0};
        for(int p=0;p<9;p++){
          m = k + (p/3);
          y = y + (p%3);
          if(n->sudo[m][l] != 0){
            if(num3[n->sudo[m][l]] == 1) return 0;
            else num3[n->sudo[m][l]] = 1;
          }
        }
      }
    }
  }
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