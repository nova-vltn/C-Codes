#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
typedef struct STUDREC {
    char studname[25];
    char studno[15];
    char studcrsyr[15];
    float GWA;
    struct STUDREC* next;
    struct STUDREC* prev;
} STUDREC;
void MainMenu();
void CreateDLL(STUDREC **HEAD,STUDREC **TAIL);
void TravHead(STUDREC **HEAD);
void TravTail(STUDREC **TAIL);
void AddHead(STUDREC **HEAD, STUDREC **TAIL);
void AddTail(STUDREC **HEAD, STUDREC **TAIL);
void AddBef(STUDREC **HEAD);
void AddAft (STUDREC **HEAD, STUDREC **TAIL);
void DelHead(STUDREC **HEAD, STUDREC **TAIL);
void DelTail(STUDREC **HEAD, STUDREC **TAIL);
void DelVal(STUDREC **HEAD, char *value);
void DelBef(STUDREC **HEAD);
void DelAft(STUDREC **HEAD, char *studno);
void gotoxy(int x, int y);
void gotoxy(int x, int y){
    printf("%c[%d;%df",0x1B,y,x);
}
int main(){
	STUDREC *HEAD,*TAIL;
	int choice;
	char deletevalue[15];
	HEAD=TAIL=NULL;
	
	menu:
	MainMenu();
	printf("Enter your choice: ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			CreateDLL(&HEAD, &TAIL);
			goto menu;
			
		case 2:
			TravHead(&HEAD);
			printf("\n---------------------------------------------------------------------------------------------------------\n\n");
			printf("Press any key to return to main menu...");
			printf("\n\n---------------------------------------------------------------------------------------------------------\n");
			getch();
			goto menu;
		
		case 3:
			TravTail(&TAIL);
			printf("\n---------------------------------------------------------------------------------------------------------\n\n");
			printf("Press any key to return to main menu...");
			printf("\n\n---------------------------------------------------------------------------------------------------------\n");
			getch();
			goto menu;
		
		case 4: 
			AddHead(&HEAD, &TAIL);
			goto menu;
			break;
			
		case 5: 
			AddTail(&HEAD, &TAIL);
			goto menu;
			break;
		
		case 6:
			AddBef(&HEAD);
			goto menu;
		
		case 7:
			AddAft(&HEAD,&TAIL);
			goto menu;
		
		case 8:
			DelHead(&HEAD,&TAIL);
			goto menu;
			
		case 9:
			DelTail(&HEAD,&TAIL);
			goto menu;
		
		case 10:
	    	DelVal(&HEAD, deletevalue); 
	    	goto menu;

		case 11:
			DelBef(&HEAD);
			goto menu;
		
		case 12:
        if (HEAD == NULL){
		    printf("--------------------------------------------------------------\n");
			printf("The Student Record is EMPTY!!!\n");
			printf("--------------------------------------------------------------\n");
        	getch();
			goto menu;
    	}
    	
		char studno[15];
   		printf("--------------------------------------------------------------\n");
		printf("Enter Student No. after which you want to delete the node: ");
        scanf("%s", studno);
        DelAft(&HEAD, studno);
        getch();
		goto menu;
		
		case 13:
			return 0;
		
		default:
			printf("Invalid Choice!!!");
			getch();
			goto menu;
	}
	return 0;
}

void MainMenu(){
	system("cls");
	printf("\n------------------------  MAIN MENU  -------------------------\n");
	printf("\n [1] Create a Student Record");
	printf("\n [2] Traverse Student Record (HEAD - from top to bottom)");
	printf("\n [3] Traverse Student Record (TAIL - from bottom to top)");
	printf("\n [4] Adding/Insertion of Node in Student Record (at the head)");
	printf("\n [5] Adding/Insertion of Node in Student Record (at the tail)");
	printf("\n [6] Adding/Insertion of Node in Student Record (Before a Value)");
	printf("\n [7] Adding/Insertion of Node in Student Record (After a Value)");		
	printf("\n [8] Deletion of Node at the Head");
	printf("\n [9] Deletion of Node at the Tail");
	printf("\n [10] Deletion of Node by Value");
	printf("\n [11] Deletion of Node Before a Node");
	printf("\n [12] Deletion of Node After a Node");
	printf("\n [13] Exit");
	printf("\n\n--------------------------------------------------------------\n");
}

