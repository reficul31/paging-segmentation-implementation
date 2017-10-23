#include "myheader.h"

// function to create new node with input data as character type in linked list 
NODE* createNewNode(char data)
{
    NODE *newNode = NULL;
    newNode=(NODE*)malloc(sizeof(NODE));
    if(newNode == NULL) {
        printf("Memory allocation error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function create new node with input data as integer type in linked list 
INTNODE* intCreateNewNode(int data)
{
    INTNODE *newNode = NULL;
    newNode=(INTNODE*)malloc(sizeof(INTNODE));
    if(newNode == NULL) {
        printf("Memory allocation error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert new node of type character at the end of list 
NODE* insertAtEnd(char data, NODE **head)
{
    NODE *current = *head;
       if (current == NULL) {
        *head = createNewNode(data);
    }else{
        while(current->next != NULL){
            current = current->next;
        }
        current->next = createNewNode(data);
    }
    return *head;
}

// function to insert new node of type integer at the end of list 
INTNODE* intInsertAtEnd(int data, INTNODE **head)
{
    INTNODE *current = *head;
       if (current == NULL) {
        *head = intCreateNewNode(data);
    }else{
        while(current->next != NULL){
            current = current->next;
        }
        current->next = intCreateNewNode(data);
    }
    return *head;
}

// function to remove nodes when more than one space characters occures in the linked list 
NODE* removeExtraSpaces(NODE** head)
{
    NODE*current = *head;
    while(current->next != NULL){
        if(current->data == ' '){
            if((current->next)->data == ' '){
                NODE*temp = (current->next)->next;
                free(current->next);
                current->next = temp;
            }
        }
        current = current->next;
    }
    return *head;
}

// function to count nodes of integer type linked list 
int countINTNodes(INTNODE *head)
{
    int count=0;
    while(head != NULL){
        count++;
        head=head->next;
  }
    return count;
}

// function to delete character type linked list 
void deleteCharList(NODE **head)
{
    NODE *current = *head;
    while(current->next != NULL){
        *head = current->next;
        free(current);
        current=*head;
    }
}

// function to delete intger type linked list 
void deleteINTList(INTNODE **inthead)
{
    INTNODE *current = *inthead;
    while(current != NULL){
        *inthead = current->next;
        free(current);
        current=*inthead;
    }
}

// function to delete front node from integer type of list 
INTNODE *deleteINTFront(INTNODE **inthead)
{
    INTNODE *current = *inthead;
    if(current == NULL) {
        printf("\nList is empty\n");
        return NULL;
    }else{
        *inthead = current->next;
        free(current);
    }
    current = current->next;
    return *inthead;
}

// function to delete last node from integer type of list 
INTNODE *deleteINTEnd(INTNODE **inthead)
{
    INTNODE *current = *inthead;

    if(countINTNodes(current) >= 2){
        while((current->next)->next != NULL){
            current=current->next;
        }
        free(current->next);
        current->next=NULL;
    }else{
        return deleteINTFront(&(*inthead));
    }

    return *inthead;
}

// function to delete node when its data is 0, starting from second node of the list 
INTNODE* deleteIntFromSecondNode(INTNODE **inthead)
{
    INTNODE *headTemp = *inthead;
    if(countINTNodes(*inthead) > 1){
        INTNODE*current = (*inthead)->next;

        while(current != NULL){
            if(current->data == 0){
                headTemp->next = current->next;
                free(current);
                current = headTemp->next;
            }else{
                break;
            }
        }
    }
    return headTemp;
}

//get each char node value from NODE structure,
// insert node with data space at the end,
//check if that data is space or not,
//if it is space then insertNewNode at the end of integer type of linked list using atoi() function,
//otherwise hold that value in variable(holdstr),
//this function separate the data,what we actually want from file
// e.g: 1 2 45  67  234  943  (each are separate characters in char type linked list,9,4 & 3 are characters)
// returns: 1 2 45 67 234 943 (each are integers stored in integer type of linked list)
void separateNumbDatas(NODE *head, INTNODE **inthead)
{
    head = insertAtEnd(' ',&head);
    NODE*current = head;
    char holdStr[50];
    int index = 0;

    while(current != NULL){
        if(current->data == ' '){
                holdStr[index] = '\0';
                intInsertAtEnd(atoi(holdStr),&(*inthead));
                index = 0;
               holdStr[index] = '\0';
               current = current->next;
        }else{
                holdStr[index] = current->data;
                index++;
                current = current->next;
            }
        }
}

// function to read file by skipping comments & call above functions to make integer type of linked list
INTNODE *getProcessData(const char *filename)
{
    NODE* head = NULL;
    INTNODE *inthead = NULL;   
    FILE *fp;
    char readData;
    bool flag = false;

    fp=fopen(filename,"r");
    if(fp == NULL) {
        printf("File openning error\n");
        exit(0);
    }

    //read each character from file
    do{
        readData = getc(fp);
        if(readData == ' '&& !flag){
            flag = false;
        }
        else{
            flag=true;
        }

        if(readData=='\t'){
            readData=' ';
        }
        /* check # character and EOF character occurs or not
        when # sign occurs keep reading data from file without adding it to list */
        if(readData == '#'){
            readData = ' ';
            char ch;
            while((ch=getc(fp)) != '\n' && ch != EOF){
            }
            readData = '\n';
        }
                    
        //inserting each char value to linked list
        if(flag){
            head = insertAtEnd(readData,&head);
        }

    } while(readData != EOF);

    fclose(fp);

    //remove extra spaces from char type linked list
    for(int i=0;i<5;i++){
       head = removeExtraSpaces(&head);
    }

    //separate integer data values & store them into new linked list(inthead)
    separateNumbDatas(head,&inthead);

    //delete unnecessary character(0),which is head
    deleteINTFront(&inthead); 

    //once integer list is created,then delete the character type list
    deleteCharList(&head);
    free(head);
    return inthead;
}