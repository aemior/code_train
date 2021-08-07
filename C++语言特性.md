# C++语言特性

##  引用

类型名 & 引用名 = 变量名;

- 定义引用是一定要将其初始化引用某个变量

- 初始化后，他就一致引用该变量，不会再引用别的变量了

  ```c++
  double a=4,b=5;
  double &r1 = a;
  r1=b //r1并没有引用b
  ```

- 引用只能引用变量，不能引用常量和表达式

- **引用作为函数的返回值**

  ```c++
  int n=4;
  int &SetValue(){ return n;}
  int main(){
  	SetValue() = 40;
  	cout << n;
  	return 0;
  }
  ```

- **常引用** 定义引用时，前面加const关键字，即为“常引用” -> 不能通过常引用修改引用的内容

- **常引用和非常引用的转换** 常引用和常变量不能初始化普通引用（除非进行强制类型转换），普通引用和普通变量可以初始化常引用

## 动态内存分配

### 用new运算符实现动态内存分配

- 第一种用法，分配一个变量

  ```c++
  P = new T; // 动态分配出一片大小为sizeof(T)字节的内存空间，并且将该内存空间的起始地址赋值给P
  int *pn;
  pn = new int;
  *pn = 5
  ```

  T是任意类型名，P是类型为T*的指针。

- 第二种用法，分配一个数组

  ```c++
  P = new T[N]; // 动态分配出一片N*sizeof(T)字节的内存空间，并将该内存空间的其实地址赋值给P
  ```

  T：任意类型名	P：类型为T*的指针	N：要分配的数组元素的个数，可以是整型表达式

  ```c++
  int *pn;
  int i=5;
  pn = new int[i*20];
  pn[0] = 20;
  pn[100] = 30; // 编译没问题，运行时导致数组越界
  ```

- 两种方法的返回值都是一样的

  ```c++
  int *p1, *p2;
  p1 = new int;
  p2 = new int[100];
  ```

### 用delete运算符释放动态分配的内存

```c++
int *p = new int;
*p = 5;
delete p;
delete p; // 导致异常，一片空间不能被delete两次
delete []p; // 释放数组时需要加[]
```

## 内联函数、函数重载、函数缺省参数

- **内联函数** 减小调用函数产生的开销。编译器会将函数内部代码进行复制和替换

  ```c++
  inline int Max(int a, int b){
  	if(a > b) return a;
  	return b;
  }
  ```

- **函数重载** 一个函数或多个函数，名字相同，参数个数或参数类型不同，这叫做函数的重载。函数重载使得函数命名变得简单，编译器根据调用语句中的实参个数和类型决定调用哪个函数（当存在歧义的时候编译报错）（仅仅返回值类型不同时叫做重复定义）

- **函数的缺省参数** 定义函数的时候可以让最右边的连续若干个参数有缺省值，那么调用函数的时候，若相应位置不写参数，参数就是缺省值。（函数增加参数的时候可以不用改调用部分的代码）

## 类和对象的基本概念

### 结构化程序设计的不足

- 结构化程序设计中，函数和其所操作的数据结构，没有直观的联系
- 随着程序规模的增加，程序逐渐难以理解，很难一下子看出来：
  - 某个数据结构到底有哪些函数可以对它进行操作
  - 某个函数到底是用来操作哪些数据结构的
  - 任何函数之间存在怎样的调用关系
- 结构化程序设计没有“封装”和“隐藏”的概念。要访问某个数据结构中的某个变量，就可以直接访问，那么当该变量的定义有改动的时候，就要把所有访问该变量的语句找出来修改，十分不利于程序的维护、扩充
- 难以查错，当某个数据结构的值不正确时，难以找出到底是哪个函数导致
- 重用：在编写某个程序时，发现需要的某项功能，在现有的某个程序里已经有了相同或类似的实现，自然希望在新程序中使用
- 在结构化程序中，随着程序规模的扩大，由于大量函数程序之间的关系错综复杂，要抽取这部分代码，会变得十分困难。

### 面向对象程序设计的特点

- 将事物的共同特点归纳出来，形成一个数据结构。
- 将事物所能进行的行为也归纳出来，形成一组函数，用这组函数可以用来操作数据结构（这一步叫做“抽象”）
- 通过某种语法形式，将数据结构和操作数据结构的函数捆绑在一起，形成一个“类”，从而使得数据结构和操作数据结构的函数呈现出显而易见的紧密关系，这就是“封装”

### 类和对象

- **数据结构和操作函数封装成为一个类，类中的变量叫做成员变量，类中的函数叫做成员函数，通过类定义的变量叫做对象**
- **对象占用的存储空间是所有成员变量所占用的存储空间之和**
- 类的成员函数分开写
- 类的定义中，用下列访问范围关键字来说明类成员可被访问的范围
  - private 私有成员，只能在成员函数内访问
  - public 公有成员，可以在任何地方访问
  - protected 保护成员
