#pragma once

#include <vector>
#include <iostream>

template <typename T>
class Vector : public std::vector<T> {
    public:
        Vector() : std::vector<T>() {}
        Vector(std::initializer_list<T> values) : std::vector<T>(values) {}

        // + operator
        // sums 2 vectors
        Vector<T> operator+(const Vector& outro) {
            Vector<T> result = *this;
            for(std::size_t i = 0; i < this->size(); ++i) {
                result[i] += outro[i];
            }

            return result;
        }

        // - operator
        // subtracts 2 vector
        Vector<T> operator-(const Vector& outro) {
            Vector<T> result = *this;
            for(std::size_t i = 0; i < this->size(); ++i) {
                result[i] -= outro[i];
            }

            return result;
        }

        // * operator
        // multiplies a vector with a scalar
        Vector<T> operator*(const double& outro) {
            Vector<T> result = *this;
            for(std::size_t i = 0; i < this->size(); ++i) {
                result[i] *= outro;
            }

            return result;
        }

        // << operator
        // std::cout's the vector
        friend std::ostream& operator<<(std::ostream& os, const Vector& outro) {
            os << '{';
            for(std::size_t i = 0; i < outro.size(); ++i) {
                os << outro[i];
                if(i+1 != outro.size()) {
                 os << ',';
                }
            }
            os << '}';

            return os;
        }
};
