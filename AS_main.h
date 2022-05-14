struct Ambulance{
    int Idno;
    char Name[30], Type[30],Phone[30];
} amblc;
int choice;
void AS_insert(){
    system("cls");
    fixed();
    FILE *fp;
    fp = fopen("AS_record.txt", "a");
    gotoxy(30, 15);
    printf("Enter the Ambulance Driver Idno        :");
    scanf("%d", &amblc.Idno);
    gotoxy(30, 16);
    printf("Enter the Ambulance Driver Name        :");
    getchar();
    scanf("%[^\n]", amblc.Name);
    gotoxy(30, 18);
    printf("1. Uttoron");
    gotoxy(30, 19);
    printf("2. Unnoyon");
    gotoxy(30, 20);
    printf("3. Shilpayon");
    gotoxy(30, 21);
    printf("4. Grihayon");
    gotoxy(30, 22);
    printf("5. Rupayon");
    gotoxy(30, 24);
    printf("Choice Ambulance Brunch(1 ~ 5) :");
    scanf("%d", &choice);
    switch (choice){
    case 1:strcpy(amblc.Type,"Uttoron");break;
    case 2:strcpy(amblc.Type,"Unnoyon");break;
    case 3:strcpy(amblc.Type,"Shilpayon");break;
    case 4:strcpy(amblc.Type,"Grihayon");break;
    case 5:strcpy(amblc.Type,"Rupayon");break;
    default:
        printf("\n %30cInvalid entry. Please enter right option :)");
    }
    gotoxy(30, 27);
    printf("Enter the Ambulance Service Number      :");
    scanf("%s", &amblc.Phone);
    fwrite(&amblc, sizeof(amblc), 1, fp);
    fclose(fp);
}
void AS_display(){
    system("cls");
    fixed();
    FILE *fp1;
    fp1 = fopen("AS_record.txt", "r");
    gotoxy(36, 15);
    printf("\tId Number\t\tDriver\t\t\tBrunch\t\t\tPhone");
    gotoxy(30, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    while (fread(&amblc, sizeof(amblc), 1, fp1)){
        printf("\t\t\t\t\t%-24d%-24s%-24s%-24s\n", amblc.Idno,amblc.Name,amblc.Type,amblc.Phone);
        printf("\t\t\t\t\t--------------------------------------------------------------------------------\n");
    }
    fclose(fp1);
}
int AS_empty(){
    int c = 0;
    FILE *fp;
    fp = fopen("AS_record.txt", "r");
    while (fread(&amblc, sizeof(amblc), 1, fp))
        c = 1;
    fclose(fp);
    return c;
}
void AS_main(){
    system("cls");
    fixed();
    int c, emp;
    gotoxy(30, 15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Select Your Choise \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 17);
    printf("1. Ambulance insert");
    gotoxy(30, 18);
    printf("2. Ambulance display");
    gotoxy(30, 19);
    printf("3. Goto main");
    gotoxy(30, 21);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 25);
    printf("Enter your choice:");
    scanf("%d", &c);
    printf("\n");
    switch (c){
    case 1:
        AS_insert();
        getch();
        AS_main();
        break;
    case 2:emp = AS_empty();
        if (emp == 0)
            printf("\n%30cThe file is AS_empty\n");
        else
            AS_display();
        getch();
        AS_main();
        break;
    case 3:break;
    default:
        gotoxy(30, 26);
        printf("\n %30cInvalid entry. Please enter right option :)");
        break;
    }
}