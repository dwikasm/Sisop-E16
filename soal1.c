#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
char command[100],attr[100],pwd2[100],pwdd[100],pwdd2[100],pwdd3[100],pwddd[100];
char* token,pwd1[100],pwd3[100],pwdd1;
/*void a(int s)
{
	if(s==SIGINT)
		{
			printf("SIGINT");
		}
	if(s==SIGHUP)
		{
			exit (0);//CTRL+D
		}
	if(s==SIGSTOP)
		{
			printf("SIGSTOP");}
		}*/
main()
{
char s[1000];
/*signal (SIGINT, a);
signal (SIGSTOP, a);
signal (SIGHUP, a);*/
int a,x,y;
pid_t pid;
while (1)
	{	
		scanf("%[^\n]",s);
		getchar();
		if(s!=NULL)
			{
				token=strtok (s , " ");	
				if(strcmp(&token[0],"&")==0)
					{
						token=strtok(NULL,"&");
						for(a=0;a<strlen(token);a++){command[a]=&token[a];}
						token=strtok (NULL , " ");
						for(a=0;a<strlen(token);a++){attr[a]=&token[a];}
						pid=fork();
						if(pid==0)
							{
								getcwd(pwd2,100);
								if(strcmp(attr,"")==0)
									{
										if(execlp("/bin",command,pwd2,NULL)==-1)
											{}
										else if(execlp("/usr/bin",command,pwd2,NULL)==-1)
											{}	
									}
								else
									{
										if(execlp("/bin",command,attr,pwd2,NULL)==-1){}
										else if(execlp("/usr/bin",command,attr,pwd2,NULL)==-1){}	
									}
								if(strcmp(command,"cd")==0)
									{
										if(strcmp(attr,"..")==0)
											{
												pwdd1=strtok(pwd2,"/");
												for(a=0;a<strlen(&pwdd1);a++)pwdd[a]=&pwdd1[a];
												while(pwdd1!=NULL)
												{
													pwdd1=strtok(NULL, "/");strcat(pwdd3,&pwdd1);
													if(pwdd1!=NULL)
														{
															strcat(pwddd,pwdd3);
														}
												}
												chdir(pwddd);
											}
										else if(strcmp(attr[0],"/")==0)
											{
												chdir(attr);
											}
										else 	
											{
												strcat(pwd2,attr);
												chdir(pwd2);
											}
									}
							}
					}
			}
		else
			{
				for(a=0;a<strlen(token);a++){command[a]=&token[a];}
				token=strtok (NULL , " ");
				for(a=0;a<strlen(token);a++){attr[a]=&token[a];}
				pid=fork();
					if(pid==0)
						{
							getcwd(pwd2,100);
							if(strcmp(attr,"")==0)
								{
								if(execlp("/bin",command,pwd2,NULL)==-1)
									{}
								else if(execlp("/usr/bin",command,pwd2,NULL)==-1)
									{}	
								}
							else
								{
								if(execlp("/bin",command,attr,pwd2,NULL)==-1)
									{}
								else if(execlp("/usr/bin",command,attr,pwd2,NULL)==-1)
									{}	
								}
							if(strcmp(command,"cd")==0)
							{
								if(strcmp(attr,"..")==0)
									{
										pwdd1=strtok(pwd2,"/");
										for(a=0;a<strlen(&pwdd1);a++)pwdd[a]=&pwdd1[a];
										while(pwdd1!=NULL)
											{
												pwdd1=strtok(NULL, "/");strcat(pwdd3,&pwdd1);
												if(pwdd1!=NULL)
												{
													strcat(pwddd,pwdd3);
												}
											}
										chdir(pwddd);
									}
								else if(strcmp(attr[0],"/")==0)
									{
										chdir(attr);
									}
								else 	
									{
										strcat(pwd2,attr);
										chdir(pwd2);
									}
							}
						}
						wait(0);
			}
	}
}

