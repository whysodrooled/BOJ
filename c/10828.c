#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int val;
    struct Node* next;
} Node;

typedef struct Stack
{
    struct Node* top;
    struct Node* last;
    int size;
} Stack;

Stack* Stack_Create()
{
    Stack* ret = malloc(sizeof(Stack));
    ret->top = NULL;
    ret->last = NULL;
    ret->size = 0;

    return ret;
}

int Stack_Pop(Stack* stack)
{
    if(stack->size == 0) return -1;
    
    Node* nxt = (stack->top)->next;
    int ret = stack->top->val;

    free(stack->top);
    stack->top = nxt;

    if(nxt == NULL)
    {
        stack->last = NULL;
    }

    stack->size--;

    return ret;
}

void Stack_Push(Stack* stack, int val)
{
    Node* new = malloc(sizeof(Node));
    new->val = val;
    new->next = NULL;

    if(stack->last == NULL)
    {
        stack->top = new;
        stack->last = new;
    }
    else
    {
        new->next = stack->top;
        stack->top = new;
    }

    stack->size++;
}

int T;
char input[15];
int num;

int main()
{
    Stack* stack = Stack_Create();
    scanf("%d", &T);

    while(T > 0)
    {
        scanf("%s", &input);
        if(strcmp(input, "push") == 0)
        {
            scanf("%d", &num);
            Stack_Push(stack, num);
        }
        else if(strcmp(input, "pop") == 0)
        {
            printf("%d\n", Stack_Pop(stack));
        }
        else if(strcmp(input, "size") == 0)
        {
            printf("%d\n", stack->size);
        }
        else if(strcmp(input, "top") == 0)
        {
            num = (stack->top == NULL) ? -1 : stack->top->val;
            printf("%d\n", num);
        }
        else
        {
            printf("%d\n", (stack->size == 0) ? 1 : 0);
        }
        
        T--;
    }
    
    return 0;
}