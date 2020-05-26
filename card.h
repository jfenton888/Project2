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
	string m_suit;
	string m_value;
	int m_valueIndex;

	
public:
	card():nextCard(nullptr){};
	
	card(string& a_suit, string& a_value, int a_valueIndex):nextCard(nullptr),
															m_suit(a_suit),
															m_value(a_value),
															m_valueIndex(a_valueIndex)
															{/*cout<<m_value<<" of "<<m_suit<<endl;*/};
	
	~card(){};
	
	card *nextCard;
	
	void setSuit(string& a_suit){m_suit=a_suit;};
	string getSuit(){return m_suit;};
	
	void setValue(string& a_value){m_value=a_value;};
	string getValue(){ return m_value;};
	
	void setValueIndex(int& a_valueIndex){m_valueIndex=a_valueIndex;};
	int getValueIndex(){ return m_valueIndex;};
	
	friend ostream& operator<<(ostream& os, card const& a_card)
	{
		return os << a_card.m_value << " of " << a_card.m_suit << endl;
	};
	
	
};


#endif //PROJECT2_CARD_H
