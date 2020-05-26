//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-19.
//

#ifndef PROJECT2_LINKLIST_H
#define PROJECT2_LINKLIST_H

#include "card.h"

class linkList
{
public:
	linkList():head(nullptr),
	           tail(nullptr),
			   current(nullptr),
			   previous(nullptr),
			   m_length(0)
			   {};
	
	card* head;
	card* tail;
	card* current;
	card* previous;
	
	int m_length;
	

	
};


#endif //PROJECT2_LINKLIST_H