- 以上三种关键字出现的次数和先后次序都没有限制
- 在类的成员函数内部，能够访问：
  - 当前对象的全部属性、函数
  - 同类其它对象的全部属性、函数
- 在类的成员函数以外，只能访问公有成员 **设置私有成员的机制叫做隐藏**（好处，只需要修改成员函数，而不需要到处修改访问成员变量的函数）

## 构造函数

- 成员函数的一种（已经开辟的内存中进行一些初始化操作）

  - 名字于类名相同，可以有参数，不能有返回值（void也不行）
  - 作用是对对象进行初始化，如给成员变脸赋初值
  - 如果定义类时没有写构造函数，则编译器生成一个默认的无参构造函数（不做任何操作）
  - 如果定义了构造函数，则编译器不生成默认的无参数构造函数
  - 对象生成时构造函数自动被调用。对象一旦生成，就再也不能在其上执行构造函数
  - 一个类可以有多个构造函数

- 为什么需要构造函数

  - 有了构造函数就不用专门的初始化函数，也不用担心忘记调用初始化函数
  - 有时候对象没有被初始化就使用，会导致程序出错

- 数组初始化时也会调用构造函数，并且根据参数进行重载

  ```c++
  class Test{
  	public:
  		Test(int n){}; // 1.
  		Test(int n, int m){}; // 2.
  		Test(){}; // 3.
  }
  Test array1[3] = {1, Test(1,2)} // 三个元素分别用1.2.3.初始化
  ```

## 复制构造函数

- 只有一个参数，即对同类对象的引用

- 形如 X::X(X&)或 X::X(const X &)，二者选一后者能以常量对象作为参数

- 如果没有定义复制构造函数，那么编译器默认生成复制构造函数

- 复制构造函数的参数必须是引用不能是对象

- 复制构造函数起作用的三种情况

  - 用一个对象去初始化另一个对象时

    ```c++
    Complex c1(c2);
    Complex c1 = c2; // 两种等价
    ```

  - **如果某函数有一个参数是类A的对象，那么该函数被调用时，类A的复制构造函数将被调用**

  - **如果某函数的返回值时类A的对象，则函数返回时，A的复制构造函数被调用**

- 常量引用参数的使用

  ```c++
  void fun(MyClass obj){} // 触发复制构造函数，增大开销
  void fun(MyClass & obj) // 使用引用避免调用复制构造函数
  void fun(const MyClass & obj) // 使用常引用，避免实参被修改
  ```

- 赋值构造函数 = 调用是对成员对象逐一调用 = 

## 类型转换构造函数

- 定义转换构造函数的目的是实现类型的自动转换
- 只有一个参数，而且不是复制构造函数的构造函数，一般就可以看做是转换构造函数

## 析构函数

- 名字和类名相同，在前面加‘~’，没有参数和返回值，一个类最多只能有一个析构函数
- 编译器自动生成的析构函数什么也不做
- 析构函数在对象作为函数返回值返回后被调用

## 构造函数和析构函数调用的时机



## 静态（static）成员变量和静态成员函数

```c++
class CRectangle{
    private:
    	int w,h;
    	static int nTotalArea;//静态成员变量
    	static int nTotalNumber;
    public:
    	CRectangle(int w_, int h_);
    	~CRectangle();
    	static void PrintTotal();//静态成员函数
}
```

- **普通成员变量每个对象各自有一份，静态成员变量一共一份，为所有对象共享**

- **sizeof 运算符不会计算静态成员变量**

- **普通成员函数必须具体作用于某个对象，而静态成员函数并不具体作用于某个对象**

- 静态成员不需要成员就能访问

- 静态成员变量是全局变量，一个对象都不存在，类的静态成员变量也存在

- 静态成员函数本质上是全局函数

- 设置静态成员这种机制的目的是将和某些类紧密相关的全局变量和函数写到类里面，看上去像一个整体，易于维护和理解。

- **必须在定义类的文件中对静态成员变量进行一次说明或初始化。否则编译能通过，链接不能通过**

  ```c++
  int CRectangle::nTotalNumber = 0;
  int CRectangle::nTotalArea = 0;
  ```

- 静态成员函数中，不能访问非静态成员变量，也不能调用非静态成员函数
- 注意复制构造函数，修改类的总数

## 成员对象和封闭类

**一个类的成员变量是另一个类的对象**

**包含成员对象的类叫做封闭类（Enclosing）**

