#include <iostream>
#include <exception>
using namespace std;

class InvalidTemperatureException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidTemperatureException - what(): std::exception";
    }
};

template <typename T>
T convertToFahrenheit(T celsius) {
    if (celsius < -273.15)
        throw InvalidTemperatureException();
    return (celsius * 9 / 5) + 32;
}

int main() {
    try {
        cout << "Attempting to convert -300C...\n";
        double result = convertToFahrenheit(-300.0);
        cout << result << "F\n";
    } catch (exception& e) {
        cout << "Caught " << e.what() << endl;
    }
    return 0;
}
