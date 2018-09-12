#include "MyCar.hpp"
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "Cylinder.hpp"

MyCar::MyCar() {
	angleRec = 0;
}

void MyCar::draw() {

	stackAngleRecord();

	//=====================Bodies
	glPushMatrix();
	positionInGL();
	glTranslated(0.0, 0.4, 0.0);
	RectangularPrism Body1(0, 0, 0, 3.2, 0.8, 1.6, 1.0, 0.0, 0.0);
	Body1.draw();
	glPopMatrix();

	glPushMatrix();
	positionInGL();
	glTranslated(0.0, 1.2, 0.0);
	RectangularPrism Body2(0, 0, 0, 3.2, 0.8, 1.6, 1.0, 1.0, 1.0);
	Body2.draw();
	glPopMatrix();

	//======================Tops
	glPushMatrix();
	positionInGL();
	glTranslated(-0.8, 2.0, 0.0);
	TriangularPrism trigTop(0, 0, 0, 1.6, 1.6, 60, 1.6, 0.0, 0.0, 0.7);
	trigTop.draw();
	glPopMatrix();

	glPushMatrix();
	positionInGL();
	glTranslated(0.8, 2.0, 0.0);
	TrapezoidalPrism trapTop(0, 0, 0, 0.8, 0.8, 1.6, 1.6, 0.4, 1.0, 0.0, 0.0);
	trapTop.draw();
	glPopMatrix();

	//=======================Rods
	glPushMatrix();
	positionInGL();
	glTranslated(-0.8, 0.3, 0.0);
	Cylinder Rod1(0, 0, 0, 0.05, 0.05, 2.2, 50, 1, 1, 0, 1, 0);
	Rod1.draw();
	glPopMatrix();

	glPushMatrix();
	positionInGL();
	glTranslated(0.8, 0.3, 0.0);
	Cylinder Rod2(0, 0, 0, 0.05, 0.05, 2.2, 50, 1, 1, 0, 1, 0);
	Rod2.draw();
	glPopMatrix();

	//=======================Wheels
	setFourWheelsRad(1, 1, 0.35, 0.35);
	double Wheel1Rad = BR;
	double Wheel2Rad = BL;
	double Wheel3Rad = FR;
	double Wheel4Rad = FL;

	glPushMatrix();
	positionInGL();
	glTranslated(-0.8, 0.0, 1.15);
	Cylinder Wheel1(0, 0, 0, Wheel1Rad, Wheel1Rad, 0.4, 50, 1, 1, 0, 1, 1);
	Wheel1.draw();
	glTranslated(0, Wheel1Rad, 0.21);
	glRotated(angleRec*0.35/Wheel1Rad, 0, 0, 1);
	RectangularPrism Hub1(0, 0, 0, 2*Wheel1Rad, 0.05, 0.02, 1, 0, 0);
	Hub1.draw();
	glPopMatrix();

	glPushMatrix();
	positionInGL();
	glTranslated(-0.8, 0.0, -1.15);
	Cylinder Wheel2(0, 0, 0, Wheel2Rad, Wheel2Rad, 0.4, 50, 1, 1, 0, 1, 1);
	Wheel2.draw();
	glTranslated(0, Wheel2Rad, -0.21);
	glRotated(angleRec*0.35 / Wheel2Rad, 0, 0, 1);
	RectangularPrism Hub2(0, 0, 0, 2*Wheel2Rad, 0.05, 0.02, 1, 0, 0);
	Hub2.draw();
	glPopMatrix();

	//Front Right
	glPushMatrix();
	positionInGL();
	glTranslated(0.8, 0.0, 1.15);
	glRotated(-steering, 0, 1, 0);
	Cylinder Wheel3(0, 0, 0, Wheel3Rad, Wheel3Rad, 0.4, 50, 1, 1, 0, 1, 1);
	Wheel3.draw();
	glTranslated(0, Wheel3Rad, 0.21);
	glRotated(angleRec*0.35 / Wheel3Rad, 0, 0, 1);
	RectangularPrism Hub3(0, 0, 0, 2*Wheel3Rad, 0.05, 0.02, 1, 0, 0);
	Hub3.draw();
	glPopMatrix();

	//Front Left
	glPushMatrix();
	positionInGL();
	glTranslated(0.8, 0.0, -1.15);
	glRotated(-steering, 0, 1, 0);
	Cylinder Wheel4(0, 0, 0, Wheel4Rad, Wheel4Rad, 0.4, 50, 1, 1, 0, 1, 1);
	Wheel4.draw();
	glTranslated(0, Wheel4Rad, -0.21);
	glRotated(angleRec*0.35 / Wheel4Rad, 0, 0, 1);
	RectangularPrism Hub4(0, 0, 0, 2*Wheel4Rad, 0.05, 0.02, 1, 0, 0);
	Hub4.draw();
	glPopMatrix();

	//=======================BackWheel (In Yellow)
	glPushMatrix();
	positionInGL();
	glTranslated(-1.8, 0.8, 0.0);
	glRotated(90, 0, 1, 0);
	Cylinder backWheel(0, 0, 0, 0.4, 0.4, 0.4, 50, 1, 1, 1, 1, 0.0);
	backWheel.draw();
	glPopMatrix();

}

void MyCar::stackAngleRecord() {
	double omega = (speed / 0.35)*(2.25);
	angleRec = angleRec - omega;
}
