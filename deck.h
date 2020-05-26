//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-18.
//

#ifndef PROJECT2_DECK_H
#define PROJECT2_DECK_H

#include <iostream>
#include "card.h"
#include "linkList.h"

using namespace std;

class deck
{
private:
	
	linkList m_deckList; //linklist contains pointers to the head of the deck
						 //as well as tracking of traversal with current and previous pointers
	
	int m_size;
	int m_score;
	
	string cardSuits[4]; //contains all the suits in order Club-Spade
	string cardValues[13]; //contains all the card values 2-A
	
	
	//Gameplay Functions
	void deal();
	
	void score();
	
	void shuffle();
	//End Gameplay Functions
	
	
	
	//Node Management Functions
	void newNode(string& a_suit, string& a_value, int a_valueIndex); //creates a new node at the tail with these values
	
	void nextNode(); //moves to following node in the linklist
	
	void toEnd(); //navigates to the end of the linklist
	void toHead(); //navigates to the head of the linklist
	
	void listInsert(card *newCard); //inserts element at current index
	void listRemove(); //removes element at current index
	
	void listFlip(int a_index1, int a_index2);//flip-flops two elements at given indices
	void flip(card*& a_card1, card*& a_card2); //flips data held in two elements provided
	//End Node Management Functions
	
	
	//Printing Functions
	void instructions(); //prints game instructions
	void printCards(int numPrint, bool a_printNeighbors=false); //prints specified number of cards
																//will also show neighboring cards if
																//second argument is specified as true
	
	
	

public:
	deck();
	
	~deck();
	
	void playFlip();

};


#endif //PROJECT2_DECK_H
