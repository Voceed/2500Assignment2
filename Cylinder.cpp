#include "Cylinder.hpp"
#include "Shape.hpp"
#include <math.h>


Cylinder::Cylinder() :Shape()
{
}

Cylinder::Cylinder(double x, double y, double z, double top, double base, double depth,
	double slice, double stack, double loop, float r, float g, float b): Shape(x,y,z)
{
	setColor(r, g, b);
	Top = top;
	Base = base;
	Depth = depth;
	Slices = slice;
	Stacks = stack;
	Loops = loop;
}

double Cylinder::GetTop()
{
	return Top;
}

double Cylinder::GetBase()
{
	return Base;
}

double Cylinder::GetDepth()
{
	return Depth;
}

double Cylinder::GetSlices()
{
	return Slices;
}

double Cylinder::GetStacks()
{
	return Stacks;
}

double Cylinder::GetLoops()
{
	return Loops;
}

void Cylinder::SetTop(double top)
{
	Top = top;
}

void Cylinder::SetBase(double base)
{
	Base = base;
}

void Cylinder::SetDepth(double depth)
{
	Depth = depth;
}

void Cylinder::SetSlices(double slice)
{
	Slices = slice;
}

void Cylinder::SetStacks(double stack)
{
	Stacks = stack;
}

void Cylinder::SetLoops(double loop)
{
	Loops = loop;
}

void Cylinder::draw()
{
	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(-90, 0, 1, 0);
	glTranslated(x,y,z);

	double top = Top, base = Base, d = Depth;
	double slice = Slices, stack = Stacks, loop = Loops;
	glTranslated(0.0, top, -d / 2);
	glColor3f(red, green, blue);
	GLUquadricObj *Cylinder = gluNewQuadric();
	gluCylinder(Cylinder, base, top, d, slice, stack);
	gluDisk(Cylinder, 0, top, slice, loop);
	glTranslated(0.0, 0, d);
	gluDisk(Cylinder, 0, top, slice, loop);
	glPopMatrix();
}