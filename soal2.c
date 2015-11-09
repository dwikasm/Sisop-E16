#include <stdio.h>
#include <pthread.h>

int v=0;

void *run(void *args){
	int *d=(int*)args;
	int i=2;
	while(i<=*d){
		if(*d%i==0 && i==*d){
			v++;
			return;
		}
		else if(*d%i==0){
			return;
		}
		i++;
	}
}

void main(){
	int a;
	printf("Masukkan input : ");
	scanf("%d",&a);
	pthread_t t1[a];
	int x,b[a];
	for(x=2;x<a;x++){
		b[x]=x;
		pthread_create(&t1[x],NULL,run,(void*)&b[x]);
	}
	for(x=2;x<a;x++){
		pthread_join(t1[x],NULL);
	}
	printf("jumlah bilangan prima kurang dari %d ada %d\n",a,v);	
}
