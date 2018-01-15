# include <stdio.h>

int main(){

struct Student{

  int sid;
  int age;
};

 struct Student stu = {11,21};
 struct Student *pstu = &stu;
 printf("%d %d \n",stu.sid,stu.age);
 printf("%d\n",pstu->age);

return 0;

}
