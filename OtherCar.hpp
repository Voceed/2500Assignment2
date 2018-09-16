#pragma once
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "TrapezoidalPrism.hpp"
#include "Triangular.hpp"
#include "RectangularPrism.hpp"
#include "Messages.hpp"
#include <Windows.h>
#include <GL/glut.h>

class OtherCar : public Vehicle
{
public:
	//===================================//
	//this constructor will take in		 //
	//a vehicle model and the the draw() //
	//function can use the data from	 //
	//the take in model					 //
	//===================================//

	OtherCar(VehicleModel _vm);
	void draw();
private:
	VehicleModel vm;
};