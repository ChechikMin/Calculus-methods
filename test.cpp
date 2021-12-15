#include<iostream>
#include<functional>
#include <eigen3/Eigen/Dense>
#include <vector>
#include<iomanip>

using namespace Eigen;
using std::cout;
using std::endl;

double f1(double &x,double &y){
    return 1.6 * std::pow(x,2)*sin(y) - y;
}

double f2(double &x,double &y){
    return 3.2 * y *std::pow(x,2) + cos(x);
}
MatrixXd F1_shtrih (Vector2d& x){
    Matrix2d F_shtrih;
    F_shtrih(0,0) = 3.2 *x[0] *sin(x[1]);
    F_shtrih(0,1) = 1.6*std::pow(x[0],2) * cos(x[1]) - 1;
    F_shtrih(1,0) = 6.4*x[0]*x[1]-sin(x[0]);
    F_shtrih(1,1) = 3.2 * std::pow(x[0],2);
    return F_shtrih;
}


int main()
{
    cout.precision(3);
    Vector2d start_condition(0.823,-0.407);
    Vector2d tmp(f1(start_condition[0],start_condition[1]),f2(start_condition[0],start_condition[1]));
    cout<<tmp<<endl;
    system("pause");
}
    //cout<<solution + start_condition<<endl;
