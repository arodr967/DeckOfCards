/*
 File name: DeckOfCards_A3.h
 
 Description: Header file which contains all of the constants, libraries, structures, and prototypes.
 
 */

#ifndef DeckOfCards_A3_h
#define DeckOfCards_A3_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARD_TOTAL 52
#define NUMBER_OF_VALUES 13
#define NUMBER_OF_SUITS 4

#define PLAYER_MAX 13 /* Maximum number of players */
#define PLAYER_MIN 1 /* Minimum number of players */

#define CARD_MAX 13 /* Maximum number of cards */
#define CARD_MIN 1 /* Minimum number of cards */

#define ARG_NUM 3 /* Validating that the correct number of arguments passed */
#define INPUT_CARD 1 /* The first argument inputied by the user which is the number of cards per player */
#define INPUT_PLAYER 2 /* The second argument inputted by the user which is the number of players */

#define CARD_NUM "N"
#define CARD_ACE 1
#define CARD_JACK 11
#define CARD_QUEEN 12
#define CARD_KING 13

#define FALSE 0
#define TRUE 1

/* Display corresponding letter for each suit */
#define SPADE	"S"
#define CLUB	"C"
#define HEART	"H"
#define DIAMOND	"D"

/* Structures: */

struct card {
    char *suit;
    char *rank;
};

struct deck {
    struct card deckOfCards[CARD_TOTAL];
};

/* Prototypes: */

int validateInput(int numberOfCards, int numberOfPlayers);
struct deck createDeck();
void shuffle(struct deck *shuff);
void printDeck(struct deck *point);
char* getCardRank(int num);
int getRandom(); /* Get a random number in order to shuffle the cards */
void deal(int numberOfCards, int numberOfPlayers);
void printHands(int numberOfCards, int numberOfPlayers, struct deck *players);

#endif /* DeckOfCards_A3_h */
