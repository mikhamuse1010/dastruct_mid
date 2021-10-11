#include<bits/stdc++.h>
#include <string> 
#include <math.h> // For Extended class
using namespace std;

queue <string> history;

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
        double Addition(double a, double b);
        double Substraction(double a, double b);
        double Multiplication(double a, double b);
        double Division(double a, double b);
};

int Operators::Addition(double a, double b) {
    return (a + b);
}

int Operators::Substraction(double a, double b) {
    return (a - b);
}

int Operators::Multiplication(double a, double b) {
    return (a * b);
}

double Operators::Division(double a, double b) {
    return double(a / b);
}

// Main function
int main() {
    //const int MAX_INPUT = 100;
    Operators op;
    string eq;
    //int i = MAX_INPUT;

    //char input[MAX_INPUT];

    getline(cin,eq);

    // ini gw bingung mau digimanain lagi 
    // how to mengolah input-nya. stuck masihan
    // makanya gw templating class nya dulu

    return 0;
}
