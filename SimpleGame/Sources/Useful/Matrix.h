#pragma once

#include <vector>

namespace uf {

template<class T>
class Matrix
{
Matrix::Matrix(uint8_t x, uint8_t y)
    : vectors(y, std::vector<T>(x));
{ }

std::vector<T> &Matrix::operator[](int index)
{
    return vectors[index];
}

private:
    std::vector<std::vector<T>> vectors;
};

}
