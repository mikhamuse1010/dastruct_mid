#include <iostream>
#include <string> 
#include <math.h> // For Extended class

using namespace std;

// For extended operators other than + - * /
class Extended {
    public:
        // Trigonometry
        double sin();
        double cos();
        double tan();
        // Numeric Operations
        double sqRoot();
        double exp();
        double log();
        double ln();
};

// For basic operators
class Operators {
    public:
        int Addition(int a, int b);
        int Substraction(int a, int b);
        int Multiplication(int a, int b);
        double Division(int a, int b);
};

int Operators::Addition(int a, int b) {
    return (a + b);
}

int Operators::Substraction(int a, int b) {
    return (a - b);
}

int Operators::Multiplication(int a, int b) {
    return (a * b);
}

double Division(int a, int b) {
    return double(a / b);
}

// Main function
int main() {
    const int MAX_INPUT = 100;
    Operators op;
    int i = MAX_INPUT;

    char input[MAX_INPUT];

    cin.getline(input, MAX_INPUT);

    // ini gw bingung mau digimanain lagi 
    // how to mengolah input-nya. stuck masihan
    // makanya gw templating class nya dulu

    return 0;
}