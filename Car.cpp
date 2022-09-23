#include "Car.h"
	Car::Car(string Brand = "", int Max_Speed = 0, int year_model = 0, string plate = "", string type = "")  //default argument constructor
	{
		Car_Brand = Brand;
		Car_Type = type;
		Car_Plate = plate;
		Speed = Max_Speed;
		Year_Model = year_model;
	}
	void Car::set_brand(string brand)
	{
		Car_Brand = brand;
	}
	void Car::set_type(string type)  //validation of type
	{
		while (!(type == "bus" || type == "private" || type == "motorcycle" || type == "truck"))
		{
			cout << "\n		* INVALID INPUT* [Type should be (bus, private, motorcycle, or truck)]\n";
			cin >> type;
		} //validate

		Car_Type = type;

	}
	void Car::set_speed(int speed)
	{
		Speed = speed;
	}
	void Car::set_model(int model)
	{
		Year_Model = model;
	}
	void Car::set_plate(string PLATE)
	{
		while (PLATE.length() != 6)
		{
			cout << "\n	 *INVALID INPUT* Plate's length is 6 \n";
			cin >> PLATE;
		}
		Car_Plate = PLATE;
	}
	int Car::get_speed()
	{
		return Speed;
	}
	int Car::get_model()
	{
		return Year_Model;
	}
	string Car::get_type()
	{
		return Car_Type;
	}
	string Car::get_plate()
	{
		return Car_Plate;
	}
	string Car::get_brand()
	{
		return Car_Brand;
	}