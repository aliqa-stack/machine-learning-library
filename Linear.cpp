#include <iostream>
#include <vector>
#include <cstdlib>


int main(){
    std::vector<std::vector<double>> x = {
        {2,1},
        {3,1},
        {5,2},
        {6,4},
        {8,5},
        {10,7}
    };
    //std::vector<double> y = {20,40,80,85,95,100};
    int n = x.size();

    double w = 0.0;
    double b = 0.0;
    double sumX = 0.0;
    double sumY = 0.0;
    double sumXX = 0.0;
    double sumXY = 0.0;


    for(size_t i = 0; i < 1000 ; i++){
  
        double gradient1 = 0.0;
        double gradient_b = 0.0;
        double e;
        double totalLoss = 0.0;
        for(size_t j = 0; j < n; j++){
            //double x_value = x[j][0];
            //sumX += x_value;
            //sumY += y[j];
            //sumXX += x_value * x_value;
            //sumXY += x_value * y[j];
            //w = ( n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
            //b = (sumY - w * sumX) / n;
            double y_pred = w*x[j][0] + b;
           double  error =  y_pred - x[j][1];
           totalLoss += error * error;
           
           gradient1 +=  error * x[j][0]; 
           gradient_b += error ;
           
           printf("at %zu actual : %f  predicted : %f and error %f\n",i,  x[j][1], y_pred, error);
            
            
        }
        
        gradient1 =  (2.0 / n) * gradient1;
        gradient_b =  (2.0 / n) * gradient_b ;
       w -= (0.0005 * gradient1);
       b -=  (0.0005 *  gradient_b);
       double mse = totalLoss / n;
       // printf("at iteration %ld the mse of function  is : %f ", i, mse);
        printf("mse : %f w %f b %f \n",mse, w, b);
    }
    printf("-------------------------------- \n");
    printf("final : %f \n", w + b);
     


    return 0;
}