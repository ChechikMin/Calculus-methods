#include<iostream>
#include<complex>
#include<eigen3/Eigen/Dense>
#include<vector>
#include<cmath>
#include <iomanip>

using namespace std;

void prymoe(){

    vector <double> data ={1.065,0.426,0.598,0.348,0.833,1.065};
    vector <double> tmp_0;
    vector <double> tmp_1;
    for (size_t i = 0; i < data.size(); i++)
     if(i % 2 == 0)
        tmp_0.push_back(data.at(i));
    else
        tmp_1.push_back(data.at(i));


    vector <complex<double>> F_0;
    vector <complex<double>> F_1;

    complex <double> com_0 = 0;
    complex <double> com_1 = 0;

    size_t N_0 = tmp_0.size();

    for (size_t i = 0; i < N_0; i++){
        cout<<"Step"<< i<<endl;
        for (size_t j = 0; j < N_0; j++){
        complex <double> com;
        com.real(cos(2* M_PI * i *j /N_0));
        com.imag(-sin(2* M_PI * i *j /N_0));
        cout<<com<<"  " << j<<endl;
        com_0 += com * tmp_0.at(j);
        com_1 += com * tmp_1.at(j);
        }
        F_0.push_back(com_0);
        F_1.push_back(com_1);
        com_0 = 0;
        com_1 = 0;
        cout<<F_0.at(i)<<":F_0   "<<F_1.at(i)<<":F_1"<<endl;
        cout<<"--------"<<endl;
     }
}

int main()
{
    cout.precision(2);
    prymoe();
    return EXIT_SUCCESS;
}