#include <Eigen/Dense>

// Define a 20x1 column vector
Eigen::VectorXd x(20);

// Define a 20x20 matrix
Eigen::MatrixXd A(20, 20);

// Fill the vector and matrix with some values
for (int i = 0; i < 20; i++) {
    x(i) = i;
    for (int j = 0; j < 20; j++) {
        A(i, j) = i * j;
    }
}

// Perform some linear algebra operations
Eigen::VectorXd y = A * x;
double dot_product = x.dot(y);
double norm = x.norm();
Eigen::MatrixXd B = A.inverse();
Eigen::MatrixXd C = A.transpose();

std::cout << "Vector x: " << std::endl << x << std::endl;
std::cout << "Matrix A: " << std::endl << A << std::endl;
std::cout << "Vector y = A * x: " << std::endl << y << std::endl;
std::cout << "Dot product of x and y: " << dot_product << std::endl;
std::cout << "Norm of x: " << norm << std::endl;
std::cout << "Inverse of A: " << std::endl << B << std::endl;
std::cout << "Transpose of A: " << std::endl << C << std::endl;
