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
	const int *p = &x;//Ч���������һ����
	 int const * p = &x;//const *p ˵�� *p���ܸı䡣Ҳ����˵����ͨ��*p�޸�ָ���������ݣ�
	/*  *p = 100;//�������  */
	 cout << p<<endl;
	++p;//���ǿ���������
	cout << p<<endl;
	p = &y;
	cout << p<<endl;

	int  n = 10;
	int  m = 10;
	int *const q = &n;//const  q��Ҳ����˵ qָ��Ĳ��ܸı䣻Ҳ����q���ܸı�
	//q = &m;  ��ı�ָ��ĵ�ַ�����С�������
	//q++;// ������q���ɸı�
	*q = 100;//����  ָ������ݿ��Ըı䣬���ǲ��ܸı����ĵ�ַ.n�Ѿ��ı䡣
	cout << n;







	system("pause");
}
