#include<iostream>
using namespace std;
#include"queueList.h"

void main()
{
	cout << "T";
	Queue<int> q;
	q.enqueue(10);
	q.enqueue(11); 
	q.enqueue(120);
	cout << q.getFront() << endl;
	cout << q.getBack() << endl;
	system("pause");
}