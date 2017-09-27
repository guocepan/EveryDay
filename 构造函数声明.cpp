
                      //定义并赋值                                  真正的初始化
Item_base(const std::string &book = "", double sales_price = 0.0)	:isbn(book), price(sales_price) {}
	
  //string   为返回类型的
  string book()const
	{
		return isbn;
	}
  
  private:
	string isbn;
