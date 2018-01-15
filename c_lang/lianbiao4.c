# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <malloc.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
} NODE,*PNODE;

PNODE create_list();
void traverse_list(PNODE pHead);
bool is_empty(PNODE);
void sort_list(PNOE);
int getSize(PNODE);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE pHead,int pos,int *pVal);

int main(){
	PNODE pHead = NULL;
	int deleteVal;
	bool b = false;

	pHead = create_list();
	traverse_list (pHead);
	if(is_empty(pHead)){
	  printf("is empty\n");
 	}else{
	  printf("not empty\n");
	}
	sort_list(pHead);
	printf("after sort\n");
	traverse_list(pHead);
	b = insert_list(pHead,4,99);
	if(b){
	  printf("after insert\n");
	  traverse_list(pHead);
	}else{
	  printf("insert failure\n");
	}
	b = delete_list(pHead,2,&deleteVal);
	printf("after delete \n");
	traverse_list(pHead);
 	if(b){
	  printf("delete succeed %d has del\n",deleteVal);
	}else{
	  printf("delete failure\n");
	}		
}

PNODE create_list(){
   int i, len , val;
   PNODE pHead = (PNODE)malloc(sizeof(PNODE));
   if(pHead == NULL){
	  printf("Dynamic memory allocation failure");
	  exit(-1);
   }
   PNODE pTail = pHead;
   pTail->pNext = NULL;
   
   printf("please input the length of the list\n");
   scanf("%d",&len);
   for(i=0;i<len;i++){
     printf("please input the %d val ",(i+1));
	 scanf("%d",&val);
	 PNODE pNew = (PNODE)malloc(sizeof(PNODE));
	  if(pHead == NULL){
		  printf("Dynamic memory allocation failure");
		  exit(-1);
      }
	 pNew->data = val;
	 pTail->pNext = pNew;
	 pNew->pNext = NULL;
	 pTail = pNew;

// this is error	
//	 pNew->data = val;
//	 pHead->pNext = pNew;
//	 pNew->pNext = NULL;
   }

	 return pHead;
}
void traverse_list (PNODE pHead){
	PNODE p = pHead->pNext;
   while(p != NULL){
      printf("%d\n",p->data);
	  p = p->pNext;
   }
	return;
}

bool is_empty(PNODE pHead){
  if(pHead->pNext == NULL)
	return true;
 	return false;


}

int getSize(PNODE pHead){
    int i = 0;
    PNODE p = pHead;
    while(p->pNext!=NULL){
	++i;
	p = p->pNext;	

}
	return i;
}

void sort_list(PNODE pHead){
  int i,j,t;
  int len = getSize(pHead);
  PNODE p = NULL;
  PNODE q = NULL;
  if(is_empty(pHead)) return;
  for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext){
	for(j=i+1,q=p->pNext;j<len;j++,q=q->pNext){
	
	   if(p->data>q->data){

		t = p->data;
		p->data = q->data;
		q->data = t;
	   }


}
}
  
  
}

bool insert_list(PNODE pHead , int pos , int val){
  int i = 0;
  PNODE p = pHead->pNext;
  PNODE q = NULL;

  while(p->pNext!=NULL && i<pos-1){
	p = p-> pNext;
	i++;
}
  if(i<pos-1) return false;
  
  PNODE pNew = (PNODE)malloc(sizeof(NODE));
 
  pNew->data = val;
  q = p->pNext;
  p->pNext = pNew;
  pNew->pNext = q;
  
  return true;  
}

bool delete_list(PNODE pHead , int pos , int *pval){
  PNODE p = pHead->pNext;
  int i = 1;
  PNODE q = NULL;
  
  while(p->pNext!=NULL && i<pos-1){
    p= p->pNext;
    i++;
}
  if(i<pos-1) return false;
    q = p->pNext;
    *pval = q->data;
    printf("value is %d \n",pval);
    p->pNext = q->pNext;
    free(q);
   return true;  
}
