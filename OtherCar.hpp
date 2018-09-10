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
	OtherCar(VehicleModel _vm);
	void draw();
private:
	VehicleModel vm;
};