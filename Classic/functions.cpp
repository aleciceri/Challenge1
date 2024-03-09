#include "functions.hpp"
#include<cmath>
#include<iostream>

namespace myfunctions{
    std::vector<double> armijo(mystruct data){
        unsigned int k=0;
        std::vector<double> x;
        x=data.initial_point;
        std::vector<double> x_old;
        x_old=x;
        double alpha=data.initial_step;
        while(k<data.maxiter){
            x_old=x;
            alpha=data.initial_step;
            while(cond(data,alpha,x))
                {alpha=alpha/2;}
            std::vector<double> grad;
            grad=data.grad(x);
            x=x-alpha*grad;
            if(norm(x-x_old)<data.tolerance_step)
                break;
            if(norm(grad)<data.tolerance_grad)
                break;
            ++k;
        }
        return x;
    }

    bool cond(mystruct data,double alpha,std::vector<double> x){
        std::vector<double> grad;
        grad=data.grad(x);
        std::vector<double> x_new;
        x_new=x;
        for(std::size_t i=0;i<x.size();++i)
            x_new[i]=x[i] - alpha * grad[i];
        double value_left=data.f(x)-data.f(x_new);
        double norm_grad=std::pow(norm(grad),2);
        double value_right=(data.sigma*alpha)*norm_grad;
        return value_left<value_right;
    }

    double norm(std::vector<double> vec){
        double norm=0;
        for(std::size_t i=0;i<vec.size();++i){
            norm+=std::pow(vec[i],2);
        }
        return std::sqrt(norm);
    }
}

std::vector<double> operator-(std::vector<double> v1,std::vector<double> v2){
    std::size_t max=std::max(v1.size(),v2.size());
    v1.resize(max,0.0);
    v2.resize(max,0.0);
    std::vector<double> result;
    for(std::size_t i=0;i<max;++i){
        result.emplace_back(v1[i]-v2[i]);
    }
    return result;
}

std::vector<double> operator*(double num,std::vector<double> vec){
    std::vector<double> result=vec;
    for(std::size_t i=0;i<vec.size();++i)
        result[i]=num*vec[i];
    return result;
}