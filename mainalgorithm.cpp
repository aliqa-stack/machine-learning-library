#include "algoritma.h"
#include <iostream>
#include <vector>

/*
    main formula 

*/


double Predc(std::vector<std::vector<double>>& x,std::vector<double>& y, double& w){
    if(x.empty() || y.empty()){
        std::cerr<<"the parameters is empty please fill it \n";

        return 1;
    }
    //INTERCEPT STATIS TIDAK DINAMIS!!
    double b = 0.0;
    double predict_value = 0.0;

    double loss =0;
    const size_t n = y.size();
    for(size_t i =0; i < n; i++){
        predict_value = w*x[i][0] +b;
        double error = predict_value - y[i];
        loss += error * error;
        
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
    w = ( y.size() * sumXY - sumX * sumY) / (y.size() * sumXX - sumX * sumX);

    return w;
}

double Search_Intc(std::vector<double>& y, std::vector<std::vector<double>>& x){
    double sumY = 0.0;
    double sumX = 0.0;
    double sumXX = 0.0;
    double sumXY = 0.0;
    double b = 0.0;
    for(size_t i = 0; i < y.size(); i++){
        sumY += y[i];
        sumX += x[i][0]; 
        sumXX += sumX * sumX;
        sumXY += sumX * sumY;


    }
    double w = Search_Intc(y, x);

    b  = (sumY - w * sumX) / y.size();

    return b;
}

//Mean Squared Error 
double MSE(double pred_y, std::vector<double>& y){
    int n = y.size();
    double error = 0.0;
    for(size_t i = 0 ; i < n; i++){
         error += pred_y - y[i];

    }
    double total_loss = error * error;
    double mean = total_loss / n;
    return mean; 
}



