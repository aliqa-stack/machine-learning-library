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
    double w = 0.5;
    double rate = 1e-1;

    for(size_t i = 0; i < 80 ; i++){

        double f = Predc(x, y, w);
        double eps = 0.01;

        double perturbed_weight = w- f;
        double dw = Predc(x, y, perturbed_weight) / eps;

        w -= rate * dw;
        std::cout<<"theprediction is: "<< Predc(x, y, w)<<" "<<w<<"\n";
    }
        std::cout<<"the final is: "<< Predc(x, y, w)<<" "<<w<<"\n";
    double y_predict = Predc(x, y, w);
    std::cout<<MSE(y_predict, y);
}
