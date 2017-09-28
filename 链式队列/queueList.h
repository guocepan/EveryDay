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
	const Object getBack()const;//引不引用貌似都可以读取
	void enqueue (const Object &x);
	Object dequeue();
	void makeEmpty();
private:
	struct ListNode
	{
		Object element;
		ListNode *nest;//nest 只是一个指针。会被对象调用
		ListNode(const Object &theElement, ListNode *n = 0
		) :element(theElement), nest(n) {};

	};
	ListNode *front;//创建了两个指针对象
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
template <class Object>
const Object Queue<Object>::getBack()const
{
	if (isEmpty())
		throw"Queue is Empty";
	return back->element;

}


template<class Object>
void Queue<Object>::enqueue(const Object&x)
{
	if (isEmpty())
		back = front = new ListNode(x);//初始化。
	else
		//	ListNode(const Object &theElement, ListNode *n = 0
		//) :element(theElement), nest(n) {};
		back = back->nest = new ListNode(x);//进队。，将其放在第二个对象上。
	//这个还不太明白

}
template<class Object>

Object Queue<Object>::dequeue()
{
	Object frontItem = getFront();//return front->element;
	ListNode *old = front;//为了能删除掉当前节点，防止内存泄漏
	front = front->nest;//删除掉当前节点，就是将其指向下一个节点
	delete old;//因为上一句
	return frontItem;

}






















#endif // !QUEUELIST_H
















#pragma once
