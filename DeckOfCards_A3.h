//
//  DeckOfCards_A3.h
//  
//
//  Created by Alicia Rodriguez on 10/19/15.
//

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

#define CARD_NUM 'N'
#define CARD_ACE 1
#define CARD_JACK 11
#define CARD_QUEEN 12
#define CARD_KING 13

/* Unix based codes for the suits */
#define HEARTS "\xe2\x99\xa5"
#define SPADES "\xe2\x99\xa4"
#define CLOVERS "\xe2\x99\xa7"
#define DIAMONDS "\xe2\x99\xa6"

/* Prototypes: */

struct deck createDeck();
void shuffle(struct deck *card);
void printDeck(struct deck *point);
void sortHand(); /* Extra credit */
char isSpecialCard (int num);
int getRandom(); /* Get a random number in order to shuffle the cards */

/* Structs: */

struct card {
    char *suit;
    int number;
    char specialCard;
    int index; /* For extra credit */
};

struct deck {
    struct card deckOfCards[CARD_TOTAL];
};

#endif /* DeckOfCards_A3_h */
