#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    short int vert;
    short int horiz;
} offsets;
offsets move[8];
typedef struct
{
    short int row;
    short int col;
    short int dir;
} Element;
Element stack[50];
int maze[5][5];
int mark[5][5];

int top = -1;
int exitrow, exitcol;
void readmaze()
{
    int r, c;
    int i, j;
    printf("enter the number of rows and cols:\n");
    scanf("%d%d", &r, &c);
    printf("enter the elements of the matrix:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }
    exitrow = r - 2;
    exitcol = c - 2;
}
void setmovetable()
{
    move[0].vert = -1, move[0].horiz = 0;
    move[1].vert = -1, move[1].horiz = 1;
    move[2].vert = 0, move[2].horiz = 1;
    move[3].vert = 1, move[3].horiz = 1;
    move[4].vert = 1, move[4].horiz = 0;
    move[5].vert = 1, move[5].horiz = -1;
    move[6].vert = 0, move[6].horiz = -1;
    move[7].vert = -1, move[7].horiz = -1;
}

void push(Element ele)
{
    top = top + 1;
    stack[top].row = ele.row;
    stack[top].col = ele.col;
    stack[top].dir = ele.dir;
    return;
}
Element pop()
{
    Element delitem;
    delitem.row = stack[top].row;
    delitem.col = stack[top].col;
    delitem.dir = stack[top].dir;
    top = top - 1;
    return delitem;
}
void findpath()
{
    int i, row, col, nextrow, nextcol, dir, found = 0;
    Element position;
    mark[1][1] = 1, top = 0;
    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 0;
    while (top > -1 && !found)
    {
        position = pop();
        row = position.row;
        col = position.col;
        dir = position.dir;
        while (dir < 8 && !found)
        {
            nextrow = row + move[dir].vert;
            nextcol = col + move[dir].horiz;
            if (nextrow == exitrow && nextcol == exitcol)
                found = 1;
            else if (!maze[nextrow][nextcol] && !mark[nextrow][nextcol])
            {
                mark[nextrow][nextcol] = 1;
                position.row = row;
                position.col = col;
                position.dir = ++dir;
                push(position);
                row = nextrow;
                col = nextcol;
                dir = 0;
            }
            else
                ++dir;
        }
    }
    if (found)
    {
        printf("the path is :\n");
        printf("\nrow\tcol\n");
        for (i = 0; i <= top; i++)
            printf("%d%d\n", stack[i].row, stack[i].col);
        printf("%2d%5d\n", row, col);
        printf("%2d%5d", exitrow, exitcol);
    }
    else
        printf("\n No path");
}
void main()
{
    readmaze();
    setmovetable();
    findpath();
    return;
}