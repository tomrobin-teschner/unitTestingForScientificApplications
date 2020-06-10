#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

namespace LinearAlgebra {

class Matrix {
public:
  using MatrixType = std::vector<std::vector<double>>;

public:
  Matrix() = default;
  Matrix(const MatrixType &inputMatrix);

  const double &operator()(int rowIndex, int columnIndex) const;

private:
  MatrixType matrix_;
};

} // namespace LinearAlgebra

#endif