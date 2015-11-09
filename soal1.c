#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
char command[100],attr[100],pwd2[100],pwdd[100],pwdd2[100];
char *token,pwd1[100],pwd3[100];
/*void a(int s)
{if(s==SIGINT)
{printf("SIGINT");}
if(s==SIGHUP)
{exit (0);}//CTRL+D
if(s==SIGSTOP)
{printf("SIGSTOP");}
}*/
main()
{
char s[1000];
/*signal (SIGINT, a);
signal (SIGSTOP, a);
signal (SIGHUP, a);*/
int x;pid_t pid;
while (1)
{scanf("%[^\n]",s);
getchar();
if(s!=NULL){
token=strtok (s , " ");	
if(strcmp(token,"&")==0){}
else{
command=&token;
token=strtok (NULL , " ");
attr=&token;
pid=fork();
			if(pid==0)
				{pwd2=getpwd();
					if(){
							if(strcmp(attr,"")==0)
								{
								execlp("/bin",command,pwd2,NULL);	
								}
							else
							{

							}
							}
					else if(){
							if(strcmp(attr,"")==0)
								{
						execlp("/usr/bin",command,pwd2,NULL);		
								}
							else
							{

							}
						}
					else if(strcmp(command,"cd")==0)
						{
						if(strcmp(attr,"..")
							{
		while(attr!=NULL){
if(){pwdd=strcat()}}
								chdir(pwdd);
							}
						else if(strcmp(attr[0],"/")==0)
							{
								chdir(attr);
							}
						else 	{
								pwdd2=strcat(pwd2,attr);
								chdir(pwdd2);
							}
						}
				}
}
}
}
}
