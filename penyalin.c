#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *salin1(){
	FILE *p1, *p2;
	char temp;
	p1=fopen("testkirim.txt","r");
	p2=fopen("salinantestkirim.txt","w");
	while(1){
		temp=fgetc(p1);
		if(temp==EOF)break;
		else putc(temp,p2);
	}
	printf("Salin 1 berhasil\n");
	fclose(p1);
	fclose(p2);
}
void *salin2(){
	FILE *p1, *p2;
	char temp;
	p1=fopen("salinantestkirim.txt","r");
	p2=fopen("salinannyasalinantestkirim.txt","w");
	while(1){
		temp=fgetc(p1);
		if(temp==EOF)break;
		else putc(temp,p2);
	}
	printf("Salin 2 berhasil\n");
	fclose(p1);
	fclose(p2);
}
void main(){
	pthread_t t1,t2;
	pthread_create(&t1,NULL,salin1,NULL);
	pthread_join(t1,NULL);
	pthread_create(&t2,NULL,salin2,NULL);
	pthread_join(t2,NULL);
}
