#include "algoritma.h"
#include <thread>
#include <iostream>
#include <vector>

/*
    main formula 

*/


double Predc(std::vector<std::vector<double>>& x,std::vector<double>& y ,double w, double b){
    if(x.empty() || y.empty()){
        std::cerr<<"the parameters is empty please fill it \n";

        return 1;
    }
    double predict_value = 0.0;

    const size_t n = y.size();
    for(size_t i =0; i < n; i++){
        predict_value = w*x[i][0] +b;
    }

    return predict_value;
}

/*
function for searching weight and slope 
dynamic weight and slope 
*/
double Search_Slp(std::vector<double> &y, std::vector<std::vector<double>>& x){
    double sumY = 0.0;
    double sumX = 0.0;
    double sumXX = 0.0;
    double sumXY = 0.0;
    double w = 0.0;
    for(size_t i = 0; i < y.size(); i++){
        sumY += y[i];
        sumX += x[i][0]; 
        sumXX += sumX * sumX;
        sumXY += sumX * sumY;


    }
    double w = ( y.size() * sumXY - sumX * sumY) / (y.size() * sumXX - sumX * sumX);
    double b = (sumY - w * sumX) / y.size();

    return b;
}

double MSE(double pred_y, std::vector<double>& y){
    return pred_y - y;
}



