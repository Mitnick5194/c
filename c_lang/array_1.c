# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
# include <stdbool.h>

int i = 0;
struct Arr{
 int *pBase;  //数据的首地址
 int len;//数组的长度
 int cnt;//数组的有效数据的个数
};
 
 void init_arr(struct Arr *pArr , int length);
 bool is_empty(struct Arr *pArr);
 void show_arr(struct Arr *pArr);




int main(){

 struct Arr arr;
 init_arr(&arr , 6 );
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




