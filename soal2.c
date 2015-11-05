#include <stdio.h>
#include <pthread.h>

int a,v=0;

void *run(void *args)
	{
int *d=(int*)args;
	if(*d!=1)	
		{
	int i=2;
	int c=1;	
	while(i<=*d)	
		{
		if(*d%i==0)c++;		
		i++;
		}
	if(c==2)v++;
		}
}

void main()
	{
	scanf("%d",&a);pthread_t t1[a];
	int x,y,b[a];
for(x=1;x<=a;x++){b[x]=x;pthread_create(&t1[x],NULL,run,(void*)&b[x]);	}
for(y=1;y<=a;y++){	pthread_join(t1[y],NULL);}
	printf("jumlah bilangan prima kurang dari %d ada:%d\n",a,v);	
	}
