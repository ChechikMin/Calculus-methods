#include<iostream>
#include<functional>
#include <eigen3/Eigen/Dense>
#include <vector>
#include<iomanip>

using namespace Eigen;
using std::cout;
using std::endl;

double f(double &x,double &y){
    return 1.6 * std::pow(x,2)*sin(y) - y;
}

double g(double &x,double &y){
    return 3.2 * y *std::pow(x,2) + cos(x);
}

double fShtrih_x(double &x,double &y){
    return 3.2 * x * sin(y);
}
double fShtrih_y(double &x,double &y){
    return 1.6*std::pow(x,2)*cos(y) - 1;
}
double gShtrih_x(double &x,double &y){
    return 6.4 * x * y - sin(x);
}
double gShtrih_y(double &x,double &y){
    return 3.2 *std::pow(x,2);
}

Vector2d calculate(Vector2d start_condition){
    Vector2d result;
    double tmp = NULL;
    double q = NULL;
    double p = NULL;
    tmp = start_condition[0] - f(start_condition[0],start_condition[1])/fShtrih_x(start_condition[0],start_condition[1]);
    q = (g(tmp,start_condition[1]) * fShtrih_x(start_condition[0],start_condition[1]))/(fShtrih_x(start_condition[0],start_condition[1]) * gShtrih_y(tmp,start_condition[1]) - fShtrih_y(start_condition[0],start_condition[1]) * gShtrih_x(tmp,start_condition[1]));
    p = (f(start_condition[0],start_condition[1]) - q * fShtrih_y(start_condition[0],start_condition[1]))/fShtrih_x(start_condition[0],start_condition[1]);
    result[0] = start_condition[0] -p;
    result[1] = start_condition[1] -q;
    return result;
}

int main()
{
    cout.precision(3);
    Vector2d start_condition(1,-1);
    for (size_t i = 1; i < 6; i++)
    {
    cout<<"iteration:"<<i<<endl;
    cout<<endl;
    Vector2d solution = calculate(start_condition);
    cout<<"solution"<<endl;
    cout<<solution<<endl;
    start_condition = solution;
    cout<<endl;
    cout<<"f1"<<endl;
    cout<<f(solution[0],solution[1])<<endl;
    cout<<"f2"<<endl;
    cout<<g(solution[0],solution[1])<<endl;
    cout<<"---------"<<endl;
    };
    //cout<<solution + start_condition<<endl;

    return EXIT_SUCCESS;
}