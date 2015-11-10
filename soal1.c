#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
char command[100],attr[100],pwd2[100],pwdd[100],pwdd2[100],pwdd3[100],pwddd[100];
char *token,*pwd1,*pwd3,*pwdd1;
/*void a(int s){
	if(s==SIGINT){
		printf("SIGINT");
	}
	if(s==SIGHUP){
		exit (0);//CTRL+D
	}
	if(s==SIGSTOP){
		printf("SIGSTOP");}
	}*/
main(){
	char s[1000],s1[1000];
/*	signal (SIGINT, a);
	signal (SIGSTOP, a);
	signal (SIGHUP, a);*/
	int a,x,y; 
	pid_t pid;
	while (1){
		memset(command,0,sizeof(command));
		memset(attr,0,sizeof(attr));
		memset(s,0,sizeof(s));
		memset(pwdd,0,sizeof(pwdd));
		memset(pwdd3,0,sizeof(pwdd3));
		memset(pwddd,0,sizeof(pwddd));
		memset(s1,0,sizeof(s1));
		scanf("%[^\n]",s);
		getchar();
		// printf("%s\n", s);
		if(s!=NULL){
			if(s[0]=='&'){
				for(a=1;a<(int)strlen(s);a++){
					s1[a-1]=s[a];
				}
				token=strtok(s1," ");
				//printf("token = %s\n",token );
				// TINGGAL COPY YANG BAWAH, waitnya gausah
			}
			else{
				token=strtok(s," ");
				for(a=0;a<(int)strlen(token);a++){
				 	command[a]=token[a];
				 	//printf("command[%d]=%c\n",a,command[a]);
				}
				//printf("%s\n",token);
				token=strtok(NULL," ");
				if(token!=NULL){
					//printf("%s\n",token);
					for(a=0;a<(int)strlen(token);a++){
						attr[a]=token[a];
						//printf("attr[%d]=%c\n",a,attr[a]);
					}	
				}
				//printf("token =%s\ncommand=%s\nattr=%s\n",token,command,attr);
				//printf("cmd = %d, attr = %d\n",(int)strlen(command),(int)strlen(attr) );
				//if(strcmp(command,"cd")==0){printf("Berhasil\n");}
				pid=fork();
				if(pid==0){
					getcwd(pwd2,100);
					// printf("pwd2=%s\n",pwd2);
					if(strcmp(command,"cd")==0){
						// printf("Berhasil masuk\n");						
						if(strcmp(attr,"..")==0){
							pwdd1=strtok(pwd2,"/");
							// printf("pwdd1=%s\n",pwdd1);
							for(a=0;a<(int)strlen(pwdd1);a++){
								pwdd[a]=pwdd1[a];
								// printf("pwdd[%d] = %c\n",a,pwdd[a] );
							}
							// while(pwdd1!=NULL){
							// 	pwdd1=strtok(NULL, "/");
							// 	printf("pwdd1 = %s\n", pwdd1);
							// 	strcat(pwdd3,pwdd1);						INI BUAT APAAN COY
							// 	if(pwdd1!=NULL){
							// 		printf("pwddd = %s\n", pwddd);
							// 		printf("pwdd3 = %s\n", pwdd3);
							// 		strcat(pwddd,pwdd3);
							// 	}
							// }
							// chdir(pwddd);
						}
						else if(attr[0]=='/'){
							// printf("%s\n", attr);
							chdir(attr);
						}
						else {
							strcat(pwd2,"/");
							 printf("%s\n",pwd2 );
							strcat(pwd2,attr);
							 printf("%s\n",pwd2 );
							chdir(pwd2);
						}
					}
					else if(strcmp(attr,"")==0){
						printf("masuk perintah tanpa atribut\n");
						if(execlp("/bin",command,pwd2,NULL)==-1){
							printf("tes nyari ls\n");
						}
						else if(execlp("/usr/bin",command,pwd2,NULL)==-1){
							printf("tes nyari lsof\n");
						}	
					}
					else{
						printf("masuk perintah dengan atribut\n");
						if(execlp("/bin",command,attr,pwd2,NULL)==-1){
							printf("command = %s\n", command);
							printf("attr = %s\n", attr);
							printf("pwd2 = %s\n", pwd2);
							printf("tes nyari ls\n");
						}
						else if(execlp("/usr/bin",command,attr,pwd2,NULL)==-1){
							printf("tes nyari lsof\n");
						}	
					}
				}
				wait(0);
			}
		}
	}
}