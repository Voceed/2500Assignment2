#include "TrapezoidalPrism.hpp"
#include <math.h>

TrapezoidalPrism::TrapezoidalPrism():Shape() {

}
TrapezoidalPrism::TrapezoidalPrism(double x, double y, double z, double H, double TW, double BW, double D, double a, 
	float r, float g, float b):Shape(x, y, z) {
	Height = H;
	TopWidth = TW;
	BottomWidth = BW;
	Depth = D;
	offset = a;
	setColor(r, g, b);
}

double TrapezoidalPrism::GetHeight() {
	return Height;
}

double TrapezoidalPrism::GetTopWidth() {
	return TopWidth;
}

double TrapezoidalPrism::GetBottomWidth() {
	return BottomWidth;
}

double TrapezoidalPrism::GetDepth() {
	return Depth;
}

double TrapezoidalPrism::GetOffset() {
	return offset;
}

void TrapezoidalPrism::SetHeight(double Hei) {
	Height = Hei;
}
void TrapezoidalPrism::SetTopWidth(double Top) {
	TopWidth = Top;
}
void TrapezoidalPrism::SetBottomWidth(double Bottom) {
	BottomWidth = Bottom;
}
void TrapezoidalPrism::SetDepth(double Dep) {
	Depth = Dep;
}
void TrapezoidalPrism::SetOffset(double Off) {
	offset = Off;
}

void TrapezoidalPrism::draw() {
	double h = Height;
	double t = TopWidth + offset;
	double b = BottomWidth;
	double d = Depth;
	double a = offset;
	glPushMatrix();
	glTranslated(-b / 2, 0, d / 2);
	glColor3f(red, green, blue);

	glBegin(GL_QUADS);
	glVertex3d(x, y, z);
	glVertex3d(x + b, y, z);
	glVertex3d(x + b, y, z - d);
	glVertex3d(x, y, z - d);//bottom face
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x, y, z);
	glVertex3d(x + b, y, z);
	glVertex3d(x + t, y + h, z);
	glVertex3d(x + a, y + h, z);//front face
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x + b, y, z);
	glVertex3d(x + b, y, z - d);
	glVertex3d(x + t, y + h, z - d);
	glVertex3d(x + t, y + h, z);//Right face
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x, y, z);
	glVertex3d(x, y, z - d);
	glVertex3d(x + a, y + h, z - d);
	glVertex3d(x + a, y + h, z);//Left face
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x + a, y + h, z);
	glVertex3d(x + t, y + h, z);
	glVertex3d(x + t, y + h, z - d);
	glVertex3d(x + a, y + h, z - d);//Top face
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x, y, z - d);
	glVertex3d(x + b, y, z - d);
	glVertex3d(x + t, y + h, z - d);
	glVertex3d(x + a, y, z - d);//back face
	glEnd();
	glPopMatrix();
}
