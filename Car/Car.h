#pragma once
#include <iostream>

using namespace std;

const int DEFAULT_STR_LEN = 10;
const int MAKE_MAX_LEN = DEFAULT_STR_LEN;
const int MODEL_MAX_LEN = DEFAULT_STR_LEN;
const int COLOR_MAX_LEN = DEFAULT_STR_LEN;


class Car
{
private:
	char make[ MAKE_MAX_LEN ];
	char model[ MODEL_MAX_LEN ];
	unsigned int year;
	unsigned int engineVol;
	char color[ COLOR_MAX_LEN ];

public:
	/**
	* Method:   Constructor
	* Class:	Car
	* Desc.:	Default constructor
	* @param
	* @return
	*/
	Car();

	/**
	* Method:   Copy Constructor
	* Class:	Car
	* Desc.:	Copy constructor
	* @param
	* @return
	*/
	Car(const Car&);

	/**
	* Method:   Constructor
	* Class:	Car
	* Desc.:	Construct the car object with year and engine volume
	* @params   unsigned int _year, unsigned int _engineVol
	* @return
	*/
	Car(unsigned int _year, unsigned int _engineVol);

	/**
	* Method:   Constructor
	* Class:	Car
	* Desc.:	Construct the car object with all parameters supllied
	* @params   char* _make, char* _model, char* _color, unsigned int _year, unsigned int _engineVol
	* @return
	*/
	Car(char* _make, char* _model, char* _color, unsigned int _year, unsigned int _engineVol);

	/**
	* Method:   setMake
	* Class:	Car
	* Desc.:	Set the car make. Return true if succeded, else false.
	* @params   char* makeStr, int makeLen
	* @return   bool
	*/
	bool setMake(char* makeStr, int makeLen);
	/**
	* Method:   getMake
	* Class:	Car
	* Desc.:	Get the car make. Returns pointer to the string.
	* @param
	* @return   char*
	*/
	const char* getMake() const;

	/**
	* Method:   setModel
	* Class:	Car
	* Desc.:	Set the car model. Return true if succeded, else false.
	* @param    char* modelStr, int mmodelLenakeLen
	* @return   bool
	*/
	bool setModel(char* makeStr, int makeLen);
	/**
	* Method:   getModel
	* Class:	Car
	* Desc.:	Get the car model. Returns pointer to the string.
	* @param
	* @return   char*
	*/
	const char* getModel() const;

	/**
	* Method:   setColor
	* Class:	Car
	* Desc.:	Set the car color. Return true if succeded, else false.
	* @param    char* colorStr, int colorLen
	* @return   bool
	*/
	bool setColor(char* makeStr, int makeLen);
	/**
	* Method:   getColor
	* Class:	Car
	* Desc.:	Get the car color. Returns pointer to the string.
	* @param
	* @return   char*
	*/
	const char* getColor() const;

	/**
	* Method:   setYear
	* Class:	Car
	* Desc.:	Set the car year make. Return true if succeded, else false.
	* @param    unsigned int year
	* @return   bool
	*/
	bool setYear(unsigned int year);
	/**
	* Method:   getYear
	* Class:	Car
	* Desc.:	Get the car's make year. Returns the year as unsigned int
	* @param
	* @return   unsigned int
	*/
	unsigned int getYear() const;

	/**
	* Method:   setEngineVol
	* Class:	Car
	* Desc.:	Set the car engine volume (in cc). Return true if succeded, else false.
	* @param    unsigned int vol
	* @return   bool
	*/
	void setEngineVol(unsigned int vol);
	/**
	* Method:   getEngineVol
	* Class:	Car
	* Desc.:	Get the car's engine volume (in cc). Returns the volume as unsigned int
	* @param
	* @return   unsigned int
	*/
	unsigned int getEngineVol() const;

	Car& biggerEng(Car& car);
	Car& newer(Car& car);

	friend ostream& operator <<(ostream& os, const Car& car);
};
