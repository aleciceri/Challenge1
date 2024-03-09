#include<iostream>
#include "functions.hpp"
#include<cmath>

int main(){
    using namespace myfunctions;
    // definition of the functions and the creation of the struct
    std::function<double(std::vector<double>)> f=[](std::vector<double> x){return x[0]*x[1]+4*std::pow(x[0],4)+std::pow(x[1],2)+3*x[0];};
    std::function<std::vector<double>(std::vector<double>)> grad=[](std::vector<double> x){
        std::vector<double> grad;
        grad.emplace_back(x[1]+16*std::pow(x[0],3)+3);
        grad.emplace_back(x[0]+2*x[1]);
        return grad;
    };
    mystruct data;
    data.f=f;
    data.grad=grad;
    data.initial_step=1.;
    data.maxiter=1000;
    data.tolerance_grad=0.01;
    data.tolerance_step=0.01;
    data.initial_point={1.0,1.0};
    data.sigma=0.4;
    // call for the armijo that computes the minimum of the funtion in the struct, given all the needed parameters 
    std::vector<double> minimum = armijo(data);
    // print of the minimum point found
    for(std::size_t i=0;i<minimum.size();++i)
        std::cout<<minimum[i]<<"  "<<std::endl;
    return 0;
}




