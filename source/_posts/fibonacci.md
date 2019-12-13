---
title: 求Fibonacci数列的两种实现方式
categories: 算法
mathjax: true
---
# Fibonacci数列
##  定义:
|1|1|2|3|5|8|....|
|-|-|-|-|-|-|-|
> 从第3项开始，每一项都等于前两项之和。

**表达式:**
$$ f(i)=\begin{cases}
1 & i=1,2\\
 f(i-1)+f(i-2)& i>2 
\end{cases}$$

## C语言递归实现
通过定义可以容易写出fibinacci数列递归形式
```c
#include <stdio.h>
int Fib(int i)
{
    if (i == 0 || i == 1)//数组从下标0开始
        return 1;
    return Fib(i - 1) + Fib(i - 2);
}

int main()
{

    int f[20];
    // 设值
    for (int i = 0; i < 20; i++)
    {
        f[i] = Fib(i);
    }
    // 打印输出
    for (int j = 0; j < 20; j++)
    {
        printf("%d\n", f[j]);
    }
}
```
## 非递归实现
在某些时刻,递归思考起来很简答,但是它的效率不高.
如果能直接获得前两项的值$f(i-1)和f(i-2)$而不是一层一层的递归下去求解,那么效率明显会提高.
设数组$a[i]=a[i-1]+a[i-2]$是不是和上面的式子很像.但这里数组可以直接通过下标取值,不需要一层一层递归下区求解

```c
#include <stdio.h>
int main()
{

    int f[20];
    // 设置前两项的值
    f[0] = 1;
    f[1] = 1;
    // 设置
    for (int i = 2; i < 20; i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    // 打印输出
    for (int j = 0; j < 20; j++)
    {
        printf("%d\n", f[j]);
    }
}
```
## end
如果你对递归和非递归的效率问题还不是很理解,当你把上面代码中的求前20项的数值改大一些你就能感受到二者的效率差别.

