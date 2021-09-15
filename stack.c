#include <stdio.h>
#include <stdlib.h>
#include "line.h"
#define MAX 10

struct stack
{
    int top;
    int data[MAX];
};

void init(struct stack *stack)
{
    stack->top = -1;
    line();
    printf("\nStack initialized.\n");
    line();
}

void push(struct stack *stack, int key)
{
    if (stack->top == MAX - 1)
        printf("\nStack is full! You can't perform PUSH operation. \n");
    stack->top++;
    stack->data[stack->top] = key;
    line();
    printf("\n%d pushed into the stack.\n", key);
    line();
}
void display(struct stack *stack)
{
    line();
    printf("\nStack : \n\n");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("    |  %d  |\n", stack->data[i]);
    }
    line();
}
int pop(struct stack *stack)
{
    if (stack->top == -1)
        printf("\nStack is empty! you can't perform POP operation.\n");
    else
    {
        int tmp = stack->data[stack->top];
        stack->top--;
        line();
        printf("\n%d Popped!\n", tmp);
        line();
        return tmp;
    }
}
int peep(struct stack *stack)
{
    if (stack->top == -1)
        printf("\nStack is empty! you can't perform PEEP operation.\n");
    else
    {
        int tmp = stack->data[stack->top];
        line();
        printf("\n%d Peeped!\n", tmp);
        line();
        return tmp;
    }
}
void main()
{
    int choice, data;
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    init(stack);
    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Peep\n4.Display\n5.Exit");
        printf("\n\nEnter option : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            line();
            printf("\nEnter the data you want to push : ");
            scanf("%d", &data);
            push(stack, data);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            peep(stack);
            break;
        case 4:
            display(stack);
            break;
        case 5:
            printf("\nFinal stack : \n\n");
            display(stack);
            line();
            printf("\nThanks for using! Have a great day :)\n");
            line();
            exit(0);
            break;
        default:
            break;
        }
    }
}
