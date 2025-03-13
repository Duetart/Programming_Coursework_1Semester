#include <stdio.h>
#include <stddef.h>

int GetSum(int a, int b, int* res);
int GetDiff(int a, int b, int* res);
int GetProd(int a, int b, int* res);
int GetQuo(int a, int b, int* res);
int GetChoice(char c, int a, int b, int* res);

int GetSum(int a, int b, int* res)
{
    if (res == NULL)
    {
        return 3;
    }
    *res = a + b;
    return 0;
}

int GetDiff(int a, int b, int* res)
{
    if (res == NULL)
    {
        return 3;
    }
    *res = a - b;
    return 0;
}

int GetProd(int a, int b, int* res)
{
    if (res == NULL)
    {
        return 3;
    }
    *res = a * b;
    return 0;
}

int GetQuo(int a, int b, int* res)
{
    if (b == 0)
    {
        return 2;
    }
    if (res == NULL)
    {
        return 3;
    }
    *res = a / b;
    return 0;
}

int GetChoice(char c, int a, int b, int* res)
{
    if (res == NULL)
    {
        return 4;
    }

    switch (c)
    {
        case '+':
            return GetSum(a, b, res);
        case '-':
            return GetDiff(a, b, res);
        case '*':
            return GetProd(a, b, res);
        case '/':
            return GetQuo(a, b, res);
        default:
            return 1;
    }
    return 0;
}

int main()
{
    int a, b, res, status;
    char c;
    if (printf("Enter an operation without spac-es(for example, 2/1): ") < 0)
    {
        printf("Output error.\n");
        return 1;
    }
    if (scanf("%d%c%d", &a, &c, &b) != 3)
    {
        printf("Input error.\n");
        return 2;
    }
    status = GetChoice(c, a, b, &res);
    if (status == 0)
    {
        if(printf("Result: %d\n", res) < 0)
        {
            printf("Output error.\n");
            return 1;
        }
    }
    else if (status == 1)
    {
        printf("Operator error.\n");
        return 3;
    }
    else if (status == 2)
    {
        printf("Division by zero error.\n");
        return 4;
    }
    else if (status == 3 || status == 4)
    {
        printf("Pointer error.\n");
        return 5;
    }
    return 0;
}