```c++
class CTyre{
    private:
    	int radius;
    	int width;
    public:
    	CTyre(int r, int w):radius(r), width(w){}//初始化列表
};
class CEngine{};

class CCar{//汽车类->封闭类
   	private:
    	int price;
    	CTyre tyre;
    	CEnging engine;
    public:
    	CCar(int p, int tr, int tw);
    
};
CCar::CCar(int p, int tr, int w):price(p), tyre(tr, w){};

int main(){
    CCar car(20000, 17, 225);
    return 0;
}
```

- 如果CCar类不定义构造函数，编译就会出错，编译器不知道car.tyre该如何初始化
- 生成封闭类对象的语句->明确‘对象中的成员对象’->如何初始化
- 当封闭对象生成时
  1. 执行所有成员对象的构造函数
  2. 执行封闭类的构造函数
- 成员对象的构造函数调用顺序
  - 和成员对象在类中的说明顺序一致
  - 和成员初始化列表中出现的顺序无关
- 当封闭类的对象消亡时
  1. 先执行封闭类的析构函数
  2. 执行成员对象的析构函数

## 友元friend

**一个类的友元函数可以访问该类的私有成员**

```c++
class CCar;
class CDriver{
    public:
    	void ModifyCar(CCar *pCar);
};
class CCar{
    private:
    	int price;
    friend int MostExpensiveCar(CCar cars[], int total); //声明友元
    friend void CDriver::ModifyCar(CCar *pCar); //声明友元
}
```

**友元类，A是B的友元类->A的成员函数可以访问B的私有成员**

```c++
class CCar{
	private:
		int price;
	friend class CDriver;
};
class CDriver{
	public:
		CCar myCar;
		void ModifyCar(){
			myCar.price += 1000; //CDriver是CCar的友元类->可以访问其私有成员
		}
}；
```

**友元类之间的关系不能传递，不能继承**

## this指针

源于C++语言到C语言的翻译，相当于python里面的self，C++翻译到C语言时，成员函数会变为全局函数，参数会增加一个 this

- 其作用就是指向成员函数所作用的对象

- 非静态成员函数中可以直接使用this来代表指向该函数作用的对象的指针

  1. ```c++
     class Complex{
     	public:
     		double real, imag;
     		void Print(){ cout << real << "," << imag;}
     		Complex(double r, double i):real(r), imag(i){}
     		Complex AddOne(){
     			this->real ++;
     			this->Print();
     			return *this;
     		}
     };
     int main(){
     	Complex c1(1,1), c2(0,0);
     	c2 = c1.AddOne();
     	return 0;
     }
     ```

  

  - **类的空指针也可以正确调用成员函数（内部不访问对象的情况下）**

- 静态成员函数中不能使用this指针，因为静态成员函数并不具体作用于某个对象，静态成员函数的真实参数个数就是程序中写出的参数个数

## const关键字的用法

- 定义常量

- 定义常量指针

  - 不可以通过常量指针修改其指向的内容

    ```c++
    int n,m;
    const int *p= &n;
    *p=5; //编译出错
    n=4; //ok.
    p=&m //ok. 常量指针的指向可以变化
    ```

  - 不能把常量指针复制给非常量指针，反过来可以

    ```c++
    const int *p1; int * p2;
    p1=p2; //ok.
    p2=p1; //error.
    p2=(int *)p1; //ok. 强制类型转换
    ```

  - 函数参数为常量指针时，可避免函数内部不小心改变参数指针所指地方的内容

    ```c++
    void MyPrintf(const char *p){
    	strcpy(p, "this"); //编译出错
    	printf("%s", p); //ok.
    }
    ```

## 常量对象、常成员函数和常引用

**如果不希望某个对象的值被改变，则定义该对象的时候可以在前面加const关键字**

```c++
class Demo{
    private:
    	int value;
    public:
    	void SetValue(){}
};

const Demo Obj; //常量对象 （不能修改值）

class Sample{
    public:
    	int value;
    	void GetValue() const; //常量成员函数
    	void func(){};
    	Sample(){};
};

void Sample::GetValue() const{
    value = 0; //wrong
    func(); //wrong
}

int main(){
    const Sample o;
    o.value = 100; //err.常量对象不可被修改
    o.func(); //err.常量对象上面不能执行非常量函数
    o.GetValue(); //ok.常量对象上可执行常量成员函数
    return 0;
}
```

- 在类的成员函数说明后面可以加const 关键字，则该成员函数成为常量成员函数
- 常量成员函数执行期间不应修改其所作用对象。因此，在常量成员函数中不能修改成员变量的值（静态成员变量除外）， 也不能调用同类的非常量成员函数（静态成员函数除外）。

- **常量成员函数的重载**：可以为一个成员函数编写常量版本和非常量版本，调用时根据是否是常量对象来重载

