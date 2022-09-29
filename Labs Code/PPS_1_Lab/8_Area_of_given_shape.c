#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14

typedef struct point
{
    int x, y;
}pt;

typedef struct rectangle
{
    char name[20];
    pt pt1;
    pt pt2;
}rect;

typedef struct circle
{
    char name[20];
    pt centre;
    int radius;
}cl;

typedef union shape
{
    rect r;
    cl c;
}sh;

int area_of_rectangle(rect r)
{
    scanf(" {{%d",&r.pt1.x);
    scanf(",%d",&r.pt1.y);
    scanf("},{%d",&r.pt2.x);
    scanf(",%d}}",&r.pt2.y);
     
    int length = abs((r.pt2.x)-(r.pt1.x));
    int width = abs((r.pt2.y)-(r.pt1.y));
    printf("%d.00\n", (length*width));
   
    return 0;   
}

float area_of_circle(cl c)
{   
    scanf(" {{%d",&c.centre.x);
    scanf(",%d",&c.centre.y);
    scanf("},%d}",&c.radius);
    printf("%.2f\n", (PI * (c.radius)*(c.radius)));
    
    return 0;
}

float calculate_area(sh shapes[], int num_of_inputs)
{
    for(int i=0;i<num_of_inputs;i++)
    {
        scanf("%s",shapes[i].r.name);
        
        if(!(strcmp(shapes[i].r.name,"rectangle")))  
            area_of_rectangle(shapes[i].r);
        
        if(!(strcmp(shapes[i].r.name,"circle")))
            area_of_circle(shapes[i].c);
    }
    return 0;
}

int main()
{    
    int num_of_inputs;
    scanf("%d",&num_of_inputs);
    
    sh shapes[num_of_inputs];
    printf("%d\n",num_of_inputs);
    
    calculate_area(shapes, num_of_inputs);
    
    return 0;
}