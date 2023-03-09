#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MS 5
int c;
struct student
{
    char usn[25], name[25], dept[25], phno[25];
    float marks1, marks2, marks3, total, average;
    struct student *next;
    struct student *prev;
};

typedef struct student node;
node *getnode(node *head)
{
    node *nn;
    nn = (node *)malloc(sizeof(node));
    printf("Enter the usn\n");
    scanf("%s", nn->usn);

    printf("Enter the name\n");
    scanf("%s", nn->name);

    printf("Enter the dept\n");
    scanf("%s", nn->dept);

    printf("Enter the phone number\n");
    scanf("%s", nn->phno);

    printf("Enter the all marks\n");
    scanf("%f%f%f", &nn->marks1, &nn->marks2, &nn->marks3);

    nn->next = nn->prev = NULL;
    return nn;
}

int countnodes(node *head)
{
    node *p;
    p = head;
    c = 0;
    while (p != NULL)
    {
        p = p->next;
        c++;
    }
    return c;
}

node *create(node *head)
{
    node *nn, *p;
    p = head;
    if (head == NULL)
    {
        nn = getnode(head);
        head = nn;
    }
    else
    {
        nn = getnode(head);
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = nn;
        nn->prev = p;
    }
    return head;
}

node *insertfront(node *head)
{
    node *nn;
    if (countnodes(head) == MS)
    {

        printf("Insertion is not possible\n");
    }
    else
    {
        nn = getnode(head);
        if (head = NULL)
        {
            head = nn;
        }

        else
        {
            nn->next = head;
            head->prev = nn;
            head = nn;
        }
    }
    return head;
}

node *insertrear(node *head)
{
    node *nn;
    if (countnodes(head == MS))
    {
        printf("Insertion is not possible\n");
    }
    else
    {
        head = create(head);
    }
    return head;
}

node *display(node *head)
{
    node *p;
    if (head == NULL)
    {
        printf("NO data\n");
    }

    else
    {
        p = head;
        printf("USN\tNAME\tDEPARTMENT\tPhoneNO\t\tMARKS1\tMARKS2\tMARKS3\tTOTAL\tAVERAGE\n");
        while (p != NULL)
        {
            p->total = p->marks1 + p->marks2 + p->marks3;
            p->average = p->total / 3;

            printf("%s\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", p->usn, p->name, p->dept, p->phno, p->marks1, p->marks2, p->marks3, p->total, p->average);

            p = p->next;
        }
    }
    printf("Tne number of countnodes is \n", countnodes(head));
    return head;
}
