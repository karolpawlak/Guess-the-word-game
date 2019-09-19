//Karol Pawlak

#include <stdio.h>
#include <stdbool.h>

void display_game_state(char* pCurrent_letters,const int NUMBER_OF_LETTERS, const int cursor_position, const int number_of_letter_changes)
{
 	for(int i = 0; i < NUMBER_OF_LETTERS; i++)
    {
        printf("%c", *pCurrent_letters);
        *pCurrent_letters++;
    }
    const char DASH = '-';
    const char SPACE = ' ';
    printf("\n");
    for(int i = 0; i < cursor_position; i++)
    {
        printf("%c", SPACE);
    }
    printf("%c", DASH);
    printf("\nChanges: %d\n\n", number_of_letter_changes);
}

void display_target_letters(char* pTarget_letters, const int size_of_word)
{
    for (int j = 0; j < size_of_word; j++)
    {
        printf("%c", *pTarget_letters);
        *pTarget_letters++;
    }
}

void move_cursor_right(int* pPosition_of_cursor, const int max)
{
    if (*pPosition_of_cursor < (max - 1))
    {
        *pPosition_of_cursor = (*pPosition_of_cursor) + 1;
    }
    else
    {
        printf("\nERROR - Cursor out of bounds.");
    }
}

void move_cursor_left(int* pPosition_of_cursor)
{
    if (*pPosition_of_cursor > 0)
    {
        *pPosition_of_cursor = (*pPosition_of_cursor) - 1;
    }
    else
    {
        printf("\nERROR - Cursor out of bounds.");
    }
}

void change_letter(char* pLetters, int position, char new_letter, int max)
{
    char* plocation_of_letter_to_change = pLetters + position;
    *plocation_of_letter_to_change = new_letter;
}

//compare_letters returns 1 if letters are the same in both arrays and 0 if they're not
bool compare_letters(char* pStart_letters, char* pTarget_letters, int size_of_array)
{
    int array_size = size_of_array;
    //printf("Size of array inside compare_letters %d", array_size);
    int counter_of_correct_guesses = 0;
    for (int i = 0; i < array_size;i++)
    {
        //printf("\n%c %c", *pStart_letters , *pTarget_letters);

        if (*pStart_letters == *pTarget_letters)
        {
            counter_of_correct_guesses++;
        }

        if (counter_of_correct_guesses == array_size)
        {
            return true;
        }
        pStart_letters++;
        pTarget_letters++;
    }
    return false;
}

int compare_letters_getGuesses(char* pStart_letters, char* pTarget_letters, int size_of_array)
{
    int counter_of_correct_guesses = 0;
    int array_size = size_of_array;
    for (int i = 0; i < array_size;i++)
    {
        if (*pStart_letters == *pTarget_letters)
        {
            counter_of_correct_guesses++;
        }
        pStart_letters++;
        pTarget_letters++;
    }
    return counter_of_correct_guesses;
}

char get_user_char() {
    //1. We create the output variable with the value the user has input by keyboard
    printf("\nEnter command: ");
    char res = getchar();

    //2. We discard any extra character the user has input by keyboard
    bool finish = false;
    char dummy_char = ' ';

    while (finish == false) {
        dummy_char = getchar();
        if (dummy_char == '\n')
            finish = true;
    }

    //3. We return the output variable
    return res;
}