- **常引用**

  1. 对象作为函数的参数时，生成该参数需要调用复制构造函数，效率比较低。用指针作为参数，代码又不好看->所以使用引用
  2. 使用引用后有可能出现修改对象值的情况，所以添加const关键字作为常引用

  ```c++
  class Sample{
  	...	
  };
  void PrintfObj(const Sample &o){ //确保函数中出现无意中修改o值的语句
  	...
  }
  ```


## 运算符重载

有时候希望对象也能通过运算符进行运算。代码更简洁和容易理解。不同类型的操作数，发生的行为不同。

```c++
class Complex{
    public:
    	double real,imag;
    	Complex(double r=0.0, double i=0.0):real(r),imag(i) {}
    	Complex operator-(const Complex &c);
}
Complex operator+(const Complex &a, const Complex & b){
    return Complex(a.real+b.real, a.imag+b.imag); // 返回一个临时对象
}
Complex Complex::operator-(const Complex &c){
    return Complex(real - c.real, imag - c.imag); // 返回一个临时对象
}
```

## 赋值运算符重载

**赋值运算符只能重载为成员函数**

```c++
class String(){
    private:
    	char * str;
    public:
    	String():str(new char[1]){str[0] = 0}
    	const char * c_str(){return str;}
    	String & operator = (const char * s){
            delete [] str;
            str = new char[strlen(s)+1];
            strcpy(str, s);
            return * this;
        }
    	~String(){delete [] str;}
}
/*
返回值的设置
void 好不好？
a=b=c; --> a = void
String 好不好？
(a=b)=c; --> 修改了a
*/
```

## 运算符重载为友元函数

```c++
class Complex{
    double real,imag;
    public:
    	Complex(double r, double i):real(r), imag(i){};
    	Complex operator+(double r);
}
Complex Complex::operator+(double r){
    return Complex(real + r, imag);
}
// Complex r(1,2);
// r = r + 5;
// r = 5 + r; --> 编译出错
Complex operator+(double r, const Complex & c) // 重载为普通函数 但是不能访问私有对象

friend Complex operator + (double r, const Complex &c); // 重载为友元函数
```

## 可变长度数组的实现

```c++
#include <iostream>
#include <string.h>

using namespace std;

class CArray{
    private:
        int * ptr;
        int size;
    public:
        CArray();
        CArray(CArray &);
        ~CArray();
        void push_back(int);
        int length();
        int & operator[](int);
        CArray & operator=(CArray);
};

CArray::CArray(){
    size = 0;
    ptr = NULL;
}
CArray::CArray(CArray & a){
    ptr = NULL;
    size = a.size;
    if(a.size){
        ptr = new int[size];
        memcpy(ptr, a.ptr, sizeof(int)*size);
    }
}

CArray::~CArray(){
    if(size){
        delete []ptr;
    }
}

void CArray::push_back(int i){
    if(size){
        int * tmp = new int[size+1];
        memcpy(tmp, ptr, sizeof(int)*size);
        delete []ptr;
        ptr = tmp;
        ptr[size] = i;
    }
    else{
        ptr = new int[1];
        ptr[0] = i;
    }
    ++size;
}

int CArray::length(){
    return size;
}

int & CArray::operator[](int i){
    return ptr[i];
}

CArray & CArray::operator=(CArray a){
    if(size){
        delete []ptr;
        ptr = NULL;
    }
    size = a.size;
    if(a.size){
        ptr = new int[size];
        memcpy(ptr, a.ptr, sizeof(int)*a.size);
    }
    return *this;
}

int main(){
    CArray a; // 开始时数组是空的
    for(int i=0; i<5; ++i){
        a.push_back(i); // --> 动态分配内存
    }
    for(int i=0; i<a.length(); ++i){
        cout << a[i] << ' '; // -->重载[]
    }
    cout << endl;
    CArray a2, a3;
    a2 = a; // --> 重载=
    for(int i=0; i<a.length(); ++i){
        cout << a2[i] << ' '; // -->重载[]
    }
    a2 = a3; // a2是空的
    for(int i=0; i<a2.length(); ++i){ // a2.length()返回0
        cout << a2[i] << ' ';
    }
    cout << endl;
    a[3] = 100;
    CArray a4(a); // --> 自定义复制构造函数
    for(int i=0; i<a4.length(); ++i){
        cout << a4[i] << ' ';
    }
    return 0;
}
```

## 流插入运算符的重载

如何实现 cout << 5 << "this";

```c++
ostream & ostream::operator<<(int n){
    ... ...// 输出 n 的代码
    return * this;
}
```

 全局函数重载的情况

```c++
ostream & operator<<(ostream & o, const CStudent){
	o << s.nAge;
	return o;
}
```

