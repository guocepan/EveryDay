class  base
{
public:
	int x;
protected:
	int y;
private:
	int z;
};

class child :public base//公有继承方式
{
	//公有的继承方式，能继承到基类里public 和protect部分的成员；
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
	//类的内部；
public:
	x = 99;//父亲的父亲的公有成员成员；
	y = 22;//base 的受保护成员
	c = 122;//child的公有成员
	w = 333;//child的受保护成员；
};

void main()
{
	//类的外部；能实现的
	base a;
	cout << a.x << endl;
	child b;
	cout << b.x << " " << b.c << endl;
	child_child c;
	cout << c.x << " " << c.c << endl;

}