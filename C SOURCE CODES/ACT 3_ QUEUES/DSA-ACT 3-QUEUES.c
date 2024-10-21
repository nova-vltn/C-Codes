#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

typedef struct SRec {
    int SNum;
    char SName[25];
    char crsYr[15];
    float GWA;
    struct SRec *next;
}SRec;

void MainMenu();
void Create(SRec **front, SRec **rear);
void travqnorep(SRec **front, SRec **rear);
void travqwrep(SRec **front, SRec **rear);
void addq(SRec **front, SRec **rear);
void delq(SRec **front);
void gotoxy(int x, int y) {
    printf("%c[%d;%df",0x1b,y,x);
}

int main () {
    SRec *front=NULL,*rear=NULL;
    int chc,chc2;
    char temp;

    menu:
	MainMenu();
    gotoxy(0,27);
	printf("=========================================================================================================");
	gotoxy(10,25);
	printf("Enter your choice: ");
    scanf("%d", &chc);
	scanf("%c", &temp);

    switch(chc) {
        case 1: 
            Create(&front,&rear);
            goto menu;
            break;
        
		case 2: 
            travqnorep(&front,&rear);
		    printf("\n---------------------------------------------------------------------------------------------------------\n\n");
			printf("\tPress any key to return to main menu...");
			printf("\n\n---------------------------------------------------------------------------------------------------------\n");
			getch();
		    goto menu;
        
        case 3:
        	travqwrep(&front,&rear);
        	printf("\n---------------------------------------------------------------------------------------------------------\n\n");
			printf("\tPress any key to return to main menu...");
			printf("\n\n---------------------------------------------------------------------------------------------------------\n");
			getch();
		    goto menu;
		
		case 4:
			addq(&front,&rear);
			printf("\n---------------------------------------------------------------------------------------------------------\n\n");
			printf("\tPress any key to return to main menu...");
			printf("\n\n---------------------------------------------------------------------------------------------------------\n");
			getch();
			goto menu;
			
        case 5: 
				delq(&front);
				getch();
				goto menu;
				
		case 6:
				return 0;
		
		default:
				gotoxy(10,26);
				printf("WARNING: Invalid Choice!!!\n");
				gotoxy(10,28);
				getch();
				goto menu;
    }
}

void MainMenu(){
	system("cls");
	system("COLOR F1");
	printf("\n========================================== MAIN MENU ====================================================\n");
	gotoxy(37, 4);
	printf("Student Record (Queues) ");
	gotoxy(36, 5);
	printf("by DSA Group 1 (Searching)\n");
	printf("\n=========================================================================================================\n");
	gotoxy(10,10);
	printf("[1] Create a Student Record\n");
	gotoxy(10,12);
	printf("[2] Traverse Student Record (No Repeating Values)");
	gotoxy(10,14);
	printf("[3] Traverse Student Record (With Repeating Values)");
	gotoxy(10,16);
	printf("[4] Add Student Record\n");
	gotoxy(10,18);
	printf("[5] Delete Student Record\n");
	gotoxy(10,20);
	printf("[6] Exit Program\n");
	gotoxy(10,22);
	printf("\n=========================================================================================================\n");
}

void Create(SRec **front, SRec **rear) {
    system("cls");
    SRec *NewRec;
    int ctr=1;
    char temp, chc1;

    NewRec = (SRec*)malloc(sizeof(SRec));
    NewRec->next = NULL;
    *front = *rear = NewRec;

    printf("\n=========================================================================================================\n");
	gotoxy(40,4);
	printf("CREATING A STUDENT RECORD\n");
	printf("\n=========================================================================================================\n");
	do{
        printf("\n\tStudent #%d Number\t\t: ", ctr);
        scanf("%d", &NewRec->SNum);
        scanf("%c", &temp);

        printf("\n\tStudent #%d Name\t\t\t: ", ctr);
        fgets(NewRec->SName,25,stdin);
        strtok(NewRec->SName, "\n");

        printf("\n\tCourse & Year\t\t\t: ");
        fgets(NewRec->crsYr,15,stdin);
        strtok(NewRec->crsYr, "\n");

        printf("\n\tGWA\t\t\t\t: ");
        scanf("%f", &NewRec->GWA);
        scanf("%c", &temp);

        printf("\n---------------------------------------------------------------------------------------------------------\n\n");
        printf("\tAdd another record? [Y/N]\t: ");
        scanf("%c", &chc1);
        scanf("%c", &temp);
        printf("\n---------------------------------------------------------------------------------------------------------\n\n");

        if (toupper(chc1) == 'Y') {
            NewRec->next = (SRec*)malloc(sizeof(SRec)); 
            *rear = NewRec->next;
            NewRec = NewRec->next;
            ctr++;
        }
    }while(toupper(chc1) == 'Y');
    (*rear)->next = NULL;
    NewRec = NULL;
}

