#include "library.h"

int checkUseBook(char bookTitle[100]){          //this function checks if the book is already used 
    int sizeTitle=strlen(bookTitle);
    FILE *bookBorrowed=NULL;
    bookBorrowed=fopen("bookBorrowed.txt","r+");
    int check=0;
    int error=0;
    char uB[100];
    while(check!=sizeTitle && error<4000){
        error++;
        fgets(uB,100,bookBorrowed);
        check=0;
        for(int i=0;i<sizeTitle;i++){
            if (uB[i]== bookTitle[i]){
                check++;
            }
        }
    }
    fclose(bookBorrowed);

    if(check==sizeTitle){
        return 2;
    }
    else {
        return 1;
    }
}

int checkBook(char bookTitle[100]){            //this function checks if the requested book exists in the list
    int sizeTitle=strlen(bookTitle);
    FILE *bookList=NULL;
    bookList=fopen("BookList.txt","r+");
    int check=0;
    int error=0;
    char uB[100];
    while(check!=sizeTitle && error<4000){
        error++;
        fgets(uB,100,bookList);
        check=0;
        for(int i=0;i<sizeTitle;i++){
            if (uB[i]== bookTitle[i]){
                check++;
            }
        }
    }
    fclose(bookList);

    if(check==sizeTitle){
        return 1;
    }
    else {
        return 2;
    }
}

void giveBook(char *login, char bookTitle[100], char *role){       //this function allows the printing of books 
    if(checkUseBook(bookTitle)==1 && checkBook(bookTitle)==1){
        FILE *bookBorrowed=NULL;
        bookBorrowed=fopen("bookBorrowed.txt","r+");
        int sizeLogin=strlen(login);
        char log[100];
        int check=0;
        int error=0;
        while(check!=sizeLogin && error<1000){
            error++;
            fgets(log,100,bookBorrowed);
            check=0;
            for(int i=0;i<sizeLogin;i++){
                if (log[i]==login[i]){
                    check++;
                }
            }
        }
        char nbBook;
        int number=1;
        nbBook=fgetc(bookBorrowed);
        nbBook=nbBook+1;
        fseek(bookBorrowed,-1,1);
        fputc(nbBook,bookBorrowed);
        while(number<nbBook-48){
        fseek(bookBorrowed,1000,1);
			number++;
			}
        fprintf(bookBorrowed,"\n%s",bookTitle);
        fclose(bookBorrowed);
        connectedmenue(role,login);
    }
    else{
		printf("\nThis book does not exist or is already printed");
		connectedmenue(role,login);
		}
}

void dispborrowedbook(char *login){         //we display the printed books
    int check=0;
    int error=0;
    FILE *bookBorrowed=NULL;
    bookBorrowed=fopen("bookBorrowed.txt","r+");
    char log[100];
    int sizeLogin=strlen(login);
    while(check!=sizeLogin && error<1000){
        error++;
        fgets(log,100,bookBorrowed);
        check=0;
        for(int i=0;i<sizeLogin;i++){
            if (log[i]==login[i]){
                check++;
            }
        }
    }
    char nbBook2;
    nbBook2=fgetc(bookBorrowed);
    char Book1[100];
    int nbBook=nbBook2;
    printf("\nyou have borrowed :");
    printf("%c",nbBook2);
    for (int i=0; i<nbBook-47;i++){
        fgets(Book1,100,bookBorrowed);
        printf("%s",Book1);
    }
    fclose(bookBorrowed);
}

int checkmaxbook(char* role,char *login){   //we verify that you have the right to borrow
    int check=0;
    int error=0;
    FILE *bookBorrowed=NULL;
    char log[100];
    bookBorrowed=fopen("bookBorrowed.txt","r+");
    int sizeLogin=strlen(login);
    while(check!=sizeLogin && error<1000){
        error++;
        fgets(log,100,bookBorrowed);
        check=0;
        for(int i=0;i<sizeLogin;i++){
            if (log[i]==login[i]){
                check++;
            }
        }
    }
	char nbBook;
    nbBook=fgetc(bookBorrowed);
    if (*role=='s'){
        if(nbBook<'1'){
            return 1;
        }
        else {
            return 0;
        }
    }
    if (*role=='t'){
        if(nbBook<'1'){
            return 1;
        }
        else {
            return 0;
        }
    }
    fclose(bookBorrowed);
}

