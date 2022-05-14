int NU_avail(int rno);
struct Nurse{
    int Idno;
    char Name[30], Type[30],Phone[30],Date[30];
} nrs;
int choice;
void NU_insert(){
    system("cls");
    fixed();
    FILE *fp;
    fp = fopen("NU_record.txt", "a");
    gotoxy(30, 15);
    printf("Enter the Nurse Idno        :");
    scanf("%d", &nrs.Idno);
    gotoxy(30, 16);
    printf("Enter the Nurse Name        :");
    getchar();
    scanf("%[^\n]", nrs.Name);
    gotoxy(30, 18);
    printf("1. Cabin-1");
    gotoxy(30, 19);
    printf("2. Cabin-2");
    gotoxy(30, 20);
    printf("3. Cabin-3");
    gotoxy(30, 21);
    printf("4. Cabin-4");
    gotoxy(30, 22);
    printf("5. Cabin-5");
    gotoxy(30, 24);
    printf("Choice the Nurse Type(1 ~5) :");
    scanf("%d", &choice);
    switch (choice){
    case 1:strcpy(nrs.Type,"Cabin-1");break;
    case 2:strcpy(nrs.Type,"Cabin-2");break;
    case 3:strcpy(nrs.Type,"Cabin-3");break;
    case 4:strcpy(nrs.Type,"Cabin-4");break;
    case 5:strcpy(nrs.Type,"Cabin-5");break;
    default:
        printf("\n %30cInvalid entry. Please enter right option :)");
    }
    gotoxy(30, 25);
    printf("Enter the Nurse Number      :");
    scanf("%s", &nrs.Phone);
    gotoxy(30, 26);
    printf("Enter the Nurse Date        :");
    scanf("%s", &nrs.Date);
    fwrite(&nrs, sizeof(nrs), 1, fp);
    fclose(fp);
}
void NU_display(){
    system("cls");
    fixed();
    FILE *fp1;
    fp1 = fopen("NU_record.txt", "r");
    gotoxy(36, 15);
    printf("\tId Number\t\tName\t\t\tType\t\t\tPhone\t\t\tDate");
    gotoxy(30, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    while (fread(&nrs, sizeof(nrs), 1, fp1)){
        printf("\t\t\t\t\t%-24d%-24s%-24s%-24s%-24s\n", nrs.Idno,nrs.Name,nrs.Type,nrs.Phone,nrs.Date);
        printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------\n");
    }
    fclose(fp1);
}
void NU_search(){
    system("cls");
    fixed();
    FILE *fp2;
    int r, s, avl;
    gotoxy(30, 15);
    printf("Enter the Id no you want to NU_search  :");
    scanf("%d", &r);
    avl = NU_avail(r);
    if (avl == 0)
        printf("Id No %d is not available in the file\n", r);
    else{
        fp2 = fopen("NU_record.txt", "r");
        gotoxy(36, 17);
        printf("\tId Number\t\tName\t\t\tType\t\t\tPhone\t\t\tDate\n\n");
        gotoxy(30, 18);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        while (fread(&nrs, sizeof(nrs), 1, fp2)){
            s = nrs.Idno;
            if (s == r){
                printf("\t\t\t\t\t%-24d%-24s%-24s%-24s%-24s\n", nrs.Idno, nrs.Name, nrs.Type, nrs.Phone, nrs.Date);
                printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------\n");
            }
        }
        fclose(fp2);
    }
}
void NU_delete(){
    system("cls");
    fixed();
    FILE *fpo;
    FILE *fpt;
    int r, s;
    gotoxy(30, 15);
    printf("Enter the Id no you want to NU_delete :");
    scanf("%d", &r);
    if (NU_avail(r) == 0)
        printf("Id no %d is not available in the file\n", r);
    else{
        fpo = fopen("NU_record.txt", "r");
        fpt = fopen("NU_temp.txt", "w");
        while (fread(&nrs, sizeof(nrs), 1, fpo)){
            s = nrs.Idno;
            if (s != r)
                fwrite(&nrs, sizeof(nrs), 1, fpt);
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("NU_record.txt", "w");
        fpt = fopen("NU_temp.txt", "r");
        while (fread(&nrs, sizeof(nrs), 1, fpt))
            fwrite(&nrs, sizeof(nrs), 1, fpo);
        gotoxy(30, 16);
        printf("NU_record.txt DELETED\n");
        fclose(fpo);
        fclose(fpt);
    }
}
void NU_update(){
    system("cls");
    fixed();
    int avl;
    FILE *fpt;
    FILE *fpo;
    int s, r, ch;
    gotoxy(30, 15);
    printf("Enter Id number to NU_update:");
    scanf("%d", &r);
    avl = NU_avail(r);
    if (avl == 0){
        gotoxy(30, 16);
        printf("Id number %d is not Available in the file", r);
    }
    else{
        fpo = fopen("NU_record.txt", "r");
        fpt = fopen("NU_temp.txt", "w");
        while (fread(&nrs, sizeof(nrs), 1, fpo)){
            s = nrs.Idno;
            if (s != r)
                fwrite(&nrs, sizeof(nrs), 1, fpt);
            else{
                gotoxy(30, 17);
                printf("1. NU_update Name of Id Number %d", r);
                gotoxy(30, 18);
                printf("2. NU_update Type of Id Number %d", r);
                gotoxy(30, 19);
                printf("3. NU_update Phone of Id Number %d", r);
                gotoxy(30, 20);
                printf("4. NU_update Date of Id Number %d", r);
                gotoxy(30, 21);
                printf("5. NU_update all of Id Number %d", r);
                gotoxy(30, 22);
                printf("Enter your choice:");
                scanf("%d", &ch);
                switch (ch){
                case 1:
                    gotoxy(30, 23);
                    printf("Enter Name:");
                    getchar();
                    scanf("%[^\n]", nrs.Name);
                    break;
                case 2:
                    gotoxy(30, 23);
                    printf("Enter Type : ");
                    scanf("%s", &nrs.Type);
                    break;
                case 3:
                    gotoxy(30, 23);
                    printf("Enter Phone : ");
                    scanf("%s", &nrs.Phone);
                    break;
                case 4:
                    gotoxy(30, 23);
                    printf("Enter Date : ");
                    scanf("%s", &nrs.Date);
                    break;
                case 5:
                    gotoxy(30, 23);
                    printf("Enter Name: ");
                    getchar();
                    scanf("%[^\n]", nrs.Name);
                    gotoxy(30, 24);
                    printf("Enter Type: ");
                    scanf("%s", &nrs.Type);
                    gotoxy(30, 25);
                    printf("Enter Phone: ");
                    scanf("%s", &nrs.Phone);
                    gotoxy(30, 26);
                    printf("Enter Date: ");
                    scanf("%s", &nrs.Date);
                    break;
                default:
                    gotoxy(30, 23);
                    printf("Invalid Selection");
                    break;
                }
                fwrite(&nrs, sizeof(nrs), 1, fpt);
            }
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("NU_record.txt", "w");
        fpt = fopen("NU_temp.txt", "r");
        while (fread(&nrs, sizeof(nrs), 1, fpt)){
            fwrite(&nrs, sizeof(nrs), 1, fpo);
        }
        fclose(fpo);
        fclose(fpt);
    }
    gotoxy(30, 28);
    printf("NU_record.txt updated");
}
void NU_sort(){
    system("cls");
    fixed();
    int a[20], count = 0, i, j, t, c;
    FILE *fpo;
    fpo = fopen("NU_record.txt", "r");
    while (fread(&nrs, sizeof(nrs), 1, fpo)){
        a[count] = nrs.Idno;
        count++;
    }
    c = count;
    for (i = 0; i < count - 1; i++){
        for (j = i + 1; j < count; j++){
            if (a[i] > a[j]){
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    gotoxy(36, 16);
    printf("\tId Number\t\tName\t\t\tType\t\t\tPhone\t\t\tDate\n\n");
    gotoxy(30, 17);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    count = c;
    for (i = 0; i < count; i++){
        rewind(fpo);
        while (fread(&nrs, sizeof(nrs), 1, fpo)){
            if (a[i] == nrs.Idno){
                printf("\t\t\t\t\t%-24d%-24s%-24s%-24s%-24s\n", nrs.Idno, nrs.Name, nrs.Type, nrs.Phone, nrs.Date);
                printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------\n");
            }
        }
    }
}
int NU_avail(int rno){
    FILE *fp;
    int c = 0;
    fp = fopen("NU_record.txt", "r");
    while (!feof(fp)){
        fread(&nrs, sizeof(nrs), 1, fp);
        if (rno == nrs.Idno){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int NU_empty(){
    int c = 0;
    FILE *fp;
    fp = fopen("NU_record.txt", "r");
    while (fread(&nrs, sizeof(nrs), 1, fp))
        c = 1;
    fclose(fp);
    return c;
}
void NU_main(){
    system("cls");
    fixed();
    int c, emp;
    gotoxy(30, 15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Select Nurse Menu \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 17);
    printf("1. Nurse insert");
    gotoxy(30, 18);
    printf("2. Nurse display");
    gotoxy(30, 19);
    printf("3. Nurse search");
    gotoxy(30, 20);
    printf("4. Nurse delete");
    gotoxy(30, 21);
    printf("5. Nurse update");
    gotoxy(30, 22);
    printf("6. Nurse sort");
    gotoxy(30, 23);
    printf("7. Nurse exit");
    gotoxy(30, 24);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 25);
    printf("Enter your choice:");
    scanf("%d", &c);
    printf("\n");
    switch (c){
    case 1:
        NU_insert();
        getch();
        NU_main();
        break;
    case 2:emp = NU_empty();
        if (emp == 0)
            printf("\n %30cThe file is NU_empty\n");
        else
            NU_display();
        getch();
        NU_main();
        break;
    case 3:
        NU_search();
        getch();
        NU_main();
        break;
    case 4:
        NU_delete();
        getch();
        NU_main();
        break;
    case 5:
        NU_update();
        getch();
        NU_main();
        break;
    case 6:emp = NU_empty();
        if (emp == 0)
            printf("\n%30cThe file is NU_empty\n");
        else
            NU_sort();break;
    case 7:break;
    default:
        gotoxy(30, 26);
        printf("\n %30cInvalid entry. Please enter right option :)");
        break;
    }
}