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
  移动-》转移资源的所有权
      1）某些资源（如动态分配的内存、文件句柄等）在复制时可能会产生昂贵的开销或引发不必要的资源重复
      2）当对象不再需要资源时，可以将资源的所有权转移到另一个对象，确保资源在正确的时间释放
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
  花括号列表初始化
->{
struct A 
{
public:
    A(int) {}
};
int main() {
    A d{123}; // c++11
    return 0;
}
}<-

6.std::function & std::bind & lambda表达式

以下都是可调对象：
*是一个函数指针
*是一个具有operator()成员函数的类对象(仿函数)，lambda表达式
*是一个可被转换为函数指针的类对象
*是一个类成员(函数)指针
*bind表达式或其它函数对象

std::function是可调对象的封装器。std::function实例可以存储、复制和调用任何可调用对象。
->{
int add(int a, int b) 
{
    return a + b;
}

class Multiply 
{
public:
    int operator()(int a, int b) {return a * b;}
};

int main() 
{
    std::function<int(int, int)> func;

    // 存储函数指针
    func = &add;
    int result1 = func(3, 4);
    std::cout << "Result1: " << result1 << std::endl;

    // 存储函数对象
    Multiply multiply;
    func = multiply;
    int result2 = func(3, 4);
    std::cout << "Result2: " << result2 << std::endl;

    // 存储 Lambda 表达式
    func = [](int a, int b) { return a - b; };
    int result3 = func(3, 4);
    std::cout << "Result3: " << result3 << std::endl;

    return 0;
}
}<-


->{
int add(int a, int b) { return a + b;}

class Multiply
{
public:
    int operator()(int a, int b) {return a * b;}
};

int main() 
{
    // 使用 std::bind 绑定函数指针和参数
    auto addFunc = std::bind(add, 3, 4);
    int result1 = addFunc();
    std::cout << "Result1: " << result1 << std::endl;

    // 使用 std::bind 绑定成员函数和对象
    Multiply multiply;
    auto multiplyFunc = std::bind(&Multiply::operator(), multiply, 3, 4);
    int result2 = multiplyFunc();
    std::cout << "Result2: " << result2 << std::endl;

    // 使用 std::bind 绑定 Lambda 表达式和参数
    auto lambdaFunc = std::bind([](int a, int b) { return a - b; }, 3, 4);
    int result3 = lambdaFunc();
    std::cout << "Result3: " << result3 << std::endl;

    return 0;
}
}<-

7.模板的改进
  1)模板的别名
  template<class T>
  struct Alloc { };

  template<class T>
  using Vec = vector<T, Alloc<T>>; // 类型标识为 vector<T, Alloc<T>>
  Vec<int> v; // Vec<int> 同 vector<int, Alloc<int>>

  2)支持变长参数模板
  template <typename T>
  void func(const T& t)
  {
    cout << t << '\n';
  }

  template <typename T, typename ... Args>
  void func(const T& t, Args ... args)
  {
    cout << t << ',';
    func(args...);
  }

8.并发

9.智能指针
  shard_ptr:使用了引用计数，每进行一次拷贝就会使计数+1；生命周期结束析构时，计数-1，在最后一个shard_ptr析构后，内存释放
