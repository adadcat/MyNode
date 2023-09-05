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
