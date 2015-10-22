/*
 File name: DeckOfCards_A3_main.c
 
 Disclaimer: I hereby certify that this collective work is my own
 and none of it is the work of any other person or entity.
 
 Created by Alicia Rodriguez.
 
 Description: The main function file which prompts the user for the number
 of cards and hands (players) and checks if the input is valid; otherwise, repeat.
 
 */

#include "DeckOfCards_A3.h"

/* Main function which validates user input. */
int main(int argc, char *argv[])
{
    struct deck gameOfCards, *point = &gameOfCards; /* Create a deck and a pointer
                                                     to the address of the deck */
    
    int numberOfCards, numberOfPlayers;
    
    if(argc == ARG_NUM)     /* There will only be 3 accepted arguments in this 
                             deck of cards */
    {
        numberOfCards = atoi(argv[INPUT_CARD]);
        numberOfPlayers = atoi(argv[INPUT_PLAYER]);
        
        if(validateInput(numberOfCards, numberOfPlayers)) /* If the validateInput function returns
                                               a 1 then the inputs were correct and the 
                                               game of cards can begin */
        {
            printf("Initializing the game of cards...\n\n");
            printf("The following is the complete deck of cards:");
            
            gameOfCards = createDeck();
            printDeck(point);
            
            deal(numberOfCards, numberOfPlayers);
            
        }
        
    } else { /* Otherwise, inform the user that they need 2 arguments. */
        printf("Please begin to run the program with 2 arguments. \n");
        printf("The first argument is the number of cards for each player,\n");
        printf("and the second is the number of players.\n\n");
    }
    
    return 0;
}
