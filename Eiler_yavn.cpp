#include<functional>
#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>

using std::cout;
using std::endl;
using std::function;
using std::vector;

double f_xt(double& x,double& y)
{
    return (cos(y)- sin(y) - 1)/(cos(x) - sin(x) + 1);
}
void calculate_Yavn (function<double(double,double)> f)
{
    vector <double> xData;
    vector <double> yData;
    double a = -0.5;
    double b = 0.5;
    double step = 0.1;
    yData.push_back(1);
    double N = (b - a)/step + 1;
    for (size_t i = 0; i < N; i++)
        xData.push_back(a + i *step);

    for (size_t i = 0; i < xData.size(); i++)
    {
        yData.push_back(yData.at(i) +step * f(xData.at(i),yData.at(i)));
        cout<<yData[i]<<"  Iteration "<<i<<endl;
    }
    
}
void calculate_modifik (function<double(double,double)> f)
{
    vector <double> xData;
    vector <double> yData;
    double a = -0.5;
    double b = 0.5;
    double step = 0.1;
    yData.push_back(1);
    double N = (b - a)/step + 1;
    for (size_t i = 0; i < N; i++)
        xData.push_back(a + i *step);

    for (size_t i = 0; i < xData.size() - 1; i++)
    {
        double tmp = yData.at(i) +step * f(xData.at(i),yData.at(i));
        yData.push_back(yData.at(i) + (step / 2) * (f(xData.at(i),yData.at(i)) + f(xData.at(i + 1),tmp)));
        cout<<yData[i]<<"  Iteration "<<i<<endl;
    }
    
}

void calculate_Runge (function<double(double,double)> f)
{
    vector <double> xData;
    vector <double> yData;
    double a = -0.5;
    double b = 0.5;
    double step = 0.1;
    yData.push_back(1);
    double N = (b - a)/step + 1;
    for (size_t i = 0; i < N; i++)
        xData.push_back(a + i *step);

    for (size_t i = 0; i < xData.size(); i++)
    {

        double K1 = f(xData.at(i),yData.at(i));
        double K2 = f(xData.at(i) + step / 2,yData.at(i) + (step/2) * K1);
        double K3 = f(xData.at(i) + step / 2,yData.at(i) + (step/2) * K2);
        double K4 = f(xData.at(i) + step,yData.at(i) + step* K3);
        double tmp = (K1 + 2 * K2 + 2* K3 + K4)/6;
        yData.push_back(yData.at(i) + step*tmp);
        cout<<yData[i]<<"  Iteration "<<i<<endl;
    }
    
}


int main(){

    function<double(double,double)> f = f_1;
    cout<<"Eiler"<<endl;
    cout.precision(4);
    calculate_Yavn(f);
    cout<<"---------"<<endl;
    cout<<"Modifik"<<endl;
    calculate_modifik(f);
    cout<<"---------"<<endl;
    cout<<"Runge"<<endl;
    calculate_Runge(f);
    cout<<"---------"<<endl;
    return EXIT_SUCCESS;
}