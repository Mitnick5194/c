# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <malloc.h>

typedef struct Node{
  int data;
  struct Node * pNext;
}NODE,*PNODE;

typedef struct Stack{
  PNODE pTop;
  PNODE pBottom;
}STACK,*PSTACK;
void init(PSTACK);
bool is_empty(PSTACK);
void push(PSTACK,int);
bool pop(PSTACK,int*);
void traverse(PSTACK);
void clear(PSTACK);

int main(){
  STACK s;
  int val;

  init(&s);
  push(&s,1); 
  push(&s,2); 
  push(&s,3); 
  push(&s,4); 
  traverse(&s); 
  if(pop(&s,&val)){
    printf("the number %d has been deleted\n",val);
    traverse(&s);
  }else{
    printf("delete failure");
   }

  clear(&s);
  if(is_empty(&s)){
    printf("is empty\n");
}else{
    printf("not empty\n");
}

}

void init(PSTACK pS){
  pS->pBottom = (PNODE)malloc(sizeof(NODE));
  pS->pBottom->pNext = NULL;
  pS->pTop = pS->pBottom;

}

bool is_empty(PSTACK pS){
  if(pS->pTop == pS->pBottom) return true;

  return false;
}

void push(PSTACK pS , int val){
  PNODE pNew = (PNODE)malloc(sizeof(PNODE));
  pNew->data = val;
  pNew->pNext = pS->pTop;
  pS->pTop = pNew;
}

bool pop(PSTACK pS , int * val ){
  PNODE q = NULL; 

 if(is_empty(pS)) return false;

 q = pS->pTop;

 if(val != NULL) *val = q->data;

 pS->pTop = pS->pTop->pNext;
 free(q);
 return true;
}

void traverse(PSTACK pS){
  PNODE q = pS->pTop;
 while(q!=pS->pBottom){
   printf("%d\n",q->data);
   q = q->pNext;
}
  printf("\n");

}

void clear(PSTACK pS){
  bool b; 
  while(1){
   b = pop(pS,NULL);
   if(!b) break;   
  }

}

