#include "RectangularPrism.hpp"
#include "Shape.hpp"


RectangularPrism::RectangularPrism() :Shape()
{
}

RectangularPrism::RectangularPrism(double x, double y, double z, double xlin, double ylin, double zlin,
	float r, float g, float b) : Shape(x, y, z)
{
	setColor(r, g, b);
	x_length = xlin;
	y_length = ylin;
	z_length = zlin;
}

double RectangularPrism::GetXlin()
{
	return x_length;
}

double RectangularPrism::GetYlin()
{
	return y_length;
}

double RectangularPrism::GetZlin()
{
	return z_length;
}

void RectangularPrism::SetXlin(double x)
{
	x_length = x;
}

void RectangularPrism::SetYlin(double y)
{
	y_length = y;
}

void RectangularPrism::SetZlin(double z)
{
	z_length = z;
}


void RectangularPrism::draw()
{
	glPushMatrix();
	double l = x_length, w = y_length, h = z_length;
	glTranslated(-l / 2, 0, -h / 2);
	glColor3f(red, green, blue);

	glBegin(GL_QUADS);
	glVertex3d(x, y, z);
	glVertex3d(x + l, y, z);
	glVertex3d(x + l, y + w, z);
	glVertex3d(x, y + w, z);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x, y, z);
	glVertex3d(x + l, y, z);
	glVertex3d(x + l, y, z + h);
	glVertex3d(x, y, z + h);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x + l, y, z + h);
	glVertex3d(x, y, z + h);
	glVertex3d(x, y + w, z + h);
	glVertex3d(x + l, y + w, z + h);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x, y + w, z);
	glVertex3d(x + l, y + w, z);
	glVertex3d(x + l, y + w, z + h);
	glVertex3d(x, y + w, z + h);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x + l, y, z);
	glVertex3d(x + l, y, z + h);
	glVertex3d(x + l, y + w, z + h);
	glVertex3d(x + l, y + w, z);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x, y, z);
	glVertex3d(x, y + w, z);
	glVertex3d(x, y + w, z + h);
	glVertex3d(x, y, z + h);
	glEnd();
	glPopMatrix();
}
