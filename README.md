# Deck Of Cards #
Program in C.

_"A simulation of a deck of cards in preparation for a game of cards."_

--------

- This simulation creates a deck of cards, shuffles the cards, displays the shuffled deck of cards, deals the specified number of cards to the specified number of players and display each of the hands of cards.

- This program includes seperate source code files for the main and functions, as well as the user-defined header file.

__Input__: Accept input via the command-line arguments and validate.

__Output__: Generate a display of a deck of cards and of the cards that each player has.

--------

### How to compile and link files for execution ###


Please use the following to compile (this will work on any OS:

__gcc DeckOfCards_A3_main.c DeckOfCards_A3_deck.c DeckOfCards_A3.h__

Please use the following to execute the program successfully:

__./a.out numberOfCards numberOfPlayers__

_numberOfCards_ = the number of cards each player should have

_numberOfPlayers_ = the number of players

_EXAMPLE_: __./a.out 4 12__


__NOTE__: When program has been successfully executed, when running on __Linux__ or __Ubuntu__, the suits will display as their corresponding letter, eg. HEART = H, SPADE= S, CLUB = C, DIAMOND = D. However, if program has been successfully executed, when running on __OS X__, the suits will display their corresponding image.
