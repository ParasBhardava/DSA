#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int greater(char c1, char c2)
{
    if (c1 == c2)
        return -1;

    else if ((c1 == 'r') && (c2 == 'p'))
        return 0;

    else if ((c1 == 'p') && (c2 == 'r'))
        return 1;

    else if ((c1 == 'r') && (c2 == 's'))
        return 1;

    else if ((c1 == 's') && (c2 == 'r'))
        return 0;

    else if ((c1 == 'p') && (c2 == 's'))
        return 0;

    else if ((c1 == 's') && (c2 == 'p'))
        return 1;
}

int main()
{
    int playerscore = 0, compscore = 0, temp;
    char dict[] = {'r', 'p', 's'}, playerchar, compchar;
    printf("Welcome to the Rock, Paper and Scissor\n\n");

    for (int i = 0; i < 3; i++)
    {

        printf("Choose 1 for Rock, 2 for Paper and 3 for Scissor\n");
        printf("Player 1's Turn: ");
        scanf("%d", &temp);
        getchar();
        playerchar = dict[temp - 1];
        printf("You Choose %c\n\n", playerchar);

        printf("Computer's Turn:\n");
        printf("Choose 1 for Rock, Choose 2 for Paper and 3 for Scissor\n");
        temp = generateRandomNumber(3) + 1;
        compchar = dict[temp - 1];
        printf("CPU choose %c\n\n", compchar);

        if (greater(compchar, playerchar) == 1)
        {
            compscore += 1;
            printf("CPU got it!\n");
        }
        else if (greater(compchar, playerchar) == -1)
        {
            compscore += 1;
            playerscore += 1;
            printf("It's a draw\n");
        }

        else
        {
            playerscore += 1;
            printf("You got it\n");
        }

        printf("You: %d\nCPU: %d\n\n", playerscore, compscore);
    }

    if (playerscore > compscore)
        printf("You win the game\n");

    else if (playerscore < compscore)
        printf("CPU win the game\n");

    else
        printf("It's a draw\n");

    return 0;
}