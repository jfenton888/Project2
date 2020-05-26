//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-18.
//

#include <iostream>
#include <cstdlib>     /* srand, rand */
#include "deck.h"


int main()
{
	srand (time(NULL));
	
	deck myDeck;
	myDeck.playFlip();
}