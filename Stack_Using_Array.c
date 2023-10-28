#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *a;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->a[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is already Empty! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        int val = ptr->a[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *st, int i)
{
    int arrayInd = st->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return st->a[arrayInd];
    }
}

void printStack(struct stack *st)
{
    if (st->top < 0)
    {
        printf("Stack is Empty!");
    }
    else
    {
        printf("Stack -> ");
        for (int i = 0; i <= st->top; i++)
        {
            printf("%d ", st->a[i]);
        }
    }
    printf("\n");
}

int main()
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->size = 100;
    st->top = -1;
    st->a = (int *)malloc(st->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing, Full: %d\n", isFull(st));
    printf("Before pushing, Empty: %d\n", isEmpty(st));

    printStack(st);

    push(st, 10);
    push(st, 20);
    push(st, 30);
    push(st, 40);

    printf("After pushing, Full: %d\n", isFull(st));
    printf("After pushing, Empty: %d\n", isEmpty(st));

    printStack(st);

    printf("Before poping, Full: %d\n", isFull(st));
    printf("Before poping, Empty: %d\n", isEmpty(st));

    printStack(st);

    pop(st);
    pop(st);

    printf("After poping, Full: %d\n", isFull(st));
    printf("After poping, Empty: %d\n", isEmpty(st));

    printStack(st);

    int peekVal, peekIdx;

    printf("Enter the position (top to bottom) whose value you want to see: ");
    scanf("%d", &peekIdx);

    peekVal = peek(st, peekIdx);

    if (peekVal != -1)
    {
        printf("Peek value at position %d = %d\n", peekIdx, peekVal);
    }

    return 0;
}
