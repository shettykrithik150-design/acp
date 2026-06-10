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
            canvas[i][j]='_';
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

    if(steps==0)
    {
        plot(x1,y1,ch);
        return;
    }

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

/* Clear Canvas */
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
        printf("9. Modify Line\n");
        printf("10. Modify Rectangle\n");
        printf("11. Modify Triangle\n");
        printf("12. Modify Circle\n");
        printf("13. Display Picture\n");
        printf("14. Clear Picture\n");
        printf("15. Exit\n");

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

                drawRectangle(x,y,w,h,'*');
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

                drawTriangle(x1,y1,x2,y2,x3,y3,'*');
                break;
            }

            case 4:
            {
                int xc,yc,r;

                printf("Enter center x y and radius: ");
                scanf("%d%d%d",&xc,&yc,&r);

                drawCircle(xc,yc,r,'*');
                break;
            }

            case 5:
            {
                int x1,y1,x2,y2;

                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

                drawLine(x1,y1,x2,y2,'_');
                break;
            }

            case 6:
            {
                int x,y,w,h;

                printf("Enter x y width height: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);

                drawRectangle(x,y,w,h,'_');
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

                drawTriangle(x1,y1,x2,y2,x3,y3,'_');
                break;
            }

            case 8:
            {
                int xc,yc,r;

                printf("Enter center x y and radius: ");
                scanf("%d%d%d",&xc,&yc,&r);

                drawCircle(xc,yc,r,'_');
                break;
            }

            case 9:
            {
                int ox1,oy1,ox2,oy2;
                int nx1,ny1,nx2,ny2;

                printf("Old x1 y1 x2 y2: ");
                scanf("%d%d%d%d",&ox1,&oy1,&ox2,&oy2);

                drawLine(ox1,oy1,ox2,oy2,'_');

                printf("New x1 y1 x2 y2: ");
                scanf("%d%d%d%d",&nx1,&ny1,&nx2,&ny2);

                drawLine(nx1,ny1,nx2,ny2,'*');
                break;
            }

            case 10:
            {
                int ox,oy,ow,oh;
                int nx,ny,nw,nh;

                printf("Old x y width height: ");
                scanf("%d%d%d%d",&ox,&oy,&ow,&oh);

                drawRectangle(ox,oy,ow,oh,'_');

                printf("New x y width height: ");
                scanf("%d%d%d%d",&nx,&ny,&nw,&nh);

                drawRectangle(nx,ny,nw,nh,'*');
                break;
            }

            case 11:
            {
                int ox1,oy1,ox2,oy2,ox3,oy3;
                int nx1,ny1,nx2,ny2,nx3,ny3;

                printf("Old Triangle Points (x1 y1 x2 y2 x3 y3): ");
                scanf("%d%d%d%d%d%d",
                      &ox1,&oy1,&ox2,&oy2,&ox3,&oy3);

                drawTriangle(ox1,oy1,ox2,oy2,ox3,oy3,'_');

                printf("New Triangle Points (x1 y1 x2 y2 x3 y3): ");
                scanf("%d%d%d%d%d%d",
                      &nx1,&ny1,&nx2,&ny2,&nx3,&ny3);

                drawTriangle(nx1,ny1,nx2,ny2,nx3,ny3,'*');
                break;
            }

            case 12:
            {
                int oxc,oyc,orad;
                int nxc,nyc,nrad;

                printf("Old center x y radius: ");
                scanf("%d%d%d",&oxc,&oyc,&orad);

                drawCircle(oxc,oyc,orad,'_');

                printf("New center x y radius: ");
                scanf("%d%d%d",&nxc,&nyc,&nrad);

                drawCircle(nxc,nyc,nrad,'*');
                break;
            }

            case 13:
                displayCanvas();
                break;

            case 14:
                clearCanvas();
                printf("Canvas Cleared!\n");
                break;

            case 15:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
