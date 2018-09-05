#ifndef CYLINDER_H
#define CYLINDER_H

#define _USE_MATH_DEFINES

#pragma once
#include <GL/glut.h>
#include "Shape.hpp"
#include <math.h>


class Cylinder : public Shape
{
private:
	double Top;
	double Base;
	double Depth;
	double Slices;
	double Stacks;
	double Loops;

public:
	Cylinder();
	Cylinder(double x, double y, double z, double top, double base, double depth,
		double slice, double stack, double loop, float r, float g, float b);

	double GetTop();
	double GetBase();
	double GetDepth();
	double GetSlices();
	double GetStacks();
	double GetLoops();

	void SetTop(double top);
	void SetBase(double base);
	void SetDepth(double depth);
	void SetSlices(double slice);
	void SetStacks(double stack);
	void SetLoops(double loop);

	void draw();
};
#endif