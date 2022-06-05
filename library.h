#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mainMenu();
void checklogin();
void signUp();
void checkPassWord(char *login,char * password,char *role);
void connectedmenue(char *role,char *login);
void clear_scan();



typedef struct{
    char author[100];
    char Name[100];
    int IDnumber;
    char category[100];
}Book;
  
  
int checkUseBook(char bookTitle[100]);
int checkBook(char bookTitle[100]);
void giveBook(char *login, char bookTitle[100], char *role);
void dispborrowedbook(char *login);
int checkmaxbook(char *loggin, char* role);
void connectedmenue(char *role,char *login);

