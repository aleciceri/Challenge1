#include<iostream>
#include<fstream>
#include "functions.hpp"
#include<cmath>
#include "GetPot"
#include<string>

int main(int argc,char *argv[]){
    using namespace myfunctions;
    
    GetPot command_line(argc, argv);
    const std::string filename = command_line.follow("dataGetPot", 2, "-f", "--file");
    GetPot datafile(filename.c_str());
    std::string funstring= datafile("fun","0");
    MuparserFun parser(funstring);


    mystruct data;
    data.f(parser);
    data.initial_step=datafile("initial_step",1.0);
    data.maxiter=datafile("maxiter",100);
    data.tolerance_grad=datafile("tolerance_grad",1e-6);
    data.tolerance_step=datafile("tolerance_step",1e-6);
    data.initial_point={0.0,0.0};
    data.sigma=datafile("sigma",0.4);
    data.h=datafile("h",1e-4);
    // call for the armijo that computes the minimum of the funtion in the struct, given all the needed parameters 
    std::vector<double> minimum = armijo(data);
    // print of the minimum point found
    for(std::size_t i=0;i<minimum.size();++i)
        std::cout<<minimum[i]<<"  "<<std::endl;
    return 0;
}




