#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.14159265358979323846;

double semiMajorAxis(double r1, double r2) {
    return (r1 + r2) / 2;
}

double transferOrbitVelocity(double r1, double r2, double a) {
    return sqrt(2 * (1/r1 - 1/(2*a)) + (1/r2 - 1/(2*a)));
}

int main() {
    double r1, r2;
    cout << "Enter the initial distance from the central body: ";
    cin >> r1;
    cout << "Enter the final distance from the central body: ";
    cin >> r2;

    double a = semiMajorAxis(r1, r2);
    double v1 = transferOrbitVelocity(r1, r2, a);
    double v2 = transferOrbitVelocity(r2, r1, a);

    cout << "The semi-major axis of the transfer orbit is: " << a << endl;
    cout << "The velocity at the initial point is: " << v1 << endl;
    cout << "The velocity at the final point is: " << v2 << endl;

    return 0;
}
