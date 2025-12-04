
#include <stdio.h>

void celsius_to_fahrenheit_kelvin(float c) {
	printf("%.2f Celsius = %.2f Fahrenheit\n", c, c * 9/5 + 32);
	printf("%.2f Celsius = %.2f Kelvin\n", c, c + 273.15);
}

void fahrenheit_to_celsius_kelvin(float f) {
	printf("%.2f Fahrenheit = %.2f Celsius\n", f, (f - 32) * 5/9);
	printf("%.2f Fahrenheit = %.2f Kelvin\n", f, (f - 32) * 5/9 + 273.15);
}

void kelvin_to_celsius_fahrenheit(float k) {
	printf("%.2f Kelvin = %.2f Celsius\n", k, k - 273.15);
	printf("%.2f Kelvin = %.2f Fahrenheit\n", k, (k - 273.15) * 9/5 + 32);
}

int main() {
	int choice;
	float temp;
	printf("Temperature Converter\n");
	printf("1. Celsius to Fahrenheit & Kelvin\n");
	printf("2. Fahrenheit to Celsius & Kelvin\n");
	printf("3. Kelvin to Celsius & Fahrenheit\n");
	printf("Enter your choice (1-3): ");
	scanf("%d", &choice);

	switch(choice) {
		case 1:
			printf("Enter temperature in Celsius: ");
			scanf("%f", &temp);
			celsius_to_fahrenheit_kelvin(temp);
			break;
		case 2:
			printf("Enter temperature in Fahrenheit: ");
			scanf("%f", &temp);
			fahrenheit_to_celsius_kelvin(temp);
			break;
		case 3:
			printf("Enter temperature in Kelvin: ");
			scanf("%f", &temp);
			kelvin_to_celsius_fahrenheit(temp);
			break;
		default:
			printf("Invalid choice!\n");
	}
	return 0;
}
