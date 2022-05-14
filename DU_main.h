int DU_avail(int rno);
struct Doctor{
    int Idno;
    char Name[30], Type[30],Phone[30],Date[30];
} dctr;
int choice;
void DU_insert(){
    system("cls");
    fixed();
    FILE *fp;
    fp = fopen("DU_record.txt", "a");
    gotoxy(30, 15);
    printf("Enter the Doctor Idno        :");
    scanf("%d", &dctr.Idno);
    gotoxy(30, 16);
    printf("Enter the Doctor Name        :");
    getchar();
    scanf("%[^\n]", dctr.Name);
    gotoxy(30, 18);
    printf("1. Surgeon");
    gotoxy(30, 19);
    printf("2. Psychologist");
    gotoxy(30, 20);
    printf("3. Pediatrician");
    gotoxy(30, 21);
    printf("4. Dentist");
    gotoxy(30, 22);
    printf("5. Cardiologist");
    gotoxy(30, 23);
    printf("6. Gynecologist");
    gotoxy(30, 24);
    printf("7. Sexologist");
    gotoxy(30, 25);
    printf("8. Otorhinolaryngologist");
    gotoxy(30, 26);
    printf("Choice the Doctor Type(1 ~ 8) :");
    scanf("%d", &choice);
    switch (choice){
    case 1:strcpy(dctr.Type,"Surgeon");break;
    case 2:strcpy(dctr.Type,"Psychologist");break;
    case 3:strcpy(dctr.Type,"Pediatrician");break;
    case 4:strcpy(dctr.Type,"Dentist");break;
    case 5:strcpy(dctr.Type,"Cardiologist");break;
    case 6:strcpy(dctr.Type,"Gynecologist");break;
    case 7:strcpy(dctr.Type,"Sexologist");break;
    case 8:strcpy(dctr.Type,"Otorhinolaryngologist");break;
    default:
        printf("\n %30cInvalid entry. Please enter right option :)");
    }
    gotoxy(30, 27);
    printf("Enter the Doctor Number      :");
    scanf("%s", &dctr.Phone);
    gotoxy(30, 28);
    printf("Enter the Doctor Date        :");
    scanf("%s", &dctr.Date);
    fwrite(&dctr, sizeof(dctr), 1, fp);
    fclose(fp);
}
void DU_display(){
    system("cls");
    fixed();
    FILE *fp1;
    fp1 = fopen("DU_record.txt", "r");
    gotoxy(36, 15);
    printf("\tId Number\t\tName\t\t\tType\t\t\tPhone\t\t\tDate");
    gotoxy(30, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    while (fread(&dctr, sizeof(dctr), 1, fp1)){
        printf("\t\t\t\t\t%-24d%-24s%-24s%-24s%-24s\n", dctr.Idno,dctr.Name,dctr.Type,dctr.Phone,dctr.Date);
        printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------\n");
    }
    fclose(fp1);
}
void DU_search(){
    system("cls");
    fixed();
    FILE *fp2;
    int r, s, avl;
    gotoxy(30, 15);
    printf("Enter the Id no you want to DU_search  :");
    scanf("%d", &r);
    avl = DU_avail(r);
    if (avl == 0)
        printf("Id No %d is not available in the file\n", r);
    else{
        fp2 = fopen("DU_record.txt", "r");
        gotoxy(36, 17);
        printf("\tId Number\t\tName\t\t\tType\t\t\tPhone\t\t\tDate\n\n");
        gotoxy(30, 18);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        while (fread(&dctr, sizeof(dctr), 1, fp2)){
            s = dctr.Idno;
            if (s == r){
                printf("\t\t\t\t\t%-24d%-24s%-24s%-24s%-24s\n", dctr.Idno, dctr.Name, dctr.Type, dctr.Phone, dctr.Date);
                printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------\n");
            }
        }
        fclose(fp2);
    }
}
void DU_delete(){
    system("cls");
    fixed();
    FILE *fpo;
    FILE *fpt;
    int r, s;
    gotoxy(30, 15);
    printf("Enter the Id no you want to DU_delete :");
    scanf("%d", &r);
    if (DU_avail(r) == 0)
        printf("Id no %d is not available in the file\n", r);
    else{
        fpo = fopen("DU_record.txt", "r");
        fpt = fopen("DU_temp.txt", "w");
        while (fread(&dctr, sizeof(dctr), 1, fpo)){
            s = dctr.Idno;
            if (s != r)
                fwrite(&dctr, sizeof(dctr), 1, fpt);
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("DU_record.txt", "w");
        fpt = fopen("DU_temp.txt", "r");
        while (fread(&dctr, sizeof(dctr), 1, fpt))
            fwrite(&dctr, sizeof(dctr), 1, fpo);
        gotoxy(30, 16);
        printf("DU_record.txt DELETED\n");
        fclose(fpo);
        fclose(fpt);
    }
}
void DU_update(){
    system("cls");
    fixed();
    int avl;
    FILE *fpt;
    FILE *fpo;
    int s, r, ch;
    gotoxy(30, 15);
    printf("Enter Id number to DU_update:");
    scanf("%d", &r);
    avl = DU_avail(r);
    if (avl == 0){
        gotoxy(30, 16);
        printf("Id number %d is not Available in the file", r);
    }
    else{
        fpo = fopen("DU_record.txt", "r");
        fpt = fopen("DU_temp.txt", "w");
        while (fread(&dctr, sizeof(dctr), 1, fpo)){
            s = dctr.Idno;
            if (s != r)
                fwrite(&dctr, sizeof(dctr), 1, fpt);
            else{
                gotoxy(30, 17);
                printf("1. DU_update Name of Id Number %d", r);
                gotoxy(30, 18);
                printf("2. DU_update Type of Id Number %d", r);
                gotoxy(30, 19);
                printf("3. DU_update Phone of Id Number %d", r);
                gotoxy(30, 20);
                printf("4. DU_update Date of Id Number %d", r);
                gotoxy(30, 21);
                printf("5. DU_update all of Id Number %d", r);
                gotoxy(30, 22);
                printf("Enter your choice:");
                scanf("%d", &ch);
                switch (ch){
                case 1:
                    gotoxy(30, 23);
                    printf("Enter Name:");
                    getchar();
                    scanf("%[^\n]", dctr.Name);
                    break;
                case 2:
                    gotoxy(30, 23);
                    printf("Enter Type : ");
                    scanf("%s", &dctr.Type);
                    break;
                case 3:
                    gotoxy(30, 23);
                    printf("Enter Phone : ");
                    scanf("%s", &dctr.Phone);
                    break;
                case 4:
                    gotoxy(30, 23);
                    printf("Enter Date : ");
                    scanf("%s", &dctr.Date);
                    break;
                case 5:
                    gotoxy(30, 23);
                    printf("Enter Name: ");
                    getchar();
                    scanf("%[^\n]", dctr.Name);
                    gotoxy(30, 24);
                    printf("Enter Type: ");
                    scanf("%s", &dctr.Type);
                    gotoxy(30, 25);
                    printf("Enter Phone: ");
                    scanf("%s", &dctr.Phone);
                    gotoxy(30, 26);
                    printf("Enter Date: ");
                    scanf("%s", &dctr.Date);
                    break;
                default:
                    gotoxy(30, 23);
                    printf("Invalid Selection");
                    break;
                }
                fwrite(&dctr, sizeof(dctr), 1, fpt);
            }
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("DU_record.txt", "w");
        fpt = fopen("DU_temp.txt", "r");
        while (fread(&dctr, sizeof(dctr), 1, fpt)){
            fwrite(&dctr, sizeof(dctr), 1, fpo);
        }
        fclose(fpo);
        fclose(fpt);
    }
    gotoxy(30, 28);
    printf("DU_record.txt updated");
}
void DU_sort(){
    system("cls");
    fixed();
    int a[20], count = 0, i, j, t, c;
    FILE *fpo;
    fpo = fopen("DU_record.txt", "r");
    while (fread(&dctr, sizeof(dctr), 1, fpo)){
        a[count] = dctr.Idno;
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
        while (fread(&dctr, sizeof(dctr), 1, fpo)){
            if (a[i] == dctr.Idno){
                printf("\t\t\t\t\t%-24d%-24s%-24s%-24s%-24s\n", dctr.Idno, dctr.Name, dctr.Type, dctr.Phone, dctr.Date);
                printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------\n");
            }
        }
    }
}
int DU_avail(int rno){
    FILE *fp;
    int c = 0;
    fp = fopen("DU_record.txt", "r");
    while (!feof(fp)){
        fread(&dctr, sizeof(dctr), 1, fp);
        if (rno == dctr.Idno){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int DU_empty(){
    int c = 0;
    FILE *fp;
    fp = fopen("DU_record.txt", "r");
    while (fread(&dctr, sizeof(dctr), 1, fp))
        c = 1;
    fclose(fp);
    return c;
}
void DU_main(){
    system("cls");
    fixed();
    int c, emp;
    gotoxy(30, 15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Select Doctor Menu \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 17);
    printf("1. Doctor insert");
    gotoxy(30, 18);
    printf("2. Doctor display");
    gotoxy(30, 19);
    printf("3. Doctor search");
    gotoxy(30, 20);
    printf("4. Doctor delete");
    gotoxy(30, 21);
    printf("5. Doctor update");
    gotoxy(30, 22);
    printf("6. Doctor sort");
    gotoxy(30, 23);
    printf("7. Doctor exit");
    gotoxy(30, 24);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 25);
    printf("Enter your choice:");
    scanf("%d", &c);
    printf("\n");
    switch (c){
    case 1:DU_insert();getch();DU_main();break;
    case 2:emp = DU_empty();
        if (emp == 0)
            printf("\n %30cThe file is DU_empty\n");
        else
            DU_display();
        getch();
        DU_main();
        break;
    case 3:DU_search();getch();DU_main();break;
    case 4:DU_delete();getch();DU_main();break;
    case 5:DU_update();getch();DU_main();break;
    case 6:emp = DU_empty();
        if (emp == 0)
            printf("\n%30cThe file is DU_empty\n");
        else
            DU_sort();break;
    case 7:break;
    default:
        gotoxy(30, 26);
        printf("\n %30cInvalid entry. Please enter right option :)");
        break;
    }
}