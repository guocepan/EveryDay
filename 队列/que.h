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
	T *queue;//指针
	int front;//队首
	int rear;//队尾
	int capacity;//扩充用
};

template <class T>
Queue<T>::Queue(int queueCapacity = 10):capacity(queueCapacity)
{
	if (capacity < 1) throw "Queue capaciti must be > 0";
	queue = new T[capacity];//动态分配。
	front = rear = 0;//刚开始，数组队列是空的，首和尾都在同一个地方。都指向0

}

template<class T>
inline bool Queue<T> ::IsEmpty()const
{
	//在别的地方更改front 和rear.如果相等返回1，如果不等返回0；
	return front == rear;
}
template<class T>
void Queue<T>::Push(const T &item)
{
/*初级判断方法
	if (rear = capacity - 1)
		rear = 0;
	else
		rear++;*/
	if ((rear + 1) % capacity == front)//判断是不是满了.满了就分配新空间
	{
		//加倍
		T* newQueue = new T[2 * capacity];
		int start = (front + 1) % capacity;
		if (start < 2)//没有回转
			copy(queue + start, queue + start + capacity - 1, newQueue);
		else
		{
			//copy 用的是算法。起始位 末尾  目的位置.
			copy(queue, queue + rear + 1, newQueue + capacity - start);
			copy(queue,queue+rear+1,newQueue+capacity-start);

		}
		//复制完后，重新初始化指针的位置
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[]queue;
		queue = newQueue;

	}
	rear = (rear + 1) % capacity;//高级判断方法；
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
