#include<iostream>
#include<fstream>
#include "muParser.h"
#include "functions.hpp"
#include<cmath>
#include <muparserx/parser/mpParser.h>

int main(){
    using namespace myfunctions;
    // definition of the functions and the creation of the struct
    mu::Parser parser;

    // Read function from file
    std::string filename = "function.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return 1;
    }

    std::string function;
    std::getline(file, function);

    // Set the expression to the parser
    if (!parser.SetExpr(function)) {
        std::cerr << "Error: Failed to parse function expression." << std::endl;
        return 1;
    }

    
    mup::ParserX parser_grad;

    // Read function from file
    std::string filename1 = "gradient.txt";
    std::ifstream file(filename1);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename1 << std::endl;
        return 1;
    }

    std::string gradient;
    std::getline(file, gradient);

    // Set the expression to the parser
    try {
        parser.SetExpr(gradient);
    } catch (const mup::ParserError &e) {
        std::cerr << "Error: " << e.GetMsg() << std::endl;
        return 1;
    }

    mystruct data;
    data.f=parser;
    data.grad=parser_grad;
    data.initial_step=1.;
    data.maxiter=1000;
    data.tolerance_grad=std::pow(10,-6);
    data.tolerance_step=std::pow(10,-6);
    data.initial_point={0.0,0.0};
    data.sigma=0.4;
    // call for the armijo that computes the minimum of the funtion in the struct, given all the needed parameters 
    std::vector<double> minimum = armijo(data);
    // print of the minimum point found
    for(std::size_t i=0;i<minimum.size();++i)
        std::cout<<minimum[i]<<"  "<<std::endl;
    return 0;
}




