#include<iostream>

using namespace std;

#include <ctime>
#include <cstdlib>


void findGcdLcm(int n1, int n2, int &gcd, int &lcm)
{
    //OUJILIDE arith
    int max;//ab�еĴ�ֵ
    int min;//ab�е�Сֵ
    int mob;//����1

    if (n1 >= n2)
    {
        max = n1;
        min = n2;
    }
    else
    {
        max = n2;
        min = n1;
    }
    while (1)
    {
        mob = max % min;
        if (mob == 0)
        { break; }
        max = min;
        min = mob;
    }

    gcd = min;
    //�������ĳ˻������������������Լ������С�������ĳ˻�
    lcm = n1 * n2 / gcd;


    return;

}

int main()
{
    int num1, num2;
    srand(time(0));

    num1 = rand() % 12;
    num2 = rand() % 12;

    cout << num1 << '\t' << num2 << endl;


    int g, l;

    findGcdLcm(num1, num2, g, l);
    cout << g << '\t' << l << endl;

    return 0;
}