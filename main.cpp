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
    std::cout<<Search_Slp(y, x) <<"\n";
    std::cout<<"theprediction is: "<< Predc(x, y)<<"\n";
    double y_predict = Predc(x, y);
    std::cout<<MSE(y_predict, y);
}
