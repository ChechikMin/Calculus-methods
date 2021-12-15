#include<iostream>
#include<complex>
#include<eigen3/Eigen/Dense>
#include<vector>
#include<cmath>
#include <iomanip>

using namespace std;

vector <complex<double>>  prymoe(){

    vector <double> data ={1.065,0.426,0.598,0.348,0.833,1.065};
    vector <complex<double>> F;
    complex <double> tmp = 0;
    size_t N = data.size();
    for (size_t i = 0; i < data.size(); i++){
        cout<<"Step"<< i<<endl;
        for (size_t j = 0; j < data.size(); j++){
        complex <double> com;
        com.real(cos(2* M_PI * i *j /N));
        com.imag(-sin(2* M_PI * i *j /N));
        cout<<com<<"  " << j<<endl;
        tmp += com * data.at(j);
        }
        F.push_back(tmp);
        tmp = 0;
        cout<<F.at(i)<<endl;
        cout<<"--------"<<endl;
     }
    return F;

}

int main()
{
    cout.precision(2);
    prymoe();
    
    
    return EXIT_SUCCESS;
}