void connectedmenue(char *role,char *login){
    if (*role=='s'){
        char choose[100];
        do {
        printf("\n     ||Welcome %s here are yours borrowed books||\n",login);
        dispborrowedbook(login);
        printf("\n\nWhat do you want to do next ?\n1-borrow another book\n2-give back a book\n3-deconecting\n");
        scanf("%s",choose);
        clear_scan();
        } while(*choose!='1' && *choose!='2' && *choose!='3');
        if (*choose=='1'){
            if(checkmaxbook(role,login)==1){
                FILE *bookList=NULL;
                printf("\nyou can choose your book with the title or the author or the id\n");
                bookList=fopen("BookList.txt","r+");
                char alpha[1000][100];
                int temp; 
                int j=0;

                
                          for(int i=0; i<1000; i++){
                            fgets(alpha[j],100,bookList);
                            j++;
                }
            int i=0;
                for (i = 0; i < 1000; i++){
                    for (j = 0; j < 1000; j++){
                        if (strcmp(alpha[i], alpha[i+1]) > 0){
                            temp = alpha[i][100];
                            alpha[i][100] = alpha[i+1][100];
                           alpha[i][100] = temp; 
                        }
                    }
                }
                 printf("\n");
                for (int i=0; i<1000; i++){
                    printf("%s",alpha[i]);
                }
                printf("\nwhich book do you want to borrow ?");
                char bookTitle[100];
                scanf("%[^\n]",bookTitle);
                clear_scan();
                fclose(bookList);
                giveBook(login,bookTitle,role);
            
        }    else{
                printf("you have borrowed too much book, the maximun number of book you can borrow is 1");
                connectedmenue(role,login);
            }
        }
        if (*choose=='2'){
            char bookTitle[100];
            FILE *bookBorrowed=NULL;
            bookBorrowed=fopen("bookBorrowed.txt","r+");
            printf("which book do you want to give back ?");
            scanf("%[^\n]",bookTitle);
            if(checkUseBook(bookTitle)==2){
            char log[100];
            int check=0;
            int error=0;
            int sizeLogin=strlen(login);
            while(check!=sizeLogin && error<4000){
                error++;
                fgets(log,100,bookBorrowed);
                check=0;
                for(int i=0;i<sizeLogin;i++){
                    if (log[i]==login[i]){
                        check++;
                    }
                }
            }
            char nbBook;
            nbBook=fgetc(bookBorrowed);
            nbBook=nbBook-1;
            fseek(bookBorrowed,-1,1);
            fputc(nbBook,bookBorrowed);
            char book= ' ';
            fgetc(bookBorrowed);
				for(int i=0;i<100;i++){
				fprintf(bookBorrowed,"%c",book);
			}
			fclose(bookBorrowed);
            connectedmenue(role,login);
		}
		else{
			printf("you did not take this book!");
            fclose(bookBorrowed);
            connectedmenue(role,login);
        }}
        if (*choose=='3'){
			mainMenu();
			}
    }
    else {
        char choose[100];
        do {
        printf("\n     ||Welcome %s here are yours borrowed books||\n",login);
        dispborrowedbook(login);
        printf("\n\nWhat do you want to do next ?\n1-borrow another book\n2-give back a book\n3-add book\n4-deconecting\n");
        scanf("%s",choose);
        clear_scan();
        } while(*choose!='1' && *choose!='2' && *choose!='3' && *choose!='4');
        if(*choose=='1'){
            if(checkmaxbook(role,login)==1){
                FILE *bookList=NULL;
                printf("\nyou can choose your book with the title or the author or the id\n");
                bookList=fopen("BookList.txt","r+");
                char alpha[1000][100];
                int temp; 
                int j=0;

                
                          for(int i=0; i<1000; i++){
                            fgets(alpha[j],100,bookList);
                            j++;
                }
            int i=0;
                for (i = 0; i < 1000; i++){
                    for (j = 0; j < 1000; j++){
                        if (strcmp(alpha[i], alpha[i+1]) > 0){
                            temp = alpha[i][100];
                            alpha[i][100] = alpha[i+1][100];
                            alpha[i][100] = temp; 
                        }
                    }
                }
                 printf("\n");
                for (int i=0; i<1000; i++){
                    printf("%s",alpha[i]);
                }
                printf("\nwhich book do you want to borrow ?");
                char bookTitle[100];
                scanf("%[^\n]",bookTitle);
                clear_scan();
                fclose(bookList);
                giveBook(login,bookTitle,role);
            }
            else{
                printf("you have borrowed too much book, the maximun number of book you can borrow is 1");
                connectedmenue(role,login);
            }
        }
        if (*choose=='2'){
            char bookTitle[100];
            FILE *bookBorrowed=NULL;
            bookBorrowed=fopen("bookBorrowed.txt","r+");
            printf("which book do you want to give back ?");
            scanf("%[^\n]",bookTitle);
            if(checkUseBook(bookTitle)==2){
            char log[100];
            int check=0;
            int error=0;
            int sizeLogin=strlen(login);
            while(check!=sizeLogin && error<4000){
                error++;
                fgets(log,100,bookBorrowed);
                check=0;
                for(int i=0;i<sizeLogin;i++){
                    if (log[i]==login[i]){
                        check++;
                    }
                }
            }
            char nbBook;
            nbBook=fgetc(bookBorrowed);
            nbBook=nbBook-1;
            fseek(bookBorrowed,-1,1);
            fputc(nbBook,bookBorrowed);
            char book= ' ';
            fgetc(bookBorrowed);
				for(int i=0;i<100;i++){
				fprintf(bookBorrowed,"%c",book);
			}
			fclose(bookBorrowed);
            connectedmenue(role,login);
		}
		else{
			printf("you did not take this book!");
            fclose(bookBorrowed);
            connectedmenue(role,login);
        }
        }
        if(*choose=='3'){
            char bookTitle[100];
            char author[100];
            char category[100];
            int IDnumber;
            clear_scan();
            printf("enter the booktitle");
            scanf("%[^\n]",bookTitle);
            clear_scan();
            printf("enter the author");
            scanf("%[^\n]",author);
            clear_scan();
            printf("enter the category");
            scanf("%[^\n]",category);
            clear_scan();
            printf("enter the IDnumber");
            scanf("%d",&IDnumber);
            clear_scan();
            FILE *bookBorrowed=NULL;
            bookBorrowed=fopen("BookList.txt","a+");
            fprintf(bookBorrowed,"%s",bookTitle);
            fprintf(bookBorrowed,"\n%s",author);
            fprintf(bookBorrowed,"\n%s",category);
            fprintf(bookBorrowed,"\n%d",IDnumber);
            fclose(bookBorrowed);
            connectedmenue(role, login);


        }
        if (*choose=='4'){
            mainMenu();
        }

    }
}
