#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 30
#define COLS 60

char canvas[ROWS][COLS];

/* Initialize Canvas */
void initCanvas()
{
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLS;j++)
            canvas[i][j]=' ';
}

/* Display Canvas */
void displayCanvas()
{
    printf("\n");

    for(int i=0;i<COLS+2;i++)
        printf("-");

    printf("\n");

    for(int i=0;i<ROWS;i++)
    {
        printf("|");

        for(int j=0;j<COLS;j++)
            printf("%c",canvas[i][j]);

        printf("|\n");
    }

    for(int i=0;i<COLS+2;i++)
        printf("-");

    printf("\n");
}

/* Plot a Point */
void plot(int x,int y,char ch)
{
    if(x>=0 && x<COLS && y>=0 && y<ROWS)
        canvas[y][x]=ch;
}

/* Draw Line (DDA Algorithm) */
void drawLine(int x1,int y1,int x2,int y2,char ch)
{
    int dx=x2-x1;
    int dy=y2-y1;

    int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);

    float xInc=(float)dx/steps;
    float yInc=(float)dy/steps;

    float x=x1;
    float y=y1;

    for(int i=0;i<=steps;i++)
    {
        plot((int)round(x),(int)round(y),ch);
        x+=xInc;
        y+=yInc;
    }
}

/* Draw Rectangle */
void drawRectangle(int x,int y,int width,int height,char ch)
{
    for(int i=x;i<x+width;i++)
    {
        plot(i,y,ch);
        plot(i,y+height-1,ch);
    }

    for(int i=y;i<y+height;i++)
    {
        plot(x,i,ch);
        plot(x+width-1,i,ch);
    }
}

/* Draw Triangle */
void drawTriangle(int x1,int y1,
                  int x2,int y2,
                  int x3,int y3,
                  char ch)
{
    drawLine(x1,y1,x2,y2,ch);
    drawLine(x2,y2,x3,y3,ch);
    drawLine(x3,y3,x1,y1,ch);
}

/* Draw Circle */
void drawCircle(int xc,int yc,int r,char ch)
{
    for(int angle=0;angle<360;angle++)
    {
        double rad=angle*3.14159265/180.0;

        int x=xc+r*cos(rad);
        int y=yc+r*sin(rad);

        plot(x,y,ch);
    }
}

/* Clear Picture */
void clearCanvas()
{
    initCanvas();
}

int main()
{
    int choice;

    initCanvas();

    while(1)
    {
        printf("\n===== DRAWING PROGRAM =====\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Line\n");
        printf("6. Delete Rectangle\n");
        printf("7. Delete Triangle\n");
        printf("8. Delete Circle\n");
        printf("9. Display Picture\n");
        printf("10. Clear Picture\n");
        printf("11. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int x1,y1,x2,y2;
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

                drawLine(x1,y1,x2,y2,'*');
                break;
            }

            case 2:
            {
                int x,y,w,h;
                printf("Enter x y width height: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);

                drawRectangle(x,y,w,h,'#');
                break;
            }

            case 3:
            {
                int x1,y1,x2,y2,x3,y3;

                printf("Enter x1 y1: ");
                scanf("%d%d",&x1,&y1);

                printf("Enter x2 y2: ");
                scanf("%d%d",&x2,&y2);

                printf("Enter x3 y3: ");
                scanf("%d%d",&x3,&y3);

                drawTriangle(x1,y1,x2,y2,x3,y3,'+');
                break;
            }

            case 4:
            {
                int xc,yc,r;

                printf("Enter center x y and radius: ");
                scanf("%d%d%d",&xc,&yc,&r);

                drawCircle(xc,yc,r,'O');
                break;
            }

            case 5:
            {
                int x1,y1,x2,y2;
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

                drawLine(x1,y1,x2,y2,' ');
                break;
            }

            case 6:
            {
                int x,y,w,h;
                printf("Enter x y width height: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);

                drawRectangle(x,y,w,h,' ');
                break;
            }

            case 7:
            {
                int x1,y1,x2,y2,x3,y3;

                printf("Enter x1 y1: ");
                scanf("%d%d",&x1,&y1);

                printf("Enter x2 y2: ");
                scanf("%d%d",&x2,&y2);

                printf("Enter x3 y3: ");
                scanf("%d%d",&x3,&y3);

                drawTriangle(x1,y1,x2,y2,x3,y3,' ');
                break;
            }

            case 8:
            {
                int xc,yc,r;

                printf("Enter center x y and radius: ");
                scanf("%d%d%d",&xc,&yc,&r);

                drawCircle(xc,yc,r,' ');
                break;
            }

            case 9:
                displayCanvas();
                break;

            case 10:
                clearCanvas();
                printf("Canvas Cleared!\n");
                break;

            case 11:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