->{
int main()
{
  std::shard_ptr<int> sharedInt(new int(16));
  //输出   shear ptr value:16
  cout<<"shear ptr value:"<<*sharedInt<<endl;
  std::shard_ptr<int> shardInt2 = sharedInt;
  //将会输出  引用计数：2
  cout<<"引用计数："<<sharedInt.use_count()<<endl;

  // 修改被管理对象的值
  *sharedInt = 99;
  // 输出: 修改后的值: 99
  cout << "修改后的值: " << *sharedInt << endl;
  // 输出: 修改后的值(sharedInt2): 99
  cout << "修改后的值(sharedInt2): " << *sharedInt2 << endl; 
  // 重置 shared_ptr，会减少引用计数
  sharedInt.reset();
  std::cout << "引用计数: " << sharedInt2.use_count() << std::endl; // 输出: 引用计数: 1
  // sharedInt2 超出作用域后，被管理的对象会被自动销毁
  return 0;
}
}<-
->{shard_ptr在循环使用时，会出现内存泄漏的问题

class A {
public:
    std::shared_ptr<B> bPtr;
    ~A() {cout << "A destructor called" << endl;}
};

class B {
public:
    std::shared_ptr<A> aPtr;

    ~B() {cout << "B destructor called" <<endl; }
};

int main()
{
    std::shared_ptr<A> aPtr(new A());
    std::shared_ptr<B> bPtr(new B());

    aPtr->bPtr = bPtr;
    bPtr->aPtr = aPtr;

    return 0;
}

初始状态下，aPtr 和 bPtr 的引用计数为1。
aPtr->bPtr = bPtr 执行后，aPtr 中的 bPtr 成员被赋值为 bPtr，同时 bPtr 的引用计数增加为2。
bPtr->aPtr = aPtr 执行后，bPtr 中的 aPtr 成员被赋值为 aPtr，同时 aPtr 的引用计数增加为2。
}<-


创建weak_ptr时，需要通过shared_ptr初始化，不能直接使用new关键字。weak_ptr本身不会增加引用计数，只是对shared_ptr进行观测。
weak_ptr需要通过lock()方法获取shared_ptr对象，然后才能访问被管理的对象。
lock() 方法会检查 weak_ptr 所观测的对象是否已被释放：
        如果未被释放，则返回一个有效的shared_ptr；如果已被释放，则返回一个空的 shared_ptr。
在使用 weak_ptr 所观测的对象之前，一定要检查使用返回的 shared_ptr 是否为空，以避免访问已经释放的对象。
->{
class A;
class B 
{
public:
    std::weak_ptr<A> a;
    ~B() {std::cout << "B destructor called" << std::endl; }
};

class A 
{
public:
    std::shared_ptr<B> b;
    ~A() {std::cout << "A destructor called" << std::endl;}
};

int main() 
{
    std::shared_ptr<A> aPtr(new A());
    std::shared_ptr<B> bPtr(new B());

    aPtr->b = bPtr;
    bPtr->a = aPtr;

    // 使用 weak_ptr 和 lock() 方法获取 shared_ptr
    std::shared_ptr<A> aPtrLock = bPtr->a.lock();
    //std::shared_ptr<B> bPtrLock = aPtr->b.lock();

    // 检查 shared_ptr 是否为空，然后访问被管理的对象
    if (aPtrLock) 
    {
        // 访问 aPtrLock
        std::cout << "aPtrLock are valid" << std::endl;
    }

    return 0;
}
}<-



unique_ptr:独占管理对象，同一时间只能有一个unique_ptr拥有对象的管理权，所以是不能进行拷贝或赋值操作。
    只能通过std::move移动语义来转移所有权。
->{
class MyClass 
{
public:
    MyClass() {std::cout << "MyClass constructor called" << std::endl;}
    ~MyClass() {std::cout << "MyClass destructor called" << std::endl;}
    void doSomething() {std::cout << "Doing something" << std::endl;}
};

int main()
{
    // 创建一个 unique_ptr，指向一个动态分配的 MyClass 对象
    std::unique_ptr<MyClass> myPtr(new MyClass());

    // 使用 unique_ptr 调用 MyClass 的成员函数
    myPtr->doSomething();

    // unique_ptr 在作用域结束时会自动释放所管理的对象
    return 0;
}
->{
unique_ptr的一些辅助函数
  1)reset()：重置 unique_ptr 所管理的对象或释放对象。
  std::unique_ptr<MyClass> myPtr(new MyClass());
  myPtr.reset(); // 释放所管理的对象

  2)get()：获取 unique_ptr 的原始指针。
  std::unique_ptr<MyClass> myPtr(new MyClass());
  MyClass* rawPtr = myPtr.get(); // 获取原始指针
  
  3)release()：释放 unique_ptr 的所有权，返回所管理的对象的指针，并将 unique_ptr 置为 nullptr。
  std::unique_ptr<MyClass> myPtr(new MyClass());
  MyClass* rawPtr = myPtr.release(); // 释放所有权
}<-

