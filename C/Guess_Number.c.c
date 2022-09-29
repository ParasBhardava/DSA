#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int original_num = rand()%100 + 1; // Generate random number between 1 to 100
    int guess_num, attempts = 1;
    // printf("%d\n", original_num);

    // keep running the loop until the number is guessed
    
    printf("\nGuess the number between 1 and 100\n");
    do
    {
        scanf("%d", &guess_num);

        if (guess_num < original_num)
            printf("\nHigher number please !\n");

        else if (guess_num > original_num)
            printf("\nLower number please !\n");

        if (guess_num == original_num)
            printf("\nYou guessed it in %d attempts\n\n", attempts);
        
        attempts++;
    } while (guess_num != original_num);

        return 0;
}
