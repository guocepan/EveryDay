#ifndef QUE_H
#define QUE_H

template <class T>
class Queue
{

public:
	Queue(int queueCapacity=10);
	bool IsEmpty()const;
	T&Front()const;
	T&Rear()const;
	void Push(const T& item);
	void Pop();

private:
	T *queue;//ָ��
	int front;//����
	int rear;//��β
	int capacity;//������
};

template <class T>
Queue<T>::Queue(int queueCapacity = 10):capacity(queueCapacity)
{
	if (capacity < 1) throw "Queue capaciti must be > 0";
	queue = new T[capacity];//��̬���䡣
	front = rear = 0;//�տ�ʼ����������ǿյģ��׺�β����ͬһ���ط�����ָ��0

}

template<class T>
inline bool Queue<T> ::IsEmpty()const
{
	//�ڱ�ĵط�����front ��rear.�����ȷ���1��������ȷ���0��
	return front == rear;
}
template<class T>
void Queue<T>::Push(const T &item)
{
/*�����жϷ���
	if (rear = capacity - 1)
		rear = 0;
	else
		rear++;*/
	if ((rear + 1) % capacity == front)//�ж��ǲ�������.���˾ͷ����¿ռ�
	{
		//�ӱ�
		T* newQueue = new T[2 * capacity];
		int start = (front + 1) % capacity;
		if (start < 2)//û�л�ת
			copy(queue + start, queue + start + capacity - 1, newQueue);
		else
		{
			//copy �õ����㷨����ʼλ ĩβ  Ŀ��λ��.
			copy(queue, queue + rear + 1, newQueue + capacity - start);
			copy(queue,queue+rear+1,newQueue+capacity-start);

		}
		//����������³�ʼ��ָ���λ��
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[]queue;
		queue = newQueue;

	}
	rear = (rear + 1) % capacity;//�߼��жϷ�����
	queue[rear] = item;

}

template<class T>
inline T& Queue<T>::Front() const
{
	if (IsEmpty()) throw "queue is empy.no front element\n";

		return queue[(front + 1) % capacity];

}

template<class T>
inline T&Queue<T>::Rear() const
{
	if (IsEmpty()) throw "Queue is empty  no rear element";
	return queue[rear];

}

template<class T>
void Queue<T>::Pop()
{
	if (IsEmpty()) throw "no element";
	queue[rear] = queue[rear-1];


}




#endif // !QUE_H
#pragma once
