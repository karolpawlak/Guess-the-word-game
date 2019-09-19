//Karol Pawlak

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "word_game.h"

int main()
{
    char  current_letters[] = {'b', 'e', 'l', 'l'};
    char target_letters[] = {'c', 'o', 'a', 't'};
    const int NUMBER_OF_LETTERS = 4;

    void start_game(char* pCurrent, char* pTarget, const int size_of_word)
    {
        char userInput;
        char enter;
        int position_of_cursor = 0;
        bool game_finished = false;
        int number_of_letter_changes = 0;
        int number_of_cursor_changes = 0;
        //char arrayOfWords[(size_of_word*2)*(sizeof(pTarget))]; //allocate 32 bytes for this array ( 8 by 4 )
        while (game_finished == false)
        {
            printf("\n---Game State ---\n");
            printf("Target is ");
            display_target_letters(pTarget, size_of_word);
            printf("\n-----------------\n");
            display_game_state (pCurrent, size_of_word, position_of_cursor, number_of_letter_changes);

            userInput = get_user_char();

            if (userInput == '>')
            {
                int cursorCopy = position_of_cursor;
                move_cursor_right(&position_of_cursor, size_of_word);
                if (cursorCopy != position_of_cursor)
                {
                    number_of_cursor_changes++;
                }
            }
            else if (userInput == '<')
            {
                int cursorCopy = position_of_cursor;
                move_cursor_left(&position_of_cursor);
                if (cursorCopy != position_of_cursor)
                {
                    number_of_cursor_changes++;
                }
            }
            else if (userInput >= 'a' && userInput <= 'z')
            {
                change_letter(pCurrent, position_of_cursor, userInput, NUMBER_OF_LETTERS);
                number_of_letter_changes++;
            }
            else
            {
                printf("\nERROR - Please enter either an arrow or a letter from a to z.");
            }

            bool result = compare_letters(pCurrent, pTarget, NUMBER_OF_LETTERS);
            int number_of_guesses = compare_letters_getGuesses(pCurrent, pTarget, NUMBER_OF_LETTERS);
            int arraySize = size_of_word;
            //printf("Size of array %d", arraySize);
            printf("You have %d letters that match the target!", number_of_guesses);
            int maxAttempts = (arraySize * 2);
            int maxCursorMoves = maxAttempts;
            if (result == true)
            {
                printf("\nYou won!\nYou guessed the word!");
                game_finished = true;
            }
            else if (number_of_letter_changes == maxAttempts)
            {
                printf("\nGame Over!\nYou ran out of attempts!");
                game_finished = true;
            }
            else if (number_of_cursor_changes == maxCursorMoves)
            {
                printf("\nGame Over!\nYou ran out of moves!");
                game_finished = true;
            }

        }
    }

    start_game(current_letters, target_letters, NUMBER_OF_LETTERS);



    //display_game_state (current_letters, NUMBER_OF_LETTERS, position_of_cursor, number_of_letter_changes);
    /*
    move_cursor_right(&position_of_cursor, NUMBER_OF_LETTERS);

    move_cursor_left(&position_of_cursor);
    display_game_state (current_letters, NUMBER_OF_LETTERS, position_of_cursor, number_of_letter_changes);

    change_letter(current_letters, position_of_cursor, command, NUMBER_OF_LETTERS);
    display_game_state (current_letters, NUMBER_OF_LETTERS, position_of_cursor, number_of_letter_changes);

    bool result = compare_letters(current_letters, target_letters, NUMBER_OF_LETTERS);

    printf("\n%d", result);
    */

}
