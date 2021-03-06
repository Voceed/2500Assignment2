#include "OtherCar.hpp"
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "Cylinder.hpp"

using namespace std;

OtherCar::OtherCar(VehicleModel _vm) {
	vm = _vm;
}

void OtherCar::draw() {
	vector<ShapeInit>::iterator shapeIt;

	//---Draw different shape depends on the shape type---//
	for (shapeIt = vm.shapes.begin(); shapeIt != vm.shapes.end(); shapeIt++) {
		switch (shapeIt->type) {

		case (RECTANGULAR_PRISM):
		{
			glPushMatrix();
			positionInGL();
			glRotated(180, 0, 1, 0);
			glTranslated(-shapeIt->xyz[0], shapeIt->xyz[1], shapeIt->xyz[2]);
			glRotated(shapeIt->rotation, 0, 1, 0);
			RectangularPrism rect(0,0,0, shapeIt->params.rect.xlen, shapeIt->params.rect.ylen, shapeIt->params.rect.zlen,
				shapeIt->rgb[0], shapeIt->rgb[1], shapeIt->rgb[2]);

			rect.draw();
			glPopMatrix();
			break;
		}
		case (TRIANGULAR_PRISM):
		{
			glPushMatrix();
			positionInGL();
			glRotated(180, 0, 1, 0);
			glTranslated(-shapeIt->xyz[0], shapeIt->xyz[1], shapeIt->xyz[2]);
			glRotated(shapeIt->rotation, 0, 1, 0);
			TriangularPrism trig(0,0,0, shapeIt->params.tri.alen, shapeIt->params.tri.blen, shapeIt->params.tri.angle, shapeIt->params.tri.depth,
				shapeIt->rgb[0], shapeIt->rgb[1], shapeIt->rgb[2]);
			trig.draw();
			glPopMatrix();
			break;
		}
		case (TRAPEZOIDAL_PRISM):
		{
			glPushMatrix();
			positionInGL();
			glRotated(180, 0, 1, 0);
			glTranslated(-shapeIt->xyz[0], shapeIt->xyz[1], shapeIt->xyz[2]);
			glRotated(shapeIt->rotation, 0, 1, 0);
			TrapezoidalPrism trap(0,0,0, shapeIt->params.trap.height, shapeIt->params.trap.blen, shapeIt->params.trap.alen, shapeIt->params.trap.depth, shapeIt->params.trap.aoff,
				shapeIt->rgb[0], shapeIt->rgb[1], shapeIt->rgb[2]);
			trap.draw();
			glPopMatrix();
			break;
		}
		case (CYLINDER):
		{
			glPushMatrix();
			positionInGL();
			glRotated(180, 0, 1, 0);
			glTranslated(-shapeIt->xyz[0], shapeIt->xyz[1], shapeIt->xyz[2]);
			glRotated(shapeIt->rotation, 0, 1, 0);
			if (shapeIt->params.cyl.isSteering == true) {
				glRotated(-steering, 0, 1, 0);
			}
			Cylinder cy(0,0,0, shapeIt->params.cyl.radius, shapeIt->params.cyl.radius, shapeIt->params.cyl.depth, 50, 1, 1, 
				shapeIt->rgb[0], shapeIt->rgb[1], shapeIt->rgb[2]);
			cy.draw();
			glPopMatrix();
			break;
		}

		}
	}
}