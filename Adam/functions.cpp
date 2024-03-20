#include "functions.hpp"
#include<cmath>
#include<iostream>

namespace myfunctions{
    // definition of the armijo function
    std::vector<double> Adam(mystruct & data){
        unsigned int k=1;
        // x will be the x_k point, and will be updated, while x_old will be the x_(k-1) point 
        
        std::vector<double> x_old,x_temp,m,v,m_hat,v_hat;
        m={0.0,0.0};
        v={0.0,0.0};
        m_hat={0.0,0.0};
        v_hat={0.0,0.0};
        double alpha=data.initial_step;
        // grad is the gradient in x_k
        std::vector<double> grad;
        grad={data.grad1.Eval(),data.grad2.Eval()};
        // while loop for the update of the x, with all the needed conditions for stoppage of the loop
        double error_step=data.tolerance_step+1;
        while(k<=data.maxiter && error_step>data.tolerance_step && norm(grad)>data.tolerance_grad){
            // update of x_old
            x_old=data.current_point;
            // computation of gradient
            grad={data.grad1.Eval(),data.grad2.Eval()};
            // update of m,v,m_hat,v_hat
            m=data.Beta1*m+(1-data.Beta1)*grad;
            v=data.Beta2*v+(1-data.Beta2)*square(grad);
            m_hat=(1/(1-power(data.Beta1,k)))*m;
            v_hat=(1/(1-power(data.Beta2,k)))*v;
            // update of current point
            x_temp=data.current_point-alpha*(m_hat/(sqrt(v_hat)+data.e));
            data.current_point=x_temp;
            error_step=norm(data.current_point-x_old);
            ++k;
        }
        return data.current_point;
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
    // if the size is different, then it is an error and it stops the compilation
    if(v1.size()!=v2.size())
        std::cerr<<"Vectors of different size, cannot apply subtraction"<<std::endl;
    std::vector<double> result{v1};
    // difference element by element
    for(std::size_t i=0;i<v1.size();++i){
        result[i]=v1[i]-v2[i];
    }
    return result;
}

std::vector<double> operator+(std::vector<double> v1,std::vector<double> v2){
    // if the size is different, then it is an error and it stops the compilation
    if(v1.size()!=v2.size())
        std::cerr<<"Vectors of different size, cannot apply sum"<<std::endl;
    std::vector<double> result;
    // sum element by element
    for(std::size_t i=0;i<v1.size();++i){
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

// operator for the elementwise division of two vectors
std::vector<double> operator/(std::vector<double> v1,std::vector<double> v2){
    // if the size is different, then it is an error and it stops the compilation
    if(v1.size()!=v2.size())
        std::cerr<<"Vectors of different size, cannot apply division"<<std::endl;
    std::vector<double> result=v1;
    for(std::size_t i=0;i<v1.size();++i){
        result[i]=v1[i]/v2[i];
    }
    return result;
}

// operator for the sum between a vector and a scalar, computed element wise
std::vector<double> operator+(std::vector<double> v1,double a){
    std::vector<double> result=v1;
    for(std::size_t i=0;i<v1.size();++i){
        result[i]=v1[i]+a;
    }
    return result;
}

// function for the element wise square root of a vector
std::vector<double> sqrt(std::vector<double> v){
    std::vector<double> result=v;
    for(std::size_t i=0;i<v.size();++i){
        result[i]=std::sqrt(v[i]);
    }
    return result;
}

// function for the element wise square of a vector
std::vector<double> square(std::vector<double> v){
    std::vector<double> result=v;
    for(std::size_t i=0;i<v.size();++i){
        result[i]=v[i]*v[i];
    }
    return result;
}

double power(double a,int b){
    double result=a;
    int k=1;
    while(k<b){
        result=result*a;
        k++;
    }
    return result;
}