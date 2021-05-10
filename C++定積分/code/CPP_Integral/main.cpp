#include <iostream>
#include <cmath>
#define pi 3.14159265358979
#define e 2.718281828459045

double f(double x);
double f(double x, double y);
double integral(double (*fun)(double), double L, double H, long n=10000000);
double integral(double (*fun)(double,double), double xL, double xH, double yL, double yH, long n=10000);

int main()
{
    using namespace std;
    cout.precision(8);//小数点位数
    cout.setf(ios_base::showpoint);//显示小数点最后面的0
    cout<<integral(f,0,100000.0)<<endl;
    cout<<integral(f,-2,2,-1,1)<<endl;
    return 0;
}

//这里可定义任意一元可积函数
double f(double x)
{
    return sin(x)/x;
}

//这里可定义任意二元可积函数
double f(double x, double y)
{
    return x*x +y*y;
}

//定积分
double integral(double (*fun)(double), double L, double H, long n)
{
    double x,dx,sum;
    dx = (H-L)/n;
    x = L + 0.5*dx;
    sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += fun(x)*dx;
        x += dx;
    }
    return sum;
}

//二重积分
double integral(double (*fun)(double,double), double xL, double xH, double yL, double yH, long n)
{
    double x,y,dx,dy,sum;
    dx = (xH-xL)/n;
    dy = (yH-yL)/n;
    x = xL + 0.5*dx;
    sum = 0;
    for(int i=0; i<n; i++)
    {
        y = yL + 0.5*dy;
        for(int j=0; j<n; j++)
        {
            sum += dx*dy*fun(x,y);
            y += dy;
        }
        x += dx;
    }
    return sum;
}
