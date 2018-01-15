# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
# include <stdbool.h>

struct Arr{
 int *pBase;  //���ݵ��׵�ַ
 int len;//����ĳ���
 int cnt;//�������Ч���ݵĸ���
};
 
 void init_arr(struct Arr *pArr , int length);
 bool is_empty(struct Arr *pArr);
 void show_arr(struct Arr *pArr);
 bool append_arr(struct Arr * pArr , int val );
 bool is_full(struct Arr * pArr);
 bool insert_arr(struct Arr * pArr , int pos , int val );  //post ��ʾ������±� //       ��0 ��ʼ��valΪ�����ֵ^
 bool delete_arr(struct Arr * pArr , int pos , int * pval );//pos ��ʾҪɾ����ֵ  //    ���±꣬valΪɾ����ֵ  
 void sort_arr(struct Arr *pArr);
 void inversion();




int main(){
 
 int val;

 struct Arr arr;
 init_arr(&arr , 6 );
 show_arr(&arr);
 append_arr(&arr,4);
 append_arr(&arr,8);
 append_arr(&arr,-2);
 append_arr(&arr,47);
 show_arr(&arr);
 printf("after insert\n");
 insert_arr(&arr , 1 , -1);
 show_arr(&arr);
 if( delete_arr(&arr , 1 , &val)){
  printf("delete success %d has been deleted\n",val);
  show_arr(&arr);
 }else{
   printf("delete failure");
 }
 printf("after sort:\n");
 sort_arr(&arr);
 show_arr(&arr);
 return 0;

}

void init_arr(struct Arr *pArr ,int  length){
 pArr->pBase = (int *)malloc(sizeof(struct Arr) * length);
 if(pArr->pBase == NULL){
   printf("Dynamic memory allocation failure");
   exit(-1);
 }else{
    pArr->len = length;
    pArr->cnt = 0;
    free(pArr->pBase);
    return;
}


}

void show_arr(struct Arr * pArr){
 
 int i = 0;
 if(is_empty(pArr)){
    printf("the List is empty\n");
}else{
  for(i;i<pArr->cnt;++i){
    printf("%d",pArr->pBase[i]);
    printf("\n");
}
}
 
  
}

bool is_empty(struct Arr * pArr){
  if(pArr->cnt == 0)
    return true;
  else 
    return false;
}   

bool is_full(struct Arr * pArr){
 if(pArr->cnt == pArr->len)
   return true;
 else
   return false; 

}
bool append_arr(struct Arr * pArr , int val){
  if(is_full(pArr)){
    return false;
}
  pArr->pBase[pArr->cnt] = val;
  pArr->cnt++;
  return true;
  
}

bool insert_arr(struct Arr * pArr , int pos , int val){
 int i; 
 if(is_full(pArr) || pos < 0 || pos > pArr->cnt  ){
    return false;
  }
 for(i=pArr->cnt;i>pos;--i){
   pArr->pBase[i] = pArr->pBase[i-1];  
 }
 pArr->pBase[pos] = val; 
 pArr->cnt++;
 return true;
}

bool delete_arr(struct Arr * pArr , int pos, int * pval){
 int i; 
 if(is_empty(pArr) ||  pos < 0 || pos > pArr->cnt  ){
    return false;  
 }
   
 *pval = pArr->pBase[pos];
   
 for(i=pos;i<pArr->cnt-1;i++){
   pArr->pBase[i] = pArr->pBase[i+1];
}
   pArr->cnt--;
 return true;
}

void sort_arr(struct Arr *pArr){
  int i,j,temp;
  for(i=0;i<pArr->cnt-1;i++){
    for(j=i+1;j<pArr->cnt;++j){
	if(pArr->pBase[i]>pArr->pBase[j]){
	   temp = pArr->pBase[i];
           pArr->pBase[i]=pArr->pBase[j];
	   pArr->pBase[j] = temp;
}
}
}
}






