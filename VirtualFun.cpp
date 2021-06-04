#include<iostream>
using namespace std;

class Base{
  public:
    virtual void func() = 0;
    
    //纯虚函数    virtual 返回类型 函数名(参数列表) = 0；
    //只要有一个纯虚函数，该类就称为抽象类
    //特点：
    //1、无法实例化对象
    //2、抽象类的子类，必须重写父类中的纯虚函数，否择也属于抽象类
}; 

class Son:public Base{
  public:
    virtual void func() {
      cout<<"子类的func函数"<<endl;
    }
};

void test()
{
  Base* base = new Son;
  base->func();
}

int main(){
  test();
  return 0;
}
