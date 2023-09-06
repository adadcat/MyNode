1.auto & decltype:类型推导
//auto推导变量类型
{
  auto test = 10;
  auto i = 1, b =1.0;//error:不能连续使用不同的类型
  auto x;//error:必须初始化
}
//decltype推导表达式类型
{
  const int& i = 1;
  int a = 2;
  decltype(i) b = 2;//这里b是const int&
}

2.左值、右值
左值：可以放到等号左边的值；可以取地址，且有名字的值
{
  *函数名和变量名：i，temp
  *返回左值引用的函数调用
  *前置自增自减表达式：++i、--i
  *由赋值表达式或赋值运算符连接的表达式：a=b, a += b
  *解引用表达式*p
}
右值：不能放到等号左边的值；不可以取地址且没有名字的值
{
  纯右值
  {
    *除字符串字面值外的字面值：1，3，4，5.5
    *返回非引用类型的函数调用
    *后置自增自减表达式i++、i--
    *算术表达式(a+b, a*b, a&&b, a==b等)
    *取地址表达式等(&a)
  }
  将亡值
  {
    和右值引用相关的表达式，即将要销毁的值
  }
}

左值引用：type &name = exp;
{
  int a = 10;
  int &b = a;
  b = 5;
  int &c = 2;//error：2无法取地址
  const int & d = 10;//这里是常引用，只能读取，不能修改
} 

右值引用：type &&name = exp;
{
  int a = 4;
  int &&b = a;//error:4是左值
  int &&b = std::move(a);//移动构造函数，这里引申出深拷贝和浅拷贝，见注1，注2
}

@@@注1：
{
  深拷贝和浅拷贝的实质差别就是有无开辟新空间，浅拷贝出来的对象将会和旧对象公用同一片空间。
}

@@@注2
{
  移动构造函数：移动语义的实现，将旧对象的资源，转为新对象所拥有，且旧对象将失去该资源
}

例子，引入完美转发来进行左值和右值的判定：
完美转发：一个可接收任意实参的函数模板，并转发到其他函数，实参的类型将会保持不变
{
  void PrintV(int &t)
  {
    cout<<"l_value";
  }
  void PrintV(int &&t)
  {
    cout<<"r_value";
  }

  template<typename T>
  void Test(T &&t)
  {
    PrintV(t);
    PrintV(std::forward<T>(t));
    PrintV(std::move(t));
  }

  int main()
  {
    Test(1); // lvalue rvalue rvalue
    int a = 1;
    Test(a); // lvalue lvalue rvalue
    Test(std::forward<int>(a)); // lvalue rvalue rvalue
    Test(std::forward<int&>(a)); // lvalue lvalue rvalue
    Test(std::forward<int&&>(a)); // lvalue rvalue rvalue
    return 0;
  }

//Test(1)：1是右值，模板中T &&t这种为万能引用，右值1传到Test函数中变成了右值引用.
            但是调用PrintV()时候，t变成了左值，因为它变成了一个拥有名字的变量，所以打印lvalue
            而PrintV(std::forward(t))时候，会进行完美转发，按照原来的类型转发，所以打印rvalue
            PrintV(std::move(t))毫无疑问会打印rvalue。
//Test(a)：a是左值，模板中T &&这种为万能引用，左值a传到Test函数中变成了左值引用，所以有代码中打印。
//Test(std::forward(a))：转发为左值还是右值，依赖于T，T是左值那就转发为左值，T是右值那就转发为右值。
}

3.基于范围的for循环
{
  vector<int> vec;
  //before c++ 11
  for(auto it = vec.begin();it!=vec.end();++it){}
  
  //now
  for(auto i ：vec){}
}

4.委托构造函数
{
  //before c++11
  class A
  {
  public:
    A(){}
    A(int a){a_a = a;}
    A(int a,int b){a_a = a;a_b=b;}
    A(int a,int b, int c){a_a = a;a_b=b;a_c=c;}
  public:
    int a_a,a_b,a_c;
  };

  //now
  class A
  {
  public:
    A(){}
    A(int a) { a_a = a; }
    A(int a, int b) : A(a) { a_b = b; }
    A(int a, int b, int c) : A(a, b) { a_c = c; }
  public:
    int a_a,a_b,a_c;
  }
}

5.初始化列表

6.std::function & std::bind & lambda表达式

以下都是可调对象：
*是一个函数指针
*是一个具有operator()成员函数的类对象(传说中的仿函数)，lambda表达式
*是一个可被转换为函数指针的类对象
*是一个类成员(函数)指针
*bind表达式或其它函数对象

std::function是可调对象的封装器。std::function实例可以存储、复制和调用任何可调用对象。
{
  std::function<void(int)> test;

}

7.模板的改进

8.并发

9.智能指针

10.委托构造函数

11.继承构造函数

12.nullptr

13.final&override

14.default

15.delete

16.explicit
