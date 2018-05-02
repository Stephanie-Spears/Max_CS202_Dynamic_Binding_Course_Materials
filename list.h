/*
CS202 ASSIGNMENT 2: MAX SMILEY
CURRENT FILE: LIST.H
*/
#ifndef _LIST_H
#define _LIST_H


#include "materials.h"

class MatNode
{
	public: 
		MatNode();
		MatNode(const MatNode & to_copy);
		~MatNode();
		MatNode(MatNode * p, Mat &to_add, MatNode * n);
		MatNode * getPrev();
		MatNode * getNext();
		void setPrev(MatNode * newPrev);
		void setNext(MatNode * newNext);
		
		void recursive_complete(int &i);
		void recursive_display(int &n);
		void recursive_display(int &i, int &n);
		void recursive_edit(int &i, int&n);
	protected:
		Mat * mat;
		MatNode * prev;
		MatNode * next;		
};


class Materials
{

	public:
		Materials();
		Materials(const Materials &to_copy);
		~Materials();

		//adds a new material to the linked list
		//should this take a POINTER or a REFERENCE
		void add(Mat & to_add);

		//allows us to mark a material as completed
		void complete(int index);

		//removes ALL materials from list
		void remove();
		//removes a single material from list
		void remove(int index);

		//displays ALL materials from list
		void display();
		//displays a single material from list
		void display(int index);

		void edit(int index);

		int getSize();
		
	protected:

		int size;
		MatNode * head;
		MatNode * tail;
};

#endif
