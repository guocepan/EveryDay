//���캯������ʹ��
#include<iostream>
using namespace std;
class  Widget
{
public:
	Widget();//default ���캯��
	Widget(const Widget &rhs);//copy���캯��
	Widget & operator=(const Widget &rhs);//copy assignment������
	
};

void main()
{}
Widget w1; //����default���캯��
Widget w2(w1);//����copy���캯��
w1 = w2;  //copy assignment������

//���ҪС��
Widget w3 = w2;//���õ���copy���캯��;
			   //������´���һ�����󣬱�Ȼ����Ĭ�Ϲ��캯��
			    //�����ܵ��ø�ֵ������
 }
