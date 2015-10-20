/*
 File name: DeckOfCards_A3_main.c
 
 Disclaimer: I hereby certify that this collective work is my own
 and none of it is the work of any other person or entity.
 
 Created by Alicia Rodriguez.
 Panther ID: 5162522
 Due date: 10/22/15 @ 6:25PM
 
 Description: The main function file which prompts the user for the number
 of cards and hands (players) and checks if the input is valid; otherwise, repeat.
 
 */

#include "DeckOfCards_A3.h"

/* Main function which validates user input. */
int main(int argc, char const *argv[])
{

    if(argc == ARG_NUM)
    {
        printf("Initializing the game of cards...\n\n");
    } else {
        printf("Please begin to run the program with 2 arguments. \n");
        printf("The first argument is the number of players, and the \n");
        printf("second is the number of cards for each players.\n\n");
    }
    
    
    return 0;
}