void CreateDLL(STUDREC **HEAD,STUDREC **TAIL){
	STUDREC *NewNode,*Prev;
	char Resp;
	int ctr=1;
	system("cls");
	NewNode=(STUDREC*)malloc(sizeof(STUDREC));
	*HEAD=NewNode;
	*TAIL=NewNode;
	(*HEAD)->prev=NULL;
	
	printf("\n------------------  CREATING A STUDENT RECORD  ------------------\n");
	do{
		printf("\nStudent #%d Number\t\t: ",ctr);
		scanf("%s", NewNode->studno);
		
		printf("\nStudent #%d Name\t\t\t: ",ctr);
		scanf(" %[^\n]", NewNode->studname);
		
		printf("\nCourse and Year\t\t\t: ");
		scanf(" %[^\n]", NewNode->studcrsyr);
		
		printf("\nGWA\t\t\t\t: ");
		scanf("%f", &NewNode->GWA);
		
		printf("\n------------------------------------------------------------------\n\n");
        printf("Add another record? [Y/N]: ");
        scanf(" %c",&Resp);
        printf("\n------------------------------------------------------------------\n\n");
        
        if(toupper(Resp) == 'Y'){
        	ctr++;
			NewNode->next=(STUDREC*)malloc(sizeof(STUDREC));
        	NewNode->next->prev=NewNode;
        	NewNode=NewNode->next;
        	*TAIL=NewNode;
		}
		
	} while(toupper(Resp) == 'Y');
	(*TAIL)->next=NULL;
	NewNode=NULL;
}

void TravHead(STUDREC **HEAD){
	STUDREC *TravNode;
	int ctr=1;
	system("cls");
	TravNode=*HEAD;
	printf("\n------------------------------- STUDENT RECORD (HEAD - from top to bottom) ------------------------------\n");
	if(TravNode==NULL){
		printf("\n%-37s Student Record is empty!\n", "");
		return;
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
		do{
			printf("%-9d",ctr);
    		printf("%-30s",TravNode->studno);
    		printf("%-30s",TravNode->studname);
    		printf("%-30s",TravNode->studcrsyr);
    		printf("%.2f\n\n",TravNode->GWA);
			TravNode=TravNode->next;
			ctr++;
		}while(TravNode!=NULL);
	}
}

void TravTail(STUDREC **TAIL){
	STUDREC *TravNode;
	int ctr=1;
	system("cls");
	TravNode=*TAIL;
	printf("\n------------------------------- STUDENT RECORD (TAIL - from bottom to top) ------------------------------\n");
	if(TravNode==NULL){
		printf("\n%-37s Student Record is empty!\n", "");
		return;
	}
	else{
		gotoxy(10, 5);
        printf("Student No.");

        gotoxy(40, 5);
        printf("Student Name");

        gotoxy(70, 5);
        printf("Course & Year");

        gotoxy(100, 5);
        printf("GWA\n\n");
        do{
            printf("%-9d", ctr);
            printf("%-30s", TravNode->studno);
            printf("%-30s", TravNode->studname);
            printf("%-30s", TravNode->studcrsyr);
            printf("%.2f\n\n", TravNode->GWA);
        	TravNode = TravNode->prev;
        	ctr++;
		}while(TravNode!=NULL);
	}
}

void AddHead(STUDREC **HEAD, STUDREC **TAIL) {
	system("cls");
	STUDREC *NewRec,*Current;
	Current=*HEAD;
	char temp;
	NewRec = (STUDREC*)malloc(sizeof(STUDREC));
	printf("\n---------------  ADD RECORD AT THE HEAD  ---------------\n\n");
	if(Current==NULL){
		printf("\n%-15s Student Record is empty!\n", "");
		printf("\n--------------------------------------------------------\n\n");
		printf("Press any key to return to main menu...");
		printf("\n\n--------------------------------------------------------");
		getch();
		return;
	}
	printf("Student Number\t\t: ");
	scanf("%s", NewRec->studno);
	strtok(NewRec->studno, "\n");
		
	printf("\nStudent Name\t\t: ");
	scanf(" %[^\n]", NewRec->studname);
		
	printf("\nCourse & Year\t\t: ");
	scanf(" %[^\n]", NewRec->studcrsyr);
	
	printf("\nGWA\t\t\t: ");
	scanf("%f", &NewRec->GWA);
	scanf("%c", &temp);
	
	NewRec->prev = NULL;
	NewRec->next = NULL;
	
	if (*HEAD == NULL) {
		*HEAD = *TAIL = NewRec;
	}
	else {
		NewRec->next = *HEAD;
		(*HEAD)->prev = NewRec;
		*HEAD = NewRec;
	}
	NewRec = NULL;
	printf("\n-------------------------------------------------------\n\n");
	printf("Record succesfully added at the head!\n");
	printf("\n-------------------------------------------------------\n");
	printf("\nPress any key to return to main menu...");
	printf("\n\n-------------------------------------------------------");
	getch();
}

