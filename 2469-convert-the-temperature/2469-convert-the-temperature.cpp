class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        
        // Convert Celsius to Kelvin
        double kelvin = celsius + 273.15;

        // Convert Celsius to Fahrenheit
        double fahrenheit = celsius * 1.80 + 32;

        // Return both values: Kelvin first, Fahrenheit second
        return {kelvin, fahrenheit};
    }
};