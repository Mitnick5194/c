# include <stdio.h>

struct Stu{
int sid;
int age;
};

void add(struct Stu *pst);
void show (struct Stu * pst );

int main(){
 struct Stu s;
 add(&s);
 show(&s);
 return 0;
}
void add(struct Stu *pst){
 pst->sid = 2222;
 pst->age = 24;
}
void show (struct Stu *pst ){
 printf("%d %d \n" , pst->sid,pst->age);
}
