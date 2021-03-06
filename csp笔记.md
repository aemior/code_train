### **格式化说明符**

\------------------------------------------------------------
格式字符      说明
\------------------------------------------------------------
%a         读入一个浮点值(仅C99有效)
%A         同上
%c         读入一个字符
%d         读入十进制整数
%i          读入十进制，八进制，十六进制整数
%o         读入八进制整数
%x          读入十六进制整数
%X         同上
%c         读入一个字符
%s         读入一个字符串
%f          读入一个浮点数
%F         同上
%e         同上
%E         同上
%g         同上
%G         同上
%p         读入一个指针
%u         读入一个无符号十进制整数
%n         至此已读入值的等价字符数
%[]         扫描字符集合
%%         读%符号
另外，还有附加格式说明字符，用于追加在上面的格式说明符后面。
\-----------------------------------------------------------------
修饰符            说明
\-----------------------------------------------------------------
L/l              长度修饰符，输入"长"数据
h               长度修饰符，输入"短"数据
W              整型常数，指定输入数据所占宽度
\*               星号，空读一个数据
hh              同 h，但仅对C99有效
ll               同 l，但仅对C99有效

例如%4.2f中，4表示总的长度的**最小值**，而2表示**小数位数**, **遵循四舍五入的原则**

### 字符数字转化

```c++
long long o;
int it
sscanf(ttstr.c_str(), "%Ld", &o);
string ttstr;
char buf[100];
sprintf(buf,"%d", it);
string tpstr(buf);
ttstr = ttstr + tpstr;
```

### 数字每一位

```c++
int n = 1234790324;
while(n>0){
    cout << ' ' << n%10;
    n=n/10;}
```

### C++98数组初始化vector

```c++
int int_array[] = {1, 2, 3, 4}; 
vector<int> vec_int(int_array, int_array+4);
```

### sort函数用法

```c++
int a[] = {1,5,7,8,2,2,6};
vector<int> v(a, a+7);
sort(v.begin(), v.end(), mycmp);
sort(a, a+7, mycmp);
```

### set函数用法

```c++
class CTestCmp {
public:
        bool operator() (int i, int j) {
                //return !!(lc.num < rc.num);
                return i>j;
        }
};
set<int, CTestCmp> s;
```

