#ifndef RECTANGULAR_H
#define RECTANGULAR_H

#pragma once
#include <GL/glut.h>
#include "Shape.hpp"

class RectangularPrism : public Shape
{
private:
	double x_length;
	double y_length;
	double z_length;

public:
	RectangularPrism();
	RectangularPrism(double x, double y, double z, double xlin, double ylin, double zlin, float r, float g, float b);

	double GetXlin();
	double GetYlin();
	double GetZlin();

	void SetXlin(double x);
	void SetYlin(double y);
	void SetZlin(double z);

	void draw();
};

#endif