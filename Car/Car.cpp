#include "Car.h"
#include <string>		/*strcpy_s*/
#include <iomanip>		/*setw*/
#include <time.h>       /* time_t, struct tm, time, localtime */

Car::Car()
{
	strcpy_s(this->make, 1, "");
	strcpy_s(this->model, 1, "");
	strcpy_s(this->color, 1, "");
	this->year = 0;
	this->engineVol = 0;
}

Car::Car(const Car& other_car)
{
	strcpy_s(this->make, strlen(other_car.make) + 1, other_car.make);
	strcpy_s(this->model, strlen(other_car.model) + 1, other_car.model);
	strcpy_s(this->color, strlen(other_car.color) + 1, other_car.color);
	this->year = other_car.year;
	this->engineVol = other_car.engineVol;
}


Car::Car(unsigned int _year, unsigned int _engineVol):
	year(_year), engineVol(_engineVol)
{
	strcpy_s(this->make, 1, "");
	strcpy_s(this->model, 1, "");
	strcpy_s(this->color, 1, "");
}

Car::Car(char* _make, char* _model, char* _color, unsigned int _year, unsigned int _engineVol) :
	year(_year), engineVol(_engineVol)
{
	strcpy_s(this->make, MAKE_MAX_LEN, _make);
	strcpy_s(this->model, MODEL_MAX_LEN, _model);
	strcpy_s(this->color, COLOR_MAX_LEN, _color);
}

bool Car::setMake(char* makeStr, int makeLen)
{
	if(makeLen > MAKE_MAX_LEN)
	{
		printf("ERROR: Make string should not exceed %d characters.", MAKE_MAX_LEN);
		printf("ERROR: Current value of make: %s.\n", make);
		return false;
	}
	strcpy_s(this->make, makeLen, makeStr);
	return true;
}
const char* Car::getMake() const
{
	return this->make;
}


bool Car::setModel(char * modelStr, int modelLen)
{
	if(modelLen > MODEL_MAX_LEN)
	{
		printf("ERROR: Model string should not exceed %d characters.", MODEL_MAX_LEN);
		printf("ERROR: Current value of model: %s.\n", model); 
		return false;
	}
	strcpy_s(this->model, modelLen, modelStr);
	return true;
}
const char* Car::getModel() const
{
	return this->model;
}

bool Car::setColor(char* colorStr, int colorLen)
{
	if(colorLen > MAKE_MAX_LEN)
	{
		printf("ERROR: Color string should not exceed %d characters.\n", MAKE_MAX_LEN);
		printf("ERROR: Current value of color: %s.\n", color);
		return false;
	}
	strcpy_s(this->color, colorLen, colorStr);
	return true;
}
const char* Car::getColor() const
{
	return this->color;
}

bool Car::setYear(unsigned int user_year)
{
	time_t t = time(NULL);
	tm Time;
	localtime_s(&Time, &t);

	if(user_year > (unsigned int)Time.tm_year + 1900)
	{
		printf("ERROR: Can't assign %d as the make year (it's in the future)\n", user_year);
		printf("ERROR: Current value of year: %d.\n", year);
		return false;
	}
	this->year = user_year;
	return true;
}
unsigned int Car::getYear() const
{
	return this->year;
}

void Car::setEngineVol(unsigned int vol)
{
	engineVol = vol;
}
unsigned int Car::getEngineVol() const
{
	return engineVol;
};

Car& Car::biggerEng(Car& car)
{
	return (this->engineVol > car.engineVol) ? *this : car;
}

Car& Car::newer(Car& car)
{
	return (this->year > car.year) ? *this : car;
}

std::ostream& operator<<(std::ostream& os, const Car& car)
{
	os << "\n\tMake : " << setw(13) << car.getMake() << std::endl;
	os << "\tModel: " << setw(13) << car.getModel() << std::endl;
	os << "\tYear : " << setw(13) << car.getYear() << std::endl;
	os << "\tEngine Vol(cc): " << setw(4) << car.getEngineVol() << std::endl;
	os << "\tColor: " << setw(13) << car.getColor() << std::endl;
	os << std::endl;
	return os;
}