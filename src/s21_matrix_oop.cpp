#include "s21_matrix_oop.h"
#include <exception>
#include <stdexcept>

static const double eps = 1e-7;

static double** create_matrix(int rows, int cols) {
    double **matrix = new double *[rows];
    matrix[0] = new double[rows * cols]();
    for (int i = 1; i < rows; i++) {
        matrix[i] = matrix[i - 1] + cols;
    }
    return matrix;
}

inline static bool is_empty_matrix(int rows, int cols) {
    return rows == 0 || cols == 0;
}

inline static bool is_size_equal(const S21Matrix& m1, const S21Matrix& m2) {
    return m1.get_rows() == m2.get_rows() && m1.get_cols() == m2.get_cols();
}

inline static bool is_square_matrix(int rows, int cols) {
    return rows == cols;
}

static double** copy_matrix(double **src, int rows, int cols) {
    double **result = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = src[i][j];
        }
    }
    return result;
}

static S21Matrix get_minor_matrix(const S21Matrix& m, int m_i, int m_j) {
    int rows = m.get_rows();
    int cols = m.get_cols();
    S21Matrix result(rows - 1, cols - 1);
    for (int i = 0, res_i = 0; i < rows; i++) {
        if (i != m_i) {
            for (int j = 0, res_j = 0; j < cols; j++) {
                if (j != m_j)
                    result(res_i, res_j++) =  m(i, j);
            }
            res_i++;
        }
    }
    return result;
}

inline S21Matrix::S21Matrix() : _rows(0), _cols(0), _matrix(nullptr) {
}

S21Matrix::S21Matrix(int rows, int cols) : _rows(rows), _cols(cols) {
    if (is_empty_matrix(rows, cols))
        throw std::invalid_argument("Rows or columns can't be less or equal 0");
    this->_matrix = create_matrix(rows, cols);
}

S21Matrix::S21Matrix(const S21Matrix& other) : _rows(other._rows), _cols(other._cols) {
    this->_matrix = copy_matrix(other._matrix, this->_rows, this->_cols);
}

S21Matrix::S21Matrix(S21Matrix&& other) : _rows(other._rows), _cols(other._cols) {
    this->_matrix = copy_matrix(other._matrix, this->_rows, this->_cols);
    delete []other._matrix[0];
    delete []other._matrix;
    other._rows = 0;
    other._cols = 0;
}

S21Matrix::~S21Matrix() {
    if (this->_rows) {
        delete []this->_matrix[0];
        delete []this->_matrix;
    }
}

inline int S21Matrix::get_cols() const {
    return this->_cols;
}

inline int S21Matrix::get_rows() const {
    return this->_rows;
}

bool S21Matrix::eq_matrix(const S21Matrix& other) {
    bool result = true;
    if (!is_size_equal(*this, other)) {
        result = false;
    } else {
        for (int i = 0; i < this->_rows; i++) {
            for (int j = 0; j < this->_cols; j++) {
                if (fabs(this->_matrix[i][j] - other._matrix[i][j]) >= eps)
                    result = false;
            }
        }
    }
    return result;
}

void S21Matrix::sum_matrix(const S21Matrix& other) {
    if (!is_size_equal(*this, other))
        throw std::logic_error("Matrixes sizes are not equal");
    for (int i = 0; i < this->_rows; i++) {
        for (int j = 0; j < this->_cols; j++)
            this->_matrix[i][j] += other._matrix[i][j];
    }
}

void S21Matrix::sub_matrix(const S21Matrix& other) {
    if (!is_size_equal(*this, other))
        throw std::logic_error("Matrixes sizes are not equal");
    for (int i = 0; i < this->_rows; i++) {
        for (int j = 0; j < this->_cols; j++) {
            this->_matrix[i][j] -= other._matrix[i][j];
        }
    }
}

void S21Matrix::mul_number(const double num) {
    for (int i = 0; i < this->_rows; i++) {
        for (int j = 0; j < this->_cols; j++) {
            this->_matrix[i][j] *= num;
        }
    }
}

