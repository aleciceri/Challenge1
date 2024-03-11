#include "functions.hpp"
#include<cmath>
#include<iostream>

namespace myfunctions{
    std::vector<double> heavy_ball(mystruct data, char type){
        unsigned int k=0;
        // x will be the x_k point, and will be updated, while x_old will be the x_(k-1) point 
        std::vector<double> x;
        std::vector<double> d,d_old;
        x=data.initial_point;
        d=(-data.initial_step)*data.grad(x);
        d_old=d;
        std::vector<double> x_old;
        double alpha=data.initial_step;
        // grad is the gradient in x_k
        std::vector<double> grad;
        grad=data.grad(x);
        double error_step=data.tolerance_step+1;
        // while loop for the update of the x, with all the needed conditions for stoppage of the loop
        while(k<data.maxiter && error_step>data.tolerance_step && norm(grad)>data.tolerance_grad){
            // update of x_old
            x_old=x;
            // computation of alpha_k
            if (type=='1')
                {alpha=data.initial_step*std::exp(-data.mu*k);}
            else if(type=='2')
                {alpha=data.initial_step/(1+data.mu*k);}
            //if type=='0' or not equal to '1' or '2' the initial value is assigned to alpha and it never changes, so the default method is applied
            // update of x
            x=x+d;
            d_old=d;
            grad=data.grad(x);
            d=data.eta*d_old-alpha*grad;
            error_step=norm(x-x_old);
            // increase the number of iterations done
            ++k;
        }
        return x;
    }


    // function for the computation of the norm of a vector, loop over the element, summing the squares then computing the square root
    double norm(std::vector<double> vec){
        double norm=0;
        for(std::size_t i=0;i<vec.size();++i){
            norm+=std::pow(vec[i],2);
        }
        return std::sqrt(norm);
    }
}

// operator for the difference of two vectors
std::vector<double> operator-(std::vector<double> v1,std::vector<double> v2){
    // if the size is different, then the smaller vector will be expanded with zeros
    std::size_t max=std::max(v1.size(),v2.size());
    v1.resize(max,0.0);
    v2.resize(max,0.0);
    std::vector<double> result;
    // difference element by element
    for(std::size_t i=0;i<max;++i){
        result.emplace_back(v1[i]-v2[i]);
    }
    return result;
}

// operator for the sum of two vectors
std::vector<double> operator+(std::vector<double> v1,std::vector<double> v2){
        // if the size is different, then the smaller vector will be expanded with zeros
    std::size_t max=std::max(v1.size(),v2.size());
    v1.resize(max,0.0);
    v2.resize(max,0.0);
    std::vector<double> result;
    // difference element by element
    for(std::size_t i=0;i<max;++i){
        result.emplace_back(v1[i]+v2[i]);
    }
    return result;
}

// operator for the scalar - vector multiplication, loop over the vector elements, each one multiplied by the scalar
std::vector<double> operator*(double num,std::vector<double> vec){
    std::vector<double> result=vec;
    for(std::size_t i=0;i<vec.size();++i)
        result[i]=num*vec[i];
    return result;
}