#include <stdio.h>
#include <pthread.h>

int a;
char *token;
void *run(void *args)
	{
int v=0,d=a;
while (d>0){if(d!=1)	{
	int i=2;
	int c=1;	
	while(i<=d)	{
		if(d%i==0)c++;		
		i++;
			}
	if(c==2)v++;
	}d--;}
printf("jumlah bilangan prima kurang dari %d ada:%d\n",a,v);
}

void main()
	{
	pthread_t t1;
	scanf("%d",&a);
	pthread_create(&t1,NULL,run,NULL);	
	pthread_join(t1,NULL);
		
	}
