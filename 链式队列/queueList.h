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
	const Object getBack()const;//��������ò�ƶ����Զ�ȡ
	void enqueue (const Object &x);
	Object dequeue();
	void makeEmpty();
private:
	struct ListNode
	{
		Object element;
		ListNode *nest;//nest ֻ��һ��ָ�롣�ᱻ�������
		ListNode(const Object &theElement, ListNode *n = 0
		) :element(theElement), nest(n) {};

	};
	ListNode *front;//����������ָ�����
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
		back = front = new ListNode(x);//��ʼ����
	else
		//	ListNode(const Object &theElement, ListNode *n = 0
		//) :element(theElement), nest(n) {};
		back = back->nest = new ListNode(x);//���ӡ���������ڵڶ��������ϡ�
	//�������̫����

}
template<class Object>

Object Queue<Object>::dequeue()
{
	Object frontItem = getFront();//return front->element;
	ListNode *old = front;//Ϊ����ɾ������ǰ�ڵ㣬��ֹ�ڴ�й©
	front = front->nest;//ɾ������ǰ�ڵ㣬���ǽ���ָ����һ���ڵ�
	delete old;//��Ϊ��һ��
	return frontItem;

}






















#endif // !QUEUELIST_H
















#pragma once
