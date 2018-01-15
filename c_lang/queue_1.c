# include <stdio.h>
# include <malloc.h>
# include <stdbool.h>

typedef struct queue{
  int * pBase;
  int floor;
  int rear;
}QUEUE;

void init_queue(QUEUE*);
bool is_full(QUEUE*);
bool is_empty(QUEUE*);
void em_queue(QUEUE*,int);
void out_queue(QUEUE*,int*);
void traverse(QUEUE*);

int main(){
  QUEUE Q; 
  int val;

  init_queue(&Q);
  if(is_empty){
   printf("empty\n");
}
  em_queue(&Q,1);
  em_queue(&Q,2);
  em_queue(&Q,3);
  em_queue(&Q,4);
  em_queue(&Q,4);
  em_queue(&Q,4);
  em_queue(&Q,4);
  
  traverse(&Q);
  out_queue(&Q,&val);
  out_queue(&Q,&val);
  out_queue(&Q,&val);
  out_queue(&Q,&val);
  out_queue(&Q,&val);

  traverse(&Q);
  if(is_empty(&Q)) printf("is empty\n");
}

void init_queue(QUEUE *pQ){
  pQ->pBase = (int*)malloc(sizeof(int) * 6);
  pQ->floor = 0;
  pQ->rear = 0;
}
bool is_full(QUEUE *pQ){
  if((pQ->rear+1) % 6 == pQ->floor) return true;
  return false;
}

bool is_empty(QUEUE *pQ){
  if(pQ->rear == pQ->floor) return true;
  return false; 
}

void em_queue(QUEUE *pQ , int val){
  if(is_full(pQ)) return;
  pQ->pBase[pQ->rear] = val;
  pQ->rear = (pQ->rear+1) % 6; 
}
void out_queue(QUEUE *pQ , int *pVal){
  if(is_empty(pQ)) return;
  *pVal = pQ->pBase[pQ->floor];
  pQ->floor = (pQ->floor+1) % 6;
}

void traverse(QUEUE* pQ){
  int i = pQ->floor;
  while(i!=pQ->rear){
    printf(" %d ",pQ->pBase[i]);
    i = (i+1) % 6;
}
  printf("\n");
}
