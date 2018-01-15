# include <stdio.h>

show(int * p , int len){

 int i = 0;
 for(i;i<len;i++){
 
 printf("%d\t",*(p+i));
 if(i == len-1) printf("\n");

}
  
}

int main(void)
{

 int arr[5] = {1,2,3,4,5};
 show(arr,5);
 return 0;

}
