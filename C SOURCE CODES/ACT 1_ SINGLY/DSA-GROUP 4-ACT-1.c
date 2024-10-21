#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	char studno[15];
	char studname[25];
	char studcrsyr[15];
	float GWA;
	struct node *next;
}node;

void MainMenu();
void CreateList(node **START);
void DisplayList(node **START);
void AddStart(node **START);
void AddEnd(node **START);
void AddBef(node **START);
void AddAft(node **START);
void DelStart(node **START);
void DelEnd(node **START);
void DelVal(node **START);
void gotoxy(int x, int y);

int main()
{
	node *START;
	int choice;
	char back;
	START=NULL;
	
	menu:
	MainMenu();
	printf("Enter your choice: ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			CreateList(&START);
			goto menu;
	
		case 2:
			DisplayList(&START);
			printf("Press any key to return to main menu...");
			printf("\n\n---------------------------------------------------------------------------------------------------------\n");
			getch();
			goto menu;
		
		case 3:
			AddStart(&START);
			printf("New record is added!");
			printf("\n\n----------------------------------------------------------------------\n\n");
			printf("Press any key to return to main menu...");
			printf("\n\n----------------------------------------------------------------------\n\n");
			getch();
			goto menu;
			
		case 4:
			AddEnd(&START);
			printf("New record is added!");
			printf("\n\n----------------------------------------------------------------------\n\n");
			printf("Press any key to return to main menu...");
			printf("\n\n----------------------------------------------------------------------\n\n");
			getch();
			goto menu;
		
		case 5:
			AddBef(&START);
			printf("Press any key to return to main menu...");
			printf("\n\n----------------------------------------------------------------------------------------\n\n");
			getch();
			goto menu;
		
		case 6:
			AddAft(&START);
			printf("Press any key to return to main menu...");
			printf("\n\n----------------------------------------------------------------------------------------\n\n");
			getch();
			goto menu;
			
		case 7:
			DelStart(&START);
			printf("Press any key to return to main menu...");
			printf("\n-------------------------------------------\n");
			getch();
			goto menu;
			
		case 8:
			DelEnd(&START);
			printf("Press any key to return to main menu...");
			printf("\n-------------------------------------------\n");
			getch();
			goto menu;
		
		case 9: 
			DelVal(&START);
			goto menu;
			
		case 10:
			return 0;
		
		default: 
			printf("Invalid Choice!!!");
			getch();
			goto menu;
	}
}

void MainMenu(){
	system("cls");
	printf("\n---------------  MAIN MENU  ---------------\n");
	printf("\n [1] Create a Student Record");
	printf("\n [2] Display Student Record");
	printf("\n [3] Add a New Record at the Start");
	printf("\n [4] Add a New Record at the End");
	printf("\n [5] Add/Insert a New Record Before a Data");
	printf("\n [6] Add/Insert a New Record After a Data");
	printf("\n [7] Deletion of Node at the Start");
	printf("\n [8] Deletion of Node at the End");
	printf("\n [9] Deletion of Node by Value");
	printf("\n [10] Exit");
	printf("\n\n-------------------------------------------\n");
}

