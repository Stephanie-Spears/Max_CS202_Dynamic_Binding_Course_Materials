#include "list.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////


Materials::Materials(): size(0), head(NULL), tail(NULL)
{}

Materials::Materials(const Materials& to_copy): size(to_copy.size), head(NULL), tail(NULL)
{

}

Materials::~Materials()
{
	while(head)
	{
		MatNode * newNode = head->getNext();
		delete head;
		head = newNode;
	}
}

void Materials::add(Mat & to_add)
{
	if(!head)
	{
		head = new MatNode(NULL, to_add, NULL);
		tail = head;
	}
	else
	{
		MatNode * newNode = new MatNode(tail, to_add, NULL);
		tail->setNext(newNode);
		tail = newNode;
	}
	++size;
}

MatNode::MatNode(MatNode * p, Mat & to_add, MatNode * n): mat(NULL), prev(NULL), next(NULL)
{
	prev = p;
	mat = &to_add;
	next = n;
}

void Materials::complete(int index)
{
	int i = index;
	if(head)
	{
		head->recursive_complete(i);
	}
}

void MatNode::recursive_complete(int &i)
{
	--i;
	if(i == 0)
	{
		mat->complete();
	}
	else if(i>0 || next)
	{
		next->recursive_complete(i);
	}
}

void Materials::remove()
{
	if(!head)
	{
		return;
	}

	else if(head == tail)
	{
		head->setNext(NULL);

		delete head;
	
		head = NULL;
		tail = NULL;
	}

	else
	{
		MatNode * node = head;
		while(head != tail)
		{
			head = head->getNext();

//			node->setPrev(NULL);
//			node->setNext(NULL);
			delete node;
			node = head;
		}
//		node->setPrev(NULL);
//		node->setNext(NULL);
		delete node;
		head = NULL;
		tail = NULL;
	}
	size = 0;
}

void Materials::remove(int index)
{
	if(!head || (index > size))
	{
		return;
	}
	else if(head == tail)
	{
		head->setNext(NULL);
		delete head;
		head = NULL;
		tail = NULL;
	}

	else
	{
		MatNode * p = NULL;
		MatNode * node = head;
		MatNode * n = head->getNext();		

		for(int i = 1; i < index; i++)
		{
			p = node;
			node = node->getNext();
			n = node->getNext();
		}

//		node->setPrev(NULL);
//		node->setNext(NULL);
		delete node;
		node = NULL;

		if(!p)
		{
			head = n;
			n->setPrev(NULL);
		}
		else
		{
			p->setNext(n);
		}

		if(!n)
		{
			tail = p;
			p->setNext(NULL);
		}
		else
		{
			n->setPrev(p);
		}

	}

	--size;
}
	
void Materials::display()
{
	int n = 1;
	if(head)
	{
		head->recursive_display(n);
	}
}

void MatNode::recursive_display(int & n)
{
	cout << "\n\n******* Node #" << n << " *******\n";
	++n;
	mat->display();
	if(next)
	{
		next->recursive_display(n);
	}
}

void Materials::display(int index)
{
	int i = index;
	int n = 1;
	if(head)
	{
		head->recursive_display(i, n);
	}
}

void MatNode::recursive_display(int &i, int & n)
{
	--i;
	if(i == 0)
	{
		cout << "\n******* Node #" << n << " *******\n";
		mat->display();
	}
	else if(i > 0 && next)
	{
		++n;
		next->recursive_display(i, n);
	}
}

void Materials::edit(int index)
{
	int i = index;
	int n = 1;
	if(head)
	{
		head->recursive_edit(i, n);
	}
}

void MatNode::recursive_edit(int &i, int &n)
{
	--i;
	if(i == 0)
	{
		cout << "**** Node #" << n << " ****\n";
		mat->edit();
	}
	else if(i > 0 && next)
	{
		++n;
		next->recursive_edit(i, n);
	}
}

int Materials::getSize()
{
	return size;
}
	

MatNode * MatNode::getPrev()
{
	return prev;
}
MatNode * MatNode::getNext()
{
	return next;
}
void MatNode::setPrev(MatNode * newPrev)
{
	prev = newPrev;
}
void MatNode::setNext(MatNode * newNext)
{
	next = newNext;
}



///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

MatNode::MatNode(): mat(NULL), prev(NULL), next(NULL)
{}

MatNode::MatNode(const MatNode & to_copy): mat(NULL), prev(NULL), next(NULL)
{
	//mat = new Mat(*to_copy.mat);
}

MatNode::~MatNode()
{
	prev = NULL;
	delete mat;
	mat = NULL;
	
}
