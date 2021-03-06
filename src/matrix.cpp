#include <cassert>
#include <cmath>

#include "src/matrix.hpp"

namespace LinearAlgebra {

Matrix::Matrix(const Matrix::MatrixType &inputMatrix) : matrix_(inputMatrix) { }

void Matrix::setSize(const unsigned &rows, const unsigned &columns) {
  matrix_.resize(rows);
  for (auto &row : matrix_)
    row.resize(columns);
}

unsigned Matrix::getNumberOfRows() const {
  return matrix_.size();
}

unsigned Matrix::getNumberOfColumns() const {
  assert(getNumberOfRows() > 0);
  return matrix_[0].size();
}

double &Matrix::operator()(int rowIndex, int columnIndex) {
  return matrix_[rowIndex][columnIndex];
}

const double &Matrix::operator()(int rowIndex, int columnIndex) const {
  return matrix_[rowIndex][columnIndex];
}

Matrix &Matrix::operator*(const double &scaleFactor) {
  for (auto &row : matrix_)
    for (auto &entry : row)
      entry *= scaleFactor;
  return *this;
}

Matrix &operator*(const double &scaleFactor, Matrix matrix) {
  return matrix * scaleFactor;
}

} // namespace LinearAlgebra