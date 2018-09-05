#ifndef TRAPEZOIDAL_H
#define TRAPEZOIDAL_H

#pragma once
#include <GL/glut.h>
#include "Shape.hpp"

class TrapezoidalPrism : public Shape
{
private:
	double Height;
	double TopWidth;
	double BottomWidth;
	double Depth;
	double offset;
public:
	TrapezoidalPrism();
	TrapezoidalPrism(double x, double y, double z, double Height, double TopWidth, double BottomWidth, 
		double Depth,double offset, float r, float g, float b);
	
	double GetHeight();
	double GetTopWidth();
	double GetBottomWidth();
	double GetDepth();
	double GetOffset();

	void SetHeight(double hei);
	void SetTopWidth(double Top);
	void SetBottomWidth(double Bottom);
	void SetDepth(double Dep);
	void SetOffset(double off);

	void draw();
};

#endif