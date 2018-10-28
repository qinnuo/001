// checking.c -- 输入验证
#include <stdio.h>
#include <stdbool.h>
// 验证输入是一个整数
long get_long(void);
// 验证范围的上下限是否有效
bool bad_limits(int begin, int end, int low, int high);
// 计算 a~b 之间的整数平方和
double sum_squares(long a, long b);
int main(void)
{
    const long MIN = -10000000L;    // 范围的下限
    const long MAX = +10000000L;    // 范围的上限
    int start;                     // 用户指定的范围最小值
    int stop;                      // 用户指定的范围最大值
    double answer;

    printf("This program computes the sum of the squares of "
           "intefers in a range.\nThe lower bound should not "
           "be less than -10000000 and\nthe upper bound "
           "should not be more than +10000000.\nEnter the "
           "limits (enter 0 for both limits to quit):\n"
           "lower limit: ");
    start = get_long();
    printf("upper limit: ");
    stop = get_long();
    while (start != 0 || stop != 0)
    {
        if (bad_limits(start, stop, MIN, MAX))
            printf("Please try again.\n");
        else
        {
            answer = sum_squares(start, stop);
            printf("The sum of squares of the integers ");
            printf("from %1d to %1d is %g\n", start, stop, answer);
        }
        printf("Enter the limits (enter 0 for both )"
               "limits to quit):\n");
        printf("lower limit: ");
        start = get_long();
        printf("upper limit: ");
        stop = get_long();      
    }
    printf("Done.\n");

    return 0;
}


// function 1
long get_long(void)
{
    int input;
    char ch;
    
    while (scanf("%1d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);    // 处理错误输入
        printf(" is not an integer.\nPlease enter an");
        printf("integer value, such as 25, -178, or 3: ");
    }
    
    return input;
}

// function 2
double sum_squares(long a, long b)
{
    double total = 0;
    long i;
     
    for (i = a; i <= b; i++)
        total += (double) i * (double) i;

    return total;
}

// function 3
bool bad_limits(int begin, int end, int low, int high)
{
    bool not_good = false;

    if (begin > end)
    {    
        printf("%1d isn't smaller than %1d.\n", begin, end);
        not_good = true;
    }
    if (begin < low || end < low)
    {
        printf("Values must be %1d or greater.\n", low);
        not_good = true;
    }
    if (begin > high || end > high)
    {
        printf("Values must be %1d or less.\n", high);
        not_good = true;
    }

    return not_good;
}





// 由于有warnings，所以
// 把 begin, end, low, high
//    start, stop
//    input
// 由 long 改为 int 类型




