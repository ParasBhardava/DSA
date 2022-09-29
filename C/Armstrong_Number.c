#include <stdio.h>

// 153 = (1*1*1) + (5*5*5) + (3*3*3)   ---> This nmber is called Armstrong number
int armstrong(int num)
{
    int ans = 0;
    while (num != 0)
    {
        int remainder = num % 10;
        ans += (remainder * remainder * remainder);
        num = num / 10;
    }

    return ans;
}

int main()
{
    int num;
    scanf("%d", &num);

    
   if (num == armstrong(num))
   {
        printf("Given number is an Armstrong number");
    }

    else
    {
        printf("Given number is not an Armstrong nummber");
    }

    return 0;
}