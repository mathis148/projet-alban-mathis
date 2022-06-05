
#include "library.h"


void clear_scan(){                //this function allows to empty the buffer during scanf
	char c;
	int res;
	do{
		res=fscanf(stdin,"%c",&c);
		}while(res==1 && c!='\n');
	}

void mainMenu(){           //mainMenu asks the user if he already has an account or if he wants to create one
    char choose[100];
    do {
    printf("\n");
    printf("Main Menu\n1-connection\n2-new user ?\n");	
	scanf("%[^\n]",choose);                        //for scanf we use "%[^\n]" that allows to scan a whole line even including spaces         
	clear_scan();
	} while(*choose!='1' && *choose!='2');        //condition to constrain the answer by 1 or 2 and not to accept the other answers
    if(*choose=='1'){
        checklogin();
    }
    else if(*choose=='2') {
        signUp();
    }	
}

int main(){
    mainMenu();        
    return 0;
}
