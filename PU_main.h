int PU_avail(int rno);
struct Patient{
    int Idno;
    char Name[30], Type[30],Phone[30],Date[30];
} ptnt;
int choice;
void PU_insert(){
    system("cls");
    fixed();
    FILE *fp;
    fp = fopen("PU_record.txt", "a");
    gotoxy(30, 15);
    printf("Enter the Patient Idno        :");
    scanf("%d", &ptnt.Idno);
    gotoxy(30, 16);
    printf("Enter the Patient Name        :");
    getchar();
    scanf("%[^\n]", ptnt.Name);
    gotoxy(30, 18);
    printf("1. Surgecal");
    gotoxy(30, 19);
    printf("2. Psychological");
    gotoxy(30, 20);
    printf("3. Pediatrical");
    gotoxy(30, 21);
    printf("4. Dental");
    gotoxy(30, 22);
    printf("5. Cardiological");
    gotoxy(30, 23);
    printf("6. Gynecological");
    gotoxy(30, 24);
    printf("7. Sexological");
    gotoxy(30, 25);
    printf("8. Otorhinolaryngological");
    gotoxy(30, 26);
    printf("Choice the Pateint Type(1 ~ 8) :");
    scanf("%d", &choice);
    switch (choice){
    case 1:strcpy(ptnt.Type,"Surgecal");break;
    case 2:strcpy(ptnt.Type,"Psychological");break;
    case 3:strcpy(ptnt.Type,"Pediatrical");break;
    case 4:strcpy(ptnt.Type,"Dental");break;
    case 5:strcpy(ptnt.Type,"Cardiological");break;
    case 6:strcpy(ptnt.Type,"Gynecological");break;
    case 7:strcpy(ptnt.Type,"Sexological");break;
    case 8:strcpy(ptnt.Type,"Otorhinolaryngological");break;
    default:
        printf("\n %30cInvalid entry. Please enter right option :)");
    }
    gotoxy(30, 27);
    printf("Enter the Patient Number      :");
    scanf("%s", &ptnt.Phone);
    gotoxy(30, 28);
    printf("Enter the Patient Date        :");
    scanf("%s", &ptnt.Date);
    fwrite(&ptnt, sizeof(ptnt), 1, fp);
    fclose(fp);
}
void PU_display(){
    system("cls");
    fixed();
    FILE *fp1;
    fp1 = fopen("PU_record.txt", "r");
    gotoxy(36, 15);
    printf("\tId Number\t\tName\t\t\tType\t\t\tPhone\t\t\tDate");
    gotoxy(30, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    while (fread(&ptnt, sizeof(ptnt), 1, fp1)){
        printf("\t\t\t\t\t%-24d%-24s%-24s%-24s%-24s\n", ptnt.Idno,ptnt.Name,ptnt.Type,ptnt.Phone,ptnt.Date);
        printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------\n");
    }
    fclose(fp1);
}
void PU_search(){
    system("cls");
    fixed();
    FILE *fp2;
    int r, s, avl;
    gotoxy(30, 15);
    printf("Enter the Id no you want to PU_search  :");
    scanf("%d", &r);
    avl = PU_avail(r);
    if (avl == 0)
        printf("Id No %d is not available in the file\n", r);
    else{
        fp2 = fopen("PU_record.txt", "r");
        gotoxy(36, 17);
        printf("\tId Number\t\tName\t\t\tType\t\t\tPhone\t\t\tDate\n\n");
        gotoxy(30, 18);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        while (fread(&ptnt, sizeof(ptnt), 1, fp2)){
            s = ptnt.Idno;
            if (s == r){
                printf("\t\t\t\t\t%-24d%-24s%-24s%-24s%-24s\n", ptnt.Idno, ptnt.Name, ptnt.Type, ptnt.Phone, ptnt.Date);
                printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------\n");
            }
        }
        fclose(fp2);
    }
}
void PU_delete(){
    system("cls");
    fixed();
    FILE *fpo;
    FILE *fpt;
    int r, s;
    gotoxy(30, 15);
    printf("Enter the Id no you want to PU_delete :");
    scanf("%d", &r);
    if (PU_avail(r) == 0)
        printf("Id no %d is not available in the file\n", r);
    else{
        fpo = fopen("PU_record.txt", "r");
        fpt = fopen("PU_temp.txt", "w");
        while (fread(&ptnt, sizeof(ptnt), 1, fpo)){
            s = ptnt.Idno;
            if (s != r)
                fwrite(&ptnt, sizeof(ptnt), 1, fpt);
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("PU_record.txt", "w");
        fpt = fopen("PU_temp.txt", "r");
        while (fread(&ptnt, sizeof(ptnt), 1, fpt))
            fwrite(&ptnt, sizeof(ptnt), 1, fpo);
        gotoxy(30, 16);
        printf("PU_record.txt DELETED\n");
        fclose(fpo);
        fclose(fpt);
    }
}
void PU_update(){
    system("cls");
    fixed();
    int avl;
    FILE *fpt;
    FILE *fpo;
    int s, r, ch;
    gotoxy(30, 15);
    printf("Enter Id number to PU_update:");
    scanf("%d", &r);
    avl = PU_avail(r);
    if (avl == 0){
        gotoxy(30, 16);
        printf("Id number %d is not Available in the file", r);
    }
    else{
        fpo = fopen("PU_record.txt", "r");
        fpt = fopen("PU_temp.txt", "w");
        while (fread(&ptnt, sizeof(ptnt), 1, fpo)){
            s = ptnt.Idno;
            if (s != r)
                fwrite(&ptnt, sizeof(ptnt), 1, fpt);
            else{
                gotoxy(30, 17);
                printf("1. PU_update Name of Id Number %d", r);
                gotoxy(30, 18);
                printf("2. PU_update Type of Id Number %d", r);
                gotoxy(30, 19);
                printf("3. PU_update Phone of Id Number %d", r);
                gotoxy(30, 20);
                printf("4. PU_update Date of Id Number %d", r);
                gotoxy(30, 21);
                printf("5. PU_update all of Id Number %d", r);
                gotoxy(30, 22);
                printf("Enter your choice:");
                scanf("%d", &ch);
                switch (ch){
                case 1:
                    gotoxy(30, 23);
                    printf("Enter Name:");
                    getchar();
                    scanf("%[^\n]", ptnt.Name);
                    break;
                case 2:
                    gotoxy(30, 23);
                    printf("Enter Type : ");
                    scanf("%s", &ptnt.Type);
                    break;
                case 3:
                    gotoxy(30, 23);
                    printf("Enter Phone : ");
                    scanf("%s", &ptnt.Phone);
                    break;
                case 4:
                    gotoxy(30, 23);
                    printf("Enter Date : ");
                    scanf("%s", &ptnt.Date);
                    break;
                case 5:
                    gotoxy(30, 23);
                    printf("Enter Name: ");
                    getchar();
                    scanf("%[^\n]", ptnt.Name);
                    gotoxy(30, 24);
                    printf("Enter Type: ");
                    scanf("%s", &ptnt.Type);
                    gotoxy(30, 25);
                    printf("Enter Phone: ");
                    scanf("%s", &ptnt.Phone);
                    gotoxy(30, 26);
                    printf("Enter Date: ");
                    scanf("%s", &ptnt.Date);
                    break;
                default:
                    gotoxy(30, 23);
                    printf("Invalid Selection");
                    break;
                }
                fwrite(&ptnt, sizeof(ptnt), 1, fpt);
            }
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("PU_record.txt", "w");
        fpt = fopen("PU_temp.txt", "r");
        while (fread(&ptnt, sizeof(ptnt), 1, fpt)){
            fwrite(&ptnt, sizeof(ptnt), 1, fpo);
        }
        fclose(fpo);
        fclose(fpt);
    }
    gotoxy(30, 28);
    printf("PU_record.txt updated");
}
void PU_sort(){
    system("cls");
    fixed();
    int a[20], count = 0, i, j, t, c;
    FILE *fpo;
    fpo = fopen("PU_record.txt", "r");
    while (fread(&ptnt, sizeof(ptnt), 1, fpo)){
        a[count] = ptnt.Idno;
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
        while (fread(&ptnt, sizeof(ptnt), 1, fpo)){
            if (a[i] == ptnt.Idno){
                printf("\t\t\t\t\t%-24d%-24s%-24s%-24s%-24s\n", ptnt.Idno, ptnt.Name, ptnt.Type, ptnt.Phone, ptnt.Date);
                printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------\n");
            }
        }
    }
}
int PU_avail(int rno){
    FILE *fp;
    int c = 0;
    fp = fopen("PU_record.txt", "r");
    while (!feof(fp)){
        fread(&ptnt, sizeof(ptnt), 1, fp);
        if (rno == ptnt.Idno){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int PU_empty(){
    int c = 0;
    FILE *fp;
    fp = fopen("PU_record.txt", "r");
    while (fread(&ptnt, sizeof(ptnt), 1, fp))
        c = 1;
    fclose(fp);
    return c;
}
void PU_main(){
    system("cls");
    fixed();
    int c, emp;
    gotoxy(30, 15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Select Patient Menu \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 17);
    printf("1. Patient insert");
    gotoxy(30, 18);
    printf("2. Patient display");
    gotoxy(30, 19);
    printf("3. Patient search");
    gotoxy(30, 20);
    printf("4. Patient delete");
    gotoxy(30, 21);
    printf("5. Patient update");
    gotoxy(30, 22);
    printf("6. Patient sort");
    gotoxy(30, 23);
    printf("7. Patient exit");
    gotoxy(30, 24);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 25);
    printf("Enter your choice:");
    scanf("%d", &c);
    printf("\n");
    switch (c){
    case 1:
        PU_insert();
        getch();
        PU_main();
        break;
    case 2:emp = PU_empty();
        if (emp == 0)
            printf("\n %30cThe file is PU_empty\n");
        else
            PU_display();
        getch();
        PU_main();
        break;
    case 3:
        PU_search();
        getch();
        PU_main();
        break;
    case 4:
        PU_delete();
        getch();
        PU_main();
        break;
    case 5:
        PU_update();
        getch();
        PU_main();
        break;
    case 6:emp = PU_empty();
        if (emp == 0)
            printf("\n %30cThe file is PU_empty\n");
        else
            PU_sort();break;
    case 7:break;
    default:
        gotoxy(30, 26);
        printf("\n %30cInvalid entry. Please enter right option :)");
        break;
    }
}