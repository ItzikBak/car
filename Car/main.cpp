#include "Car.h"

#define BUFF_LEN 256

int main()
{
	Car carA = Car();

	unsigned int user_year;
	unsigned int user_engine_vol;
	unsigned int user_str_len;
	char user_make[ BUFF_LEN ] ;
	char user_model[ BUFF_LEN ];
	char user_color[ BUFF_LEN ];

	// get user input
	cout << "Please enter the car's make:" << endl;
	cin >> user_make;
	user_str_len = strlen(user_make);
	carA.setMake(user_make, user_str_len + 1);

	cout << "Please enter the car's model:" << endl;
	cin >> user_model;
	user_str_len = strlen(user_model);
	carA.setModel(user_model, user_str_len + 1);

	cout << "Please enter the car's color:" << endl;
	cin >> user_color;
	user_str_len = strlen(user_color);
	carA.setColor(user_color, user_str_len + 1);

	cout << "Please enter the car's engine volume:" << endl;
	cin >> user_engine_vol;
	carA.setEngineVol(user_engine_vol);

	cout << "Please enter the car's year of make:" << endl;
	cin >> user_year;
	carA.setYear(user_year);

	cout << "The details of the car are:" << endl;
	cout << carA;

	Car carB("Hyundai", "Veluster", "Black", 2017, 500);
	cout << "CarA:" << carA << endl;
	cout << "CarB:" << carB << endl;
	cout << endl;

	cout << "The car with the bigger engine is: " << carA.biggerEng(carB);
	cout << "The newest car is: " << carA.newer(carB);

}