void AddTail(STUDREC **HEAD, STUDREC **TAIL){
	system("cls");
	STUDREC *NewRec,*Current;
	char temp;
	Current=*HEAD;
	NewRec = (STUDREC*)malloc(sizeof(STUDREC));
	printf("\n---------------  ADD RECORD AT THE END  ---------------\n\n");
	if(Current==NULL){
		printf("\n%-15s Student Record is empty!\n", "");
		printf("\n--------------------------------------------------------\n\n");
		printf("Press any key to return to main menu...");
		printf("\n\n--------------------------------------------------------");
		getch();
		return;
	}
	printf("Student Number\t\t: ");
	scanf("%s", NewRec->studno);
	strtok(NewRec->studno, "\n");
		
	printf("\nStudent Name\t\t: ");
	scanf(" %[^\n]", NewRec->studname);
		
	printf("\nCourse & Year\t\t: ");
	scanf(" %[^\n]", NewRec->studcrsyr);
		
	printf("\nGWA\t\t\t: ");
	scanf("%f", &NewRec->GWA);
	scanf("%c", &temp);
	
	NewRec->prev = NULL;
	NewRec->next = NULL;
	if (*TAIL == NULL) {
		*HEAD = *TAIL = NewRec;
	}
	else {
		NewRec->prev = *TAIL;
		(*TAIL)->next = NewRec;
		*TAIL = NewRec;
	}
	NewRec = NULL;
	printf("\n-------------------------------------------------------\n\n");
	printf("Record succesfully added at the tail!\n");
	printf("\n-------------------------------------------------------\n");
	printf("\nPress any key to return to main menu...");
	printf("\n\n-------------------------------------------------------");
	getch();
}

void AddBef(STUDREC **HEAD){
	system("cls");
	STUDREC *NewNode,*Current;
	int Flag=0;
	char temp;
	Current=*HEAD;
	printf("\n-----------------------------  ADD RECORD BEFORE A VALUE  ------------------------------\n\n");
	if(Current==NULL){
		printf("\n%-30s Student Record is empty!\n", "");
		printf("\n---------------------------------------------------------------------------------------\n\n");
		printf("Press any key to return to main menu...");
		printf("\n\n---------------------------------------------------------------------------------------\n\n");
		getch();
		return;
	}
	char find[15];
    printf("Enter the Student Number before which you want to add the new record: ");
    scanf("%s",find);
    printf("\n----------------------------------------------------------------------------------------\n\n");
	
	while(Flag==0 && Current!=NULL){
			if (strcmp(Current->studno, find) == 0){
				Flag=1;
			}
			else{
				Current=Current->next;
			}
	}	
	NewNode = (STUDREC*)malloc(sizeof(STUDREC));
	if(Flag==0){
			printf("The Value where the NewNode will be inserted before does not exist.");
			getch();
			return;
		}	
	printf("\n---------------------------  INSERT RECORD BEFORE A VALUE  -----------------------------\n\n");
	printf("Student Number\t\t: ");
	scanf("%s", NewNode->studno);
		
	printf("\nStudent Name\t\t: ");
	scanf(" %[^\n]", NewNode->studname);
		
	printf("\nCourse & Year\t\t: ");
	scanf(" %[^\n]", NewNode->studcrsyr);
		
	printf("\nGWA\t\t\t: ");
	scanf("%f", &NewNode->GWA);
	scanf("%c", &temp);
	
	NewNode->prev=NULL;
	NewNode->next=NULL;
	if(Current==*HEAD){
		NewNode->next=*HEAD;
		(*HEAD)->prev=NewNode;
		*HEAD=NewNode;
	}
	else{
		NewNode->next=Current;
		NewNode->prev=Current->prev;
		Current->prev->next=NewNode;
		Current->prev=NewNode;
	}		
	Current=NewNode=NULL;
	printf("\n----------------------------------------------------------------------------------------\n\n");
	printf("Record succesfully added at the end!\n");
	printf("\n----------------------------------------------------------------------------------------\n");
	printf("\nPress any key to return to main menu...");
	printf("\n\n----------------------------------------------------------------------------------------");
	getch();
}

