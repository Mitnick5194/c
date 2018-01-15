# include <stdio.h>
# include <malloc.h>
int main(){
  int len;
  scanf("%d",&len);
  int * pArr = (int *)malloc(sizeof(int)*len); 
  for(int i=0;i<len;i++)
   scanf("%d",&pArr[i]) ;
  for(i;i<len;i++)
   printf("%d\n",*(pArr+i)); 
   free(pArr);
  return 0;
}
