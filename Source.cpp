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

	Car(string Brand = "", int Max_Speed = 0, int year_model = 0, string plate = "", string type = "")  //default argument constructor
	{
		Car_Brand = Brand;
		Car_Type = type;
		Car_Plate = plate;
		Speed = Max_Speed;
		Year_Model = year_model;
	}
	void set_brand(string brand)
	{
		Car_Brand = brand;
	}
	void set_type(string type)  //validation of type
	{
		while (!(type == "bus" || type == "private" || type == "motorcycle" || type == "truck"))
		{
			cout << "\n		* INVALID INPUT* [Type should be (bus, private, motorcycle, or truck)]\n";
			cin >> type;
		} //validate

		Car_Type = type;

	}
	void set_speed(int speed)
	{
		Speed = speed;
	}
	void set_model(int model)
	{
		Year_Model = model;
	}
	void set_plate(string PLATE)
	{
		while (PLATE.length() != 6)
		{
			cout << "\n	 *INVALID INPUT* Plate's length is 6 \n";
			cin >> PLATE;
		}
		Car_Plate = PLATE;
	}
	int get_speed()
	{
		return Speed;
	}
	int get_model()
	{
		return Year_Model;
	}
	string get_type()
	{
		return Car_Type;
	}
	string get_plate()
	{
		return Car_Plate;
	}
	string get_brand()
	{
		return Car_Brand;
	}
};

class Road {
private:
	char Road_Type; //should only be A,B,C;
	int Speed_limit;
	int cars_number;
public:

	Road(char road_type = ' ', int speed_limit = 0)  //default argument constructor
	{
		while (!(road_type == 'A' || road_type == 'B' || road_type == 'C'))
		{
			cout << "\n	*INVALID ROAD TYPE* \n";
			cin >> road_type;
		}
		Road_Type = road_type;
		Speed_limit = speed_limit;
		cars_number = 0;
	}
	bool radar(int car_speed)
	{
		if (car_speed > Speed_limit)
			return true;
		else
			return false;

	}
	void allow(string car_type)
	{
		if (Road_Type == 'B')
		{
			cout << "This " << car_type << " is allowed on road B ";
			cars_number++;
		}
		else if ((car_type == "private" || car_type == "motorcycle") && Road_Type == 'A')
		{
			cout << "+ road A";
			cars_number++;
		}
		else if (Road_Type == 'C' && car_type == "truck")
		{
			cout << "+ road C";
			cars_number++;
		}
	}
	int age(int year_model)
	{
		return 2022 - year_model;
	}

	float get_cars_num()
	{
		return cars_number;
	}


};

void genereator(Car* cars)
{

	srand(time(NULL));
	string types[] = { "bus", "private", "truck", "motorcycle" };
	string brands[] = { "BMW", "Huyndai", "Hunda", "Chevroleit", "Toyota" };
	for (int i = 0; i < 20; i++)
	{
		cars[i].set_speed((rand() % 10) * 10 + 50);

		cars[i].set_type(types[rand() % 4]);

		cars[i].set_model(rand() % 72 + 1950);

		cars[i].set_brand(brands[rand() % 5]);

		string x = "";		// randomizing a plate
		for (int i = 0; i < 6; i++)
		{
			if (i < 3)
				x += char(rand() % 26 + 65);
			else
				x += char(rand() % 10 + 48);
		}
		cars[i].set_plate(x);

	}
}


void main()
{
	Road A('A', 100);
	Road B('B', 100);			//Roads
	Road C('C', 110);

	Car cars[30];							// creating 30 cars objects

	queue <Car> q;						// creating a queue

	genereator(cars);				// Ws3 ll creativity --> (generating all data randomly)

	for (int i = 0; i < 6; i++)
	{
		q.push(cars[i]);
	}

	for (int i = 0; i < 6; i++)
	{
		cout << "Veichle " << i + 1 << ":-     \n\n";
		cout << "AGE:	" << B.age((q.front()).get_model()) << " years" << endl;			 //	AGE
		cout << endl;
		cout << "ALLOW:	";
		B.allow((q.front()).get_type());
		A.allow((q.front()).get_type());												//  ALLOW
		C.allow((q.front()).get_type());

		cout << endl;
																					//  RADAR
		cout << "\nRADAR:	";
		cout << "Brand: " << q.front().get_brand() << "	Type: " << q.front().get_type() << "	Year Model: " << q.front().get_model()
			<< "	Plate: " << q.front().get_plate() << "	Speed: " << q.front().get_speed();
		if (B.radar(q.front().get_speed()))
		{
			cout << endl;
			cout << "\n $$$$ This Veichle is gonna be fined for exceeding the maximum speed (100) $$$$";
		}


		cout << endl;
		for (int j = 0; j < 90; j++)
			cout << "-"; cout << endl;


		q.pop();
	}
	cout << "\n\n\n";

						//Efficiency Part

	cout << "Efficiency:- \n\n";
	cout << " Road A = " << int(A.get_cars_num() / B.get_cars_num() * 100) << "%\n";
	cout << " Road B = 100%\n";
	cout << " Road C = " << int(C.get_cars_num() / B.get_cars_num() * 100) << "%\n";



}