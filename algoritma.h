#ifndef _ALM_
#define _ALM_
#include <vector>
#include <math.h>


//double Predc(std::vector<std::vector<double>>& x,std::vector<double>& y, double& w);
//double Search_Slp(std::vector<double>&y, std::vector<std::vector<double>>& x);
//double MSE(double pred_y, std::vector<double>& y);
class Model{
    private:
        double learning_rate;
        double w;
        double b;
        double db;
        double gw;
    
    public:
        double mse;
        Model();
        double Predc(int epoch, const std::size_t Sizesample, const std::vector<std::vector<double>>& x, const std::vector<double>& y, double& w);
        double Search_Slp(std::vector<double>&y, std::vector<std::vector<double>>& x);
        double MSE(double pred_y, std::vector<double>& y);
};





#endif //_ALM_