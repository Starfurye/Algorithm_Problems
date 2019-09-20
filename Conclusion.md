## 排序

1. (PAT_A1047) 不存储实际值，而利用索引和巧妙的sort函数排序：

```C++
bool cmp(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}
```

2. 若`32-321` 大于 `32-132`：

```C++
bool cmp(string a, string b) {return a + b < b + a;}
```





## 空间换时间

### 哈希表

1. (PAT_A1084) 直接以字符的ASCII码作为索引；
2. (PAT_A1052) 链表地址只有五位，可以直接用地址作为下标；



## 字符串处理

### scanf(), getline(), getchar()

`scanf()` 以空格、制表符tab、换行符为截止标识，而 `getline(cin, str)` 以换行符为截止标识，因此若要在使用 `scanf()` 后用 `getline()`，先用 `getchar()` 读取空格。



## 常用function

### lower_bound( ), upper_bound( )

(PAT_A1085)

`lower_bound( )` 和 `upper_bound( )` 利用二分查找的方法在一个排好序的数组中进行查找。

 在从小到大的排序数组中，

   `lower_bound(begin,end,num)`：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的索引，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。

   `upper_bound(begin,end,num)`：从数组的begin位置到end-1位置二分查找第一个大于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。



## 技巧

### 两点法

(PAT_A1048) 基本思路为使用两个下标（反向或同向）对两个序列进行扫描，达到较低的时间复杂度（O(n)）：

```C++
while(i < j) {
    if (a[i] + a[j] == m) {
        printf("%d %d\n", i, j);
        ++i;
        --j;
    }
    else if (a[i] + a[j] < m) {
        ++i;
    }
    else --j;
}
```



### 边读边处理

(PAT_A1029) 可以防止内存超限。



### 打表

(PAT_A1093) 事前把一些能计算好的量存到数组里（可手动），实在没有办法的时候用于解决超时问题。



### map妙用

(PAT_A1022) 书的**每个属性**都用string存储且**都要分别和id建立映射**，由于需要字典序输出且唯一，id用set储存：

```C++
map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;
```

(PAT_A1034) 

```C++
map<int, string> intToString;
map<string, int> stringToInt;
```

单个的map用value来查找key或使用find又会增加复杂度，所以可以使用这种双map来提供快速转换功能。



### 特殊（边界）情况测试与处理 



## 调试

```C++
#include <stdio.h>   
#include <iostream.h>   
int main()   
{   
    int a,b;   
    freopen("debug\\in.txt","r",stdin); //输入重定向，输入数据将从in.txt文件中读取   
    freopen("debug\\out.txt","w",stdout); //输出重定向，输出数据将保存在out.txt文件中   
    while(cin>>a>>b)   
    cout<<a+b<<endl; // 注意使用endl   
    fclose(stdin);//关闭文件   
    fclose(stdout);//关闭文件   
    return 0;   
}  
```

