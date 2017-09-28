//构造函数基本使用
#include<iostream>
using namespace std;
class  Widget
{
public:
	Widget();//default 构造函数
	Widget(const Widget &rhs);//copy构造函数
	Widget & operator=(const Widget &rhs);//copy assignment操作符
	bool fool(Widget w);//最好不要这样传参数，这是以值方式传参，会调用copy构造函数。
};

void main()
{}
Widget w1; //调用default构造函数
Widget w2(w1);//调用copy构造函数
w1 = w2;  //copy assignment操作符

//这个要小心
Widget w3 = w2;//调用的是copy构造函数;
			   //这个是新创建一个对象，必然调用默认构造函数
			    //不可能调用赋值操作。
 }
