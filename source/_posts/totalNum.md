---
title: C语言统计某个字符串中某个单词出现的次数
date: 2019-12-14
tags: 
    - C语言
    - 统计单词
---
## strstr()
> `char *strstr(const char *s1, const char *s2)`　在头文件`string.h`中，作用是返回字符串中首次出现子串的地址,没有找到返回NULL

## 思想：
1. 在一个字符串str中找到指定单index词(strstr不返回NUll)，计数变量count++。
2. 修改str为index之后的字符串，重复（1）
3. 若在str中找不到index程序结束，输出结果
**代码**

```c
#include<stdio.h>
#include<string.h>
int main()
{
    char *p="hellodfdfshellodsfaffehellodfafehellodfsdfg";
    int count=0;
    while (1)
    {
        char * index = strstr(p,"hello");
        if(index==NULL)//没有找到
        {
            break;
        }
        count++;//找到一次
        //修改p地址 p=这一次出现hello的地址+hello的长度
        p=index+strlen("hello");
    }

    printf("%d\n",count);
    
}
```


