#include<stdio.h>
#include<pthread.h>
int jum=0;
void *prime(void *args){
	int *a=(int*)args;
	int i=2;
	while(i<=*a){
		if(*a%i==0 && i==*a){
			jum++;
			return;
		}
		else if(*a%i==0){
			return;
		}
		i++;
	}
}

void main(){
	pthread_t t1;
	int input;
	printf("Masukkan input : ");
	scanf("%d",&input);
	int i;
	for(i=2;i<input;i++){
		pthread_create(&t1,NULL,prime,(void*)&i);
		pthread_join(t1,NULL);
	}
	printf("Jumlah bilangan prima sebelum %d adalah %d\n",input,jum);
}
