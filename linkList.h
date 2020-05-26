//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-19.
//

#ifndef PROJECT2_LINKLIST_H
#define PROJECT2_LINKLIST_H

#include "card.h"


//3 element linked list management
//in addition to member that tracks the length of the list
class linkList
{
public:
	linkList():head(nullptr),
			   current(nullptr),
			   previous(nullptr),
			   m_length(0)
			   {};
	
	card* head;
	card* current;
	card* previous;
	
	int m_length;

	
};


#endif //PROJECT2_LINKLIST_H
