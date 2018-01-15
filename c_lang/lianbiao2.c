# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <malloc.h>


typedef struct Node{
  int data;
  struct Node * pNext;
}NODE,*PNODE;

PNODE create_list();
void inversion_list(PNODE);

int main(){
  
  PNODE pHead = NULL;
  pHead = create_list();
  inversion_list(pHead);

}

PNODE create_list(){
  int i,len,val;

  PNODE pHead = (PNODE)malloc(sizeof(PNODE));
  PNODE pTail = pHead;
  pTail->pNext = NULL;

  if(pHead==NULL){
    printf("failure");
    exit(-1);
}
  printf("please input the length of the size \n");
  scanf("%d",&len);

  for(i=0;i<len;++i){
	printf("please input the %d val ",i+1);
	scanf("%d",&val);
	PNODE pNew = (PNODE)malloc(sizeof(PNODE));

	if(pNew==NULL){
		printf("failure");
		exit(-1);

	}

	pNew->data = val;
	pTail->pNext = pNew;
	pNew->pNext = NULL;
	pTail = pNew;
	
  }
	return pHead;


}

void inversion_list(PNODE pHead){
  PNODE p = pHead->pNext;
  while(p!=NULL){
     printf("%d\n",p->data);
     p = p->pNext;
}
    return;
}
