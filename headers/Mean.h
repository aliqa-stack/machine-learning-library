#ifndef MEAN_ALGORITHM
#define MEAN_ALGORITHM
#include <cstddef>
#include <vector>

namespace MEAN{

    class Squared{
        public:
        #if defined(ERROR_MEAN)
        double MSE(double pred_y, std::vector<double>& y);
        #endif //mse        
        double  mean(int Sizesample, std::vector<double>& y);


    };
        
}


#endif