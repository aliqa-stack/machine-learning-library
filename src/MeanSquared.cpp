#include "../headers/Mean.h"


#if defined(ERROR_MEAN)
    double Squared::MSE(double pred_y, std::vector<double>& y){
        size_t n = y.size();
        double SY = 0;
        for(size_t i = 0; i < n; i++){
            SY = y[i];
        }
        double totalErr = pred_y - SY;
        double error = std::pow(totalErr, 2); 
        double mse = error / n;

        return mse;
    }
#endif //mse

double MEAN::Squared::mean(int Sizesample, std::vector<double>& y){

    double xbar = 0;
    for(size_t i = 0; i < y.size(); i++){
        xbar = xbar + y[i];
    }

    xbar = xbar/Sizesample;

    return xbar;

}