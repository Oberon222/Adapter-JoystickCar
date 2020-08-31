#include <iostream>
#include<string>
using namespace std;

class ClassikCar
{
public:
	virtual void ClassicControlMethod()
	{
		cout << "Steering wheel and pedals" << endl;
	}
};

class JoystickCar
{
public:
	virtual void JoysticControlMethod()
	{
		cout << "Joystick and buttons" << endl;
	}

	virtual void JoystickLeft()
	{
		cout << "Go left" << endl;
	}

	virtual void JoystickRight()
	{
		cout << "Go right" << endl;
	}

	virtual void JoystickUp()
	{
		cout << "Acceleration" << endl;
	}

	virtual void JoystickDown()
	{
		cout << "Braking" << endl;
	}

	virtual void RightButton()
	{
		cout << "Start the engine" << endl;
	}

	virtual void LeftButton()
	{
		cout << "Stop" << endl;
	}

};

class Driver
{
	
public:

	void Drive(JoystickCar* joystic)
	{
		joystic->JoysticControlMethod();
	}

};

class Adapter : public JoystickCar
{
	ClassikCar* cCar;
public:
	Adapter(ClassikCar* classicCar)
	{
		cCar= classicCar;
	}

	virtual void JoysticControlMethod() override
	{
		cCar->ClassicControlMethod();
	}
	
};

int main()
{
	ClassikCar classicCar;

	Driver driver;

	Adapter ad(&classicCar);

	driver.Drive(new Adapter(&classicCar));



	system("pause");
	return 0;
}