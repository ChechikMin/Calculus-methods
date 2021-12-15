#include<iostream>
#include<eigen3/Eigen/Dense>
#include<vector>
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

Vector2d solver(Vector2d x){
    Matrix2d A ;
    Vector2d F;
    A <<0.2,0.5,-0.4,0;

    F [0] = 1.6 * std::pow(x[0],2)*sin(x[1]) - x[1];
    F [1] = 3.2 * x[1] *std::pow(x[0],2) + cos(x[0]);
    
    Vector2d tmp = A*F;
    return tmp;
}
Vector2d solver_1(Vector2d x){
    Vector2d F;
    F [0] = 1.6 * std::pow(x[0],2)*sin(x[1]) - x[1];
    F [1] = 3.2 * x[1] *std::pow(x[0],2) + cos(x[0]);
    
    return F;
}


int main()
{
  std::vector<Vector2d> x;
    cout.precision(5);
    Vector2d start_condition_1(1,-1);
    Vector2d start_condition = solver_1(start_condition_1);

    for (size_t i = 1; i < 10; i++)
    {
    cout<<"iteration:"<<i<<endl;
    cout<<endl;
    Vector2d solution = start_condition - solver(start_condition);
    cout<<"solution"<<endl;
    cout<<start_condition<<endl;
    start_condition = solution;
    cout<<endl;
    /*cout<<"f1"<<endl;
    cout<<f1(x.at(i)[0],x.at(i)[1])<<endl;
    cout<<"f2"<<endl;
    cout<<f2(x.at(i)[0],x.at(i)[1])<<endl;*/
    cout<<"---------"<<endl;
    };
}
    //cout<<solution + start_condition<<endl;
