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
	
	linkList m_deckList;
	
	int m_size;
	
	int m_score;
	
	string cardSuits[4];
	string cardValues[13];
	
	
	void deal();
	
	void score();
	
	void shuffle();
	
	void newNode(string& a_suit, string& a_value, int a_valueIndex);
	
	void nextNode();
	
	void toEnd();
	void toHead();
	
	
	void listInsert(card *newCard); //inserts element at current index
	void listRemove(); //removes element at current index
	
	void listFlip(int a_index1, int a_index2);//flip-flops two elements at given indices
	void flip(card*& a_card1, card*& a_card2); //flips data held in two elements provided
	
	
	void instructions();
	void printCards(int numPrint, bool a_printNeighbors=false);
	
	
	

public:
	deck();
	
	~deck();
	
	
	
	void playFlip();

};


#endif //PROJECT2_DECK_H
