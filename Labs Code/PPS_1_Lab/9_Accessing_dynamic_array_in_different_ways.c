#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int rno;
    float cpi;
    char nm[13];
}stu;

int main()
{
    int i=0;
    
    void *v=malloc(5*sizeof(stu));
    
    stu *e=(stu *)v;
    stu *e1=(stu *)v;

    stu (*t) [5]=(stu (*) [5])v;
    
    for(i=0;i<5;i++)
    {
        scanf("%s%d%f",(e+i)->nm,&((e+i)->rno),&((e+i)->cpi) );
    }
                
    for(i=0;i<5;i++)
    {
        printf("%s %d %f\n",(e+i)->nm,(e+i)->rno,(e+i)->cpi); // Pointer and Offset
        
        printf("%s %d %f\n",(&e[i])->nm,(&e[i])->rno,(&e[i])->cpi); // Index Notation
        
        printf("%s %d %f\n",(e[i]).nm,(e[i]).rno,(e[i]).cpi); // Index Notation

        printf("%s %d %f\n",(e1)->nm,(e1)->rno,(e1)->cpi); // Pointer Incrementation
        e1++;

        //Index Notation with Pointer of Memory     
        printf("%s %d %f\n",(&t[0][i])->nm,(&t[0][i])->rno,(&t[0][i])->cpi);
    }
                            
    free(t);

    return 0;
    
}