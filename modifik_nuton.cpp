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

MatrixXd F1_shtrih (Vector2d x){
    Matrix2d F_shtrih;
    F_shtrih(0,0) = 3.2 *x[0] *sin(x[1]);
    F_shtrih(0,1) = 1.6*std::pow(x[0],2) * cos(x[1]) - 1;
    F_shtrih(1,0) = 6.4*x[0]*x[1]-sin(x[0]);
    F_shtrih(1,1) = 3.2 * std::pow(x[0],2);
    return F_shtrih;
}
Vector2d F1(Vector2d x,Vector2d vec_const){
  Vector2d F;
    F [0] = 1.6 * std::pow(x[0],2)*sin(x[1]) - x[1];
    F [1] = 3.2 * x[1] *std::pow(x[0],2) + cos(x[0]);
    Matrix2d f_shtrih = F1_shtrih(vec_const);
    cout<<"Matrix A:"<<endl;
    cout<<f_shtrih<<endl;
    cout<<endl;
    cout<<"Vector b:"<<endl;
    cout<<F<<endl;
    cout<<endl;
    return f_shtrih.colPivHouseholderQr().solve(-F);
};

int main()
{
    cout.precision(3);
    Vector2d start_condition(1,-1);
    Vector2d start_condition_1(1,-1);
    for (size_t i = 1; i < 4; i++)
    {
    cout<<"iteration:"<<i<<endl;
    cout<<endl;
    Vector2d solution = start_condition + F1(start_condition,start_condition_1);
    start_condition = solution;
    cout<<"solution"<<endl;
    cout<<solution<<endl;
    cout<<endl;
    cout<<"f1"<<endl;
    cout<<f1(solution[0],solution[1])<<endl;
    cout<<"f2"<<endl;
    cout<<f2(solution[0],solution[1])<<endl;
    cout<<"---------"<<endl;
    if (i == 2)
     start_condition_1 = solution;
    
    };
    //cout<<solution + start_condition<<endl;

    return EXIT_SUCCESS;
}