/*
 File name: DeckOfCards_A3.h
 
 Description: Header file.
 
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
#define PLAYER_MIN 2 /* Minumum number of players */

#define CARD_MAX 13 /* Maximum number of cards */
#define CARD_MIN 1 /* Minumum number of cards */

#define ARG_NUM 3 /* Validating that the correct number of arguments passed */
#define INPUT_CARD 1 /* The first argument inputted by the user which is the number of cards per player */
#define INPUT_PLAYER 2 /* The second argument inputted by the user which is the number of players */

#define CARD_NUM "N"
#define CARD_ACE 1
#define CARD_JACK 11
#define CARD_QUEEN 12
#define CARD_KING 13

#define FALSE 0
#define TRUE 1

/* Codes for the suits */
#if defined(_WIN32) || defined(_MSDOS_)
#define SPADE	"\x06"
#define CLUB	"\x05"
#define HEART	"\x03"
#define DIAMOND	"\x04"
#else
#define SPADE	"\xe2\x99\xa4"
#define CLUB	"\xe2\x99\xa7"
#define HEART	"\xe2\x99\xa5"
#define DIAMOND	"\xe2\x99\xa6"
#endif

/* Prototypes: */

int validateInput(char *arg1, char *arg2);
struct deck createDeck();
void shuffle(struct deck *card);
void printDeck(struct deck *point);
void sortHand(); /* Extra credit */
char* getCardRank(int num);
int getRandom(); /* Get a random number in order to shuffle the cards */
void quickSort(int card[], int left, int right);
void swap(int card[], int i, int j);
void deal(char *arg1, char *arg2);

/* Structs: */

struct card {
    char *suit;
    char *rank;
    int index; /* For extra credit */
};

struct deck {
    struct card deckOfCards[CARD_TOTAL];
};

#endif /* DeckOfCards_A3_h */
