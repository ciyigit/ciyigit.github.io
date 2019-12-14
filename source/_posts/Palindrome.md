---
title: C语言判断一个字符串是不是回文
date: 2019-12-14
tag:
    - c语言
    - 回文
---
# 回文
## 定义：
回文一般指 从前往后和从后往前读的顺序一样 比如一个回文字符串 "ABCBA"
## 实现
一般横容易想到下面的方法：
{% asset_img 1.png%}
就是从头和尾开始依次比较
**{%asset_link isPalindrome.c 代码%}**
```c
int isPalindrome(char *str, int n)
{
    int times = n/2;//比较的次数
    char *first = str;//指向头
    char *end = str + n - 1;//指向尾
    while (times)
    {
        if (*first != *end)//头尾内容是否一致
        {
            return -1;//不是回文
        }
        //移动到下一个位置
        first ++;
        end --;
        times--;
    }
    //是回文
    return 1;
}
```