## 类型转换运算符

```c++
#include <iostream>

using namespace std;

class Complex{
    double real, imag;
    public:
    	Complex(double r=0, double i=0):real(r), imag(i) {}
    	operator double（）{return real;}
}
int main(){
    Complex c(1.2,3.4);
    cout << (double)c << endl; // 输出1.2
    double n = 2 + c; // 等价于 double n = 2 + c.operator double()
    cout << n; // 输出 3.2
}
```

## 自增自检运算符的重载

```c++
#include <iostream>

using namespace std;

class CDemo{
    int v;
    public:
    	CDemo(int i=0):v(i) {}
    	CDemo(const CDemo & i):v(i.v) {}
    	CDemo operator++(int);
    	CDemo & operator++();
	operator int(){return v;}
	friend CDemo & operator--(CDemo &);
	friend CDemo operator--(CDemo &, int);
};

CDemo CDemo::operator++(int){
    CDemo tmp(*this);
    v++;
    return tmp;
}
CDemo & CDemo::operator++(){
    v++;
    return *this;
}
CDemo operator--(CDemo & a, int){
    CDemo tmp(a);
    a.v--;
    return tmp;
}
CDemo & operator--(CDemo & a){
    a.v--;
    return a;
}

int main(){
    CDemo d(5);
    cout << (d++) << ',';
    cout << d << ',';
    cout << (++d) << ',';
    cout << d << endl;
    cout << (d--) << ',';
    cout << d << ',';
    cout << (--d) << ',';
    cout << d << endl;
    return 0;
}
```

### 运算符重载的注意事项

1. c++不运行定义新的运算符
2. 重载后运算符的含义应该符合日常习惯
3. 运算符重载不改变运算符优先级
4. 以下运算符不能被重载：, * :: ?: sizeof;
5. 重载运算符()、[]、->或者运算符=时，运算符重载函数必须声明为类的成员函数

## 继承和派生的基本概念

- **继承**：在定义一个新类B时，如果该类与某个已有的类A相似（指B拥有A的全部特点），那么就可以把A作为一个基类，而把B作为基类的一个派生类。
- 派生类可以扩充新的成员变量和成员函数。
- 派生类拥有基类的全部成员函数和成员变量，不论private、protected、public
  - 在派生类的各个成员函数中，不能访问基类中的private成员
- 派生类对象的内存空间：基类对象的体积，再加上派生类对象自己的成员变量的体积。派生类对象包含着基类的对象，而基类对象的存储位置位于派生类对象新增的穿越变量之前。

## 继承关系和复合关系

**类和类之间的关系**： 没关系、继承关系、复合关系

- 继承：‘是’ 关系
  - 基类 A,B是A的派生类
  - 逻辑上要求->一个B对象也是一个A对象
- 复合：‘有’ 关系
  - 类C中有成员变量k,k是类D的对象，则C和D是复合关系（封闭类）
  - 一般逻辑上要求：D对象是C对象的固有属性或组成部分

继承关系： CHuman-> CMan; CHuman-> CWoman;

复合关系：几何程序中需要点类和圆类，园中需要包含点类，而不是继承点类再加一个半径。

**在涉及复合关系时，需要注意循环定义** -> **可能导致循环定义的地方使用指针**

## 覆盖

- 派生类可以定义一个和基类成员同名的成员，这叫覆盖。在派生类中访问这类成员时，缺省的情况时访问派生类中定义的成员。要在派生类中访问由基类定义的同名成员时，要使用作用域符号::。
- **尽量不覆盖成员变量，然而覆盖成员函数是很常见的**

## 保护成员 protected

- 基类的private成员：可以被下列函数访问
  - 基类的成员函数
  - 基类的友元函数
- 基类的public成员：可以被下列函数访问
  - 基类成员函数
  - 基类友元函数
  - 派生类成员函数
  - 派生类友元函数
  - 其他函数
- 基类的protected成员：可以被下列函数访问
  - 基类的成员函数
  - 基类的友元函数
  - 派生类的成员函数可以访问当前对象的基类保护成员

## 派生类的构造函数

```c++
class Bug {
    private:
    	int nLegs; int nColor;
    public:
    	int nType;
    	Bug (int legs, int color);
    	void PrintBug （）{};
};
class FlyBug: public Bug {
    	int nWings;
    public:
    	FlyBug(int legs, int color, int wings);
}
Bug::Bug(int legs, int color){
    nLegs = legs;
    nColor = color;
}
FlyBug::FlyBug(int legs, int color, int wings):Bug(legs, color),
nWings(wings){}
```



