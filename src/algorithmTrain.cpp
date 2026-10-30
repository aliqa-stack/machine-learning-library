#include "../headers/algoritma.h"
#include <iostream>
#include <vector>

/*
    main formula 

*/




double Model::mean(int Sizesample, std::vector<double>& y){

    double xbar = 0;
    for(size_t i = 0; i < y.size(); i++){
        xbar = xbar + y[i];
    }

    xbar = xbar/Sizesample;

    return xbar;

}


double Model::Predc(int epoch, const size_t Sizesample ,const std::vector<std::vector<double>>& x,  std::vector<double>& y){
    double barof_y = mean(Sizesample, y);
for(int j = 0 ; j < epoch; j++){
    double error =0;
    double error2=0;

    for(size_t i = 0; i < Sizesample; i++){
        //double y_pred = (w * x[i][0]) + b;
        double y_pred = predict(x[i][0]);
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

        
        mse = error / Sizesample;
}

return mse;
}

double  Model::predict(double x){
 
    return (w * x) + b;
}

double Model::Search_Intc(std::vector<double>&y, std::vector<std::vector<double>>& x){
    double intercept = 0;
    int n = y.size();
    double sumX = 0;
    double sumY = 0;
    double sumXY = 0;
    double sumXX = 0;
    
  for(size_t i = 0; i < y.size(); i++){
    double x_value = x[i][0];
     sumX += x_value;
     sumY += y[i];
     sumXY += sumX * sumY;
     sumXX += std::pow(sumX, 2);

    intercept = ( n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);

  }


  return intercept;
}

#if defined(ERROR_MEAN)
    double MSE(double pred_y, std::vector<double>& y){
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

std::vector<std::vector<double>> Model::openData(const std::string& fileName){
    
    std::ifstream file(fileName);
    std::vector<std::vector<double>> data;

    if(!file.is_open()){
        std::cerr<<"gagal membuka file csv \n";
        return data;
    }

    std::string line;
    std::getline( file, line);
    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string value;

        std::vector<double> row;

        while(std::getline(ss, value, ',')){
            row.push_back(std::stod(value));
        }

        if(row.size() < 3 ){
            std::cerr<<"format csv tidak valid!! \n";
            continue;
        }
        data.push_back(row);

        
    }
    return data;

}


std::vector<int> Model::CreateInt_Torch(int count, int from, int until){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(from, until);

    std::vector<int> array;

    for(int i = 0; i < count;i++){
        array.push_back(distrib(gen));
    }

    return array;

}