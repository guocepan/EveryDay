class  base
{
public:
	int x;
protected:
	int y;
private:
	int z;
};

class child :public base//���м̳з�ʽ
{
	//���еļ̳з�ʽ���ܼ̳е�������public ��protect���ֵĳ�Ա��
public:
	x = 100;//x->base;
	y = 100;//y->base;
	int c;
protected:
	int w;
private:
	int q;
};
class child_child :public child
{
	//����ڲ���
public:
	x = 99;//���׵ĸ��׵Ĺ��г�Ա��Ա��
	y = 22;//base ���ܱ�����Ա
	c = 122;//child�Ĺ��г�Ա
	w = 333;//child���ܱ�����Ա��
};

void main()
{
	//����ⲿ����ʵ�ֵ�
	base a;
	cout << a.x << endl;
	child b;
	cout << b.x << " " << b.c << endl;
	child_child c;
	cout << c.x << " " << c.c << endl;

}