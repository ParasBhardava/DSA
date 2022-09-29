#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int strcicmp(char const *p, char const *q)
{
    for (;; p++, q++) {
        int l = tolower((unsigned char)*p) - tolower((unsigned char)*q);
        if (l != 0 || !*q)
            return l;
    }
}

void sort(char **names,int number)
{
    char a[200],aname[200];
    for(int i=-1;i<number;i++)
    {
        fgets(a,200,stdin);
        int len=strlen(a);
        if(i<number-1)
        a[len-1]='\0';
           if(i>-1)
           {
            strcpy(names[i],a);
            strcpy(aname,names[i]);
            }
    }
    for(int i=1;i<number;i++)
    {
        for(int j=1;j<number;j++)
        {
           if(strcicmp(names[j-1],names[j])>0)
           {
               strcpy(aname,names[j-1]);
               strcpy(names[j-1],names[j]);
               strcpy(names[j],aname);
            }
        }
    } 
    printf("%d\n",number);
    for(int i=0;i<number;i++)
       printf("%s\n",names[i]);
}

int main()
{
    int number;
    scanf("%d",&number);
    
    char **names=(char**) calloc(number,sizeof(char*));
    for(int i=0;i<number;i++)
    {
        names[i] = (char*) calloc(200,sizeof(char));
    }
    
    sort(names,number);
    
    for(int i=0;i<number;i++)
    {
        free(names[i]);
    }
    free(names);
    
    return 0;
}