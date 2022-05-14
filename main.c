#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "fixed.h"
#include "DU_main.h"
#include "NU_main.h"
#include "PU_main.h"
#include "BMU_main.h"
#include "PMU_main.h"
#include "SMU_main.h"
#include "MU_main.h"
#include "AS_main.h"
#include "last.h"
int choice;
char ans;
void login();
void signup();
void userMenu();
struct Login{
    char username[30],password[30];
}lgin;
void lginmain(){
    system("cls");
    fixed();
    int c;
    gotoxy(30, 17);
    printf("1.Signup");
    gotoxy(30, 18);
    printf("2.Login");
    gotoxy(30, 20);
    printf("Enter Your choice: ");
    scanf("%d",&c);
    if(c==1){
        signup();
    }
    else if(c==2){
        login();
    }
}
void signup(){
    system("cls");
    fixed();
    FILE *log;
    log=fopen("login.txt","w");
    gotoxy(30, 17);
    printf("Enter username: ");
    scanf("%s",lgin.username);
    gotoxy(30, 18);
    printf("Enter password: ");
    scanf("%s",lgin.password);
    fwrite(&lgin,sizeof(lgin),1,log);
    fclose(log);
    gotoxy(30, 21);
    printf("Now you can log in");
    gotoxy(30, 23);
    printf("Enter any key to continue..");
    getch();
    system("cls");
    login();
}
void login(){
    system("cls");
    fixed();
    char e[25] = " Loading.";
    char user[30], pass[30],ch;
    FILE *log;
    int i = 0, j;
    gotoxy(30, 17);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Log In Panel \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    log=fopen("login.txt","r");
    gotoxy(30, 20);
    printf("Enter UserName:");
    scanf("%s", &user);
    gotoxy(30, 22);
    printf("Enter Password:");
    while (ch != 13){
        ch = getch();
        if (ch != 13 && ch != 8){
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    while (fread(&lgin,sizeof(lgin),1,log)){
        if (strcmp(pass, lgin.password) == 0 && strcmp(user, lgin.username) == 0){
            gotoxy(30, 24);
            for (j = 0; j < 55; j++){
                delay(10);
                printf("\xB2");
            }
            for (j = 0; j < 11; j++){
                delay(10);
                printf("%c", e[j]);
            }
            for (j = 0; j < 55; j++){
                delay(10);
                printf("\xB2");
            }
            gotoxy(30, 26);
            printf("LogIn Successful");
            gotoxy(30, 28);
            printf("Press any key to continue.....");
            getch();
        }
        else{
            gotoxy(30, 26);
            printf("Warning!! Incorrect UserName or Password");
            getch();
            login();
        }
    }
    fclose(log);
}
void adminMenu(){
    system("cls");
    fixed();
    gotoxy(30, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Admin Menu  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 18);
    printf("1. Our Doctors' Unit");
    gotoxy(30, 19);
    printf("2. Our Nurses' Unit");
    gotoxy(30, 20);
    printf("3. Our Patients' Unit");
    gotoxy(30, 21);
    printf("4. Our Blood Management Unit");
    gotoxy(30, 22);
    printf("5. Our Payment Management Unit");
    gotoxy(30, 23);
    printf("6. Our Salary Management Unit");
    gotoxy(30, 24);
    printf("7. Our Medicine Unit");
    gotoxy(30, 25);
    printf("8. Our Ambulance List");
    gotoxy(30, 26);
    printf("9. Our Contact Details");
    gotoxy(30, 27);
    printf("10. Goto User Menu");
    gotoxy(30, 28);
    printf("Enter your choice(1-10): ");
    scanf("%d", &choice);
    switch (choice){
    case 1:DU_main();break;
    case 2:NU_main();break;
    case 3:PU_main();break;
    case 4:BMU_main();break;
    case 5:PMU_main();break;
    case 6:SMU_main();break;
    case 7:MU_main();break;
    case 8:AS_main();break;
    case 9:CD_display();break;
    case 10:userMenu();break;
    default:
        printf("\n %30cInvalid entry. Please enter right option :)");
    }
    getch();
    adminMenu();
}
void userMenu(){
    system("cls");
    fixed();
    gotoxy(30, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 User Menu \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 18);
    printf("1. Display Our Doctor");
    gotoxy(30, 19);
    printf("2. Display Our Nurse");
    gotoxy(30, 20);
    printf("3. Display Our Patient");
    gotoxy(30, 21);
    printf("4. Search A Blood Donor");
    gotoxy(30, 22);
    printf("5. Display Our Ambulance List");
    gotoxy(30, 23);
    printf("6. Display Our Contact Datails");
    gotoxy(30, 24);
    printf("7. Search Medicine Here");
    gotoxy(30, 25);
    printf("8. Search Due Payment Here");
    gotoxy(30, 26);
    printf("9. Goto Admin Menu");
    gotoxy(30, 27);
    printf("Enter Your Choice(1 ~ 9): ");
    scanf("%d", &choice);
    switch (choice){
    case 1:DU_display();printf("\n %30cEnter any key to continue..");getch();break;
    case 2:NU_display();printf("\n %30cEnter any key to continue..");getch();break;
    case 3:PU_display();printf("\n %30cEnter any key to continue..");getch();break;
    case 4:BMU_display;printf("\n %30cEnter any key to continue..");getch();break;
    case 5:AS_display();break;
    case 6:CD_display();break;
    case 7:MU_search();break;
    case 8:PMU_due_search();break;
    case 9:adminMenu();break;
    default:
        printf("\n %30cInvalid entry. Please enter right option :)");
    }
    getch();
    userMenu();
}
int Main(){
    system("cls");
    fixed();
    gotoxy(30, 16);
    printf("1.Admin Menu");
    gotoxy(30, 17);
    printf("2.User Menu");
    gotoxy(30, 18);
    printf("Enter Your Choice(1-2):");
    scanf("%d",&choice);
    if (choice==1){
        lginmain();
        adminMenu();
    }
    else if(choice==2){
        lginmain();
        userMenu();
    }
    else
        printf("\n %30cInvalid entry. Please enter right option :)");
    getch();
    Main();
}
int main(){
    printf("Before starting maximize your terminal and hit any key: ");
    getch();
    Main();
    return 0;
}