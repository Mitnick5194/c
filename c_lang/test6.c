#include <stdio.h>
void main()
{ 
int x,i,j=10,a[11]={10,20,30,40,50,60,70,80,90,100,0};
printf("�������У�10��20��30��40��50��60��70��80��90��100\n");
printf("������һ��������");
scanf("%d",&x);
for(i=0;i<10;i++)if(x<a[i]){j=i;break;}
for(i=10;i>=j;i--)a[i]=a[i-1];
a[j]=x;
printf("�����У�");
for(i=0;i<11;i++)printf("%d��",a[i]);
getchar();
getchar();
getchar();
}

