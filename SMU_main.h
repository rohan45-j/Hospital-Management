void SMU_due_search();
void SMU_due_insert();
void SMU_due_delete(int);
int SMU_due_avail(int);
int SMU_paid_avail(int);
int SMU_due_empty();
int SMU_paid_empty();
int choice;
struct Salary{
    int Idno,Amount,Type;
} due2,paid2;
void SMU_paid_insert(int r,int s,int t){
    system("cls");
    fixed();
    FILE *fp1;
    fp1 = fopen("SMU_paid_record.txt", "a");
    paid2.Idno=r;
    paid2.Amount=s;
    paid2.Type=t;
    fwrite(&paid2, sizeof(paid2), 1, fp1);
    fclose(fp1);
}
void SMU_due_insert(){
    system("cls");
    fixed();
    FILE *fp2;
    fp2 = fopen("SMU_due_record.txt", "a");
    gotoxy(30, 15);
    printf("Enter the Idno        :");
    scanf("%d", &due2.Idno);
    gotoxy(30, 16);
    printf("Enter the Due        :");
    scanf("%d", &due2.Amount);
    gotoxy(30, 18);
    printf("1. Doctor");
    gotoxy(30, 19);
    printf("2. Nurse");
    gotoxy(30, 20);
    printf("3. Driver");
    gotoxy(30, 21);
    printf("4. Technician");
    gotoxy(30, 22);
    printf("5. Others");
    gotoxy(30, 24);
    printf("Choice the Medicine Type(1 ~5) :");
    scanf("%d", &choice);
    switch (choice){
    case 1:due2.Type=1;break;
    case 2:due2.Type=2;break;
    case 3:due2.Type=3;break;
    case 4:due2.Type=4;break;
    case 5:due2.Type=5;break;
    default:
        printf("\n %30cInvalid entry. Please enter right option :)");
    }
    fwrite(&due2, sizeof(due2), 1, fp2);
    fclose(fp2);
}
void SMU_paid_display(){
    system("cls");
    fixed();
    char ch[30];
    int a= rand()*rand()*rand();
    FILE *fp3;
    fp3 = fopen("SMU_paid_record.txt", "r");
    gotoxy(36, 15);
    printf("\t\tId Number\t\tPaid Amount\t\tType\t\tTransaction Number");
    gotoxy(30, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    while (fread(&paid2, sizeof(paid2), 1, fp3)){
        switch (paid2.Type){
        case 1:strcpy(ch,"Doctor");break;
        case 2:strcpy(ch,"Nurse");break;
        case 3:strcpy(ch,"Driver");break;
        case 4:strcpy(ch,"Technician");break;
        case 5:strcpy(ch,"Other");break;
        default:
            printf("\n %30cInvalid entry. Please enter right option :)");
        }
        printf("\t\t\t\t\t\t%-24d%-24d%-16s%-16x\n",paid2.Idno,paid2.Amount,ch,a/paid2.Idno);
        printf("\t\t\t\t\t\t---------------------------------------------------------------------------------\n");
    }
    fclose(fp3);
}
void SMU_due_display(){
    system("cls");
    fixed();
    FILE *fp4;
    char ch[30];
    fp4 = fopen("SMU_due_record.txt", "r");
    gotoxy(36, 15);
    printf("\t\t\tId Number\t\tDue Amount\t\tType");
    gotoxy(30, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    while (fread(&due2, sizeof(due2), 1, fp4)){
        switch (due2.Type){
        case 1:strcpy(ch,"Doctor");break;
        case 2:strcpy(ch,"Nurse");break;
        case 3:strcpy(ch,"Driver");break;
        case 4:strcpy(ch,"Technician");break;
        case 5:strcpy(ch,"Other");break;
        default:
            printf("\n %30cInvalid entry. Please enter right option :)");
        }
        printf("\t\t\t\t\t\t\t%-24d%-24d%-16s\n",due2.Idno,due2.Amount,ch);
        printf("\t\t\t\t\t\t\t-----------------------------------------------------------\n");
    }
    fclose(fp4);
}
void SMU_login(){
    system("cls");
    fixed();
    gotoxy(30, 17);
    printf("Amount Transfered Successfully");
    printf("\n %30cPress any key to show details.....");
    getch();
}
void SMU_paid_search(int r){
    system("cls");
    fixed();
    int a= rand()*rand()*rand();
    gotoxy(36, 15);
    FILE *fp5;
    int s,avl;
    char ch[30];
    avl=SMU_paid_avail(r);
    if (avl== 0)
        printf("Id No %d is not available in the file\n", r);
    else{
        fp5 = fopen("SMU_paid_record.txt", "r");
        printf("\t\tId Number\t\tPaid Amount\t\tChoice\t\tTransaction Number");
        gotoxy(30, 16);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        while (fread(&paid2, sizeof(paid2), 1, fp5)){
            s = paid2.Idno;
            if (s == r){
                switch (paid2.Type){
                case 1:strcpy(ch,"Doctor");break;
                case 2:strcpy(ch,"Nurse");break;
                case 3:strcpy(ch,"Driver");break;
                case 4:strcpy(ch,"Technician");break;
                case 5:strcpy(ch,"Other");break;
                default:
                    printf("\n %30cInvalid entry. Please enter right option :)");
                }
                printf("\t\t\t\t\t\t%-24d%-24d%-16s%-16x\n",paid2.Idno,paid2.Amount,ch,a/paid2.Idno);
                printf("\t\t\t\t\t\t---------------------------------------------------------------------------------\n");
            }
        }
        fclose(fp5);
    }
    printf("\n %30cPress any key to continue.....");
    getch();
}
void SMU_due_search(){
    system("cls");
    fixed();
    FILE *fp6;
    int r,s,avl,yesno;
    gotoxy(30, 15);
    printf("Enter the Id no you want to SMU_due_search  :");
    scanf("%d", &r);
    avl=SMU_due_avail(r);
    if (avl== 0)
        printf("Id No %d is not available in the file\n", r);
    else{
        fp6 = fopen("SMU_due_record.txt", "r");
        while (fread(&due2, sizeof(due2), 1, fp6)){
            s=due2.Idno;
            if (s==r){
                gotoxy(30, 17);
                printf("Employee Due Salary Amount is: %d\n", due2.Amount);
                gotoxy(30, 18);
                printf("Do You want to clear this employee due? (1/0): ");
                scanf("%d",&yesno);
                if (yesno==1){
                    SMU_login();
                    SMU_paid_insert(due2.Idno,due2.Amount,due2.Type);
                    SMU_paid_search(due2.Idno);
                    SMU_due_delete(due2.Idno);
                }
                else{
                    printf("\n %30cWelcome");
                }
            }  
        }
        fclose(fp6);
    }
}
void SMU_due_delete(int r){
    system("cls");
    fixed();
    FILE *fpo;
    FILE *fpt;
    int s,avl,yesno;
    avl=SMU_due_avail(r);
    if(avl== 0)
        printf("Id no %d is not available in the file\n", r);
    else{
        fpo = fopen("SMU_due_record.txt", "r");
        fpt = fopen("SMU_due_temp.txt", "w");
        while (fread(&due2, sizeof(due2), 1, fpo)){
            s = due2.Idno;
            if (s != r)
                fwrite(&due2, sizeof(due2), 1, fpt);
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("SMU_due_record.txt", "w");
        fpt = fopen("SMU_due_temp.txt", "r");
        while (fread(&due2, sizeof(due2), 1, fpt))
            fwrite(&due2, sizeof(due2), 1, fpo);
        gotoxy(30, 16);
        printf("Due Deleted Successfully\n");
        fclose(fpo);
        fclose(fpt);
    }
    printf("\n %30cDo You want to search again? (1/0): ");
    scanf("%d",&yesno);
    if (yesno==1)
        SMU_due_search();
    else
        printf("\n %30cWelcome");
}
int SMU_paid_avail(int rno){
    FILE *fp;
    int c = 0;
    fp = fopen("SMU_paid_record.txt", "r");
    while (!feof(fp)){
        fread(&paid2, sizeof(paid2), 1, fp);
        if (rno == paid2.Idno){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int SMU_paid_empty(){
    int c = 0;
    FILE *fp;
    fp = fopen("SMU_paid_record.txt", "r");
    while (fread(&paid2, sizeof(paid2), 1, fp))
        c = 1;
    fclose(fp);
    return c;
}
int SMU_due_avail(int rno){
    FILE *fp;
    int c = 0;
    fp = fopen("SMU_due_record.txt", "r");
    while (!feof(fp)){
        fread(&due2, sizeof(due2), 1, fp);
        if (rno == due2.Idno){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int SMU_due_empty(){
    int c = 0;
    FILE *fp;
    fp = fopen("SMU_due_record.txt", "r");
    while (fread(&due2, sizeof(due2), 1, fp))
        c = 1;
    fclose(fp);
    return c;
}
void SMU_main(){
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
    scanf("%d", &choice);
    printf("\n");
    switch (choice){
    case 1:
        SMU_due_insert();
        getch();
        SMU_main();
        break;
    case 2:
        if (SMU_due_empty() == 0)
            printf("\n %30cThe due file empty\n");
        else
            SMU_due_display();
        getch();
        SMU_main();
        break;
    case 3:
        if (SMU_paid_empty() == 0)
            printf("\n %30cThe paid file is empty\n");
        else
            SMU_paid_display();
        getch();
        SMU_main();
        break;
    case 4:
        SMU_due_search();
        getch();
        SMU_main();
        break;
    case 5:break;
    default:
        gotoxy(30, 26);
        printf("\n %30cInvalid entry. Please enter right option :)");
        break;
    }
}