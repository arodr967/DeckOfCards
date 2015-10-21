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
int main(int argc, char *argv[])
{
    struct deck gameOfCards, *point = &gameOfCards;
    
    //check for argc 2 and 3
    if(argc == ARG_NUM)
    {
        if(validateInput(argv[1], argv[2]))
        {
            printf("Initializing the game of cards...\n\n");
            printf("The following is the complete deck of cards: \n");
            
            gameOfCards = createDeck();
            printDeck(point);
        }
        
        //if(argv [1]) //blahblah
        // enter to create the deck
//        printf("Initializing the game of cards...\n\n");
//        
//        printf("The following is the deck of cards: \n\n");
//        gameOfCards = createDeck();
//        printDeck(point);
//        
//        printf("Shuffling the deck...\n\n");
//        shuffle(point);
//        printDeck(point);
        
    } else {
        printf("Please begin to run the program with 2 arguments. \n");
        printf("The first argument is the number of cards for each player,\n");
        printf("and the second is the number of cards.\n\n");
    }
    
    return 0;
}

int validateInput(char *arg1, char *arg2)
{
    int numberOfCards = atoi(arg1);
    int numberOfPlayers = atoi(arg2);
    
    int total = numberOfCards * numberOfPlayers;
    
    printf("Number of cards per player: %d and number of players: %d\n\n", numberOfCards, numberOfPlayers);
    printf("The total number of cards is %d\n\n", total);
    
    if ((total > CARD_TOTAL) || (total == 0))
    {
        printf("There are only %d cards in total available. Please try again.\n\n", CARD_TOTAL);
        return 0; //false: invalide input
    } else {
        return 1; //true: valide input
    }
}

/* Deck method which creates a method and adds those values in the struct. */
struct deck createDeck()
{
    /* Create an array of char points to the suits. */
    char *suits[NUMBER_OF_SUITS] = {HEARTS, SPADES, CLOVERS, DIAMONDS};
    
    int forSuits, forNum, counter = 0;
    struct deck theDeck;
    
    for (forSuits = 0; forSuits < NUMBER_OF_SUITS; ++forSuits)
    {
        for (forNum = 1; forNum <= NUMBER_OF_VALUES; ++forNum)
        {
            theDeck.deckOfCards[counter].suit = suits[forSuits];
            theDeck.deckOfCards[counter].number = getCardNumber(forNum);
            
            counter++;
        }
        printf("\n");
    }
    
    return theDeck;
}

void printDeck(struct deck *point)
{
    int forSuits, forNum, counter = 0;
    
    for (forSuits = 0; forSuits < NUMBER_OF_SUITS; ++forSuits)
    {
        for (forNum = 1; forNum <= NUMBER_OF_VALUES; ++forNum)
        {
            printf("[%s %2s]", point->deckOfCards[counter].suit, point->deckOfCards[counter].number);
            counter++;
        }
        printf("\n");
    }
    
}

/* isSpecialCard method which will test for the cards that are ACE, JACK, QUEEN,
 and KING, and print it's corresponding letter, instead of the number. */
char* getCardNumber(int num)
{
    switch (num) {
        case CARD_ACE:
            return "A";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "10";
        case CARD_JACK:
            return "J";
        case CARD_QUEEN:
            return "Q";
        case CARD_KING:
            return "K";
        default:
            return CARD_NUM;
    }
}

/* shuffle method which will shuffle the deck of cards */
void shuffle(struct deck *shuff)
{
    // get position 0 of the deckOfCards and then swap whats in there with
    // getRandom number
    
    int random, i;
    //char specialC;
    
    for(i = 0; i < CARD_TOTAL; ++i)
    {
        random = getRandom();
        struct card tempCard = shuff->deckOfCards[i];
        
        //Swap
        shuff->deckOfCards[i] = shuff->deckOfCards[random];
        shuff->deckOfCards[random] = tempCard;

    }
    
    printf("Shuffled");
    
}

/* getRandom method which will get a random number in order to shuffle the cards */
int getRandom()
{
    srand(clock() * CARD_TOTAL + clock());
    return rand() % CARD_TOTAL;
}

void sortHand()
{
    printf("Sorted");
}




