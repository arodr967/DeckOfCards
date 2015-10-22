/*
    File name: DeckOfCards_A3_deck.c
    
    Description: The deck file which includes all of the functions to implement the deck.
 */

#include "DeckOfCards_A3.h"


/* validateInput function which will validate the user's input and make sure that
 it is valide by calculating the total number of cards from the inputs and making
 sure that there are enough cards to play the game. */
int validateInput(int numberOfCards, int numberOfPlayers)
{
    int total = numberOfCards * numberOfPlayers;
    
    printf("Number of cards per player: %d and number of players: %d\n\n", numberOfCards, numberOfPlayers);
    printf("The total number of cards is %d\n\n", total);
    
    if (((total > CARD_TOTAL) || (total == 0)))
    {
        printf("There are only %d cards in total available. Please try again.\n\n", CARD_TOTAL);
        return FALSE; //invalid input
    }
    else if ((numberOfPlayers < PLAYER_MIN) || (numberOfPlayers > PLAYER_MAX))
    {
        printf("There can only be a minimum of %d players and a maximum of %d players. Please try again.\n\n", PLAYER_MIN, PLAYER_MAX);
        return FALSE; //invalid input
    }
    else if ((numberOfCards < CARD_MIN) || (numberOfCards > CARD_MAX))
    {
        printf("There can only be a minimum of %d card and a maximum of %d cards. Please try again.\n\n", CARD_MIN, CARD_MAX);
        return FALSE; //invalid input
    } else {
        printf("Your input is valid.\n\n");
        return TRUE; //valid input
    }
}

/* createDeck function which creates a full deck. */
struct deck createDeck()
{
    /* Create an array of char pointers to the Unix suits. */
    char *suits[NUMBER_OF_SUITS] = {SPADE, CLUB, HEART, DIAMOND};
    
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

/* deal function which accepts the 2 arguments passed by the command-line, already converted
 to int, and then deal and display the cards. */
void deal(int numberOfCards, int numberOfPlayers)
{
    int i, j, currentCard = 0, currentPlayer = 1;
    
    printf("\n\nReady to deal %d card(s) to %d player(s)...\n\n", numberOfCards, numberOfPlayers);

    struct deck cardDeck, *point = &cardDeck;
    cardDeck = createDeck(); /* Create the cardDeck with all cards */
    
    shuffle(point);
    printDeck(point);
    
    struct card *players[numberOfPlayers];
    
    printf("\n");
    
    for(i = 0; i < numberOfPlayers; ++i)
    {
        printf("Player %d has card(s): \n", currentPlayer);
        if (numberOfCards > 1) /* If numberOfCards is greater than 1 then we must display
                                all of the cards the players have */
        {
            for (j = 0; j < numberOfCards; ++j)
            {
                players[j] = &cardDeck.deckOfCards[currentCard];
                printf("[%s %2s] ", players[j]->suit, players[j]->rank);
                // sort the hands here and display again
                
//                quickSort(*players, 0, numberOfPlayers-1);
//                
//                printf("[%s %2s] ", players[j]->suit, players[j]->rank);
                
                currentCard++;
            }
        } else { /* Otherwise, the number of cards is 1. */
            
            players[i] = &cardDeck.deckOfCards[currentCard];
            printf("[%s %2s] ", players[i]->suit, players[i]->rank);
            // sort the hands here and display again
            
            currentCard++;
        }
        currentPlayer++;
        printf("\n");
    }
    printf("\n");
}

/* getRandom method which will get a random number in order to shuffle the cards */
int getRandom()
{
    srand(clock() * CARD_TOTAL + clock());
    return rand() % CARD_TOTAL;
}

/* sortHand function which sorts the cards that each player has by rank. */
void sortHand()
{
    printf("Sorted");
}

/* quickSort recursive function to sort the hands. */
//void quickSort(struct deck *players, int left, int right)
//{
//    int i, last;
//    void swap(struct deck *players, int i, int j);
//    
//    if (left >= right) /* If the array contains fewer than 2 elements,
//                        then just return the function as it is and do nothing. */
//    {
//        return;
//    }
//    
//    swap(players, left, ((left + right)/2)); /* Move partition element to card[0] */
//    last = left;
//    
//    for (i = left+1; i <= right; i++) /* Partition */
//    {
//        if (players->deckOfCards[i] < players->deckOfCards[left])
//        {
//            swap(players, ++last, i);
//        }
//    }
//    
//    swap(players, left, last);     /* Restore the partitioned element */
//    quickSort(players, left, last-1);
//    quickSort(players, last+1, right);
//}

/* swap function for the quickSort function. */
//void swap(struct deck *players, int i, int j)
//{
//    struct deck temp = players->deckOfCards[i];
//    
//    players->deckOfCards[i] = players->deckOfCards[j];
//    players->deckOfCards[j] = temp;
//}