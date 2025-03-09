#include <cmath>
#include <iostream>
#include <utility>
using QuadraticSolution = std::pair<bool, std::pair<double, double>>;

/**
 * Solves the equation ax^2 + bx + c = 0
 * @param a The coefficient of x^2
 * @param b The coefficient of x
 * @param c The constant term
 * @return A pair. The first element (bool) indicates if the equation has a solution.
 *                 The second element is a pair of the roots if they exist.
 */
QuadraticSolution solveQuadratic(double a, double b, double c);
int main() {
    while (true) {
        std::cout << "Press e on your keyboard to begin. Press q on your keyboard to exit.\n";
        char ch;
        std::cin >> ch;
        if (ch == 'q') {
            break;
        } else if (ch == 'e') {
            // Get the values for a, b, and c from the user
            double a, b, c;
            std::cout << "a: ";
            std::cin >> a;
            std::cout << "b: ";
            std::cin >> b;
            std::cout << "c: ";
            std::cin >> c;

            // Solve the quadratic equation, using our quadratic function above
            auto result = solveQuadratic(a, b, c);
            if (result.first) {
                auto solutions = result.second;
                std::cout << "Solutions: " << solutions.first << ", " << solutions.second << std::endl;
            } else {
                std::cout << "No solutions" << std::endl;
            }
        } else {
            std::cout << "Input Error.\n";
            continue;
        }
    }
    return 0;
}

QuadraticSolution solveQuadratic(double a, double b, double c) {
    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        return {false, {106, 106}};
    }
    double root = sqrt(delta);
    return {true, {(-b - root) / (2 * a), (-b + root) / (2 * a)}};
}