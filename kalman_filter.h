#include <Eigen/Dense>

// Define state vector and its size
Eigen::VectorXd state(4);
const int state_size = 4;

// Define state transition matrix
Eigen::MatrixXd A(state_size, state_size);

// Define measurement matrix
Eigen::MatrixXd H(2, state_size);

// Define process noise covariance matrix
Eigen::MatrixXd Q(state_size, state_size);

// Define measurement noise covariance matrix
Eigen::MatrixXd R(2, 2);

// Define Kalman gain
Eigen::MatrixXd K(state_size, 2);

// Define error covariance matrix
Eigen::MatrixXd P(state_size, state_size);

void KalmanFilter(Eigen::VectorXd& state, Eigen::MatrixXd& A, Eigen::MatrixXd& H, Eigen::MatrixXd& Q, Eigen::MatrixXd& R, Eigen::MatrixXd& P)
{
    // Predict state
    state = A * state;
    P = A * P * A.transpose() + Q;

    // Update state
    Eigen::VectorXd measurement(2);
    Eigen::VectorXd residual = measurement - H * state;
    K = P * H.transpose() * (H * P * H.transpose() + R).inverse();
    state = state + K * residual;
    P = (Eigen::MatrixXd::Identity(state_size, state_size) - K * H) * P;
}
