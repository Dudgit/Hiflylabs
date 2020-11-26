#include "matrix.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <istream>
#include <ostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <future>

double paralell_mult(Matrix<double> const& m,Matrix<double> const& n, Matrix<double>& res)
{
    auto mylambda=[&res](Matrix<double> const& m, Matrix<double> const& n,int first, int last){
        for(int i=first;i<last;i++){
            for(int k=0;k<m.cols();k++){
                for(int j = 0;j<n.rows();j++){
                    res(i,k)+=m(i,j)*n(j,k);
                }
            }        
        }
    };
    auto time_1 = std::chrono::high_resolution_clock::now();

    auto t1 = std::async(mylambda,m,n,0,m.cols()/3);
    auto t2 = std::async(mylambda,m,n,m.cols()/3,2*m.cols()/3);
    auto t3 = std::async(mylambda,m,n,2*m.cols()/3,m.cols());
    t1.get();t2.get();t3.get();

    auto time_2 = std::chrono::high_resolution_clock::now();
    double x =(static_cast<std::chrono::duration<double, std::milli>>(time_2-time_1)).count();
    return x;
}

int main()
{

    int n = 3;
    std::vector<double> v = {5.0,3.0,1.0,-1.0,-9.0,-11.0,-13.0,15.0,19.0};
    std::vector<double> u = {0.3,0.3,0.9,-0.11,-0.9,0.1,0.3,0.15,0.17};
    std::vector<double> v_1 = {3.0,5.0,7.0,9.0,11.0,12.0};
    std::vector<double> u_1 = {-1.0,5.0,0.0,0.7,9.0,1.0,-1.0,3.1,4.0,0.0,2.0,1.0};


    Matrix<double>  M(n,n,v);
    std::vector<double> zero ={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    Matrix<double> N(n,n,zero);

    {
    std::ofstream ofile("time.txt");
    std::vector<double> data_1(10);
    std::vector<double> data_2(10);
    int j = 1500;
    double first=0.0;
    double second = 1.0;
    while(first<second)
    {
        for(int i=0; i<10; i++)
        {
            std::vector<double> u(j*j);
            std::vector<double> v(j*j);
            std::vector<double> zero(j*j);
            for(auto e:zero){e=0.0;}
            std::random_device rd{};
            std::mt19937 gen(rd());
            std::normal_distribution<double> distr(0,2);
            std::generate(u.begin(),u.end(),[&]{ return distr(gen); });
            std::generate(v.begin(),v.end(),[&]{ return distr(gen); });

            Matrix<double> m(j,j,u);
            Matrix<double> n(j,j,v);
            Matrix<double> res(j,j,zero);

            double y =paralell_mult(m,n,res);

            auto t1 = std::chrono::high_resolution_clock::now();
            m=m*n;
            auto t2 = std::chrono::high_resolution_clock::now();
            
            double x =(static_cast<std::chrono::duration<double, std::milli>>(t2-t1)).count();

            data_1[i] = x;
            data_2[i] = y;
        } 
            second = *std::min_element(std::begin(data_2),std::end(data_2));
            first = *std::min_element(std::begin(data_1),std::end(data_1));
        j+=300;
    }
    ofile<<" the matrix size, where the paralell method is faster than the normal is: "<<j<<" and the execution time was: "<< second<<"milisec"<<std::endl;
    }

}