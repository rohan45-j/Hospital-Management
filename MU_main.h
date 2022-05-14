int choice;
int MU_avail(int rno);
int MU_vail(int tp);
struct Medicine{
    int Idno,Type,Quantity;
    char Name[30],Company[30];
} mdcn;
void MU_insert(){
    system("cls");
    fixed();
    FILE *fp;
    fp = fopen("MU_record.txt", "a");
    gotoxy(30, 15);
    printf("Enter the Medicine Idno        :");
    scanf("%d", &mdcn.Idno);
    gotoxy(30, 16);
    printf("Enter the Medicine Name        :");
    getchar();
    scanf("%[^\n]", mdcn.Name);
    gotoxy(30, 18);
    printf("1. Antibiotic");
    gotoxy(30, 19);
    printf("2. Antiviral");
    gotoxy(30, 20);
    printf("3. Antidiabetic");
    gotoxy(30, 21);
    printf("4. Cardiovascular");
    gotoxy(30, 22);
    printf("5. Paracetamol");
    gotoxy(30, 24);
    printf("Choice the Medicine Type(1 ~ 5) :");
    scanf("%d", &choice);
    switch (choice){
    case 1:mdcn.Type=1;break;
    case 2:mdcn.Type=2;break;
    case 3:mdcn.Type=3;break;
    case 4:mdcn.Type=4;break;
    case 5:mdcn.Type=5;break;
    default:
        printf("\n %30cInvalid entry. Please enter right option :)");
    }
    gotoxy(30, 25);
    printf("Enter the Medicine Company     :");
    scanf("%s", &mdcn.Company);
    gotoxy(30, 26);
    printf("Enter the Medicine Quantity    :");
    scanf("%d", &mdcn.Quantity);
    fwrite(&mdcn, sizeof(mdcn), 1, fp);
    fclose(fp);
}
void MU_display(){
    system("cls");
    fixed();
    FILE *fp1;
    char ch[30];
    fp1 = fopen("MU_record.txt", "r");
    gotoxy(36, 15);
    printf("\tId Number\t\tName\t\t\tType\t\t\tCompany\t\t\tQuantity");
    gotoxy(30, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    while (fread(&mdcn, sizeof(mdcn), 1, fp1)){
        switch (mdcn.Type){
        case 1:strcpy(ch,"Antibiotic");break;
        case 2:strcpy(ch,"Antiviral");break;
        case 3:strcpy(ch,"Antidiabetic");break;
        case 4:strcpy(ch,"Cardiovascular");break;
        case 5:strcpy(ch,"Paracetamol");break;
        default:
            printf("\n %30cInvalid entry. Please enter right option :)");
        }
        printf("\t\t\t\t\t%-24d%-24s%-24s%-24s%-24d\n", mdcn.Idno,mdcn.Name,ch,mdcn.Company,mdcn.Quantity);
        printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------\n");
    }
    fclose(fp1);
}
void MU_search(){
    system("cls");
    fixed();
    FILE *fp2;
    int avl,r,s;
    char ch[30];
    gotoxy(30, 18);
    printf("1. Antibiotic");
    gotoxy(30, 19);
    printf("2. Antiviral");
    gotoxy(30, 20);
    printf("3. Antidiabetic");
    gotoxy(30, 21);
    printf("4. Cardiovascular");
    gotoxy(30, 22);
    printf("5. Paracetamol");
    gotoxy(30, 24);
    printf("Choice Your Desire Medicine Type(1 ~5) :");
    scanf("%d", &choice);
    switch (choice){
    case 1:r=1;break;
    case 2:r=2;break;
    case 3:r=3;break;
    case 4:r=4;break;
    case 5:r=5;break;
    default:
        printf("\n %30cInvalid entry. Please enter right option :)");
    }
    avl = MU_vail(r);
    if (avl == 0)
        printf("Id No %d is not available in the file\n", r);
    else{
        fp2 = fopen("MU_record.txt", "r");
        gotoxy(36, 26);
        printf("\tId Number\t\tName\t\t\tType\t\t\tCompany\t\t\tQuantity");
        gotoxy(30, 27);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        while (fread(&mdcn, sizeof(mdcn), 1, fp2)){
            s= mdcn.Type;
            if (s == r){
                switch (mdcn.Type){
                case 1:strcpy(ch,"Antibiotic");break;
                case 2:strcpy(ch,"Antiviral");break;
                case 3:strcpy(ch,"Antidiabetic");break;
                case 4:strcpy(ch,"Cardiovascular");break;
                case 5:strcpy(ch,"Paracetamol");break;
                default:
                    printf("\n %30cInvalid entry. Please enter right option :)");
                }
                printf("\t\t\t\t\t%-24d%-24s%-24s%-24s%-24d\n", mdcn.Idno, mdcn.Name, ch, mdcn.Company, mdcn.Quantity);
                printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------\n");
            }
        }
        fclose(fp2);
    }
}
void MU_delete(){
    system("cls");
    fixed();
    FILE *fpo;
    FILE *fpt;
    int r, s;
    gotoxy(30, 15);
    printf("Enter the Idno you want to Delete :");
    scanf("%d", &r);
    if (MU_avail(r) == 0)
        printf("Id no %d is not available in the file\n", r);
    else{
        fpo = fopen("MU_record.txt", "r");
        fpt = fopen("MU_temp.txt", "w");
        while (fread(&mdcn, sizeof(mdcn), 1, fpo)){
            s = mdcn.Idno;
            if (s != r)
                fwrite(&mdcn, sizeof(mdcn), 1, fpt);
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("MU_record.txt", "w");
        fpt = fopen("MU_temp.txt", "r");
        while (fread(&mdcn, sizeof(mdcn), 1, fpt))
            fwrite(&mdcn, sizeof(mdcn), 1, fpo);
        gotoxy(30, 16);
        printf("MU_record.txt DELETED\n");
        fclose(fpo);
        fclose(fpt);
    }
}
void MU_update(){
    system("cls");
    fixed();
    int avl;
    FILE *fpt;
    FILE *fpo;
    int s, r, ch;
    gotoxy(30, 15);
    printf("Enter Id number to Update Quantity:");
    scanf("%d", &r);
    avl = MU_avail(r);
    if (avl == 0){
        gotoxy(30, 16);
        printf("Id number %d is not Available in the file", r);
    }
    else{
        fpo = fopen("MU_record.txt", "r");
        fpt = fopen("MU_temp.txt", "w");
        while (fread(&mdcn, sizeof(mdcn), 1, fpo)){
            s = mdcn.Idno;
            if (s != r)
                fwrite(&mdcn, sizeof(mdcn), 1, fpt);
            else{
                gotoxy(30, 17);
                printf("1.How many Quantity Do You Sold? - ");
                scanf("%d",&ch);
                mdcn.Quantity=mdcn.Quantity-ch;
                fwrite(&mdcn, sizeof(mdcn), 1, fpt);
            }
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("MU_record.txt", "w");
        fpt = fopen("MU_temp.txt", "r");
        while (fread(&mdcn, sizeof(mdcn), 1, fpt)){
            fwrite(&mdcn, sizeof(mdcn), 1, fpo);
        }
        fclose(fpo);
        fclose(fpt);
    }
    gotoxy(30, 28);
    printf("MU_record.txt updated");
}
int MU_avail(int rno){
    FILE *fp;
    int c = 0;
    fp = fopen("MU_record.txt", "r");
    while (!feof(fp)){
        fread(&mdcn, sizeof(mdcn), 1, fp);
        if (rno == mdcn.Idno){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int MU_vail(int tp){
    FILE *fp;
    fp = fopen("MU_record.txt", "r");
    while (!feof(fp)){
        fread(&mdcn, sizeof(mdcn), 1, fp);
        if (tp == mdcn.Type){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int MU_empty(){
    int c = 0;
    FILE *fp;
    fp = fopen("MU_record.txt", "r");
    while (fread(&mdcn, sizeof(mdcn), 1, fp))
        c = 1;
    fclose(fp);
    return c;
}
void MU_main(){
    system("cls");
    fixed();
    int c, emp;
    gotoxy(30, 15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Select Your Choise \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 17);
    printf("1. Medicine Insert");
    gotoxy(30, 18);
    printf("2. Medicine Display");
    gotoxy(30, 19);
    printf("3. Medicine Search");
    gotoxy(30, 20);
    printf("4. Medicine Delete");
    gotoxy(30, 21);
    printf("5. Medicine Update");
    gotoxy(30, 22);
    printf("6. Goto main");
    gotoxy(30, 23);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 24);
    printf("Enter your choice(1 ~ 6):");
    scanf("%d", &c);
    printf("\n");
    switch (c){
    case 1:
        MU_insert();
        getch();
        MU_main();
        break;
    case 2:emp = MU_empty();
        if (emp == 0)
            printf("\n %30cThe file is empty\n");
        else
            MU_display();
        getch();
        MU_main();        
        break;
    case 3:
        MU_search();
        getch();
        MU_main();
        break;
    case 4:
        MU_delete();
        getch();
        MU_main();
        break;
    case 5:
        MU_update();
        getch();
        MU_main();
        break;
    case 6:break;
    default:
        gotoxy(30, 26);
        printf("\n %30cInvalid entry. Please enter right option :)");
        getch();
        MU_main();        
        break;
    }
}