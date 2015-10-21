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
    struct deck gameOfCards, *point = &gameOfCards; /* Create a deck and a pointer
                                                     to the address of the deck */
    if(argc == ARG_NUM)     /* There will only be 3 accepted arguments in this 
                             deck of cards */
    {
        if(validateInput(argv[1], argv[2])) /* If the validateInput function returns
                                               a 1 then the inputs were correct and the 
                                               game of cards can begin */
        {
            printf("Initializing the game of cards...\n\n");
            printf("The following is the complete deck of cards:");
            
            gameOfCards = createDeck();
            printDeck(point);
            
            deal(argv[1], argv[2]);
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
        
    } else { /* Otherwise, inform the user that they need 2 arguments. */
        printf("Please begin to run the program with 2 arguments. \n");
        printf("The first argument is the number of cards for each player,\n");
        printf("and the second is the number of cards.\n\n");
    }
    
    return 0;
}

/* validateInput function which will validate the user's input and make sure that 
 it is valide by calculating the total number of cards from the inputs and making
 sure that there are enough cards to play the game. */
int validateInput(char *arg1, char *arg2)
{
    int numberOfCards = atoi(arg1);
    int numberOfPlayers = atoi(arg2);
    
    int total = numberOfCards * numberOfPlayers;
    
    printf("Number of cards per player: %d and number of players: %d\n\n", numberOfCards, numberOfPlayers);
    printf("The total number of cards is %d\n\n", total);
    
    if (((total > CARD_TOTAL) || (total == 0)))
    {
        printf("There are only %d cards in total available. Please try again.\n\n", CARD_TOTAL);
        return 0; //false: invalid input
    }
    else if ((numberOfPlayers < PLAYER_MIN) || (numberOfPlayers > PLAYER_MAX))
    {
        printf("There can only be a minimum of %d players and a maximum of %d players. Please try again.\n\n", PLAYER_MIN, PLAYER_MAX);
        return 0; //false: invalid input
    }
    else if ((numberOfCards < CARD_MIN) || (numberOfCards > CARD_MAX))
    {
        printf("There can only be a minimum of %d card and a maximum of %d cards. Please try again.\n\n", CARD_MIN, CARD_MAX);
        return 0; //false: invalid input
    } else {
        printf("Your input is valid.\n\n");
        return 1; //true: valid input
    }
}

/* createDeck function which creates a full deck. */
struct deck createDeck()
{
    /* Create an array of char pointers to the Unix suits. */
    char *suits[NUMBER_OF_SUITS] = {HEARTS, SPADES, CLOVERS, DIAMONDS};
    
    int forSuits, forNum, counter = 0;
    struct deck theDeck;
    
    for (forSuits = 0; forSuits < NUMBER_OF_SUITS; ++forSuits)
    {
        for (forNum = 1; forNum <= NUMBER_OF_VALUES; ++forNum)
        {
            theDeck.deckOfCards[counter].suit = suits[forSuits];
            theDeck.deckOfCards[counter].rank = getCardRank(forNum);
            
            counter++;
        }
        printf("\n");
    }
    
    return theDeck;
}

/* printDeck function which prints the deck in formatted output with the suit symbols */
void printDeck(struct deck *point)
{
    int forSuits, forNum, counter = 0;
    
    /* For loop, which creates the grades in a form of a table. */
    for (forSuits = 0; forSuits < NUMBER_OF_SUITS; ++forSuits)
    {
        for (forNum = 1; forNum <= NUMBER_OF_VALUES; ++forNum)
        {
            printf("[%s %2s]", point->deckOfCards[counter].suit, point->deckOfCards[counter].rank);
            counter++;
        }
        printf("\n");
    }
}

/* getCardRank method which will test for the cards that are ACE, JACK, QUEEN,
 and KING, and print it's corresponding letter, instead of the number. */
char* getCardRank(int num)
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
    
    for(i = 0; i < CARD_TOTAL; ++i)
    {
        random = getRandom();
        struct card tempCard = shuff->deckOfCards[i];
        
        //Swap
        shuff->deckOfCards[i] = shuff->deckOfCards[random];
        shuff->deckOfCards[random] = tempCard;

    }
    
    printf("The deck has been shuffled...\n\n");
    
}

/* deal function which accepts the 2 arguments passed by the command-line.
 IDEA: Create an array of players, player[0] is player 1, and in there, is where they
 should have their own cards */
void deal(char *arg1, char *arg2)
{
    int numberOfCards = atoi(arg1);
    int numberOfPlayers = atoi(arg2);
    int i, j, currentCard = 0, currentPlayer = 1;
    //struct deck *players[numberOfPlayers];
    
    if (numberOfCards > 1) {
        printf("\n\nReady to deal %d cards to %d players...\n\n", numberOfCards, numberOfPlayers);
    } else {
        printf("\n\nReady to deal %d card to %d players...\n\n", numberOfCards, numberOfPlayers);
    }
    
    struct deck cardDeck, *point = &cardDeck;
    cardDeck = createDeck(); /* Create the playerDeck with all cards */
    shuffle(point); /* Shuffle all of the cards in the playerDeck */
    
    printDeck(point);
    printf("\n\n");
    
    struct card *players[numberOfPlayers];
    
    for(i = 0; i < numberOfPlayers; ++i)
    {
        if (numberOfCards > 1) /* If numberOfCards is greater than 1 then we must display 
                                all of the cards the players have */
        {
            for (j = 0; j < numberOfCards; ++j)
            {
                players[j] = &cardDeck.deckOfCards[currentCard];
                printf("Player %d has [%s %2s] card.\n", currentPlayer, players[j]->suit, players[j]->rank);
                currentCard++;
            }
        } else { /* Otherwise, the number of cards is 1. */
            
            players[i] = &cardDeck.deckOfCards[currentCard];
            printf("Player %d has [%s %2s] card.\n", currentPlayer, players[i]->suit, players[i]->rank);
            currentCard++;
        }
        currentPlayer++;
    }
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

/* quickSort recursive function to sort the hands. */
void quickSort(int card[], int left, int right)
{
    int i, last;
    void swap(int card[], int i, int j);
    
    if (left >= right) /* If the array contains fewer than 2 elements,
                        then just return the function as it is and do nothing. */
    {
        return;
    }
    
    swap(card, left, ((left + right)/2)); /* Move partition element to card[0] */
    last = left;
    
    for (i = left+1; i <= right; i++) /* Partition */
    {
        if (card[i] < card[left])
        {
            swap(card, ++last, i);
        }
    }
    swap(card, left, last);     /* Restore the partitioned element */
    quickSort(card, left, last-1);
    quickSort(card, last+1, right);
}

/* swap function for the quickSort function. */
void swap(int card[], int i, int j)
{
    int temp;
    
    temp = card[i];
    card[i] = card[j];
    card[j] = temp;
}


