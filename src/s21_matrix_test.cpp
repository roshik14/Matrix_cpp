#include <gtest/gtest.h>
#include "s21_matrix_oop.h"

TEST(MatrixEqualSuit, EqTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a(i, j) =  k++;
    S21Matrix b(a);
    bool eq = a.eq_matrix(b);
    ASSERT_EQ(eq, true);

    b(0, 0) = 25;
    bool eq2 = a.eq_matrix(b);
    ASSERT_EQ(eq2, false);

    S21Matrix c(2, 3);
    double d = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            c(i, j) =  d++;
    bool eq3 = a.eq_matrix(c);
    ASSERT_EQ(eq3, false);
}

TEST(MatrixEqualOperatorSuit, EqOperatorTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a(i, j) =  k++;
    S21Matrix b(a);
    bool eq = a == b;
    ASSERT_EQ(eq, true);

    b(0, 0) = 25;
    bool eq2 = a == b;
    ASSERT_EQ(eq2, false);

    S21Matrix c(2, 3);
    double d = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            c(i, j) = d++;
    bool eq3 = a == c;
    ASSERT_EQ(eq3, false);
}

TEST(MatrixSumSuit, SumTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) =  k++;
        }
    }
    S21Matrix b(a);
    a.sum_matrix(b);
    S21Matrix expected(3, 3);
    expected(0, 0) = 2;
    expected(0, 1) = 4;
    expected(0, 2) = 6;
    expected(1, 0) = 8;
    expected(1, 1) = 10;
    expected(1, 2) = 12;
    expected(2, 0) = 14;
    expected(2, 1) = 16;
    expected(2, 2) = 18;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_DOUBLE_EQ(a(i, j), expected(i, j));
        }
    }

    S21Matrix d(5, 5);
    ASSERT_ANY_THROW(a.sum_matrix(d));
}

TEST(MatrixSumAssignOperatorSuit, SumAssignOperatorTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = k++;
        }
    }
    S21Matrix b(a);
    a += b;
    S21Matrix expected(3, 3);
    expected(0, 0) = 2;
    expected(0, 1) = 4;
    expected(0, 2) = 6;
    expected(1, 0) = 8;
    expected(1, 1) = 10;
    expected(1, 2) = 12;
    expected(2, 0) = 14;
    expected(2, 1) = 16;
    expected(2, 2) = 18;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_DOUBLE_EQ(a(i, j), expected(i, j));
        }
    }
}


TEST(MatrixSumOperatorSuit, SumOperatorTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = k++;
        }
    }
    S21Matrix b(a);
    S21Matrix c = a + b;
    S21Matrix expected(3, 3);
    expected(0, 0) = 2;
    expected(0, 1) = 4;
    expected(0, 2) = 6;
    expected(1, 0) = 8;
    expected(1, 1) = 10;
    expected(1, 2) = 12;
    expected(2, 0) = 14;
    expected(2, 1) = 16;
    expected(2, 2) = 18;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_DOUBLE_EQ(c(i, j), expected(i, j));
        }
    }
}

TEST(MatrixSubSuit, SubTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = k++;
        }
    }
    S21Matrix b(a);
    a.sub_matrix(b);
    S21Matrix expected(3, 3);
    expected(0, 0) = 0;
    expected(0, 1) = 0;
    expected(0, 2) = 0;
    expected(1, 0) = 0;
    expected(1, 1) = 0;
    expected(1, 2) = 0;
    expected(2, 0) = 0;
    expected(2, 1) = 0;
    expected(2, 2) = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_DOUBLE_EQ(a(i, j), expected(i, j));
        }
    }
    S21Matrix d(5, 5);
    ASSERT_ANY_THROW(a.sub_matrix(d));
}

TEST(MatrixSubAssignOperatorSuit, SubAsignOperatorTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = k++;
        }
    }
    S21Matrix b(a);
    a -= b;
    S21Matrix expected(3, 3);
    expected(0, 0) = 0;
    expected(0, 1) = 0;
    expected(0, 2) = 0;
    expected(1, 0) = 0;
    expected(1, 1) = 0;
    expected(1, 2) = 0;
    expected(2, 0) = 0;
    expected(2, 1) = 0;
    expected(2, 2) = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_DOUBLE_EQ(a(i, j), expected(i, j));
        }
    }
}

TEST(MatrixSubOperatorSuit, SubOperatorTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = k++;
        }
    }
    S21Matrix b(a);
    S21Matrix c = a - b;
    S21Matrix expected(3, 3);
    expected(0, 0) = 0;
    expected(0, 1) = 0;
    expected(0, 2) = 0;
    expected(1, 0) = 0;
    expected(1, 1) = 0;
    expected(1, 2) = 0;
    expected(2, 0) = 0;
    expected(2, 1) = 0;
    expected(2, 2) = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_DOUBLE_EQ(c(i, j), expected(i, j));
        }
    }
}

