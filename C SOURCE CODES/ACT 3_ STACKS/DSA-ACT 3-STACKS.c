#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
typedef struct studrec {
    char studname[50];
    char studno[25];
    char studcrsyr[25];
    float GWA;
    struct studrec* next;
} studrec;
void MainMenu();
void createstack(studrec **top);
void travstack(studrec **top);
void addstack(studrec **top);
void delstack(studrec **top);
void gotoxy(int x, int y){
    printf("%c[%d;%df",0x1B,y,x);
}

int main(){
	studrec *top=NULL;
	int choice;
	menu:
		MainMenu();
		gotoxy(0,25);
		printf("=========================================================================================================");
		gotoxy(10,23);
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				createstack(&top);
				goto menu;
				
			case 2:
				travstack(&top);
				goto menu;
				return;
				
			case 3:
				addstack(&top);
				getch();
				goto menu;
				
			case 4:	
				delstack(&top);
				getch();
				goto menu;
			
			case 5:
				return 0;
				
			default:
			gotoxy(10,27);
			printf("WARNING: Invalid Choice!!!\n");
			printf("\n=========================================================================================================\n\n");
			getch();
			goto menu;	
		}
		return 0;
}

void MainMenu(){
	system("cls");
	system("COLOR F1");
	printf("\n========================================== MAIN MENU ====================================================\n");
	gotoxy(37, 4);
	printf("Student Record (Stacks) ");
	gotoxy(36, 5);
	printf("by DSA Group 1 (Searching)\n");
	printf("\n=========================================================================================================\n");
	gotoxy(10,10);
	printf("[1] Create a Student Record\n");
	gotoxy(10,12);
	printf("[2] Traverse Student Record");
	gotoxy(10,14);
	printf("[3] Add Student Record\n");
	gotoxy(10,16);
	printf("[4] Delete Student Record\n");
	gotoxy(10,18);
	printf("[5] Exit Program\n");
	gotoxy(10,20);
	printf("\n=========================================================================================================\n");
}

void createstack(studrec **top){
	studrec *PushNode;
	char Resp;
	int ctr=1;
	system("cls");
	
	PushNode=(studrec*)malloc(sizeof(studrec));
	PushNode->next=NULL;
	*top=PushNode;

	printf("\n=========================================================================================================\n");
	gotoxy(40,4);
	printf("CREATING A STUDENT RECORD\n");
	printf("\n=========================================================================================================\n");
	do{
		printf("\n\tStudent #%d Number\t\t: ",ctr);
		scanf("%s",PushNode->studno);
		
		printf("\n\tStudent #%d Name\t\t\t: ",ctr);
		scanf(" %[^\n]", PushNode->studname);
		
		printf("\n\tCourse and Year\t\t\t: ");
		scanf(" %[^\n]", PushNode->studcrsyr);

		printf("\n\tGWA\t\t\t\t: ");
		scanf("%f", &PushNode->GWA);
		
		printf("\n---------------------------------------------------------------------------------------------------------\n\n");
        printf("\tAdd another record? [Y/N]\t: ");
        scanf(" %c",&Resp);
		printf("\n---------------------------------------------------------------------------------------------------------\n\n");
        
        if(toupper(Resp) == 'Y'){
			ctr++;
			PushNode=(studrec*)malloc(sizeof(studrec));
			PushNode->next=*top;
			*top=PushNode;	        
		}
	}while(toupper(Resp)=='Y');
	PushNode=NULL;
	printf("\tPress any key to return to main menu...");
	printf("\n\n---------------------------------------------------------------------------------------------------------\n");
	getch();
}

void travstack(studrec **top){
	int ctr=1;
	system("cls");
	studrec *PopNode=*top,*TempTop=NULL;
	printf("\n=========================================================================================================\n");
	gotoxy(40,4);
	printf("STUDENT RECORD\n");
	printf("\n=========================================================================================================\n");
	
	if(PopNode==NULL){
		gotoxy(35,8);
		printf("Student Record is empty!\n", "");
		printf("\n=========================================================================================================\n");
		getch();
	}
	else{
		studrec *TempTop = *top;
		gotoxy(10,8);
    	printf("Student No.");
    	
    	gotoxy(40,8);
    	printf("Student Name");
    	
    	gotoxy(70,8);
    	printf("Course & Year");
    	
    	gotoxy(100,8);
    	printf("GWA\n\n");
		while (TempTop != NULL) {
            printf("%-9d", ctr);
            printf("%-30s", TempTop->studno);
            printf("%-30s", TempTop->studname);
            printf("%-30s", TempTop->studcrsyr);
            printf("%.2f\n\n", TempTop->GWA);
            TempTop = TempTop->next;
            ctr++;
        }
	}
	printf("\n---------------------------------------------------------------------------------------------------------\n\n");
	printf("\tPress any key to return to main menu...");
	printf("\n\n---------------------------------------------------------------------------------------------------------\n");
	getch(); 
}

void addstack(studrec **top){
	studrec *PushNode;
	system("cls");
	PushNode = (studrec*)malloc(sizeof(studrec));
	printf("\n=========================================================================================================\n");
	gotoxy(40,4);
	printf("ADDING OF STUDENT RECORD IN STACK\n");
	printf("\n=========================================================================================================\n");
	
	if(*top==NULL){
		gotoxy(45,8);
		printf("Student Record is empty!\n", "");
		printf("\n=========================================================================================================\n");
		getch();
		return;
	}
	printf("\n\tStudent Number\t\t: ");
	scanf("%s", PushNode->studno);
	
	printf("\n\tStudent Name\t\t: ");
	scanf(" %[^\n]", PushNode->studname);
	
	printf("\n\tCourse & Year\t\t: ");
	scanf(" %[^\n]", PushNode->studcrsyr);
	
	printf("\n\tGWA\t\t\t: ");
	scanf("%f", &PushNode->GWA);
	PushNode->next=NULL;
	
	if(*top==NULL){
		*top=PushNode;
	}
	else{
		PushNode->next=*top;
		*top=PushNode;
	}
	PushNode=NULL;
	printf("\n=========================================================================================================\n");
	gotoxy(40,18);
	printf("Record succesfully added!\n");
	printf("\n=========================================================================================================\n");
}

void delstack(studrec **top) {
    studrec *PopNode = *top;
    if (PopNode == NULL) { 
        gotoxy(10,24);
		printf("Student Record is Empty!");
    } 
	else {
        *top = (*top)->next;
		gotoxy(10,24);
    	printf("Record succesfully deleted!\n"); 
	}
	free(PopNode); 
    PopNode=NULL;
}
