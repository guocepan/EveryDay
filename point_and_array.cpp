#include<iostream>

using namespace std;
int main()
{
	int    arr[2][4] = {1,2,3,4,
			     		5,6,7,8};
	//如何用一级指针来处理二维数组。
	int *p = NULL;;
	//p = arr;////   p+1;只会移动四个字节。，而arr+1 移动4*4个字节。所以类型不匹配。
	//p指向的一列的首地址。arr 指向的是一行的首地址。
	p = arr[0];//p指向第一个元素的地址，可以匹配。
	cout << *p<<endl;
	p = *arr;//p指向的是第一行第一个元素的地址，可以匹配
	cout << *p << endl;
	p = *(arr + 1);//p指向的是第2行第一个元素的地址，可以匹配
	cout << *p << endl;
	p = &arr[0][0];//第一行第一列的地址；
	p = arr[1];//p指向的第二行第1个元素的地址。就是将二维数组变成一维数组。
	cout << *p << endl;
	cout << p[1] <<" =="<< arr[1][1]<<endl;//所以*p[1]是语法错误。
	cout << *arr[1] << endl;
	p = arr[4];//想指向第四行，越界
	cout << *p << "  " << *arr[4] << endl;

	system("pause");
	exit(0);
}