TEST(MatrixMulSuit, MulMatrixTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = k++;
        }
    }
    S21Matrix b(a);
    a.mul_matrix(b);
    S21Matrix expected(3, 3);
    expected(0, 0) = 30;
    expected(0, 1) = 36;
    expected(0, 2) = 42;
    expected(1, 0) = 66;
    expected(1, 1) = 81;
    expected(1, 2) = 96;
    expected(2, 0) = 102;
    expected(2, 1) = 126;
    expected(2, 2) = 150;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_DOUBLE_EQ(a(i, j), expected(i, j));
        }
    }
    S21Matrix c(4, 3);
    ASSERT_ANY_THROW(a.mul_matrix(c));
}

TEST(MatrixMulAssignOperatorSuit, MulMatrixAssignOperatorTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = k++;
        }
    }
    S21Matrix b(a);
    a *= b;
    S21Matrix expected(3, 3);
    expected(0, 0) = 30;
    expected(0, 1) = 36;
    expected(0, 2) = 42;
    expected(1, 0) = 66;
    expected(1, 1) = 81;
    expected(1, 2) = 96;
    expected(2, 0) = 102;
    expected(2, 1) = 126;
    expected(2, 2) = 150;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_DOUBLE_EQ(a(i, j), expected(i, j));
        }
    }
}

TEST(MatrixMulOperatorSuit, MulMatrixOperatorTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = k++;
        }
    }
    S21Matrix b(a);
    S21Matrix c = a * b;
    S21Matrix expected(3, 3);
    expected(0, 0) = 30;
    expected(0, 1) = 36;
    expected(0, 2) = 42;
    expected(1, 0) = 66;
    expected(1, 1) = 81;
    expected(1, 2) = 96;
    expected(2, 0) = 102;
    expected(2, 1) = 126;
    expected(2, 2) = 150;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_DOUBLE_EQ(c(i, j), expected(i, j));
        }
    }
}

TEST(MatrixMulNumberSuit, MulNumberTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = k++;
        }
    }
    a.mul_number(132);
    S21Matrix expected(3, 3);
    expected(0, 0) = 132;
    expected(0, 1) = 264;
    expected(0, 2) = 396;
    expected(1, 0) = 528;
    expected(1, 1) = 660;
    expected(1, 2) = 792;
    expected(2, 0) = 924;
    expected(2, 1) = 1056;
    expected(2, 2) = 1188;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_DOUBLE_EQ(a(i, j), expected(i, j));
        }
    }
}

TEST(MatrixMulNumberAssignOperatorSuit, MulNumberAssignOperatorTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = k++;
        }
    }
    a *= 132.0;
    S21Matrix expected(3, 3);
    expected(0, 0) = 132;
    expected(0, 1) = 264;
    expected(0, 2) = 396;
    expected(1, 0) = 528;
    expected(1, 1) = 660;
    expected(1, 2) = 792;
    expected(2, 0) = 924;
    expected(2, 1) = 1056;
    expected(2, 2) = 1188;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_DOUBLE_EQ(a(i, j), expected(i, j));
        }
    }
}

TEST(MatrixMulNumberOperatorSuit, MulNumberOperatorTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a(i, j) = k++;
    S21Matrix c = a * 132.0;
    S21Matrix d = 132.0 * a;
    S21Matrix expected(3, 3);
    expected(0, 0) = 132;
    expected(0, 1) = 264;
    expected(0, 2) = 396;
    expected(1, 0) = 528;
    expected(1, 1) = 660;
    expected(1, 2) = 792;
    expected(2, 0) = 924;
    expected(2, 1) = 1056;
    expected(2, 2) = 1188;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_DOUBLE_EQ(c(i, j), expected(i, j));
            ASSERT_DOUBLE_EQ(d(i, j), expected(i, j));
        }
    }
}

TEST(MatrixTransposeSuit, TransposeTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = k++;
        }
    }
    S21Matrix result = a.transpose();
    S21Matrix expected(3, 3);
    expected(0, 0) = 1;
    expected(0, 1) = 4;
    expected(0, 2) = 7;
    expected(1, 0) = 2;
    expected(1, 1) = 5;
    expected(1, 2) = 8;
    expected(2, 0) = 3;
    expected(2, 1) = 6;
    expected(2, 2) = 9;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_DOUBLE_EQ(result(i, j), expected(i, j));
        }
    }
}