void S21Matrix::mul_matrix(const S21Matrix &other) {
    if (this->_cols != other._rows)
        throw std::logic_error("Can't mul matrixes");
    S21Matrix result(this->_rows, other._cols);
    for (int i = 0; i < result._rows; i++) {
        for (int j = 0; j < result._cols; j++) {
            for (int k = 0; k < other._rows; k++)
                result._matrix[i][j] += this->_matrix[i][k] * other._matrix[k][j];
        }
    }
    *this = result;
}

S21Matrix S21Matrix::transpose() {
    S21Matrix result(this->_cols, this->_rows);
    for (int i = 0; i < this->_rows; i++) {
        for (int j = 0; j < this->_cols; j++) {
            result._matrix[j][i] = this->_matrix[i][j];
        }
    }
    return result;
}

double S21Matrix::determinant() {
    double result = 0;
    if (!is_square_matrix(this->_rows, this->_cols))
        throw std::logic_error("Matrix isn't square matrix");
    if (_rows == 1) {
        result = (*this)(0, 0);
    } else if (_rows == 2) {
        result =  ((*this)(0, 0) * (*this)(1, 1))
            -  ((*this)(1, 0) * (*this)(0, 1));
    } else {
        for (int i = 0; i < _rows; i++) {
            S21Matrix minor = get_minor_matrix(*this, 0, i);
            result += pow(-1, i+2) * (*this)(0, i) * minor.determinant();
        }
    }
    return result;
}

S21Matrix S21Matrix::calc_complements() {
    if (!is_square_matrix(this->_rows, this->_cols))
        throw std::logic_error("Matrix isn't square matrix");
    S21Matrix result(this->_rows, this->_cols);
    if (this->_rows == 1) {
        result(0, 0) = 1;
    } else {
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                S21Matrix minor = get_minor_matrix(*this, i, j);
                result(i, j) = pow(-1, i+j+2) * minor.determinant();
            }
        }
    }
    return result;
}

S21Matrix S21Matrix::inverse_matrix() {
    double det = this->determinant();
    if (det == 0.0)
        throw std::invalid_argument("Determinant is 0");
    S21Matrix calc = this->calc_complements();
    S21Matrix transposed = calc.transpose();
    transposed.mul_number(1 / det);
    return transposed;
}

S21Matrix S21Matrix::operator +(const S21Matrix& other) {
    S21Matrix result(*this);
    result.sum_matrix(other);
    return result;
}

S21Matrix S21Matrix::operator -(const S21Matrix& other) {
    S21Matrix result(*this);
    result.sub_matrix(other);
    return result;
}

S21Matrix S21Matrix::operator *(const double num) {
    S21Matrix result(*this);
    result.mul_number(num);
    return result;
}

S21Matrix S21Matrix::operator *(const S21Matrix& other) {
    S21Matrix result(*this);
    result.mul_matrix(other);
    return result;
}

bool S21Matrix::operator ==(const S21Matrix& other) {
    return this->eq_matrix(other);
}

S21Matrix& S21Matrix::operator =(const S21Matrix& other) noexcept {
    this->_rows = other._rows;
    this->_cols = other._cols;
    delete [] this->_matrix[0];
    delete [] this->_matrix;
    this->_matrix = create_matrix(this->_rows, this->_cols);
    for (int i = 0; i < this->_rows; i++) {
        for (int j = 0; j < this->_cols; j++)
            this->_matrix[i][j] = other._matrix[i][j];
    }
    return *this;
}

void S21Matrix::operator +=(const S21Matrix& other) {
    this->sum_matrix(other);
}

void S21Matrix::operator -=(const S21Matrix& other) {
    this->sub_matrix(other);
}

void S21Matrix::operator *=(const S21Matrix& other) {
    this->mul_matrix(other);
}

void S21Matrix::operator *=(const double num) {
    this->mul_number(num);
}

double& S21Matrix::operator ()(int i, int j) const {
    if ((i < 0 || i > _rows) || (j < 0 || j > _cols))
        throw std::out_of_range("Outside of matrix");
    return this->_matrix[i][j];
}

S21Matrix operator *(const double num, const S21Matrix& other) {
    S21Matrix result(other);
    result *= num;
    return result;
}