- 创建派生类对象时，需要调用基类的构造函数：初始化派生类对象中从基类继承的成员。在执行一个派生类的构造函数之前，总是先执行基类的构造函数。
- 调用基类构造函数使用显式方式或是隐式方式，隐式方式调用无参构造函数，如果基类没有无参构造函数则编译出错
- 析构函数执行时，先执行派生类的析构函数，再执行基类的析构函数

**构造函数调用顺序**

1. 先执行基类的构造函数
2. 在执行成员对象的构造函数
3. 最后执行派生类自己的构造函数

**析构函数调用顺序**

1. 先执行派生类自己的析构函数
2. 执行成员对象的析构函数
3. 执行基类的析构函数

## 公有（public）继承的赋值兼容规则

```c++
class base{};
class derived:public base{};
base b;
derived d;
```

1. 派生类的对象可以赋值给基类对象

   b=d;

2. 派生类可以初始化基类引用

   base &br = d;

3. 派生类的地址可以赋值给基类指针

   base *br = &d;

**直接基类和间接基类**

- 派生类包含直接基类和所有间接基类的所有成员
- 构造函数先执行最底层的基类构造函数

## 虚函数

- 加入virtual 关键字的成员函数就是虚函数
- virtual关键字只能用在定义的声明中，实现时不用加
- 构造函数和静态成员函数不能是虚函数

## 多态的表现形式一（指针）

- 派生类的指针可以赋给基类指针
- 通过基类指针调用基类和派生类中的同名虚函数时：
  1. 若该指针指向一个基类的对象，那么被调用时基类的虚函数
  2. 若该指针指向一个派生类的对象，那么被调用的是派生类的虚函数

## 多态的表现形式二（引用）

- 派生类的对象可以赋给基类引用
- 通过基类引用调用基类和派生类中的同名虚函数时：
  1. 若该引用引用的是一个基类的对象，那么被调用是基类的虚函数
  2. 若该引用引用的是一个派生类的对象，那么被调用的是派生类的虚函数

**多态增加程序的可扩充性**

重载函数的参数为基类的多个派生类时，使用多态可以避免冗余重载代码

**纯虚函数** virtual void fun() = 0;

**用基类指针存放指向各种派生类对象的指针，然后遍历该数组，就能对各个派生类对象做各种操作，是很常用的做法**

**非构造函数，非析构函数的成员函数中调用虚函数，是多态，反之不是多态**

## 多态的实现原理

- 编译时不知道是基类的函数还是派生类的函数，运行时确定。使用**动态联编**实现

- 多态增加了空间上的开销，需要一个指针指向虚函数表，增加了空间上的开销，需要查表调用虚函数。

```c++
#include <iostream>
using namespace std;
class A {
    public: virtual void Func() { cout << "A::Func" << endl;}
};
class B:public A {
    public: virtual void Func() { cout << "B::Func" << endl;}
};
int main() {
    A a;
    A *pa  = new B(); // 正常多态 输出 B::Func
    long long *p1 = (long long *) &a; 
    long long *p2 = (long long *) pa;
    *p2 = *p1; // 修改虚函数表的地址
    pa->Func(); // 修改虚函数表的地址 输出 A::Func
    return 0;
}
```

## 虚析构函数

- 通过基类的指针删除派生类的对象时，通常情况下只调用基类的析构函数
  - 但是，删除一个派生类的对象时，应该先调用派生类的析构，然后调用基类的析构函数
- 解决办法：把基类的析构函数声明为virtual
  - 派生类的析构函数可以virtual不进行声明
  - 通过基类的指针删除派生类的对象时，首先调用派生类的析构函数，然后调用基类的析构函数
- 一般来说，一个类如果定义了虚函数，则应该将析构函数也定义成虚函数。或者，一个类打算作为基类使用，也应该将析构函数定义成虚函数。

## 纯虚函数和抽象类

- 没有函数体的函数是纯虚函数
- 包含纯虚函数的类是抽象类，不能创造对象
- 构造函数和析构函数中不能调用纯虚函数

## 输入输出流

- stdin stdout stderr/cin cout cerr

- freopen

- 判断输入是否结束 while(cin >> x) 

  - 如果文件输入，读到文件末尾输入结束
  - 如果键盘输入，Ctrl + z 输入结束

- cin.getline(char *buf, int bufSize)

  从输入流中读取bufSize-1个字符到缓冲区buf，或读到碰到‘\n’为止

- cin.geline(char *buf, int bufSize, char delim)

  从输入流中读取bufSize-1个字符到缓冲区buf，或读到碰到delim或‘\n’为止

- 可以用 if(!cin.getline())判断输入是否结束

- bool eof() 判断输入流是否结束

- int peek() 返回下一个字符，但不从流中去掉

- cin.putback(char c) 将字符c放回输入流

- cin.ignore(int nCount=1, int delim=EOF) 从流中删除最多nCount个字符，遇到EOF结束