TEST(MatrixCalcComplementsSuit, CalcComplementsTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = k++;
        }
    }
    a(0, 0) = 2;
    a(1, 2) = 7;
    S21Matrix result = a.calc_complements();
    S21Matrix expected(3, 3);
    expected(0, 0) = -11;
    expected(0, 1) = 13;
    expected(0, 2) = -3;
    expected(1, 0) = 6;
    expected(1, 1) = -3;
    expected(1, 2) = -2;
    expected(2, 0) = -1;
    expected(2, 1) = -2;
    expected(2, 2) = 2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_DOUBLE_EQ(result(i, j), expected(i, j));
        }
    }
    S21Matrix b(1, 1);
    b(0, 0) = 2.5;
    S21Matrix b_result = b.calc_complements();
    ASSERT_EQ(b_result(0, 0), 1);
    S21Matrix d(5, 3);
    ASSERT_ANY_THROW(d.calc_complements());
}

TEST(MatrixDeterminantSuit, DeterminantTest) {
    S21Matrix a(3, 3);
    a(0, 0) = 25;
    a(0, 1) = 33;
    a(0, 2) = 44;
    a(1, 0) = 56;
    a(1, 1) = 78;
    a(1, 2) = 1.2;
    a(2, 0) = 3.4;
    a(2, 1) = 53.222;
    a(2, 2) = 0.4;
    double result = a.determinant();
    double expected = 118048.988;
    ASSERT_DOUBLE_EQ(result, expected);
    S21Matrix b(1, 1);
    b(0, 0) = 2.5;
    double b_result = b.determinant();
    ASSERT_DOUBLE_EQ(b_result, b(0, 0));
    S21Matrix d(5, 3);
    ASSERT_ANY_THROW(d.determinant());
}

TEST(MatrixInverseSuit, InverseMatrixTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a(i, j) = k++;
    a(0, 0) = 2;
    a(1, 2) = 7;
    S21Matrix result = a.inverse_matrix();
    S21Matrix expected(3, 3);
    expected(0, 0) = 11.0/5;
    expected(0, 1) = -6.0/5;
    expected(0, 2) = 1.0/5;
    expected(1, 0) = -13.0/5;
    expected(1, 1) = 3.0/5;
    expected(1, 2) = 2.0/5;
    expected(2, 0) = 3.0/5;
    expected(2, 1) = 2.0/5;
    expected(2, 2) = -2.0/5;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            ASSERT_DOUBLE_EQ(result(i, j), expected(i, j));
    S21Matrix c(3, 3);
    double p = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            c(i, j) = p++;
    ASSERT_ANY_THROW(c.inverse_matrix());
}


TEST(MatrixMoveConstructorSuit, MoveConstructorTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a(i, j) = k++;
    S21Matrix result(std::move(a));
    S21Matrix expected(3, 3);
    expected(0, 0) = 1;
    expected(0, 1) = 2;
    expected(0, 2) = 3;
    expected(1, 0) = 4;
    expected(1, 1) = 5;
    expected(1, 2) = 6;
    expected(2, 0) = 7;
    expected(2, 1) = 8;
    expected(2, 2) = 9;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            ASSERT_DOUBLE_EQ(result(i, j), expected(i, j));
}

TEST(MatrixCopyConstructorSuit, CopyConstructorTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a(i, j) = k++;
    S21Matrix result(a);
    S21Matrix expected(3, 3);
    expected(0, 0) = 1;
    expected(0, 1) = 2;
    expected(0, 2) = 3;
    expected(1, 0) = 4;
    expected(1, 1) = 5;
    expected(1, 2) = 6;
    expected(2, 0) = 7;
    expected(2, 1) = 8;
    expected(2, 2) = 9;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            ASSERT_DOUBLE_EQ(result(i, j), expected(i, j));
    ASSERT_EQ(a.get_rows(), result.get_rows());
    ASSERT_EQ(a.get_cols(), result.get_cols());
}

TEST(MatrixIndexationOperatorSuit, IndexationOperatorTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a(i, j) = k++;
    a(0, 0) = 1024;
    double expected = 1024;
    ASSERT_DOUBLE_EQ(a(0, 0), expected);
    ASSERT_ANY_THROW(a(5, 5) = 25);
    ASSERT_ANY_THROW(a(5, 5));
    ASSERT_ANY_THROW(a(5, 5) =  25);
}

TEST(MatrixAsignOperatorSuit, MatrixAsignOperatorTest) {
    S21Matrix a(3, 3);
    double k = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a(i, j) = k++;
    S21Matrix b(1, 1);
    b = a;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            ASSERT_DOUBLE_EQ(a(0, 0), b(0, 0));
    ASSERT_ANY_THROW(S21Matrix b(0, 0));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
