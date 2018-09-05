#ifndef TRIANGULAR_H
#define TRIANGULAR_H

#define _USE_MATH_DEFINES

#pragma once
#include <GL/glut.h>
#include "Shape.hpp"
#include <math.h>


class TriangularPrism : public Shape
{
private:
	double Side1;
	double Side2;
	double Theta;	//in degree
	double Depth;
	
public:
	TriangularPrism();
	TriangularPrism(double x, double y, double z, double side1, double side2, double theta, double depth,
					float r, float g, float b);

	double Getside1();
	double Getside2();
	double Gettheta();
	double Getdepth();

	void Setside1(double side1);
	void Setside2(double side2);
	void Settheta(double theta);
	void Setdepth(double depth);

	void draw();
};
#endif
