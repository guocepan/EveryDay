#include<iostream>

using namespace std;
struct MyStruct
{
	int x;
};


int main()
{

	char *str = "adfasdfad";//str指向了一个字符常量。
	str = "asdfasdfsad";//将指向改变
	//str[0] = 'd';不可，str是一个指向常量的指针，str保存的是一个常量。str【0】语法错误；

	char arr[] = "asfsdfsdf";//数组存放字符串,arr是常量
	//arr = "sdfsdf";//不能给常量赋值
	//arr[0] = "asdfsadf";//想将字符常量赋值个char型的第一个元素，不可
	arr[0] = 's';//类型匹配，‘s’是一个char型的字符。
	//想要给字符串数组重新给一个字符串，要用函数
	strcpy_s(arr,strlen(arr),"adddd");
	cout << arr << endl;
	system("pause");
	exit(0);
}
