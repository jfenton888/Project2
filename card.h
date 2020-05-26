//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-18.
//

#ifndef PROJECT2_CARD_H
#define PROJECT2_CARD_H

#include <iostream>
using namespace std;

class card
{
private:
	//3 private members are the values that identify a card as unique
	//the valueIndex is the numberical representation of the cards value
	//J=11,Q=12,K=13,A=14 -- These are used to speed up evaluation for scoring
	string m_suit;
	string m_value;
	int m_valueIndex;

	
public:
	//default constructor has null pointer to the next card
	card():nextCard(nullptr){};
	
	//this is the constructor used for making the deck
	//refrences are passed for the suit, value, and the index of that value
	//refrenced values get assigned to corresponding members
	card(string& a_suit, string& a_value, int a_valueIndex):nextCard(nullptr),
															m_suit(a_suit),
															m_value(a_value),
															m_valueIndex(a_valueIndex)
															{};
	
	~card(){};
	
	card *nextCard;
	
	//set(), get() function pair for suit of card
	void setSuit(string& a_suit){m_suit=a_suit;};
	string getSuit(){return m_suit;};
	
	//set(), get() function pair for value of card
	void setValue(string& a_value){m_value=a_value;};
	string getValue(){ return m_value;};
	
	//set(), get() function pair for index of value of card
	void setValueIndex(int& a_valueIndex){m_valueIndex=a_valueIndex;};
	int getValueIndex(){ return m_valueIndex;};
	
	//overloaded function for printing cards
	//defined as a friend so it can be used outside the class
	//prints in the format '(value) of (suit)', like '2 of spades'
	friend ostream& operator<<(ostream& os, card const& a_card)
	{
		return os << a_card.m_value << " of " << a_card.m_suit << endl;
	};
	
	
};


#endif //PROJECT2_CARD_H
