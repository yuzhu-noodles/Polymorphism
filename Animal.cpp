#include<iostream>
using namespace std;

//动态多态满足条件
//1、有继承关系
//2、子类重写父类的虚函数

//动态多态的使用
//父类的指针或引用，指向于类对象

//重写和重载区别
//重写：函数名相同，返回值类型相同，函数参数相同
//重载：函数名相同，函数参数不同

class Animal{
  public:
    virtual void Speak(){
      cout<<"动物在说话"<<endl;
    }
};

class Cat: public Animal{
  public:
    void Speak(){
      cout<<"小猫在说话"<<endl;
    }
};
//不加virtual 地址早绑定，编译阶段就确定了函数地址 此时动物在说话
//加virtual 地址晚绑定，程序运行时才确定函数地址 此刻小猫在说话
void doSpeak(Animal& animal){
  animal.Speak();
}

void test01(){
  Cat cat;
  doSpeak(cat);
}


void test02(){
  cout<<"sizeof of Animal:"<<sizeof(Animal)<<endl;
}
int main(){
  test01();
  test02();
  return 0;
}
