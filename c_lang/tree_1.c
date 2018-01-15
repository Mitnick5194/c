# include <stdio.h>
# include <malloc.h>

typedef struct Node{
  char data;
  struct Node * pLChild;
  struct Node * pRChild;
} NODE,* PNODE;

PNODE createTree();
void preTranverse(PNODE);//先序遍历
void midTranverse(PNODE);//中序遍历
void postTranverse(PNODE);//后序遍历

int main(){
  PNODE pHead = createTree();
  preTranverse(pHead);
  printf("\n");
  midTranverse(pHead);
  printf("\n");
  postTranverse(pHead);
  return 0;
}

PNODE createTree(){
  PNODE pA = (PNODE)malloc(sizeof(NODE));
  PNODE pB = (PNODE)malloc(sizeof(NODE));
  PNODE pC = (PNODE)malloc(sizeof(NODE));
  PNODE pD = (PNODE)malloc(sizeof(NODE));
  PNODE pE = (PNODE)malloc(sizeof(NODE));
  PNODE pF = (PNODE)malloc(sizeof(NODE));
  PNODE pG = (PNODE)malloc(sizeof(NODE));

  pA->data = 'A';
  pA->pLChild = pB;
  pA->pRChild = pC;

  pB->data = 'B';
  pB->pLChild = NULL;
  pB->pRChild = NULL;

  pC->data = 'C';
  pC->pLChild = NULL;
  pC->pRChild = pD;

  pD->data = 'D';
  pD->pLChild = pE;
  pD->pRChild = NULL;
  
  pE->data = 'E';
  pE->pLChild = pG;
  pE->pRChild = pF;
  
  pG->data = 'G';
  pG->pLChild = NULL;
  pG->pRChild = NULL;

  pF->data = 'F';
  pF->pLChild = NULL;
  pF->pRChild = NULL;

  return pA;

 }

 
void preTranverse(PNODE pHead){ 
  if(NULL !=pHead)  printf("%c\n",pHead->data);
  if(NULL != pHead->pLChild) preTranverse(pHead->pLChild);
  if(NULL != pHead->pRChild) preTranverse(pHead->pRChild);
}

void midTranverse(PNODE pHead){
  if(NULL != pHead->pLChild) midTranverse(pHead->pLChild);
  if(NULL !=pHead)  printf("%c\n",pHead->data);
  if(NULL != pHead->pRChild) midTranverse(pHead->pRChild);
}
void postTranverse(PNODE pHead){
  
  if(NULL != pHead->pLChild) postTranverse(pHead->pLChild);
  if(NULL != pHead->pRChild) postTranverse(pHead->pRChild);
  if(NULL !=pHead)  printf("%c\n",pHead->data);
}
