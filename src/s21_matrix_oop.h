#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_
#include <iostream>
#include <cmath>

class S21Matrix {
 private:
        int _rows, _cols;
        double **_matrix;

 public:
        S21Matrix();
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        S21Matrix(S21Matrix&& other);
        ~S21Matrix();
        int get_rows() const;
        int get_cols() const;
        bool eq_matrix(const S21Matrix& other);
        void sum_matrix(const S21Matrix& other);
        void sub_matrix(const S21Matrix& other);
        void mul_number(const double num);
        void mul_matrix(const S21Matrix& other);
        S21Matrix transpose();
        S21Matrix calc_complements();
        double determinant();
        S21Matrix inverse_matrix();
        S21Matrix operator +(const S21Matrix& other);
        S21Matrix operator -(const S21Matrix& other);
        S21Matrix operator *(const S21Matrix& other);
        S21Matrix operator *(const double num);
        bool operator ==(const S21Matrix& other);
        S21Matrix& operator =(const S21Matrix& other) noexcept;
        void operator +=(const S21Matrix& other);
        void operator -=(const S21Matrix& other);
        void operator *=(const S21Matrix& other);
        void operator *=(const double num);
        double& operator()(int i, int j) const;
};

S21Matrix operator *(const double num, const S21Matrix& other);

#endif  // SRC_S21_MATRIX_OOP_H_
