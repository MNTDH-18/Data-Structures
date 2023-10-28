#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void homePage();
void showList();
void updateList();
void createLinkedList();
void dataSearch();
void add();
void del();
void addFirst();
void addMiddle();
void addLast();
void delFirst();
void delMiddle();
void delLast();
void updateData();


typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Node;

Node *head, *temp, *tail;

void main()
{

    head = temp = tail = NULL;

    homePage();
}

void homePage()
{
    system("cls");

    int choose;
    printf (" \n 1. Create linked list  \t 2. See linked list \n 3. Search \t \t \t 4. Add \n 5. Delete \t \t \t 6. Update \n 7. Exit \n \n");
    printf(" Choose one from above options: ");
    scanf ("%d", &choose);

    switch(choose)
    {
    case 1:
        createLinkedList();
        break;
    case 2:
        showList();
        break;
    case 3:
        dataSearch();
        break;
    case 4:
        add();
        break;
    case 5:
        del();
        break;
    case 6:
        updateData();
        break;
    case 7:
        exit(0);
    default:
        printf("\n\n\t \t \t \t \t \t \t \t Kindly choose a valid option \n\t \t \t \t \t \t \t \t Press any key to continue");
        getch();
        homePage();
    }
}

void createLinkedList()
{
    system("cls");

    int n, i;
    printf("Enter node numbers: ");
    scanf("%d",&n);

    printf("\nEnter node values: \n");

    for(i = 1; i <= n; i++)
    {
        temp = (Node *) malloc(sizeof(Node));

        temp->prev = NULL;

        scanf("%d", &temp->data);

        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
        }

        else
        {
            tail->next = temp;
            temp->prev = tail;
        }

        tail = temp;
    }

    printf("\n\n\t \t \t \t \t \t \t \t    Press any key to continue");
    getch();
    homePage();
}

void showList()
{
    system("cls");

    temp = head;

    printf("\nLinked List's data: \n");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n\n\t \t \t \t \t \t \t \t    Press any key to continue");
    getch();
    homePage();
}


void updateList()
{
    temp = head;

    printf("\nLinked List's data: \n");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


void dataSearch()
{
    system("cls");

    int z, flag = 0;

    printf("\nEnter the data you want to search: ");

    scanf("%d", &z);

    temp = head;

    while(temp != NULL)
    {
        if(temp->data == z)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if(flag == 1)
    {
        printf("\nData Found\n");
    }
    else
    {
        printf("\nData Not Found\n");
    }

    printf("\n\n\t \t \t \t \t \t \t \t    Press any key to continue");
    getch();
    homePage();
}


void add()
{
    system("cls");

    int choose;

    printf (" \n 1. Add data at first  \t \t 2. Add data in middle \n 3. Add data at last \t \t 4. Exit \n \n");
    printf(" Choose one from above options: ");
    scanf ("%d", &choose);

    switch(choose)
    {
    case 1:
        addFirst();
        break;
    case 2:
        addMiddle();
        break;
    case 3:
        addLast();
        break;
    case 4:
        homePage();
        break;
    default:
        printf("\n\n\t \t \t \t \t \t \t \t Kindly choose a valid option \n\t \t \t \t \t \t \t \t Press any key to continue");
        getch();
        add();
    }
}


void del()
{
    system("cls");

    int choose;

    printf (" \n 1. Delete first data \t \t 2. Delete middle data \n 3. Delete data from last \t 4. Exit \n \n");
    printf(" Choose one from above options: ");
    scanf ("%d", &choose);

    switch(choose)
    {
    case 1:
        delFirst();
        break;
    case 2:
        delMiddle();
        break;
    case 3:
        delLast();
        break;
    case 4:
        homePage();
        break;
    default:
        printf("\n\n\t \t \t \t \t \t \t \t Kindly choose a valid option \n\t \t \t \t \t \t \t \t Press any key to continue");
        getch();
        del();
    }
}


void addFirst()
{
    system("cls");

    temp = (Node *) malloc(sizeof(Node));

    printf("\nEnter the data you want to add to first: ");

    scanf("%d", &temp->data);

    tail = head;

    temp->next = tail;
    tail->prev = temp;

    head = temp;

    printf("\nAfter adding data to first...\n");

    updateList();

    printf("\n\n\t \t \t \t \t \t \t \t    Press any key to continue");
    getch();
    add();
}


void addMiddle()
{
    system("cls");

    updateList();

    int d, i;

    temp = (Node *) malloc(sizeof(Node));

    printf("\nEnter the data you want to add: ");

    scanf("%d", &temp->data);

    printf("Enter the position you want to add at(Other than first and last): ");

    scanf("%d", &d);

    tail = head;

    for(i = 2; i <= d; i++)
    {
        tail = tail->next;
    }

    temp->next = tail;
    tail->prev = temp;

    tail = head;

    for(i = 2; i < d; i++)
    {
        tail = tail->next;
    }

    tail->next = temp;
    temp->prev = tail;

    printf("\nAfter adding data to middle...\n");

    updateList();


    printf("\n\n\t \t \t \t \t \t \t \t    Press any key to continue");
    getch();
    add();
}


void addLast()
{
    system("cls");

    temp = (Node *) malloc(sizeof(Node));

    printf("\nEnter the data you want to add to the last: ");

    temp->prev = NULL;

    scanf("%d", &temp->data);

    temp->next = NULL;

    tail = head;

    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = temp;
    temp->prev = tail;

    printf("\nAfter adding data to last...\n");

    updateList();


    printf("\n\n\t \t \t \t \t \t \t \t    Press any key to continue");
    getch();
    add();
}


void delFirst()
{
    system("cls");

    tail = head;
    tail = tail->next;
    tail->prev = NULL;
    head = tail;

    printf("\nAfter deleting the first data...\n");

    updateList();

    printf("\n\n\t \t \t \t \t \t \t \t    Press any key to continue");
    getch();
    del();
}


void delMiddle()
{
    system("cls");

    updateList();

    int d, i;

    printf("\nEnter the position of the data you want to delete (Other than first and last): ");
    scanf("%d", &d);

    tail = head;

    for(i = 2; i <= d+1; i++)
    {
        tail = tail->next;
    }

    temp = tail;

    tail = head;

    for(i = 2; i < d; i++)
    {
        tail = tail->next;
    }

    tail->next = temp;
    temp->prev = tail;

    printf("\nAfter deleting a data from middle...\n");

    updateList();

    printf("\n\n\t \t \t \t \t \t \t \t    Press any key to continue");
    getch();
    del();
}


void delLast()
{
    system("cls");

    tail = head;

    while(tail->next != NULL)
    {
        temp = tail;
        tail = tail->next;
    }

    temp->next = NULL;

    printf("\nAfter deleting the last data...\n");

    updateList();

    printf("\n\n\t \t \t \t \t \t \t \t    Press any key to continue");
    getch();
    del();
}


void updateData()
{
    system("cls");

    updateList();

    int d, i;

    printf("\n\nEnter the position of the data you want to update: ");
    scanf("%d", &d);

    tail = head;

    for(i = 2; i <= d; i++)
    {
        tail = tail->next;
    }

    printf("Enter the updated data: ");
    scanf("%d", &tail->data);

    printf("\nAfter updating the data...\n");

    updateList();

    printf("\n\n\t \t \t \t \t \t \t \t    Press any key to continue");
    getch();
    homePage();
}
