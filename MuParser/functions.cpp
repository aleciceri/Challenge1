#include "functions.hpp"
#include<cmath>
#include<iostream>

namespace myfunctions{
    // definition of the armijo function
    std::vector<double> armijo(mystruct & data){
        unsigned int k=0;
        // x will be the x_k point, and will be updated, while x_old will be the x_(k-1) point 
        
        std::vector<double> x_old,x_temp;
        double alpha=data.initial_step;
        // grad is the gradient in x_k
        std::vector<double> grad;
        grad={data.grad1.Eval(),data.grad2.Eval()};
        // while loop for the update of the x, with all the needed conditions for stoppage of the loop
        double error_step=data.tolerance_step+1;
        while(k<data.maxiter && error_step>data.tolerance_step && norm(grad)>data.tolerance_grad){
            // update of x_old
            x_old=data.current_point;
            // computation of alpha_k with armijo rule
            alpha=data.initial_step;
            grad={data.grad1.Eval(),data.grad2.Eval()};
            while(cond(data,alpha))
                {alpha=alpha/2;}
            // update of current point
            x_temp=data.current_point-alpha*grad;
            data.current_point=x_temp;
            // increase the number of iterations done
            error_step=norm(data.current_point-x_old);
            ++k;
        }
        return data.current_point;
    }

    // cond is the function needed for the armijo condition on alpha
    bool cond(mystruct & data,double alpha){
        // computation of gradient
        std::vector<double> grad;
        std::vector<double> x_old{data.current_point};
        grad={data.grad1.Eval(),data.grad2.Eval()};
        // computation of left and right parts of inequality
        double value_left=data.f.Eval();
        std::vector<double> x_new;
        x_new=data.current_point-alpha*grad;
        data.current_point=x_new;
        double value_left1=data.f.Eval();
        data.current_point=x_old;
        double norm_grad=std::pow(norm(grad),2);
        double value_right=(data.sigma*alpha)*norm_grad;
        // return the opposite condition because if this return false (i.e. the condition holds) then the loop stops
        return value_left-value_left1<value_right;
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