/*
1 meter = 3.2808 feet;
1 gram = 0.002205 pounds;
temperature in degrees Fahrenheit = 32 + 1.8 × temperature in degrees Celsius.
*/

#include<stdio.h>

void getInputs(int numInputs, double resultValuesArray[], char* resultTypeArray[]);
void displayResults(int numInputs, double resultValuesArray[], char* resultTypeArray[]);
double metersToFeet(double meters);
double gramToPound(double grams);
double CelsiusToFahrenheit(double tempCelsius);
const char* getConversionType(char inputType);

int main(void){
    int numInputs;

    scanf("%d", &numInputs);
    double resultValuesArray[numInputs];
    char* resultTypeArray[numInputs];

    getInputs(numInputs, resultValuesArray, resultTypeArray);
    displayResults(numInputs, resultValuesArray, resultTypeArray);

    return 0;
}

void getInputs(int numInputs, double resultValuesArray[], char* resultTypeArray[]){
    
    double inputValue;
    char conversionType;
    int i;

    for (i = 0; i < numInputs; i++){    
        scanf("%lf %c", &inputValue, &conversionType);
        
        if (conversionType == 'm')
            resultValuesArray[i] =  metersToFeet(inputValue);
        else if (conversionType == 'g')
            resultValuesArray[i] =  gramToPound(inputValue);
        else if (conversionType == 'c')
            resultValuesArray[i] =  CelsiusToFahrenheit(inputValue);

        resultTypeArray[i] = getConversionType(conversionType);
    }
}

void displayResults(int numInputs, double resultValuesArray[], char* resultTypeArray[]){
    int i;
    for (i = 0; i < numInputs; i++){
        printf("%lf %s\n", resultValuesArray[i], resultTypeArray[i]);
    }
}

double metersToFeet(double meters){
    return meters * 3.2808;
}

double gramToPound(double grams){
    return grams * 0.002205;
}

double CelsiusToFahrenheit(double tempCelsius){
    return  32 + (1.8 * tempCelsius);
}

const char* getConversionType(char inputType){
    if (inputType == 'm')
        return "ft";
    if (inputType == 'g')
        return "lbs";
    if (inputType == 'c')
        return "f";
}