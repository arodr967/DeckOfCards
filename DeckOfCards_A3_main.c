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
int void main()
{
    int numberOfCards;	/* User input for the number of cards per player? */
    int numberOfHands; 	/* User input for the number of hands/players. */
    char buffer;
    
    do {
        printf("\n");
        printf("Please choose the number of players. (2-13 players)");
        scanf("%d", &numberOfHands);
        
        printf("\n");
        
        if (numberOfHands >= MIN && numberOfHands <= LIMIT)
        {
            printf("Initializing %d players...", numberOfHands);
            
        } else {
            printf("Your input is incorrect. Please try again. \n");
            while((buffer = getchar()) != '\n' && buffer != EOF);
        }
        
    } while ();
        
    return 0;
}