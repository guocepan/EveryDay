//����  �Ƚ��ȳ�
//����������˳�����
#include<iostream>
#include<string>
#include "que.h"
#include <algorithm>

using namespace std;

void  main()
{
	Queue<int>  q(4);
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(2);
	q.Push(3);
	q.Push(2);
	q.Push(3);
	q.Pop();
	cout << q.Front() << " " << q.Rear();

	system("pause");
}