void CreateList(node **START){
	node *NewNode,*temp;
	int ctr=1;
	char choice2;
	
	system("cls");
	
	*START=NULL;
	NewNode = NULL;
	
	printf("\n------------------  CREATING A STUDENT RECORD  ------------------\n");
    do {
    	NewNode=(node*)malloc(sizeof(node));
		if (NewNode == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
		
		printf("\nStudent #%d Number\t\t: ",ctr);
		scanf("%s", NewNode->studno);
		
		printf("\nStudent #%d Name\t\t\t: ",ctr);
		scanf(" %[^\n]", NewNode->studname);
		
		printf("\nCourse and Year\t\t\t: ");
		scanf(" %s", NewNode->studcrsyr);
		
		printf("\nGWA\t\t\t\t: ");
		scanf("%f", &NewNode->GWA);
		
		printf("\n------------------------------------------------------------------\n\n");
        printf("Add another record? [Y/N]: ");
        scanf(" %c", &choice2);
        printf("\n------------------------------------------------------------------\n\n");	
		
		NewNode->next = NULL;

        if (*START == NULL) {
            *START = NewNode;
        } else {
            temp->next = NewNode;
        }

        temp = NewNode;
        ctr++;
    } while (toupper(choice2) == 'Y');
}		

void DisplayList(node **START) {
	node *Current;
	int ctr=1;
	system("cls");
	
    printf("\n--------------------------------------  STUDENT'S GWA REPORT  -------------------------------------------\n\n");
    Current = *START;
	if (Current==NULL) {
		printf("\n%-37s Student Record is empty!\n", "");
        printf("\n---------------------------------------------------------------------------------------------------------\n\n");
    }
    
    else{
    	gotoxy(10,5);
    	printf("Student No.");
    	
    	gotoxy(40,5);
    	printf("Student Name");
    	
    	gotoxy(70,5);
    	printf("Course & Year");
    	
    	gotoxy(100,5);
    	printf("GWA\n\n");
    	
    	while(Current!=NULL){
    		printf("%-9d",ctr);
    		printf("%-30s",Current->studno);
    		printf("%-30s",Current->studname);
    		printf("%-30s",Current->studcrsyr);
    		printf("%.2f\n\n",Current->GWA);
    		Current=Current->next;
    		ctr++;
		}
		printf("\n---------------------------------------------------------------------------------------------------------\n\n");
    }
}

void AddStart(node **START) {
    node *NewNode;
    char temp;
    system("cls");
    
	printf("\n-----------------  ADDING A NEW RECORD AT THE START  -----------------\n\n\n");
    NewNode = (node*)malloc(sizeof(node));
    scanf("%c", &temp);
    
	printf("Student Number\t\t: ");
    gets(NewNode->studno);
    
	printf("\nStudent Name\t\t: ");
    gets(NewNode->studname);
    
	printf("\nCourse & Year\t\t: ");
    gets(NewNode->studcrsyr);
    
	printf("\nGWA\t\t\t: ");
    scanf("%f", &NewNode->GWA);
	printf("\n----------------------------------------------------------------------\n\n");
    
	NewNode->next = NULL;
    NewNode->next = *START;
    *START = NewNode;
    NewNode = NULL;
}

void AddEnd(node **START){
	node *NewNode,*END;
	char temp;
	system("cls");
    NewNode=(node*)malloc(sizeof(node));
    
	printf("\n-----------------  ADDING A NEW RECORD AT THE END  -----------------\n\n\n");
    scanf("%c", &temp);
    
	printf("Student Number\t\t: ");
    gets(NewNode->studno);
    
	printf("\nStudent Name\t\t: ");
    gets(NewNode->studname);
    
	printf("\nCourse & Year\t\t: ");
    gets(NewNode->studcrsyr);
    
	printf("\nGWA\t\t\t: ");
    scanf("%f", &NewNode->GWA);
	printf("\n----------------------------------------------------------------------\n\n");
	
	NewNode->next = NULL;
	END = *START;
	
    while (END->next != NULL) {
        END = END->next;
    }
    
	END->next = NewNode;
    NewNode = NULL;
    END = NULL;
}

void AddBef(node **START){
    system("cls");
    
	printf("\n-----------------  ADDING A NEW RECORD BEFORE A GIVEN STUDENT RECORD  -----------------\n\n\n");

    if (*START == NULL) {
        printf("\n%-27s Student Record is empty!\n", "");
        printf("\n\n----------------------------------------------------------------------------------------\n\n");
    	printf("Press any key to return to main menu...\n");
    	printf("\n----------------------------------------------------------------------------------------\n\n");
        getch();
		return;
	}

    char studentNoToFind[15];
    printf("Enter the Student Number before which you want to add the new record: ");
    scanf("%s", studentNoToFind);
    printf("\n\n----------------------------------------------------------------------------------------\n\n");

    node *current = *START;
    node *prev = NULL;

    while (current != NULL && strcmp(current->studno, studentNoToFind) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: The specified student record not found.\n");
        printf("\n----------------------------------------------------------------------------------------\n\n");
        getch();
		return;
    }

    node *newRecord = (node*)malloc(sizeof(node));
    if (newRecord == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    printf("\n-------------------------------  INSERT THE NEW RECORD  --------------------------------\n\n\n");
    printf("Student Number\t\t\t: ");
    scanf("%s", newRecord->studno);
    
	printf("\nStudent Name\t\t\t: ");
    scanf(" %[^\n]", newRecord->studname);
    
	printf("\nCourse and Year\t\t\t: ");
    scanf("%s", newRecord->studcrsyr);
    
	printf("\nGWA\t\t\t\t: ");
    scanf("%f", &newRecord->GWA);
	printf("\n----------------------------------------------------------------------------------------\n\n");
    
	if (prev == NULL) {
        newRecord->next = *START;
        *START = newRecord;
    } else {
        newRecord->next = current;
        prev->next = newRecord;
    }

    printf("New Student Record has been added before the specified Student Number.\n");
    printf("\n----------------------------------------------------------------------------------------\n\n");
    getch();
}

void AddAft(node **START){
    system("cls");
    printf("\n-----------------  ADDING A NEW RECORD AFTER A GIVEN STUDENT RECORD  -----------------\n\n\n");

    if (*START == NULL) {
        printf("\n%-27s Student Record is empty!\n", "");
        printf("\n\n----------------------------------------------------------------------------------------\n\n");
    	printf("Press any key to return to main menu...\n");
    	printf("\n----------------------------------------------------------------------------------------\n\n");
        getch();
		return;
    }

    char studentNoToFind[15];
    printf("Enter the Student Number after which you want to add the new record: ");
    scanf("%s", studentNoToFind);
    printf("\n\n----------------------------------------------------------------------------------------\n\n");

    node *current = *START;

    while (current != NULL && strcmp(current->studno, studentNoToFind) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: The specified student record not found.\n");
        printf("\n----------------------------------------------------------------------------------------\n\n");
        getch();
		return;
    }

    node *newRecord = (node*)malloc(sizeof(node));
    if (newRecord == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    printf("\n-------------------------------  INSERT THE NEW RECORD  --------------------------------\n\n\n");
    printf("Student Number\t\t\t: ");
    scanf("%s", newRecord->studno);
    
	printf("\nStudent Name\t\t\t: ");
    scanf(" %[^\n]", newRecord->studname);
    
	printf("\nCourse and Year\t\t\t: ");
    scanf("%s", newRecord->studcrsyr);
    
	printf("\nGWA\t\t\t\t: ");
    scanf("%f", &newRecord->GWA);
    printf("\n----------------------------------------------------------------------------------------\n\n");

    newRecord->next = current->next;
    current->next = newRecord;

    printf("New Student Record has been added after the specified Student Number.\n");
    printf("\n----------------------------------------------------------------------------------------\n\n");
    getch();
}

void DelStart(node **START){
	if (*START != NULL){
        node *temp = *START;
        *START = (*START)->next;
        free(temp);
        printf("-------------------------------------------\n");
		printf("Node at the start deleted successfully.\n");
		printf("-------------------------------------------\n");
        getch();
    } 
	else {
		printf("-------------------------------------------\n");
        printf("List is empty. No node to delete.\n");
        printf("-------------------------------------------\n");
		getch();
    }
}

void DelEnd(node **START){
	if (*START!=NULL){
		node *Previous = NULL;
    	node *DelNode = *START;
    	
    while (DelNode->next!= NULL){
        Previous = DelNode;
        DelNode = DelNode->next;
	}

    if (Previous!= NULL){
        Previous->next = NULL;
	}
	
    else{
        *START = NULL;
    }
	printf("-------------------------------------------\n");
	printf("Node at the end deleted successfully.\n");
    printf("-------------------------------------------\n");
	getch();
	free(DelNode);
}
    else {
        printf("-------------------------------------------\n");
		printf("List is empty. No node to delete.\n");
		printf("-------------------------------------------\n");
        getch();
    }
}

void DelVal(node **START){
    char Del_Val[15];
    int Flag = 0;
    node *DelNode, *Previous = NULL, *temp;

    system("cls");
    printf("\n-----------------  DELETION OF NODE BY VALUE  ----------------------\n\n\n");
    printf("Enter Student No.\t\t: ");
    scanf("%s", Del_Val);
    printf("\n--------------------------------------------------------------------\n\n");
	

    Previous = NULL;
	DelNode = *START;

    while (DelNode != NULL) {
        if (strcmp(Del_Val, DelNode->studno) == 0) {
            Flag = 1;
            break;
        }
        Previous = DelNode;
        DelNode = DelNode->next;
    }

    if (Flag == 0) {
        printf("Student Record Not Found!");
        printf("\n\n--------------------------------------------------------------------\n\n");
        printf("Press any key to return to main menu...\n");
		printf("\n--------------------------------------------------------------------\n\n");
        getch();
    } 
	else {
        if (Previous == NULL) {
            *START = (*START)->next;
        } 
		else {
            Previous->next = DelNode->next;
        }
        printf("Node with Student No. %s deleted successfully.", Del_Val);
        printf("\n\n--------------------------------------------------------------------\n\n");
        printf("Press any key to return to main menu...\n");
		printf("\n--------------------------------------------------------------------\n\n");
        free(DelNode);
        getch();
    }
}

void gotoxy(int x, int y){
	printf("%c[%d;%df",0x1b,y,x);
}
