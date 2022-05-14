int BMU_avail(int rno);
struct Blood{
    int Idno;
    char Name[30],Phone[30],Date[30];
} bld;
int choice;
void BMU_insert(){
    system("cls");
    fixed();
    FILE *fp;
    fp = fopen("BMU_record.txt", "a");
    gotoxy(30, 18);
    printf("1. A+");
    gotoxy(30, 19);
    printf("2. A-");
    gotoxy(30, 20);
    printf("3. B+");
    gotoxy(30, 21);
    printf("4. B-");
    gotoxy(30, 22);
    printf("5. AB+");
    gotoxy(30, 23);
    printf("6. AB-");
    gotoxy(30, 24);
    printf("7. O+");
    gotoxy(30, 25);
    printf("8. O-");
    gotoxy(30, 26);
    printf("Choice Donor Blood Group(1 ~ 8) :");
    scanf("%d", &choice);
    switch (choice){
    case 1:bld.Idno=1;break;
    case 2:bld.Idno=2;break;
    case 3:bld.Idno=3;break;
    case 4:bld.Idno=4;break;
    case 5:bld.Idno=5;break;
    case 6:bld.Idno=6;break;
    case 7:bld.Idno=7;break;
    case 8:bld.Idno=8;break;
    default:
        printf("\n %30cInvalid entry. Please enter right option :)");
    }
    gotoxy(30, 27);
    printf("Enter Donor Name        :");
    getchar();
    scanf("%[^\n]", bld.Name);
    gotoxy(30, 28);
    printf("Enter the Number      :");
    scanf("%s", &bld.Phone);
    gotoxy(30, 29);
    printf("Enter the Date        :");
    scanf("%s", &bld.Date);
    fwrite(&bld, sizeof(bld), 1, fp);
    fclose(fp);
}
void BMU_display(){
    system("cls");
    fixed();
    FILE *fp1;
    char ch[30];
    fp1 = fopen("BMU_record.txt", "r");
    gotoxy(36, 15);
    printf("\tBlood Group\t\tName\t\t\tPhone\t\t\tDate");
    gotoxy(30, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    while (fread(&bld, sizeof(bld), 1, fp1)){
        switch (bld.Idno){
                case 1:strcpy(ch,"A+");break;
                case 2:strcpy(ch,"A-");break;
                case 3:strcpy(ch,"B+");break;
                case 4:strcpy(ch,"B-");break;
                case 5:strcpy(ch,"AB+");break;
                case 6:strcpy(ch,"AB-");break;
                case 7:strcpy(ch,"O+");break;
                case 8:strcpy(ch,"O-");break;
                default:
                    printf("\n %30cInvalid entry. Please enter right option :)");
                }
        printf("\t\t\t\t\t%-24s%-24s%-24s%-24s\n", ch,bld.Name,bld.Phone,bld.Date);
        printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------\n");
    }
    fclose(fp1);
}
void BMU_search(){
    system("cls");
    fixed();
    FILE *fp2;
    char ch[30];
    int r, s, avl;
    gotoxy(30, 15);
    gotoxy(30, 18);
    printf("1. A+");
    gotoxy(30, 19);
    printf("2. A-");
    gotoxy(30, 20);
    printf("3. B+");
    gotoxy(30, 21);
    printf("4. B-");
    gotoxy(30, 22);
    printf("5. AB+");
    gotoxy(30, 23);
    printf("6. AB-");
    gotoxy(30, 24);
    printf("7. O+");
    gotoxy(30, 25);
    printf("8. O-");
    gotoxy(30, 26);
    printf("Choice Searching Blood Group(1 ~ 8) :");
    scanf("%d", &choice);
    switch (choice){
    case 1:r=1;break;
    case 2:r=2;break;
    case 3:r=3;break;
    case 4:r=4;break;
    case 5:r=5;break;
    case 6:r=6;break;
    case 7:r=7;break;
    case 8:r=8;break;
    default:
        printf("\n %30cInvalid entry. Please enter right option :)");
    }
    avl = BMU_avail(r);
    if (avl == 0)
        printf("Id No %d is not available in the file\n", r);
    else{
        fp2 = fopen("BMU_record.txt", "r");
        gotoxy(36, 29);
        printf("\tBlood Group\t\tName\t\t\tPhone\t\t\tDate\n\n");
        gotoxy(30, 30);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        while (fread(&bld, sizeof(bld), 1, fp2)){
            s = bld.Idno;
            if (s == r){
                switch (bld.Idno){
                case 1:strcpy(ch,"A+");break;
                case 2:strcpy(ch,"A-");break;
                case 3:strcpy(ch,"B+");break;
                case 4:strcpy(ch,"B-");break;
                case 5:strcpy(ch,"AB+");break;
                case 6:strcpy(ch,"AB-");break;
                case 7:strcpy(ch,"O+");break;
                case 8:strcpy(ch,"O-");break;
                default:
                    printf("\n %30cInvalid entry. Please enter right option :)");
                }
                printf("\t\t\t\t\t%-24s%-24s%-24s%-24s\n", ch,bld.Name,bld.Phone,bld.Date);
                printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------\n");
            }
        }
        fclose(fp2);
    }
}
int BMU_avail(int rno){
    FILE *fp;
    int c = 0;
    fp = fopen("BMU_record.txt", "r");
    while (!feof(fp)){
        fread(&bld, sizeof(bld), 1, fp);
        if (rno == bld.Idno){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int BMU_empty(){
    int c = 0;
    FILE *fp;
    fp = fopen("BMU_record.txt", "r");
    while (fread(&bld, sizeof(bld), 1, fp))
        c = 1;
    fclose(fp);
    return c;
}
void BMU_main(){
    system("cls");
    fixed();
    int c, emp;
    gotoxy(30, 15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Select Your Choise \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 17);
    printf("1. Blood Insert");
    gotoxy(30, 18);
    printf("2. Blood Display");
    gotoxy(30, 19);
    printf("3. Blood Search");
    gotoxy(30, 20);
    printf("4. Goto main");
    gotoxy(30, 22);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 25);
    printf("Enter your choice:");
    scanf("%d", &c);
    printf("\n");
    switch (c){
    case 1:
        BMU_insert();
        getch();
        BMU_main();
        break;
    case 2:emp = BMU_empty();
        if (emp == 0)
            printf("\n %30cThe file is BMU_empty\n");
        else
            BMU_display();
        getch();
        BMU_main();
        break;
    case 3:
        BMU_search();
        getch();
        BMU_main();
        break;
    case 4:break;
    default:
        gotoxy(30, 26);
        printf("\n %30cInvalid entry. Please enter right option :)");
        break;
    }
}