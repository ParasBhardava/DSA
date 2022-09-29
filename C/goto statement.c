#include<stdio.h>

int main()
{
    label:

    printf("We are inside label\n");
    //goto end;
    printf("Hello World\n");
    //goto end;
    goto label;
    end:
        printf("We are at end\n");

    /*int num;
    for(int i=0; i < 8; i++)
    {
        printf("%d.", i);
        for(int j =0; j<8; j++)
        {
            printf("Enter the number. Enter 0 to exit\n");
            scanf("%d", &num);
            if (num==0)
            {
                //break;
                goto end;
            }
        }
    }
end:*/

    return 0;
}
