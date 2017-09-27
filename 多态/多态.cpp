//动态，只能通过指针和引用指向基类

#include<iostream>
#include<string>
using namespace std;

class Item_base
{
public:
	Item_base(const std::string &book = "", double sales_price = 0.0)
		:isbn(book), price(sales_price) {}
	string book()const
	{
		return isbn;
	}
	//虚函数，声明为这样是为了在别的地方可以重新定义
	virtual double net_price(size_t n)const
	{
		return n*price;
	}
private:
	string isbn;
protected:
	double price;
};
class Bulk_item :public Item_base
{
public:
	//调用基类的构造函数初始化派生类。并且前两个参数都是，基类的成员；
	Bulk_item(const string &book =" ", double sales_price = 0.0, size_t qty=0,
		double disc_rate = 0.0) :Item_base(book, sales_price), min_qty(qty),
		discount(disc_rate) {}
	
	
	//net_price 看情况调用
	double net_price(size_t cnt) const
	{
		if (cnt >= min_qty)
			return cnt*(1 - discount)*price;
		else
			return cnt*price;
	}
private:
	size_t min_qty;
	double discount;


};

//多态的实现。一个接口，实现多种不同对象调用；
//注意这个Item_base &item  他是基类创建的对象，在下面其派生类对象对他调用的
//时候，也就是传进来的对象是派生类对象的时候，他能自动变成派生类里面的东西，
//调用的是派生类的函数。如果是Item_base item传，那么都是调用基类的东西
void  print(Item_base &item,size_t num)
{

	cout << "*book[1]";
	cout << item.book() << "  " <<num<<"  "<< item.net_price(num)<< endl;
	
}
//多态
void  print(Item_base *item, size_t num)
{
	cout << "book[0]";
	cout << item->book() << "  " << num << "  " << item->net_price(num) << endl;

}
////对象传递，在基类中完成操作，派生类对象传进来也会进行基类操作，不存在多态问题
//void  print(Item_base item, size_t num)
//{
//
//	cout << "*book[1]";
//	cout << item.book() << "  " << num << "  " << item.net_price(num) << endl;
//
//}


void main()
{
	Item_base item("212-212-122",9.9);
	//&item.book必须是引用。要不然就报错。难道是因为继承过去后变成重载函数了啊；
	cout <<& item.book() << " ," << item.net_price(10) << endl;
	Bulk_item item2("999-233-3x", 9.9, 10, 0.12);
	cout << &item2.book() << "," << item2.net_price(10) << endl;

	//要实现多态要使用指针或者引用。要实现多态，：虚函数，抽象类，重载，覆盖，模板
	Item_base *book[5];
	book[0] = new Item_base("0-122-112-0",10);//可用基类初始化,但是派生类就不行
	book[1] = new Bulk_item("0-123-122-1",20,99,0.05);//可用派生类初始化
	book[2] = new Item_base("0-122-112-0", 130);//可用基类初始化
	book[3] = new Bulk_item("0-123-122-1", 200, 3, 0.05);//可用派生类初始化
	book[4] = new Item_base("0-122-112-0", 12);//可用基类初始化

	int  num[5];
	num[0] = 2;
	num[1] = 5;
	num[2] = 3;
	num[3] = 2;
	num[4] = 20;

	for (int i = 0; i < 5; i++)
	{
		//void print(item_base &item,size_t num);
		print(*book[i],num[i]);

	}
	for (int i = 0; i < 5; i++)
	{
		//void print(item_base *item,size_t num);
		print(book[i], num[i]);

	}


	system("pause");


}