## 流操作算子

- 整数流的基数 dec，oct，hex，setbase

- 浮点数精度 precision,setprecision

- 设置域宽度（setw, width）

- 用户自定义的流操作算子 

- #include \<iomanip>

- setiosflags(ios::fixed),resetiosflags(ios::fixed)

- 设置宽度cin >> setw(4)

- showpos 显示正号

- setfill('*')设置填补

- 用户自定义流操作算子

  ```c++
  ostream &tab(ostream &output) {
      return outpur << '\t';
  }
  ostream & opeartor<<(ostream & (*p)(ostream &));
  ```

## 文件读写

```c++
ofstream fout("out.dat", ios::app);
ifstriam fin("in.dat", ios::in);
long location  = fout.tellp();
location = 10;
fout.seekp(location, ios::beg);
fout.seekp(location, ios::curr);
fout.seekp(location, ios::end);


```

## 二进制文件读写

```c++
istream& read (char* s, long n);
istream& write (const char* s, long n);
fstream f("some.data", ios::out|ios::in|ios::binary);

f.write("Mike", strlen("Mike")+1);

readBytes = inFile.gcount();

struct Student{
    char name[20];
    int score;
};
// Linux 下打开文件，用不用ios::binary没有区别
```

## 函数模板

```c++
template <class T>
void Swap(T &x, T &x){
    	T tmp = x;
    	x = y;
    	y = tmp;
}
```

- 模板生成函数的过程叫做模板的实例化
- 不通过实参也可以实例化
- 函数模板的调用顺序：
  1. 先找参数完全匹配的普通函数
  2. 再找参数完全匹配的模板函数
  3. 再找实参经过自动类型转换后能匹配的普通函数
  4. 如果上面都找不到则报错

## 类模板

```c++
template <class T>
class A{
    public:
    	template<class T2>
        void Func(T2 t) {cout << t;}
}
```

非类型参数

```c++
template <class T, int size>
class CArray{
	T array[size];
	public:
		void Print(){
			for (int i=0; i<size; ++i)
				cout << array[i] << endl;
		}
}

CArray<double, 40> a2;
CArray<int, 50> a3;
```

## 类模板于派生、友元、静态成员变量

```c++
template <class T1, class T2>
class A {
    T1 v1; T2 v2;
}
template <class T1, class T2>
class B:public A<T2, T1> {
    T1 v3; T2 v4;
}
template <class T>
class C:public B<T, T> {
    T v5;
}
```

- 类模板包含静态成员变量，需要单独进行声明，因为不同实例化类的静态成员变量会存储在内存的不同位置

  ```c++
  template<> int A<int>::count = 0;
  template<> int A<double>::count = 0;
  ```


## 泛型程序设计

- 简单说就是使用模板的程序设计法，将一些常用的数据结构（比如链表，数组，二叉树）和算法（比如排序，查找）写成模板

  1. **容器** 可容纳各种数据类型的通用数据结构，是类模板

  2. **迭代器** 可用于依次存取容器中的元素，类似于指针

  3. **算法** 用来操作容器中的元素的函数模板

     - sort（）用来对vector中的数据进行排序
     - find（）用来搜索一个list中的对象

     算法本身与他们操作的数据的类型无关，因此他们可以在从简单数组到高度复杂容器的任何数据结构上使用

### 容器

**顺序容器**，元素的插入位置同元素的值无关

- vector ，增删元素（大部分情况下是常数时间），中间插入删除元素，不是常数时间
- deque，双向队列，两端增删元素具有相对vector更好的性能
- list 双向链表，元素在内存内不连续存放。在任何位置增删元素都能在常数时间完成。不支持随机存取

**关联容器**，元素是排序的，插入任何元素都会根据相应的排序规则来确定其位置，在查找时具有非常好的性能，通常以平衡二叉树来实现，插入和检索的时间都是O(log(N))

- seg/multiset
- map/multimap

**容器适配器**

- stack 后进先出
- queue 先进先出
- priority_queue 优先级队列

### 迭代器

用于指向顺序容器和关联容器中的元素

容器类型::iterator/容器类型::reverse_iterator -> 容器对象.begin()/end()/rbegin()/rend()

| 容器           | 容器上的迭代器级别 |
| -------------- | ------------------ |
| vector         | 随机访问           |
| deque          | 随机访问           |
| list           | 双向               |
| set/multiset   | 双向               |
| map/multimap   | 双向               |
| stack          | 不支持迭代器       |
| queue          | 不支持迭代器       |
| priority_queue | 不支持迭代器       |
|                |                    |

### 算法

通过迭代器来操作容器中的元素，有的算法返回容器的迭代器

