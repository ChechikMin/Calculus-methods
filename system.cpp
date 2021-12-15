#include<functional>
#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>

using std::cout;
using std::endl;
using std::function;
using std::vector;

double f_xt(double& x,double& y,double& t)
{
    return 2*x + y + cos(t);
}

double f_yt(double& x,double& y,double& t)
{
    return 2*sin(t) - x;
}
void calculate_Yavn (function<double(double,double,double)> f_xt,function<double(double,double,double)> f_yt)
{
    vector <double> tData;
    vector <double> xData;
    vector <double> yData;
    double a = 0;
    double b = 1;
    double step = 0.1;
    yData.push_back(1);
    xData.push_back(1);
    double N = (b - a)/step + 1;
    for (size_t i = 0; i < N; i++)
        tData.push_back(a + i *step);

    for (size_t i = 0; i < tData.size(); i++)
    {
        yData.push_back(yData.at(i) +step * f_yt(xData.at(i),yData.at(i),tData.at(i)));
        xData.push_back(xData.at(i) +step * f_xt(xData.at(i),yData.at(i),tData.at(i)));
        cout<<yData[i]<<"  Iteration "<<i<<endl;
    }
    
}
void calculate_modifik (function<double(double,double,double)> f_xt,function<double(double,double,double)> f_yt)
{
    vector <double> tData;
    vector <double> xData;
    vector <double> yData;
    double a = 0;
    double b = 1;
    double step = 0.1;
    yData.push_back(1);
    xData.push_back(1);
    double N = (b - a)/step + 1;
    for (size_t i = 0; i < N; i++)
        tData.push_back(a + i *step);

    for (size_t i = 0; i < tData.size(); i++)
    {
        double tmp0 = xData.at(i) +step * f_xt(xData.at(i),yData.at(i),tData.at(i));
        double tmp1 = yData.at(i) +step * f_yt(xData.at(i),yData.at(i),tData.at(i));
        xData.push_back(xData.at(i) + (step / 2) * (f_xt(xData.at(i),yData.at(i),tData.at(i)) + f_xt(tmp0,tmp1,tData.at(i) + step)));
        yData.push_back(yData.at(i) + (step / 2) * (f_yt(xData.at(i),yData.at(i),tData.at(i)) + f_yt(tmp0,tmp1,tData.at(i) + step)));
        cout<<tData[i]<<" "<<xData[i]<<" "<<yData[i]<<"  Iteration "<<i<<endl;
    }
    
}

void calculate_Runge (function<double(double,double,double)> f_xt,function<double(double,double,double)> f_yt)
{
    vector <double> tData;
    vector <double> xData;
    vector <double> yData;
    double a = 0;
    double b = 1;
    double step = 0.1;
    yData.push_back(1);
    xData.push_back(1);
    double N = (b - a)/step + 1;
    for (size_t i = 0; i < N; i++)
        tData.push_back(a + i *step);

    for (size_t i = 0; i < tData.size(); i++)
    {

        double K1 = step *f_xt(xData.at(i),yData.at(i),tData.at(i));
        double l1 = step *f_yt(yData.at(i),yData.at(i),tData.at(i));

        double K2 = step * f_xt(xData.at(i) + K1/2,yData.at(i) + 0.5 * l1,tData.at(i) + step/2);
        double l2 = step * f_yt(xData.at(i) + K1/2,yData.at(i) + 0.5 * l1,tData.at(i) + step/2);

        double K3 = step*f_xt(xData.at(i) + K2/2,yData.at(i) + 0.5 * l2,tData.at(i) + 0.5 * step);
        double l3 = step*f_yt(yData.at(i) + K2/2,yData.at(i) + 0.5 * l2,tData.at(i) + 0.5 * step);

        double K4 = step * f_xt(xData.at(i) + K3,yData.at(i) +  l3,tData.at(i) +  step);
        double l4 = step * f_yt(yData.at(i) + K3,yData.at(i) +  l3,tData.at(i) +  step);
         
        double tmp0 = (1 / 6) * (K1 + 2* K2 + 2*K3 + K4);
        double tmp1 = (1 / 6) * (l1 + 2* l2 + 2*l3 + l4); 
        
        yData.push_back(yData.at(i) + tmp1);
        xData.push_back(xData.at(i) + tmp0);

        cout<<tData[i]<<" "<<xData[i]<<" "<<yData[i]<<"  Iteration "<<i<<endl;
    }
    
}


int main(){
    function<double(double,double,double)> fx = f_xt;
    function<double(double,double,double)> fy = f_yt;
    cout<<"Eiler"<<endl;
    cout.precision(4);
    calculate_Yavn(f_xt,f_yt);
    cout<<"---------"<<endl;
    cout<<"Modifik"<<endl;
    calculate_modifik(f_xt,f_yt);
    cout<<"---------"<<endl;
    cout<<"Runge"<<endl;
    calculate_Runge(f_xt,f_yt);
    cout<<"---------"<<endl;
    return EXIT_SUCCESS;
}