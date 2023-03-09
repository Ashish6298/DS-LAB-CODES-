#include <stdio.h>
#include <stdlib.h>
#define MS 5
char infix[50], postfix[50], item;
struct stack
{
    int top;
    char item[MS];
} s;

void push(char value)
{
    if (s.top == (MS - 1))
    {
        printf("Overflow\n");
        exit(0);
    }
    else
    {
        s.item[++s.top] = value;
    }
}

char pop()
{
    if (s.top == -1)
    {
        printf("Underflow\n");
        exit(0);
    }
    return (s.item[s.top--]);
}
int empty()
{
    if (s.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char c)
{
    switch (c)
    {
    case '^':
        return 3;
    case '*':
    case '/':
    case '%':
        return 2;
    case '+':
    case '-':
        return 1;
    case '(':
        return 0;
    }
}

void convert()
{
    int i, pos = 0;
    char symb, t;
    for (i = 0; infix[i] != '\0'; i++)
    {
        symb = infix[i];
        switch (symb)
        {
        case '(':
            push(symb);
            break;

        case ')':
            while ((t = pop()) != '(')
            {
                postfix[pos++] = t;
            }
            break;

        case '^':
        case '*':
        case '/':
        case '+':
        case '%':
        case '-':

            while ((!empty()) && ((precedence(s.item[s.top])) >= precedence(symb)))
            {
                postfix[pos++] = pop();
            }
            push(symb);
            break;
        default:
            postfix[pos++] = symb;
            break;
        }
    }

    while (!empty())
    {
        postfix[pos++] = pop();
    }
    postfix[pos] = '\0';
}

void main()
{
    s.top = -1;
    printf("Enter the infix exp\n");
    gets(infix);
    convert();
    printf("The postfix exp is\n");
    puts(postfix);
}