std::unique_ptr<MyClass> myPtr(new MyClass());
std::unique_ptr<MyClass> otherPtr = std::move(myPtr); // 转移所有权

}<-

10.委托构造函数

11.继承构造函数

12.nullptr
  表示空指针，而NULL本质上是一个int型(0).
void func(void *ptr){cout<<"fun ptr";}
void func(int i){cout<<"i";}

int main()
{
  func(NULL);//编译失败，会产生二义性
  func(nullptr);//输出 fun ptr；
  return 0;
}

13.final&override
  final:修饰类，表示该类禁止被派生
class Base final
{
public:
  virutal void test();
};

class Son: public final//编译失败
{};

  override:修饰派生类的成员函数，标明该类重写了基类函数；如果一个父类，不是该函数的虚函数，编译报错；
class Father
{
public:
  virtual test1(){}
  void test2(){}
};

class Son : public Father
{
public:
  test1() override{}
  test2() override{//报错}
};

14.default
  辅助声明构造函数
->{
class Test
{
public:
  int a;
  Test(int a){a = 10;}
};

int main()
{
  Test xx;//编译失败
}
}<-
->{
class Test
{
  Test() = default;
  int a;
  Test(int a){a = 10;}
};

int main()
{
  Test t;
  return 0;
}
}<-

15.delete
  用于禁止拷贝构造和赋值操作符
->{
class Test
{
public:
  A() = default;
  A(const &A) = delete;
  A& operator = (const &A) = delete;
  int a;
};

int main()
{
 A a1;
 A a2 = a1;//失败
 A a3；
 a3 = a1;//失败
}
}<-

16.explicit
  修饰构造函数，只能显示转换，不能隐式转换。
->{
class MyClass
{
public:
  explicit MyClass(int value) : num(value){}
  int value;
};

int mian()
{
  //显式构造函数创建对象
  MyClass a(6);

  // 错误示例：隐式类型转换将 int 转换为 MyClass
  // MyClass obj2 = 10;

  // 正确示例：显式类型转换将 int 转换为 MyClass
  MyClass obj3 = MyClass(10)
  return 0;
}
}<-

17、constexpr
  可用于修饰常量表达式，在编译时可以求值--->1、提前计算，避免运行时开销；2、在编译阶段，检测常量表达式的错误：除以0，越界等

18、enum class
  强枚举
->{
enum AColor 
{
    Red,
    Green,
};

enum BColor 
{
    White,
    Black,
};

int main() 
{
    if (Red == White 
    {
        cout << "red == white" << endl;
    }
    return 0;
}
}<-
->{
enum class AColor 
{
    Red,
    Green,
};

enum class BColor
{
    kWhite,
    kBlack,
};

int main()
{
    if (AColor::kRed == BColor::kWhite) // 编译失败
    { 
        cout << "red == white" << endl;
    }
    return 0;
}
}<-

19、static_assert
  一种静态断言机制，用于在编译时检查一些条件是否为真。如果断言条件为假，编译会失败，并显示一个错误消息。
  static_assert(condition, error_message);
->{
template<typename T>
void processValue(T value) 
{
    static_assert(std::is_integral<T>::value, "T must be an integral type.");
    // 处理值...
}

int main()
{
    int num = 10;
    processValue(num);  // 正确，T 是整型类型
    double pi = 3.14159;
    // processValue(pi);  // 错误，T 不是整型类型，编译时断言失败
    return 0;
}
}<-

20、新数据结构
  std::forword_list:单向链表；相对于std::list节省了内存，提高了性能
  std::unordered_set：基于hash表实现的set，内部不会排序，使用方法和set类似
  std::unordered_map：基于hash表实现的map，内部不会排序，使用方法和map类似
  std::array：数组，在越界访问时抛出异常，建议使用std::array替代普通的数组
  std::tuple：元组类型，类似pair，但比pair扩展性好
