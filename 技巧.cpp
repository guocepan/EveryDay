//想在class里面定义常量方法

class Dog
{
public:

private:
//如果不给直接在这边初始化，就在类外面初始化。
static  const int NumTurns =5;
//也可以这样定义一个常量
enum{NumTurns=5};
int scores[NumTurns];

}
const int  Dog::NUMTurns=5;
