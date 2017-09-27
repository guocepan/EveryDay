//��̬��ֻ��ͨ��ָ�������ָ�����

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
	//�麯��������Ϊ������Ϊ���ڱ�ĵط��������¶���
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
	//���û���Ĺ��캯����ʼ�������ࡣ����ǰ�����������ǣ�����ĳ�Ա��
	Bulk_item(const string &book =" ", double sales_price = 0.0, size_t qty=0,
		double disc_rate = 0.0) :Item_base(book, sales_price), min_qty(qty),
		discount(disc_rate) {}
	
	
	//net_price ���������
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

//��̬��ʵ�֡�һ���ӿڣ�ʵ�ֶ��ֲ�ͬ������ã�
//ע�����Item_base &item  ���ǻ��ഴ���Ķ��������������������������õ�
//ʱ��Ҳ���Ǵ������Ķ���������������ʱ�������Զ��������������Ķ�����
//���õ���������ĺ����������Item_base item������ô���ǵ��û���Ķ���
void  print(Item_base &item,size_t num)
{

	cout << "*book[1]";
	cout << item.book() << "  " <<num<<"  "<< item.net_price(num)<< endl;
	
}
//��̬
void  print(Item_base *item, size_t num)
{
	cout << "book[0]";
	cout << item->book() << "  " << num << "  " << item->net_price(num) << endl;

}
////���󴫵ݣ��ڻ�������ɲ�������������󴫽���Ҳ����л�������������ڶ�̬����
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
	//&item.book���������á�Ҫ��Ȼ�ͱ����ѵ�����Ϊ�̳й�ȥ�������غ����˰���
	cout <<& item.book() << " ," << item.net_price(10) << endl;
	Bulk_item item2("999-233-3x", 9.9, 10, 0.12);
	cout << &item2.book() << "," << item2.net_price(10) << endl;

	//Ҫʵ�ֶ�̬Ҫʹ��ָ��������á�Ҫʵ�ֶ�̬�����麯���������࣬���أ����ǣ�ģ��
	Item_base *book[5];
	book[0] = new Item_base("0-122-112-0",10);//���û����ʼ��,����������Ͳ���
	book[1] = new Bulk_item("0-123-122-1",20,99,0.05);//�����������ʼ��
	book[2] = new Item_base("0-122-112-0", 130);//���û����ʼ��
	book[3] = new Bulk_item("0-123-122-1", 200, 3, 0.05);//�����������ʼ��
	book[4] = new Item_base("0-122-112-0", 12);//���û����ʼ��

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