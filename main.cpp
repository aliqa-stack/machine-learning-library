#include <iostream>
#include <vector>
#include "algoritma.h"


int main(){
    
    std::vector<std::vector<double>> x = {
        {2,4},
        {1,4},
        {3,4},
        {8,7},
        {4,8},
    };
    std::vector<double> y = {2,4,6,8,9};
    size_t Sizesample = x.size();
    double w = 0.5;

    Model linear;
    for(int i = 0; i < 500; i++){
         double mse = linear.Predc(1, Sizesample, x, y, w);
         std::cout<<mse<<"\n";
     }
    
}
