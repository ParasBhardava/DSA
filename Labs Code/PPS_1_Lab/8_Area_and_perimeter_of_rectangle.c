#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct point
{ 
        int x, y;
}pt;

typedef struct rectangle
{
         pt pt1;
         pt pt2;
}rect;

int can_rect_be_found(rect r)
    {
    if(r.pt1.x == r.pt2.x || r.pt1.y == r.pt2.y)
        return 0;
    return 1;
    }

int area_of_rectangle(rect r)
    {
        if(!can_rect_be_found(r))
            return -1;
        else
            return abs((r.pt1.x - r.pt2.x)*(r.pt1.y - r.pt2.y));
    }

int perimeter_of_rectangle(rect r)
    {
    
    if(!can_rect_be_found(r))
            return -1; 
        else
            return 2*(abs(r.pt1.x - r.pt2.x) + abs(r.pt1.y - r.pt2.y));
    }

int main()
{
    rect r;
    scanf("%d, %d %d, %d", &r.pt1.x, &r.pt1.y, &r.pt2.x, &r.pt2.y);
    
    
    int area = area_of_rectangle(r);
    printf("%d\n", area);
    if(area != -1)
    printf("%d", perimeter_of_rectangle(r));
    
    return 0;
}