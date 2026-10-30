#include <iostream>
#include <vector>
#include "../headers/algoritma.h"


int main(){
    Model linear;
    std::vector<std::vector<double>> csvSet = linear.openData("data/train1.csv");

    if (csvSet.empty()) {
        std::cerr << "No CSV data loaded. Check the file path and CSV contents.\n";
        return 1;
    }

    std::vector<std::vector<double>> x;
    std::vector<double> y;
    for (const auto& row : csvSet) {
        x.emplace_back(row.begin(), row.end() - 1);
        y.push_back(row.back());
    }

    const double mse = linear.Predc(200, y.size(), x, y);
    //std::cout << "Training MSE: " << mse << '\n';
    const std::vector<int> test = linear.CreateInt_Torch(10, 1, 10);
    for(auto& i : test){
        std::cout<<i<<"\n";
    }

    const double newX1 = 4.0;
    std::cout << "Prediction for x1 = " << newX1 << ": "
              << linear.predict(newX1) << '\n';

    return 0;
}
