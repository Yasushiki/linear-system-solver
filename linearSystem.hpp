#pragma once

#include "vectorOperatorOverload.hpp"

class LinearSystem {
    public:
        // linear system variable
        std::vector<Vector<double>> ls;
        std::size_t nVar = ls.size();

        // class constructor
        LinearSystem(std::vector<Vector<double>> v) : ls(v) {}

        // solving the linear system
        Vector<double> solve() {
            Vector<double> result;

            // Gauss' method
            for(std::size_t i = 0; i < nVar-1; ++i) {
                // force the element to be 1
                ls[i] = ls[i]*(1/ls[i][i]);

                // iterate through the rest of the matrix
                for(std::size_t j = i+1; j < nVar; ++j) {
                    ls[j] = ls[j]-(ls[i]*ls[j][i]);
                }
            }

            // Gauss-Jordan method
            for(std::size_t i = nVar-1; i > 0; --i) {
                // force the element to be 1
                ls[i] = ls[i]*(1/ls[i][i]);

                // iterate through the rest of the matrix
                for(std::size_t j = i-1; j != -1; --j) {
                    ls[j] = ls[j]-(ls[i]*ls[j][i]);
                }
            }

            // create the solution matrix
            for(size_t i = 0; i < nVar; ++i) {
                result.push_back(ls[i][nVar]);
            }

            return result;
        }
};
