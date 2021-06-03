#include<iostream>
using namespace std;

//为什么析构函数一般写成虚函数
//由于类的多态性，基类指针可以指向派生类的对象，如果删除基类的指针，就会调用指针指向派生类的析构函数
//而派生类的析构函数又会自动调用基类的析构函数，这样整个派生类的对象会完全被释放
//
//如果析构函数不使用虚函数，则编译器实施静态绑定，再删除基类指针时，只会调用基类的析构函数，而不会调用派生类的析构函数
//这样就会造成派生类析构不完全，造成内存泄漏
class Parent{
  public:
    Parent(){
      cout<<"Parent的构造函数"<<endl;
    }
    virtual~Parent(){         //如果不使用虚函数，派生类不会析构
      cout<<"Parent的析构函数"<<endl;
    }
};

class Son:public Parent{
  public:
    Son(){
      cout<<"Son的构造函数"<<endl;
    }
    ~Son(){
      cout<<"Son的析构函数"<<endl;
    }
};

void test(){
  Parent* p = new Son();
  delete p;
  p = NULL;
}
int main(){
  test();
  return 0;
}
