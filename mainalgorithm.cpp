#include "algoritma.h"
#include <iostream>
#include <vector>

/*
    main formula 

*/

Model::Model(){
    learning_rate = 0.001;
    w = 0.5;
    b = 0.5;
}


double Model::mean(int Sizesample, std::vector<double>& y){

    double xbar = 0;
    for(size_t i = 0; i < y.size(); i++){
        xbar = xbar + y[i];
    }

    xbar = xbar/Sizesample;

    return xbar;

}


double Model::Predc(int epoch, const size_t Sizesample ,const std::vector<std::vector<double>>& x,  std::vector<double>& y, double &w){
    double barof_y = mean(Sizesample, y);
for(int j = 0 ; j < epoch; j++){
    double error =0;
    double error2=0;

    for(size_t i = 0; i < Sizesample; i++){
        double y_pred = (w * x[i][0]) + b;
        double loss = y_pred - barof_y;
        double ssr = y_pred - y[i];
         error2 += std::pow(loss, 2);
         error += std::pow(ssr, 2);
         
         gw += ssr* x[i][0];
         db += ssr;

             std::cout<<"expected prediction of y : "<<y_pred<<"  actual value is : "<<y[i]<<"\n";
         
        }
        
        gw = (2.0 / Sizesample) * gw;
       db  = (2.0 / Sizesample) * db;
        w = w - (learning_rate * gw);
        b = b - (learning_rate * db);
        gw = 0;
        db = 0;
        mse = error / Sizesample;
}

return mse;
}

