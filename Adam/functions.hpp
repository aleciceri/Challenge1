#include<functional>
#include<vector>
#include<cmath>
#include "muParser.h"
#include "mpParser.h"
#include<string>

// creation of a namespace for my methods and struct 
namespace myfunctions{

// definition of the struct, with the function, its gradient and all the parameters
struct mystruct{
    mu::Parser f;
    mu::Parser grad1;
    mu::Parser grad2;
    //mup::ParserX grad;
    std::vector<double> initial_point{0.0,0.0};
    double tolerance_step=0.1;
    double tolerance_grad=0.1;
    double initial_step=1;
    unsigned int maxiter=100;
    double Beta1=0.5;
    double Beta2=0.5;
    double e=0.01;
    std::vector<double> current_point{0.0,0.0};
};

// declaration of all the methods I'll need
std::vector<double> Adam(mystruct &);

double norm(std::vector<double>);

}

// to make the code easier to read, I define these 2 operators for making the difference between two vectors and the muliplication between a scalar and a vector
std::vector<double> operator-(std::vector<double>,std::vector<double>);

std::vector<double> operator+(std::vector<double>,std::vector<double>);

std::vector<double> operator*(double,std::vector<double>);

std::vector<double> operator/(std::vector<double>,std::vector<double>);

std::vector<double> operator+(std::vector<double>,double);

std::vector<double> sqrt(std::vector<double>);

std::vector<double> square(std::vector<double>);

double power(double,int);

