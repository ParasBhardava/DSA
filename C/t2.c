#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define INPUT_STRING_LEN 10001
#define OUTPUT_STRING_LEN 20003

void convert_to_pig_latin(char string[])
{
    char input[INPUT_STRING_LEN];
    char current_char = ' ', previous_char;
    char first_character_of_word;
    int input_index = 0, str_index = 0;
    strcpy(input, string);
    while(1)
        {
        previous_char = current_char;
        current_char = input[input_index];
        input_index++;
        if(current_char == ' ' || current_char == '.' || current_char == '\n' ||  current_char == '\0')
            {
            if(previous_char != ' ' && previous_char != '.' && previous_char != '\n')
                {
                string[str_index] = first_character_of_word;
                str_index++;
                string[str_index] = 'l';
                str_index++;
                string[str_index] ='y';
                str_index++;
                }
            string[str_index] = current_char;
            str_index++;
            if(current_char == '\0')
                break;
            }
        
        else
            {
            if(previous_char == ' ' || previous_char == '\n' || previous_char == '.')
            first_character_of_word = current_char;
            
            else
                {
                string[str_index] = current_char;
                str_index++;
                }
             }
          }
}

int main()
{
    int i=0;
    char str[OUTPUT_STRING_LEN];
    gets(str);
    // while(1)
    //     {
    //     str[i] = getchar();
    //     if(str[i] == EOF)
    //         {
    //         str[i] = '\0';
    //         break;
    //         }
    //     i++;
    //     }
    
    convert_to_pig_latin(str);
    printf("%s", str);
    
    return 0;
}