void AddAft(STUDREC **HEAD,STUDREC **TAIL){
	system("cls");
	STUDREC *NewNode,*Current;
	int Flag=0;
	char temp;
	Current=*HEAD;
	printf("\n-----------------------------  ADD RECORD AFTER A VALUE  ------------------------------\n\n");
	if(Current==NULL){
		printf("\n%-30s Student Record is empty!\n", "");
		printf("\n---------------------------------------------------------------------------------------\n\n");
		printf("Press any key to return to main menu...");
		printf("\n\n---------------------------------------------------------------------------------------\n\n");
		getch();
		return;
	}
	char find[15];
    printf("Enter the Student Number after which you want to add the new record: ");
    scanf("%s",find);
    printf("\n---------------------------------------------------------------------------------------\n\n");
	
	while(Flag==0 && Current!=NULL){
		if (strcmp(Current->studno, find) == 0){
			Flag=1;
		}	
		else{
			Current=Current->next;
		}
	}
	NewNode = (STUDREC*)malloc(sizeof(STUDREC));
	if(Flag==0){
			printf("The Value where the NewNode will be inserted after does not exist.");
			getch();
			return;
	}	
	printf("\n---------------------------  INSERT RECORD AFTER A VALUE  -----------------------------\n\n");
	printf("Student Number\t\t: ");
	scanf("%s", NewNode->studno);
		
	printf("\nStudent Name\t\t: ");
	scanf(" %[^\n]", NewNode->studname);
		
	printf("\nCourse & Year\t\t: ");
	scanf(" %[^\n]", NewNode->studcrsyr);
		
	printf("\nGWA\t\t\t: ");
	scanf("%f", &NewNode->GWA);
	scanf("%c", &temp);
	
	NewNode->prev=NULL;
	NewNode->next=NULL;
	
	if(Current==*TAIL){
		NewNode->next=*TAIL;
		(*TAIL)->prev=NewNode;
		*TAIL=NewNode;
	}			
	else{
		NewNode->next=Current->next;
		NewNode->prev=Current;
		Current->next->prev=NewNode;
		Current->next=NewNode;
	}
	Current=NewNode=NULL;
	printf("\n---------------------------------------------------------------------------------------\n\n");
	printf("Record succesfully added at the end!\n");
	printf("\n---------------------------------------------------------------------------------------\n");
	printf("\nPress any key to return to main menu...");
	printf("\n\n---------------------------------------------------------------------------------------");
	getch();
}

void DelHead(STUDREC **HEAD, STUDREC **TAIL){
	STUDREC *DelNode;
	DelNode=*HEAD;
	if (DelNode==NULL){
		printf("--------------------------------------------------------------\n");
        printf("Student Record is empty!\n", "");
        printf("--------------------------------------------------------------\n");
        printf("Press any key to return to main menu...");
		printf("\n--------------------------------------------------------------\n");
		getch();
		return;
	}
	
	if (DelNode->next == NULL){ //If there is only one node in the student record
		free(DelNode);
		*HEAD=NULL;
		*TAIL=NULL;
	}
	
    else {
        *HEAD = (*HEAD)->next;
        (*HEAD)->prev = NULL;
        free(DelNode);
        DelNode=NULL;
    }
    printf("--------------------------------------------------------------\n");
    printf("Node at the head deleted successfully!");
    printf("\n--------------------------------------------------------------\n");
    printf("Press any key to return to main menu...");
	printf("\n--------------------------------------------------------------\n");
	getch();
}

void DelTail(STUDREC **HEAD, STUDREC **TAIL){
	STUDREC *DelNode;
	DelNode=*TAIL;
	
	if (DelNode==NULL){
        printf("--------------------------------------------------------------\n");
        printf("Student Record is empty!\n", "");
        printf("--------------------------------------------------------------\n");
        printf("Press any key to return to main menu...");
		printf("\n--------------------------------------------------------------\n");
		getch();
        return;
	}
	
	if (DelNode->prev == NULL){ //If there is only one node in the student record
		free(DelNode);
		*HEAD=NULL;
		*TAIL=NULL;
	}
	
    else {
        *TAIL = (*TAIL)->prev;
        (*TAIL)->next = NULL;
        free(DelNode);
        DelNode=NULL;
    }
    printf("--------------------------------------------------------------\n");
    printf("Node at the tail deleted successfully!");
    printf("\n--------------------------------------------------------------\n");
    printf("Press any key to return to main menu...");
	printf("\n--------------------------------------------------------------\n");
	getch();
}

