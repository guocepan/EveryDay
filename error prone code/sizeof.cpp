 //sizeof是C/C++中的一个操作符（operator），简单的说其作用就是返回一个对象或者类型所占的内存字节数。

int GetSize(int data[])
{
//data 是一个指针，是数组的首地址
  return sizeof(data);
}


void main()
{
  int data[]={1,2,3,4,5};
  int size =sizeof(data);//    20   计算打他这个对象有多少字节，因为data有5个元素，4*5=20
  
  
  //p指针变量，指向首地址。
  int *p =data;
  int size2=sizeof(p);//  4
  int  size3=GetSize(data); ///   4


}


