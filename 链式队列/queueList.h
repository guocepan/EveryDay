#ifndef QUEUELIST_H
#define QUEUELIST_H

template<class Object>
class Queue
{
public:
	Queue();
	~Queue();
	bool isEmpty()const;
	const Object &getFront() const;
	void enqueue (const Object &x);
	Object dequeue();
	void makeEmpty();

private:
	struct ListNode
	{
		Object element;
		ListNode *nest;
		ListNode(const Object &theElement, ListNode *n = 0
		) :element(theElement), nest(n) {};

	};
	ListNode *front;
	ListNode *back;

};

template <class Object>
Queue<Object>::Queue()
{
	front = back=0;


}
template<class Object>
Queue<Object>::~Queue()
{
	makeEmpty();

}
template<class Object>
void Queue<Object>::makeEmpty()
{
	while (!isEmpty())
		dequeue();

}
template<class Object>
bool Queue<Object>::isEmpty()const
{
	return front == 0;

}

template <class Object>
const Object &Queue<Object>::getFront()const
{
	if (isEmpty())
		throw"Queue is Empty";
	return front->element;

}


template<class Object>

void Queue<Object>::enqueue(const Object&x)
{
	if (isEmpty())
		back = front = new ListNode(x);
	else
		back = back->nest = new ListNode(x);


}
template<class Object>

Object Queue<Object>::dequeue()
{
	Object frontItem = getFront();
	ListNode *old = front;
	front = front->nest;
	delete old;
	return frontItem;

}






















#endif // !QUEUELIST_H
















#pragma once