void DelVal(STUDREC **HEAD, char *value){
	STUDREC *temp=*HEAD,*prev;
	printf("--------------------------------------------------------------\n");
	if (*HEAD == NULL) {
        printf("Student Record is empty!\n", "");
        printf("--------------------------------------------------------------\n");
        printf("Press any key to return to main menu...");
		printf("\n--------------------------------------------------------------\n");
		getch();
		return;
    }
	printf("Enter Student Number to delete a node: ");
	scanf("%s", value);
	if (temp != NULL && strcmp(temp->studno, value) == 0) {
        *HEAD = temp->next;
        if (*HEAD != NULL)
        	(*HEAD)->prev = NULL;
        	free(temp);
        printf("--------------------------------------------------------------\n");
		printf("Node with Student Number %s deleted successfully.\n", value);
		printf("--------------------------------------------------------------\n");
	    printf("Press any key to return to main menu...");
		printf("\n--------------------------------------------------------------\n");
		getch();
		return;
    }
    
    while (temp != NULL && strcmp(temp->studno, value) != 0) {
        prev = temp;
        temp = temp->next;
	}
	if (temp == NULL) {
        printf("--------------------------------------------------------------\n");
		printf("Node with Student Number %s not found.\n", value);
        printf("--------------------------------------------------------------\n");
        printf("Press any key to return to main menu...");
		printf("\n--------------------------------------------------------------\n");
		getch();
		return;
    }
    
    prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = prev;
    free(temp);
}

void DelBef(STUDREC **HEAD){
	STUDREC *Del_Val,*Previous,*DelNode;
	if(*HEAD == NULL){
		printf("--------------------------------------------------------------\n");
		printf("The Student Record is EMPTY!!!\n");
		printf("--------------------------------------------------------------\n");
		printf("Press Enter to Return to Main Menu...");			
		printf("\n--------------------------------------------------------------\n");
		getch();
		return;
	}
	
	else{
		char Del_Val[15];
		printf("--------------------------------------------------------------\n");
		printf("Enter Student No. before which you want to delete the node: ");
		scanf("%s", Del_Val);
		getchar();			
	
	Previous = NULL;
	DelNode = *HEAD;
		while(DelNode != NULL){
			if(strcmp(DelNode->studno, Del_Val)== 0){
				if(DelNode == *HEAD){
					printf("--------------------------------------------------------------\n");
					printf("There is no record before the node!!!\n");
					printf("--------------------------------------------------------------\n");
					printf("Press Enter to Return to Main Menu...");
					printf("\n--------------------------------------------------------------\n");
					getch();
					return;
				}
		
				else{
				Previous = DelNode->prev;
				Previous->prev->next = DelNode;	
				DelNode->prev = Previous->prev;		
				free(Previous);
				printf("--------------------------------------------------------------\n");
		        printf("Node before Student No. %s deleted successfully.\n", Del_Val);
		        printf("--------------------------------------------------------------\n");
		        printf("Press Enter to Return to Main Menu...");
		        printf("\n--------------------------------------------------------------\n");
		        getch();
		        return;
				}
				break;	
			}
		DelNode = DelNode->next;
		}
		
		if(DelNode == NULL){
		printf("--------------------------------------------------------------\n");
		printf("Student Record not Found!!!\n");
		printf("--------------------------------------------------------------\n");	
		printf("Press Enter to Return to Main Menu...");
		printf("\n--------------------------------------------------------------\n");
		getch();
		return;
		}
	}
}

void DelAft(STUDREC **HEAD, char *studno){
    STUDREC *current = *HEAD;
    while (current != NULL && strcmp(current->studno, studno) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("--------------------------------------------------------------\n");
		printf("Student Record not Found!!!\n");
		printf("--------------------------------------------------------------\n");
        printf("Press Enter to Return to Main Menu...");
		printf("\n--------------------------------------------------------------\n");
		getch();
		return;
    }
    
    if(current->next == NULL){
    	printf("--------------------------------------------------------------\n");
		printf("There is no record after the node!!!\n");
		printf("--------------------------------------------------------------\n");
		printf("Press Enter to Return to Main Menu...");
		printf("\n--------------------------------------------------------------\n");
		getch();
		return;
	}
    STUDREC *temp = current->next;
    current->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = current;
    }
    free(temp);
	printf("--------------------------------------------------------------\n");
    printf("Student record after Student No. %s has been deleted successfully.\n", studno);
    printf("--------------------------------------------------------------\n");
	getch();
}
