#ifndef MYCAR_H
#define MYCAR_H

#include "Shape.hpp"
#include "Vehicle.hpp"
#include "TrapezoidalPrism.hpp"
#include "Triangular.hpp"
#include "RectangularPrism.hpp"
#include <Windows.h>
#include <GL/glut.h>

class MyCar : public Vehicle 
{
public:
	MyCar();
	void draw();
	void getAngleRecord();
private:
	double angleRec;
};
#endif