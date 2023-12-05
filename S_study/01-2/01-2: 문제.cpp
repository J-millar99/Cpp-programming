#include <iostream>

void swap(int *int1, int *int2)
{
    int temp;

    temp = *int1;
    *int1 = *int2;
    *int2 = temp;
}

void swap(char *char1, char *char2)
{
    char temp;

    temp = *char1;
    *char1 = *char2;
    *char2 = temp;
}

void swap(double *double1, double *double2)
{
    double temp;

    temp = *double1;
    *double1 = *double2;
    *double2 = temp;
}

int main(void)
{
    int num1 = 20, num2 = 30;
    swap(&num1, &num2);
    std::cout<<num1<<' '<<num2<<std::endl;

    char ch1 = 'A', ch2 ='Z';
    swap(&ch1, &ch2);
    std::cout<<ch1<<' '<<ch2<<std::endl;

    double dbl1 = 1.111, dbl2 = 5.555;
    swap(&dbl1, &dbl2);
    std::cout<<dbl1<<' '<<dbl2<<std::endl;
    return 0;
}