void travqnorep(SRec **front, SRec **rear) {
    system("cls");
    SRec *TravNode = *front;
    int ctr = 1;

    printf("\n=========================================================================================================\n");
    gotoxy(40, 4);
    printf("STUDENT RECORD\n");
    printf("\n=========================================================================================================\n");

    if (TravNode == NULL) {
        gotoxy(35, 8);
        printf("Student Record is empty!\n", "");
        printf("\n=========================================================================================================\n");
        getch();  
    }
	else{
        SRec *prev = NULL;
        int repeat = 0;
        gotoxy(8, 8);
        printf("Student No.");
        gotoxy(33, 8);
        printf("Student Name");
        gotoxy(63, 8);
        printf("Course & Year");
        gotoxy(88, 8);
        printf("GWA\n\n");

        do{
            repeat = 0;
            SRec *temp = *front;
            while (temp != TravNode){
                if (temp->SNum == TravNode->SNum){
                    repeat=1;
                    break;
                }
                temp = temp->next;
            }

            if (!repeat) {
                printf("%-7d", ctr);
                printf("%-25d", TravNode->SNum);
                printf("%-30s", TravNode->SName);
                printf("%-25s", TravNode->crsYr);
                printf("%0.2f\n\n", TravNode->GWA);
                ctr++;
            }
            prev = TravNode;
            TravNode = TravNode->next;
        } while (TravNode != NULL);
        printf("\n=========================================================================================================\n");
        getch();
    }
}

void travqwrep(SRec **front, SRec **rear) {
    system("cls");
    SRec *TravNode = *front;
    int ctr = 1;
	
	printf("\n=========================================================================================================\n");
	gotoxy(40,4);
	printf("STUDENT RECORD\n");
	printf("\n=========================================================================================================\n");
	
    if (TravNode == NULL) {
        gotoxy(35,8);
		printf("Student Record is empty!\n", "");
		printf("\n=========================================================================================================\n");
		getch();
    } 
	else {
        
        gotoxy(8,8); printf("Student No.");
        gotoxy(33,8); printf("Student Name");
        gotoxy(63,8); printf("Course & Year");
        gotoxy(88,8); printf("GWA\n\n");
        do {
            printf("%-7d", ctr);
            printf("%-25d", TravNode->SNum);
            printf("%-30s", TravNode->SName);
            printf("%-25s", TravNode->crsYr);
            printf("%0.2f\n\n", TravNode->GWA);
            TravNode = TravNode->next;
            ctr++;
        } while (TravNode != NULL);
		printf("\n=========================================================================================================\n");
    }
}

void addq(SRec **front, SRec **rear){
	system("cls");
	SRec *NewRec = (SRec*)malloc(sizeof(SRec));
	
	printf("\n=========================================================================================================\n");
	gotoxy(40,4);
	printf("ADDING OF STUDENT RECORD IN STACK\n");
	printf("\n=========================================================================================================\n");
	
	if(*front==NULL){
		gotoxy(45,8);
		printf("Student Record is empty!\n", "");
		printf("\n=========================================================================================================\n");
		getch();
		return;
	}
	
	printf("\n\tStudent Number\t\t\t: ");
	scanf("%d",&NewRec->SNum);
	getchar();
	
	printf("\n\tStudent Name\t\t\t: ");
	fgets(NewRec->SName,25,stdin);
    strtok(NewRec->SName, "\n");

	printf("\n\tCourse & Year\t\t\t: ");
	fgets(NewRec->crsYr,15,stdin);
    strtok(NewRec->crsYr, "\n");
	
	printf("\n\tGWA\t\t\t\t: ");
    scanf("%f", &NewRec->GWA);
    
    if(*rear==NULL){
    	*front=*rear=NewRec;
	}
	
	else{
		(*rear)->next=NewRec;
		*rear=NewRec;
	}	
	NewRec->next=NULL;
	printf("\n=========================================================================================================\n");
	gotoxy(40,18);
	printf("Record succesfully added!\n");
	printf("\n=========================================================================================================\n");
	getch();
}

void delq(SRec **front) {
	if (*front == NULL) {
    gotoxy(10,26);
	printf("The Queue is empty. Nothing can be deleted.\n");
	return;
    }

    SRec *temp = *front;
    *front = (*front)->next;
    free(temp);
	gotoxy(10,26);
    printf("Student record is successfully deleted!\n");
}
