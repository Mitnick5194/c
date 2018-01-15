# include <stdio.h>

void f();
void g();
void k();

f(){
 printf("FFF\n");
 g();
}
g(){
 printf("GGG\n");
 k();
}
k(){
 printf("kkk\n");
 f();
}

int main(){
  f();
}