- find(first, last, val) 查找[first, last)中间等于val的元素
- binery_search

### 函数对象

一个类重载了（），那么相应的对象就是函数对象

**STL中还有函数对象模板** P208



## STL算法

- **不变序算法** 时间

  | 算法名称    | 功能                                                     |
  | ----------- | -------------------------------------------------------- |
  | min         | 求两个对象中较小的（自定义比较器）                       |
  | max         | 求两个对象中较大的（自定义比较器）                       |
  | min_element | 求区间中最小值（自定义比较器）                           |
  | max_element | 求取件中最大值（自定义比较器）                           |
  | for_each    | 对区间中的每个元素都做某种操作                           |
  | count       | 计算区间中等于某值的元素个数                             |
  | count_if    | 计算区间中符合某种条件的元素个数                         |
  | **find**    | 在区间中查找等于某值的元素                               |
  | **search**  | 区间中查找另一区间第一次出现的位置                       |
  | **equal**   | 判断两个区间是否相等                                     |
  | mismatch    | 逐个比较两个区间的元素，返回第一次不相等的两个元素的位置 |
  |             |                                                          |
  |             |                                                          |
  |             |                                                          |

- **变值算法** （不可以属于关联容器）

  | 算法名称      | 功能                                           |
  | ------------- | ---------------------------------------------- |
  | for_each      | 对区间中的每个元素都做某种操作                 |
  | copy          | 复制一个区间到别处                             |
  | copy_backward | 复制一个区间到别处，目标区间是从后往前被修改的 |
  | transform     | 将一个区间的元素变形后拷贝到另一个区间         |
  |               |                                                |

- **删除算法** 删除不会使容器的元素减少（不可用于关联容器）

  | 算法名称    | 功能                                                         |
  | ----------- | ------------------------------------------------------------ |
  | **remove**  | 删除区间中等于某个值的元素                                   |
  | remove_if   | 删除区间中满足某种条件的元素                                 |
  | **unique**  | 删除区间中连续相等的元素，只留下一个                         |
  | unique_copy | 拷贝区间到另一个区间，连续相等的元素，只拷贝第一个到目标区间（可自定义比较器） |
  |             |                                                              |

- **变序算法** 改变元素顺序但是不改变元素的值（不可用于关联容器）

  

- **排序算法** 需要随机迭代器支持

- **有序区间算法** 要求所操作的区间是已经从小到达排好序的，随机访问迭代器

  | 算法名称          | 功能                                           |
  | ----------------- | ---------------------------------------------- |
  | **binary_search** | 判断区间中是否包含某个元素                     |
  | includes          | 判断是否一个区间中的每个元素都在另一个区级那种 |
  | **lower_bound**   | 查找最后一个不小于某值元素的位置               |
  | **upper_bound**   | 查找第一个大于某值的元素的位置                 |
  | **equal_range**   | 同时获取lower_bound和upper_bound               |
  | merge             | 合并两个有序区间到第三个区间                   |
  | set_**            | 有序区间集合操作                               |
  |                   |                                                |

  

- 数值算法

  | 算法名称 | 功能 |
  | -------- | ---- |
  | bitset   |      |
  |          |      |
  |          |      |
  |          |      |
  |          |      |

## C++ 11新特性

### 统一初始化方法 {}

### 成员变量默认初始值

### auto关键字

### decltype 关键字，求表达式的类型

### 空指针nullptr

### 基于范围的for循环

### 智能指针 shared_ptr

- 头文件 \<memory\>

- 通过shared_ptr的构造函数，可以让shared_ptr对象托管一个new运算符返回的指针，写法如下

  shared_ptr\<T\> ptr(new T); // T可以使 int char 类名等各种类型

  此后ptr就可以像 T* 类型的指针一样来使用，即 *ptr就是用new动态分配的那个对象，而且不必操心释放内存的事

### 右值引用和move语义 

避免深拷贝

### 无序容器（哈希表）

\<unordered_map\>

### 正则表达式

\<regex\>

### Lambda表达式

### 强制类型转换

- static_cast 低风险转换，不能用于不同类型的指针之间的转换
- reinterpred_cast 不同类型的指针之间的转换、不同类型的引用之间的转换
- const_cast 去除const属性的类型转换
- dynamic_cast 专门用于多态基类的指针进行进行转换，并且能够检查转换的安全性（返回NULL，或抛出异常）

## 异常处理

- 把异常于函数的接口分开，并且能够区分不同的异常

- 在函数体外捕获所发生的异常，并提供更多的异常信息

  try throw catch

**\<stdexcept\>**

- **bad_cast** bad_cast&e e.what
- **bac_alloc** new运算符无法开辟内存空间
- **out_of_range** vector或string的at成员函数下标越界
