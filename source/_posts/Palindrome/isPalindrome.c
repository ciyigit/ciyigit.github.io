#include <stdio.h>
#include <string.h>
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
int main()
{
    char str[] = "abcba";
    int n = strlen(str);
    int index = isPalindrome(str, n);
    index==1? printf("%s是回文\n",str):printf("%s不是回文\n",str);
   
    return 0;
}