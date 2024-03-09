#include<functional>

namespace myfunctions{

struct mystruct{
    std::function<double(std::vector<double>)> f;
    std::function<std::vector<double>(std::vector<double>)> grad;
    std::vector<double> initial_point;
    double tolerance_step;
    double tolerance_grad;
    double initial_step;
    unsigned int maxiter;
    double sigma;
};

std::vector<double> armijo(mystruct);

bool cond(mystruct,double,std::vector<double>);

double norm(std::vector<double>);

}

std::vector<double> operator-(std::vector<double>,std::vector<double>);

std::vector<double> operator*(double,std::vector<double>);