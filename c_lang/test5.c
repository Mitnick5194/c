# include <stdio.h>

void f(int*);

int main(){
  int i;
  f(NULL);


}
void f(int * val){
  printf("test\n");
  *val = 2;
}

