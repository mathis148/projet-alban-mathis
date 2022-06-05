
#include "library.h"



void signUp(){           //function for creating an account
    char login[100];
    char passWord[100];
    char choose[100];
    FILE *userList=NULL;                 
    FILE *bookBorrowed=NULL;
    userList=fopen("UserList.txt","a+");           //we open the files userlist for login and 
    bookBorrowed=fopen("bookBorrowed.txt","a+");   //password and bbokborrowed to print them afterwards
    printf("\n");
    printf("0-Back Menu");
    printf("\nchoose a login:");
    scanf("%[^\n]",login);
	clear_scan();
    if (*login=='0'){
		mainMenu();
		}
	else {
		fprintf(userList,"\n%s",login);
		fprintf(bookBorrowed,"\n%s",login);	
		printf("\nchoose a passWord:");
		scanf("%s",passWord);
		fprintf(userList,"\n%s",passWord);
		clear_scan();
		do{
			printf("\n");
			printf("you are a 1-teacher or a 2-student ?");
			scanf("%[^\n]",choose);
		}while(*choose!='1' && *choose!='2');                   //we assign the role of student or teacher
		if (*choose=='1'){
			fprintf(userList,"\n%s","teacher");
			clear_scan();
			char nbBook='0';
			fprintf(bookBorrowed,"\n%c",nbBook);
			char book= ' ';
			
				fprintf(bookBorrowed,"\n%c",book);
				for(int i=0;i<1000;i++){
					fprintf(bookBorrowed,"%c",book);
				}
							
			fclose(userList);                      //we close the files after each use to avoid the recording time
			fclose(bookBorrowed);
			mainMenu();
		}
		else{
			fprintf(userList,"\n%s","student");
			clear_scan();
			char nbBook='0';
			fprintf(bookBorrowed,"\n%c",nbBook);
			char book= ' ';
			
				fprintf(bookBorrowed,"\n%c",book);
				for(int i=0;i<1000;i++){
					fprintf(bookBorrowed,"%c",book);
				}
				
			fclose(userList);
			fclose(bookBorrowed);
			mainMenu();

		}
	}
}
void checkPassWord(char *login,char *passWord,char *role){         //we check the password
    char pw [100];
   // printf("\n%s",login);
   // printf("  %s",passWord);
    int check=0;
   // printf("\n%s",login);
    printf("\nPassWord:");
    scanf("%[^\n]",pw);
    clear_scan();
	// printf("%s",passWord);
    int sizePw=0;
    sizePw=strlen(pw);
    
    for(int i=0;i<sizePw;i++){
		if (pw[i]==passWord[i]){
			check++;
         }
     }
    
    if (check==sizePw){
        connectedmenue(role,login);
    }
    else{
        printf("Wrong password,try again-");
        checkPassWord(login,passWord,role);
    }
}

void checklogin(){            //we check the login 
    char login[100];
    char passWord[100];
    char role[15];
    char log [100];
    int sizeLog=0;
    int check=0;
    int error=0;
    printf("\n");
    printf("0-Back Menu");
    printf("\nlogin:");
	scanf("%[^\n]",login);
    clear_scan();
    if (*login=='0'){
		mainMenu();
		}
	else{
    sizeLog=strlen(login);
    FILE *userList=NULL;
    userList=fopen("UserList.txt","r+");
    sizeLog=strlen(login);
    while(check!=sizeLog && error<1000){
        error++;
        fgets(log,100,userList);
        check=0;
        for(int i=0;i<sizeLog;i++){
            if (log[i]==login[i]){
                check++;
            }
        }
    }
    if(check==sizeLog){
		fgets(passWord,100,userList);
		fgets(role,100,userList);
        checkPassWord(login,passWord,role);
    }
    else{
        printf("wrong login, try again\n");
        checklogin();
    }
	}  
}
