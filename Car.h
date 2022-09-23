#pragma once
#include <iostream>
#include<queue>
#include<string>
#include<ctime>
#include<stdlib.h>
using namespace std;

class Car {
private:
	string Car_Brand, Car_Type, Car_Plate;
	int Speed, Year_Model;

public:

	Car(string Brand = "", int Max_Speed = 0, int year_model = 0, string plate = "", string type = "");  //default argument constructor

	void set_brand(string brand);
	void set_type(string type);  //validation of type

	void set_speed(int speed);
	void set_model(int model);
	void set_plate(string PLATE);
	int get_speed();
	int get_model();
	string get_type();
	string get_plate();
	string get_brand();
};

