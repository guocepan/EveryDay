#include <iostream>
#include<string>
using namespace std;
class Dog {
	int cat(int  z)const
	{
		int w;
		w = x;
		w = z;

	}

private:
	static const int NUM = 5;
	static const int NUM2;
	enum {NUM3=5};
	int arr[NUM];
	int x;
	int y;
};
const int Dog::NUM2 = 10;


void main()
{

	int x = 10;
	int y = 10;
	const int *p = &x;//效果跟下面的一样。
	 int const * p = &x;//const *p 说明 *p不能改变。也就是说不能通过*p修改指向对象的内容；
	/*  *p = 100;//这个错误  */
	 cout << p<<endl;
	++p;//但是可以这样。
	cout << p<<endl;
	p = &y;
	cout << p<<endl;

	int  n = 10;
	int  m = 10;
	int *const q = &n;//const  q；也就是说 q指向的不能改变；也就是q不能改变
	//q = &m;  想改变指向的地址，不行。不允许。
	//q++;// 不允许，q不可改变
	*q = 100;//允许  指向的内容可以改变，就是不能改变他的地址.n已经改变。
	cout << n;







	system("pause");
}
