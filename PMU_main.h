void PMU_due_delete(int);
int PMU_due_avail(int);
int PMU_paid_avail(int);
int PMU_due_empty();
int PMU_paid_empty();
struct Payment{
    int Idno,Amount,Choice;
    char Type[30];
} due1,paid1;
void PMU_paid_insert(int r,int s,int c){
    system("cls");
    fixed();
    FILE *fp1;
    fp1 = fopen("PMU_paid_record.txt", "a");
    paid1.Idno=r;
    paid1.Amount=s;
    paid1.Choice=c;
    fwrite(&paid1, sizeof(paid1), 1, fp1);
    fclose(fp1);
}
void PMU_due_insert(){
    system("cls");
    fixed();
    FILE *fp2;
    fp2 = fopen("PMU_due_record.txt", "a");
    gotoxy(30, 15);
    printf("Enter the Idno        :");
    scanf("%d", &due1.Idno);
    gotoxy(30, 16);
    printf("Enter the Due        :");
    scanf("%d", &due1.Amount);
    fwrite(&due1, sizeof(due1), 1, fp2);
    fclose(fp2);
}
void PMU_paid_display(){
    system("cls");
    fixed();
    int a= rand()*rand()*rand();
    FILE *fp3;
    fp3 = fopen("PMU_paid_record.txt", "r");
    gotoxy(36, 15);
    printf("\t\tId Number\t\tPaid Amount\t\tChoice\t\tTransaction Number");
    gotoxy(30, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    while (fread(&paid1, sizeof(paid1), 1, fp3)){
        switch (paid1.Choice){
        case 1:strcpy(paid1.Type,"Bkash");break;
        case 2:strcpy(paid1.Type,"Nagad");break;
        case 3:strcpy(paid1.Type,"Rocket");break;
        case 4:strcpy(paid1.Type,"DBBL");break;
        case 5:strcpy(paid1.Type,"IBBL");break;
        default:
            printf("\n %30cInvalid entry. Please enter right option :)");
        }
        printf("\t\t\t\t\t\t%-24d%-24d%-16s%-16x\n",paid1.Idno,paid1.Amount,paid1.Type,a/paid1.Idno);
        printf("\t\t\t\t\t\t---------------------------------------------------------------------------------\n");
    }
    fclose(fp3);
}
void PMU_due_display(){
    system("cls");
    fixed();
    FILE *fp4;
    fp4 = fopen("PMU_due_record.txt", "r");
    gotoxy(36, 15);
    printf("\t\t\t\t\t\tId Number\t\tDue Amount");
    gotoxy(30, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    while (fread(&due1, sizeof(due1), 1, fp4)){
        printf("\t\t\t\t\t\t\t\t\t\t%-24d%-24d\n",due1.Idno,due1.Amount);
        printf("\t\t\t\t\t\t\t\t\t\t----------------------------------\n");
    }
    fclose(fp4);
}
void PMU_login(){
    system("cls");
    fixed();
    char e[25] = " Loading.";
    char user[30], pass[30],ch;
    FILE *log;
    int i = 0, j;
    gotoxy(30, 15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Pin Submit \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    gotoxy(30, 17);
    printf("Enter Account/Phone Number  :");
    scanf("%s", &user);
    gotoxy(30, 18);
    printf("Enter Pin Number            :");
    while (ch != 13){
        ch = getch();
        if (ch != 13 && ch != 8){
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    gotoxy(30, 20);
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
    gotoxy(30, 22);
    printf("Pin Submitted Successfully");
    printf("\n %30cPress any key to show details.....");
    getch();
}
void PMU_paid_search(int r){
    system("cls");
    fixed();
    int a= rand()*rand()*rand();
    gotoxy(36, 15);
    FILE *fp5;
    int s,avl;
    avl=PMU_paid_avail(r);
    if (avl== 0)
        printf("Id No %d is not available in the file\n", r);
    else{
        fp5 = fopen("PMU_paid_record.txt", "r");
        printf("\t\tId Number\t\tPaid Amount\t\tChoice\t\tTransaction Number");
        gotoxy(30, 16);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        while (fread(&paid1, sizeof(paid1), 1, fp5)){
            s = paid1.Idno;
            switch (paid1.Choice){
            case 1:strcpy(paid1.Type,"Bkash");break;
            case 2:strcpy(paid1.Type,"Nagad");break;
            case 3:strcpy(paid1.Type,"Rocket");break;
            case 4:strcpy(paid1.Type,"DBBL");break;
            case 5:strcpy(paid1.Type,"IBBL");break;
            default:
                printf("\n %30cInvalid entry. Please enter right option :)");
            }
            if (s == r){
                printf("\t\t\t\t\t\t%-24d%-24d%-16s%-16x\n",paid1.Idno,paid1.Amount,paid1.Type,a/paid1.Idno);
                printf("\t\t\t\t\t\t---------------------------------------------------------------------------------\n");
            }
        }
        fclose(fp5);
    }
    printf("\n %30cPress any key to continue.....");
    getch();
}
void PMU_due_search(){
    system("cls");
    fixed();
    FILE *fp6;
    int r,s,avl,yesno;
    gotoxy(30, 15);
    printf("Enter the Id no you want to PMU_due_search  :");
    scanf("%d", &r);
    avl=PMU_due_avail(r);
    if (avl== 0)
        printf("Id No %d is not available in the file\n", r);
    else{
        fp6 = fopen("PMU_due_record.txt", "r");
        while (fread(&due1, sizeof(due1), 1, fp6)){
            s=due1.Idno;
            if (s==r){
                gotoxy(30, 17);
                printf("Your Due Payment Idno is: %d\n", due1.Idno);
                gotoxy(30, 18);
                printf("Your Due Payment Amount is: %d\n", due1.Amount);
                gotoxy(30, 19);
                printf("Do You want to clear your due? (1/0): ");
                scanf("%d",&yesno);
                if (yesno==1){
                    gotoxy(30, 21);
                    printf("1. Bkash");
                    gotoxy(30, 22);
                    printf("2. Nagad");
                    gotoxy(30, 23);
                    printf("3. Rocket");
                    gotoxy(30, 24);
                    printf("4. DBBL");
                    gotoxy(30, 25);
                    printf("5. IBBL");
                    gotoxy(30, 26);
                    printf("Enter your Payment Method(1-5) : ");
                    scanf("%d", &due1.Choice);
                    PMU_login();
                    PMU_paid_insert(due1.Idno,due1.Amount,due1.Choice);
                    PMU_paid_search(due1.Idno);
                    PMU_due_delete(due1.Idno);
                }
                else{
                    printf("\n %30cWelcome");
                }
            }  
        }
        fclose(fp6);
    }
}
void PMU_due_delete(int r){
    system("cls");
    fixed();
    FILE *fpo;
    FILE *fpt;
    int s,avl,yesno;
    avl=PMU_due_avail(r);
    if(avl== 0)
        printf("Id no %d is not available in the file\n", r);
    else{
        fpo = fopen("PMU_due_record.txt", "r");
        fpt = fopen("PMU_due_temp.txt", "w");
        while (fread(&due1, sizeof(due1), 1, fpo)){
            s = due1.Idno;
            if (s != r)
                fwrite(&due1, sizeof(due1), 1, fpt);
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("PMU_due_record.txt", "w");
        fpt = fopen("PMU_due_temp.txt", "r");
        while (fread(&due1, sizeof(due1), 1, fpt))
            fwrite(&due1, sizeof(due1), 1, fpo);
        gotoxy(30, 16);
        printf("Due Deleted Successfully\n");
        fclose(fpo);
        fclose(fpt);
    }
    printf("\n %30cDo You want to search again? (1/0): ");
    scanf("%d",&yesno);
    if (yesno==1)
        PMU_due_search();
    else
        printf("\n %30cWelcome");
}
int PMU_paid_avail(int rno){
    FILE *fp;
    int c = 0;
    fp = fopen("PMU_paid_record.txt", "r");
    while (!feof(fp)){
        fread(&paid1, sizeof(paid1), 1, fp);
        if (rno == paid1.Idno){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int PMU_paid_empty(){
    int c = 0;
    FILE *fp;
    fp = fopen("PMU_paid_record.txt", "r");
    while (fread(&paid1, sizeof(paid1), 1, fp))
        c = 1;
    fclose(fp);
    return c;
}
int PMU_due_avail(int rno){
    FILE *fp;
    int c = 0;
    fp = fopen("PMU_due_record.txt", "r");
    while (!feof(fp)){
        fread(&due1, sizeof(due1), 1, fp);
        if (rno == due1.Idno){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int PMU_due_empty(){
    int c = 0;
    FILE *fp;
    fp = fopen("PMU_due_record.txt", "r");
    while (fread(&due1, sizeof(due1), 1, fp))
        c = 1;
    fclose(fp);
    return c;
}
void PMU_main(){
    system("cls");
    fixed();
    gotoxy(30, 15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Select Your Choice \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 17);
    printf("1. Due insert");
    gotoxy(30, 18);
    printf("2. Due display");
    gotoxy(30, 19);
    printf("3. Paid display");
    gotoxy(30, 20);
    printf("4. Due search");
    gotoxy(30, 21);
    printf("5. Goto main");
    gotoxy(30, 22);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 24);
    printf("Enter your choice:");
    scanf("%d", &due1.Choice);
    printf("\n");
    switch (due1.Choice){
    case 1:
        PMU_due_insert();
        getch();
        PMU_main();
        break;
    case 2:
        if (PMU_due_empty() == 0)
            printf("\n %30cThe due file empty\n");
        else
            PMU_due_display();
        getch();
        PMU_main();
        break;
    case 3:
        if (PMU_paid_empty() == 0)
            printf("\n %30cThe paid file is empty\n");
        else
            PMU_paid_display();
        getch();
        PMU_main();
        break;
    case 4:
        PMU_due_search();
        getch();
        PMU_main();
        break;
    case 5:break;
    default:
        gotoxy(30, 26);
        printf("\n %30cInvalid entry. Please enter right option :)");
        break;
    }
}