/* Only for Windows */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void homePage();
void push();
void pop();
void display();
void displayPOP();
void peek();

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *top, *tail, *temp;

void main()
{
    top = temp = tail = NULL;

    homePage();
}

void homePage()
{
    system("cls");
    system("color D");

    int choose;
    printf(" \n 1. Push  \t 2. See the Stack \n 3. Pop \t 4. Peek \n 5. Exit \n \n");
    printf(" Choose one from above options: ");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
        push();
        break;
    case 2:
        display();
        break;
    case 3:
        pop();
        break;
    case 4:
        peek();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("\n\n\t \t \t \t \t \t \t \t Kindly choose a valid option \n\t \t \t \t \t \t \t \t Press any key to continue");
        getch();
        homePage();
    }
}

void push()
{
    system("cls");

    int n, i;

    printf("Enter the number of nodes you want to push: ");
    scanf("%d", &n);
    printf("\nEnter pushed node values: \n");

    for (i = 1; i <= n; i++)
    {
        temp = (Node *)malloc(sizeof(Node));

        scanf("%d", &temp->data);

        temp->next = top;
        top = temp;
    }

    printf("\n\n\t \t \t \t \t\tStack successfully created! \n \t \t \t \t \t \t Press any key to continue");
    getch();
    homePage();
}

void displayPOP()
{
    if (top == NULL)
    {
        printf("\n\n\t \t \t \t \t \t\tStack is empty! \n \t \t \t \t \t \t Press any key to continue");
    }
    else
    {
        printf("\n The stack values are: \n");

        tail = top;

        while (tail != NULL)
        {
            printf("\n\t %d\n", tail->data);

            tail = tail->next;
        }

        printf("\n\n\t \t \t \t \t \t \t \t    Press any key to continue");
    }

    getch();
    homePage();
}

void display()
{
    system("cls");

    if (top == NULL)
    {
        printf("\n\n\t \t \t \t \t \t\tStack is empty! \n \t \t \t \t \t \t Press any key to continue");
    }
    else
    {
        printf("\n The stack values are: \n");

        tail = top;

        while (tail != NULL)
        {
            printf("\n\t %d\n", tail->data);

            tail = tail->next;
        }

        printf("\n\n\t \t \t \t \t \t \t \t    Press any key to continue");
    }

    getch();
    homePage();
}

void pop()
{
    system("cls");

    tail = top;
    top = top->next;
    tail = NULL;
    free(tail);

    printf("\n\n\t \t \t \t \t \t \t Successfully popped the top stack value\n\n");

    displayPOP();
}

void peek()
{
    system("cls");

    printf("\n The top value of the stack is: %d", top->data);

    printf("\n\n\t \t \t \t \t \t \t \t    Press any key to continue");
    getch();
    homePage();
}
