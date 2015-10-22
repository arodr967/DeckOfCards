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
    
    printf("\n\nNumber of cards per player: %d and number of players: %d\n\n", numberOfCards, numberOfPlayers);
    printf("The total number of card(s) is %d.\n\n", total);
    
    if (((total > CARD_TOTAL) || (total == 0)))
    {
        printf("There are only %d cards in total available. Please try again.\n\n", CARD_TOTAL);
        return FALSE; //invalid input
    }
    else if ((numberOfPlayers < PLAYER_MIN) || (numberOfPlayers > PLAYER_MAX))
    {
        printf("There can only be a minimum of %d player(s) and a maximum of %d players. Please try again.\n\n", PLAYER_MIN, PLAYER_MAX);
        return FALSE; //invalid input
    }
    else if ((numberOfCards < CARD_MIN) || (numberOfCards > CARD_MAX))
    {
        printf("There can only be a minimum of %d card(s) and a maximum of %d cards. Please try again.\n\n", CARD_MIN, CARD_MAX);
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
    
    //theDeck.deckOfCards[CARD_TOTAL].index[CARD_TOTAL];
    
    for (forSuits = 0; forSuits < NUMBER_OF_SUITS; ++forSuits)
    {
        for (forNum = 1; forNum <= NUMBER_OF_VALUES; ++forNum)
        {
            theDeck.deckOfCards[counter].suit = suits[forSuits];
            theDeck.deckOfCards[counter].rank = getCardRank(forNum);
            //theDeck.deckOfCards[counter].index = counter;
            
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

/* shuffle function which will shuffle the deck of cards */
void shuffle(struct deck *shuff)
{
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

/* deal function which accepts the 2 arguments passed by the command-line, 
 already converted to int, create a new deck, shuffle the deck, print the deck, then deal and display the cards that each player has. */
void deal(int numberOfCards, int numberOfPlayers)
{
    
    
    int forPlayer, forCard, currentCard = 0;
    
    printf("\n\nReady to deal %d card(s) to %d player(s)...\n\n", numberOfCards, numberOfPlayers);

    struct deck cardDeck, *point = &cardDeck;
    cardDeck = createDeck(); /* Create the cardDeck with all cards */
    
    shuffle(point);
    printDeck(point);
    
    struct card players[numberOfPlayers];
    struct card *playersPoint;
    
    playersPoint = players;
    
    printf("\n");
    
    for(forPlayer = 0; forPlayer < numberOfPlayers; ++forPlayer)
    {
        if (numberOfCards > 1) /* If numberOfCards is greater than 1 then we must
                                display all of the cards the players have */
        {
            for (forCard = 0; forCard < numberOfCards; ++forCard)
            {
                playersPoint[forCard] = cardDeck.deckOfCards[currentCard];
                
                currentCard++;
            }
        } else { /* Otherwise, the number of cards is 1. */
            
            playersPoint[forPlayer] = cardDeck.deckOfCards[currentCard];
            
            currentCard++;
        }
    }
    
    printf("\n");
    
    printHands(numberOfCards, numberOfPlayers, point);
    
}

/* printHands function which prints the values  */
void printHands(int numberOfCards, int numberOfPlayers, struct deck *players)
{
    int forPlayer, forCard, currentPlayer = 1, counter = 0;
    
    printf("Ready to print the hands...\n");
    
    for(forPlayer = 0; forPlayer < numberOfPlayers; ++forPlayer)
    {
        printf("\nPlayer %d has card(s): \n", currentPlayer);
        
        for(forCard = 1; forCard <= numberOfCards; ++forCard)
        {
            printf("[%s %2s] ", players->deckOfCards[counter].suit, players->deckOfCards[counter].rank);
            counter++;
            
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
