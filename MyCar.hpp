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
	void stackAngleRecord();
	double getAngleRec() {
		return angleRec;
	}
	void setFourWheelsRad(double _BR, double _BL, double _FR, double _FL) {
		BR = _BR; BL = _BL; FR = _FR; FL = _FL;
	}

	double getBR() { return BR; }
	double getBL() { return BL; }
	double getFR() { return FL; }
	double getFL() { return FL; }
private:
	double angleRec;
	double BR, BL, FR, FL;
};
#endif