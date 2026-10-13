#ifndef _ALM_
#define _ALM_
#include <vector>

double Predc(std::vector<std::vector<double>>& x,std::vector<double>& y, double w, double b);
double Search_Slp(std::vector<double>&y, std::vector<std::vector<double>>& x);
double MSE(double pred_y, std::vector<double>& y);





#endif //_ALM_