#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
char command[100],attr[100],pwd2[100],pwdd[100],pwdd2[100],pwdd3[100],pwddd[100],safe[100];
char *token,*pwd1,*pwd3,*pwdd1;
void sinyal(int tes){
	// printf("%d\n",tes);
}
void main(){
	signal (SIGINT, sinyal);
	signal (SIGTSTP, sinyal);
	char s[1000],s1[1000];
	char dflt[100];
	int task1,task2;
	char tsk1[100],tsk2[100];
	getcwd(dflt,100);
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
		memset(s,0,sizeof(s));
		scanf("%[^\n]",s);
		if(getchar()==EOF){
			return;
		}
		// printf("s=%s\n", s);
		if(strcmp(s,"")==0){
			//penyebab segmentation fault :(
		}
		else if(s!=NULL){
			if(s[0]=='&'){
				for(a=1;a<(int)strlen(s);a++){
					s1[a-1]=s[a];
				}
				token=strtok(s1," ");
				//printf("token = %s\n",token );
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
							// for(a=0;a<(int)strlen(pwdd1);a++){
							// 	pwdd[a]=pwdd1[a];
							// 	printf("pwdd[%d] = %c\n",a,pwdd[a] );
							// }
							// strcat(pwdd,pwdd1);
							while(pwdd1!=NULL){
								strcpy(safe,pwdd);
								if(pwdd1!=NULL){
									strcat(pwdd,"/");
									strcat(pwdd,pwdd1);
									// printf("pwdd = %s\n",pwdd );
									// printf("safe = %s\n", safe);
								}
								pwdd1=strtok(NULL,"/");
							}
							// printf("safe f=%s\n", safe);
							// printf("pwdd f= %s\n", pwdd);
							chdir(safe);
						}
						else if(attr[0]=='/'){
							// printf("%s\n", attr);
							chdir(attr);
						}
						else {
							strcat(pwd2,"/");
							 // printf("%s\n",pwd2 );
							strcat(pwd2,attr);
							 // printf("%s\n",pwd2 );
							chdir(pwd2);
							// getcwd(pwd2,100);
							// printf("now %s\n", pwd2);
						}
					}
					else if(strcmp(attr,"")==0){
						strcpy(tsk1,"/bin/");
						strcat(tsk1,command);
						strcpy(tsk2,"/usr/bin/");
						strcat(tsk2,command);
						task1=execlp(tsk1,command,pwd2,NULL);
						task2=execlp(tsk2,command,pwd2,NULL);
					}
					else{
						strcpy(tsk1,"/bin/");
						strcat(tsk1,command);
						strcpy(tsk2,"/usr/bin/");
						strcat(tsk2,command);
						task1=execlp(tsk1,command,attr,pwd2,NULL);
						task2=execlp(tsk2,command,attr,pwd2,NULL);
					}
				}
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
							// for(a=0;a<(int)strlen(pwdd1);a++){
							// 	pwdd[a]=pwdd1[a];
							// 	printf("pwdd[%d] = %c\n",a,pwdd[a] );
							// }
							// strcat(pwdd,pwdd1);
							while(pwdd1!=NULL){
								strcpy(safe,pwdd);
								if(pwdd1!=NULL){
									strcat(pwdd,"/");
									strcat(pwdd,pwdd1);
									// printf("pwdd = %s\n",pwdd );
									// printf("safe = %s\n", safe);
								}
								pwdd1=strtok(NULL,"/");
							}
							// printf("safe f=%s\n", safe);
							// printf("pwdd f= %s\n", pwdd);
							chdir(safe);
						}
						else if(attr[0]=='/'){
							// printf("%s\n", attr);
							chdir(attr);
						}
						else {
							strcat(pwd2,"/");
							 // printf("%s\n",pwd2 );
							strcat(pwd2,attr);
							 // printf("%s\n",pwd2 );
							chdir(pwd2);
							// getcwd(pwd2,100);
							// printf("now %s\n", pwd2);
						}
					}
					else if(strcmp(attr,"")==0){
						strcpy(tsk1,"/bin/");
						strcat(tsk1,command);
						strcpy(tsk2,"/usr/bin/");
						strcat(tsk2,command);
						task1=execlp(tsk1,command,pwd2,NULL);
						task2=execlp(tsk2,command,pwd2,NULL);
					}
					else{
						strcpy(tsk1,"/bin/");
						strcat(tsk1,command);
						strcpy(tsk2,"/usr/bin/");
						strcat(tsk2,command);
						task1=execlp(tsk1,command,attr,pwd2,NULL);
						task2=execlp(tsk2,command,attr,pwd2,NULL);
					}
				}
				wait(0);
			}
		}
	}
}