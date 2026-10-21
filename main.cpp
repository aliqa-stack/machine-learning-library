#include <iostream>
#include <vector>
#include "algoritma.h"


int main(){
    
    std::vector<std::vector<double>> x = {
        {1,1},
        {2,2},
        {3,4},
        {5,7},
        {7,8},
    };
    std::vector<double> y = {2,4,6,8,9};
    size_t Sizesample = y.size();
    double w = 0.5;

    Model linear;
    for(int i = 0; i < 200; i++){
         double mse = linear.Predc(1, Sizesample, x, y);
         std::cout<<"the mse is : "<<mse<<"\n";
     }
    
}
