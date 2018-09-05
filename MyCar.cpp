#include "MyCar.hpp"
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "Cylinder.hpp"

MyCar::MyCar() {

}

void MyCar::draw() {
	glPushMatrix();
	positionInGL();
	glTranslated(0.0, 0.1, 0.0);
	RectangularPrism Body1(0, 0, 0, 0.8, 0.2, 0.4, 1.0, 1.0, 0.0);
	Body1.draw();
	glPopMatrix();

	glPushMatrix();
	positionInGL();
	glTranslated(0.0, 0.3, 0.0);
	RectangularPrism Body2(0, 0, 0, 0.8, 0.2, 0.4, 1.0, 0.0, 0.0);
	Body2.draw();
	glPopMatrix();

	glPushMatrix();
	positionInGL();
	glTranslated(-0.22, 0.53, 0.0);
	TriangularPrism trigTop(0, 0, 0, 0.4, 0.15, 25, 0.4, 0.0, 0.0, 0.7);
	trigTop.draw();
	glPopMatrix();

	glPushMatrix();
	positionInGL();
	glTranslated(-0.4, 0.0, 0.2);
	Cylinder Wheel1(0, 0, 0, 0.1, 0.1, 0.2, 50, 1, 1, 0, 1, 0);
	Wheel1.draw();
	glPopMatrix();

	glPushMatrix();
	positionInGL();
	glTranslated(0.4, 0.0, 0.2);
	Cylinder Wheel2(0, 0, 0, 0.1, 0.1, 0.1, 50, 1, 1, 0, 1, 0);
	Wheel2.draw();
	glPopMatrix();

	glPushMatrix();
	positionInGL();
	glTranslated(-0.4, 0.0, -0.2);
	Cylinder Wheel3(0, 0, 0, 0.1, 0.1, 0.1, 50, 1, 1, 1, 0, 0);
	Wheel3.draw();
	glPopMatrix();

	glPushMatrix();
	positionInGL();
	glTranslated(0.4, 0.0, -0.2);
	Cylinder Wheel4(0, 0, 0, 0.1, 0.1, 0.1, 50, 1, 1, 1, 0, 0);
	Wheel4.draw();
	glPopMatrix();

}
