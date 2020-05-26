//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-18.
//

#include <iostream>
#include <cstdlib>     /* srand, rand */
#include "deck.h"
#include "linkList.h"
#include "card.h"

#define CARD_SUIT (m_deckList.current->getSuit())
#define CARD_VALUE (m_deckList.current->getValue())
#define CARD_VALUE_INDEX (m_deckList.current->getValueIndex())

using namespace std;

deck::deck():m_size(52),
			 cardSuits{"Clubs", "Diamonds", "Hearts", "Spades"},
			 cardValues{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"}
{
	for(int itSuit=0;itSuit<4;itSuit++)
	{
		for(int itValue=0;itValue<13;itValue++)
		{
			newNode(cardSuits[itSuit], cardValues[itValue], itValue+2);
		}
		
	}
}


deck::~deck(){}


void deck::playFlip()
{
	int userChoice=0;
	shuffle();
	toHead();
	
	//printCards(52);
	
	
	cout<<"Playing Flip \n";
	
	while(userChoice!=2)
	{
		cout<<"Draw a Card (1) or Finish game (2): ";
		cin>>userChoice;
		
		if(userChoice==1) deal();
	}
	cout<<"Final Score: "<<m_score<<endl;
}


void deck::deal()
{
	score();
	printCards(1);
	cout<<"Score: "<<m_score<<endl;
	listRemove();
}


void deck::score()
{
	if(CARD_VALUE_INDEX==14)
		m_score+=10;
	else if(CARD_VALUE_INDEX>=11)
		m_score+=5;
	else if(CARD_VALUE_INDEX>=8)
		m_score+=0;
	else if(CARD_VALUE_INDEX==7)
		m_score/=2;
	else
		m_score=0;
	if(CARD_SUIT=="Hearts")
		m_score+=1;
}


void deck::replace(card a_newCard){}



void deck::shuffle()
{
	//Shuffle using Dustenfeld's version of Fisher-Yates shuffle
	int index1, index2;
	
	//elements with index higher than the iterator have already been shuffled
	//on each iteration the number at the highest position not yet shuffled gets flipped
	//with another of the unshuffled cards, maintaining the pattern
	for(int it=m_size;it>0;it--)
	{
		index1=rand()%(it); //picks random low index card
		index2=it-1; //position that will be shuffled after flip-flop
		
		listFlip(index1,index2);//flips cards at those positions
	}
}


void deck::listFlip(int a_index1, int a_index2)
{
	card *card1, *card2;
	
	//starting from the head, the card objects at the specified index of each is identified
	//saved to temporary positions
	toHead();
	for(int it=0;it<=a_index2;it++)
	{
		if(it==a_index1)
		{
			card1 = m_deckList.current;
		}
		if(it==a_index2)
		{
			card2 = m_deckList.current;
		}
		nextNode();
	}
	
	flip(card1,card2); //data held by the two objects will be flipped
}


//ver inelegant way of implimenting but ran into issues with other ways
//method chosen as to avoid dealing with changing pointers between elements
void deck::flip(card*& a_card1, card*& a_card2)
{
	string tempSuit1, tempSuit2, tempVal1, tempVal2;
	int tempValIndex1, tempValIndex2;
	
	//stores all 3 data members from both objects in temporary variables
	tempSuit1=a_card1->getSuit();
	tempVal1=a_card1->getValue();
	tempValIndex1=a_card1->getValueIndex();
	
	tempSuit2=a_card2->getSuit();
	tempVal2=a_card2->getValue();
	tempValIndex2=a_card2->getValueIndex();
	
	//assign data to opposite objects as previous
	a_card1->setSuit(tempSuit2);
	a_card1->setValue(tempVal2);
	a_card1->setValueIndex(tempValIndex2);
	
	a_card2->setSuit(tempSuit1);
	a_card2->setValue(tempVal1);
	a_card2->setValueIndex(tempValIndex1);
	
}


void deck::newNode(string& a_suit, string& a_value, int a_valueIndex)
{
	card *nextCard= new card(a_suit, a_value, a_valueIndex);
	if(m_deckList.m_length==0)
	{
		m_deckList.head = nextCard;
		m_deckList.current = nextCard;
	}
	else
	{
		toEnd();
		listInsert(nextCard);
	}
	m_deckList.m_length++;
	
	
	
}


//moves to the next element in the list
//updates 'previous' accordingly
//will not move too far, defined as when previous would become nullptr
void deck::nextNode()
{
	if(m_deckList.current != nullptr)
	{
		m_deckList.previous=m_deckList.current;
		m_deckList.current=m_deckList.current->nextCard;
	}
}

//Traverses list until at position pointed to by last known object
void deck::toEnd()
{
	while(m_deckList.current!=nullptr)
		nextNode();
}

//Moves current position pointed to by m_deckList to the head
void deck::toHead()
{
	m_deckList.previous= nullptr;
	m_deckList.current=m_deckList.head;
}


//Inserts element at the kth position in the linked list
//element that was previously in that position is moved to the k+1
//to add an element to the end, 'current' must be the one pointed to by the last card
//previously defined
void deck::listInsert(card *newCard)
{
	newCard->nextCard=m_deckList.current;
	
	if(m_deckList.current==m_deckList.head)
		m_deckList.head=newCard;
	else
		m_deckList.previous->nextCard=newCard;
	
	m_deckList.current=newCard;
}



//deletes element at the 'current' position and links its surrounding elements
//to maintain continuity
void deck::listRemove()
{
	
	if(m_deckList.current==m_deckList.head)
		m_deckList.head=m_deckList.current->nextCard;
	else
		m_deckList.previous->nextCard=m_deckList.current->nextCard;
	
	card* next = m_deckList.current->nextCard;
	delete m_deckList.current;
	
	m_deckList.current=next;
	
	m_deckList.m_length--;
	
}





//Prints the next a_numPrint number of cards starting at any point in the deck
//Additional optional argument that allows for previous and next cards to be printed in groupings
void deck::printCards(int a_numPrint, bool a_printNeighbors)
{
	for(int it=0;it<a_numPrint;it++)
	{
		if(m_deckList.previous!=nullptr && a_printNeighbors){
			cout<<"Prev: ";
			cout<<*(m_deckList.previous);
		}
		if(m_deckList.current!= nullptr){
			cout<<"Current: ";
			cout<<*(m_deckList.current);
		}
		if(m_deckList.current->nextCard!= nullptr && a_printNeighbors){
			cout<<"Next: ";
			cout<<*(m_deckList.current->nextCard);
			cout<<endl;
		}
		
		nextNode();
	}
	toHead(); //returns to head at end of printing
}
