#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
char in[10001];
pthread_t t1,t2;
void *salin1(){
	FILE *p1, *p2;
	char temp;
	p1=fopen(in,"r");
	char *token = strtok(in,".");
	strcat(token,"-salinan.txt");
	p2=fopen(token,"w");
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
	pthread_join(t1,NULL);
	FILE *p1, *p2;
	char temp;
	p1=fopen(in,"r");
	char *token2 = strtok(in,".");
	strcat(token2,"-salinan.txt");
	p2=fopen(token2,"w");
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
	printf("Masukkan nama file yang mau disalin : ");
	scanf("%[^\n]",in);
	pthread_create(&t1,NULL,salin1,NULL);
	pthread_create(&t2,NULL,salin2,NULL);
	pthread_join(t2,NULL);

}
