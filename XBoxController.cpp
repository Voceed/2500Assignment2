#include <iostream>
#include <cmath>
#include "XBoxController.h"

using namespace GamePad;

//GIVEN FUNCTIONS METHODS//
XBoxController::XBoxController(XInputWrapper* xinput, DWORD id) {
	this->xinput = xinput;
	this->index = id;
	this->DeadZone = 0;
}

DWORD XBoxController::GetControllerId() {
	return this->index;
}

bool XBoxController::IsConnected() {
	XINPUT_STATE State;
	DWORD result = this->xinput->XInputGetState(this->index, &State);
	if (result == ERROR_DEVICE_NOT_CONNECTED) {
		return false;
	}
	return true;
}

bool XBoxController::PressedA() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	WORD button = State.Gamepad.wButtons;
	if (button >> 12 == 0x0001 || button >> 12 == 0x0003 || button >> 12 == 0x0007 || button >> 12 == 0x000F ||
		button >> 12 == 0x0005 || button >> 12 == 0x0009 || button >> 12 == 0x000B || button >> 12 == 0x000D) {
		return true;
	}
	return false;
}

bool XBoxController::PressedB() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	WORD button = State.Gamepad.wButtons;
	if (button >> 12 == 0x0002 || button >> 12 == 0x0003 || button >> 12 == 0x0006 || button >> 12 == 0x000A ||
		button >> 12 == 0x0007 || button >> 12 == 0x000B || button >> 12 == 0x000E || button >> 12 == 0x000F) {
		return true;
	}
	return false;
}

bool XBoxController::PressedX() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	WORD button = State.Gamepad.wButtons;
	if (button >> 12 == 0x0004 || button >> 12 == 0x0005 || button >> 12 == 0x0006 || button >> 12 == 0x000C ||
		button >> 12 == 0x0007 || button >> 12 == 0x000E || button >> 12 == 0x000D || button >> 12 == 0x000F) {
		return true;
	}
	return false;
}

bool XBoxController::PressedY() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	WORD button = State.Gamepad.wButtons;
	if (button >> 12 == 0x0008 || button >> 12 == 0x0009 || button >> 12 == 0x000A || button >> 12 == 0x000C ||
		button >> 12 == 0x000B || button >> 12 == 0x000E || button >> 12 == 0x000D || button >> 12 == 0x000F) {
		return true;
	}
	return false;
}

bool XBoxController::PressedLeftShoulder() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	WORD button = State.Gamepad.wButtons;
	button = button << 4;
	button = button >> 12;
	if (button == 0x0001 || button == 0x0003) {
		return true;
	}
	return false;
}

bool XBoxController::PressedRightShoulder() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	WORD button = State.Gamepad.wButtons;
	button = button << 4;
	button = button >> 12;
	if (button == 0x0002 || button == 0x0003) {
		return true;
	}
	return false;
}

bool XBoxController::PressedLeftDpad() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	WORD button = State.Gamepad.wButtons;
	button = button << 12;
	if (button == 0x4000 || button == 0x5000 || button == 0x6000 || button == 0xC000 || 
		button == 0x7000 || button == 0xE000 || button == 0xD000 || button == 0xF000) {
		return true;
	}
	return false;
}

bool XBoxController::PressedRightDpad() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	WORD button = State.Gamepad.wButtons;
	button = button << 12;
	if (button == 0x8000 || button == 0x9000 || button == 0xA000 || button == 0xC000 ||
		button == 0xB000 || button == 0xE000 || button == 0xD000 || button == 0xF000) {
		return true;
	}
	return false;
}

bool XBoxController::PressedUpDpad() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	WORD button = State.Gamepad.wButtons;
	button = button << 12;
	if (button == 0x1000 || button == 0x3000 || button == 0x5000 || button == 0x9000 ||
		button == 0x7000 || button == 0xD000 || button == 0xB000 || button == 0xF000) {
		return true;
	}
	return false;
}

bool XBoxController::PressedDownDpad() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	WORD button = State.Gamepad.wButtons;
	button = button << 12;
	if (button == 0x2000 || button == 0x3000 || button == 0x6000 || button == 0xA000 ||
		button == 0x7000 || button == 0xE000 || button == 0xB000 || button == 0xF000) {
		return true;
	}
	return false;
}

bool XBoxController::PressedStart() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	WORD button = State.Gamepad.wButtons;
	button = button << 8;
	button = button >> 12;
	if (button == 0x0001 || button == 0x0003 || button == 0x0007 || button == 0x000F ||
		button == 0x0005 || button == 0x0009 || button == 0x000B || button == 0x000D) {
		return true;
	}
	return false;
}

bool XBoxController::PressedBack() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	WORD button = State.Gamepad.wButtons;
	button = button << 8;
	button = button >> 12;
	if (button == 0x0002 || button == 0x0003 || button == 0x0006 || button == 0x000A ||
		button == 0x0007 || button == 0x000E || button == 0x000B || button == 0x000F) {
		return true;
	}
	return false;
}

bool XBoxController::PressedLeftThumb() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	WORD button = State.Gamepad.wButtons;
	button = button << 8;
	button = button >> 12;
	if (button == 0x0004 || button == 0x0005 || button == 0x0006 || button == 0x000C ||
		button == 0x0007 || button == 0x000E || button == 0x000D || button == 0x000F) {
		return true;
	}
	return false;
}

bool XBoxController::PressedRightThumb() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	WORD button = State.Gamepad.wButtons;
	button = button << 8;
	button = button >> 12;
	if (button == 0x0008 || button == 0x0009 || button == 0x000A || button == 0x000C ||
		button == 0x000B || button == 0x000E || button == 0x000D || button == 0x000F) {
		return true;
	}
	return false;
}

BYTE XBoxController::LeftTriggerLocation() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	BYTE trigVal = State.Gamepad.bLeftTrigger;
	return trigVal;
}

BYTE XBoxController::RightTriggerLocation() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	BYTE trigVal = State.Gamepad.bRightTrigger;
	return trigVal;
}

Coordinate XBoxController::LeftThumbLocation() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	SHORT posX = State.Gamepad.sThumbLX;
	SHORT posY = State.Gamepad.sThumbLY;
	double DEADZONE = this->DeadZone;

	double x = posX;
	if (x == 0) {
		x = 0;
	}
	else if (x > 0) {
		if (x <= DEADZONE) {
			x = 0;
		}
		else if (x > DEADZONE) {
			x = (x - DEADZONE)*(32767 / (32767 - DEADZONE));
		}
	}
	else if (x < 0) {
		if (x >= -DEADZONE) {
			x = 0;
		}
		else if (x < -DEADZONE) {
			x = (x + DEADZONE)*(-32768 / (-32768 + DEADZONE));
		}
	}
	posX = x;

	double y = posY;
	if (y == 0) {
		y = 0;
	}
	else if (y > 0) {
		if (y <= DEADZONE) {
			y = 0;
		}
		else if (y > DEADZONE) {
			y = (y - DEADZONE)*(32767 / (32767 - DEADZONE));
		}
	}
	else if (y < 0) {
		if (y >= -DEADZONE) {
			y = 0;
		}
		else if (y < -DEADZONE) {
			y = (y + DEADZONE)*(-32768 / (-32768 + DEADZONE));
		}
	}
	posY = y;
	
	//Implement this??//
	if (DEADZONE == 32767) {
		posX = 0;
		posY = 0;
	}

	Coordinate pos = Coordinate::Coordinate(posX, posY);

	return pos;
}

Coordinate XBoxController::RightThumbLocation() {
	XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	SHORT posX = State.Gamepad.sThumbRX;
	SHORT posY = State.Gamepad.sThumbRY;
	double DEADZONE = this->DeadZone;

	double x = posX;
	if (x == 0) {
		x = 0;
	}
	else if (x > 0) {
		if (x <= DEADZONE) {
			x = 0;
		}
		else if (x > DEADZONE) {
			x = (x - DEADZONE)*(32767 / (32767 - DEADZONE));
		}
	}
	else if (x < 0) {
		if (x >= -DEADZONE) {
			x = 0;
		}
		else if (x < -DEADZONE) {
			x = (x + DEADZONE)*(-32768 / (-32768 + DEADZONE));
		}
	}
	posX = x;

	double y = posY;
	if (y == 0) {
		y = 0;
	}
	else if (y > 0) {
		if (y <= DEADZONE) {
			y = 0;
		}
		else if (y > DEADZONE) {
			y = (y - DEADZONE)*(32767 / (32767 - DEADZONE));
		}
	}
	else if (y < 0) {
		if (y >= -DEADZONE) {
			y = 0;
		}
		else if (y < -DEADZONE) {
			y = (y + DEADZONE)*(-32768 / (-32768 + DEADZONE));
		}
	}
	posY = y;

	//Implement this??//
	if (DEADZONE == 32767) {
	posX = 0;
	posY = 0;
	}

	Coordinate pos = Coordinate::Coordinate(posX, posY);

	return pos;
}

void XBoxController::Vibrate(WORD left, WORD right) {
	XINPUT_VIBRATION Vibration;
	Vibration.wLeftMotorSpeed = left;
	Vibration.wRightMotorSpeed = right;
	this->xinput->XInputSetState(this->index, &Vibration);
}

void XBoxController::SetDeadzone(unsigned int radius) {
	unsigned int tempDeadZone = radius;
	if (tempDeadZone >= 32767) {
		this->DeadZone = 32767;
	}
	else {
		this->DeadZone = tempDeadZone;
	}
}

//OWN FUNCTIONS METHODS//
bool XBoxController::IsNegative(SHORT num) {
	if (num >= -32768 && num <= -1) {
		return true;
	}
	return false;
}

bool XBoxController::IsNotNegative(SHORT num) {
	if (num >= 0 && num <= 32767) {
		return true;
	}
	return false;
}

/*
XINPUT_STATE State;
this->xinput->XInputGetState(this->index, &State);
SHORT posX = State.Gamepad.sThumbLX;
SHORT posY = State.Gamepad.sThumbLY;
SHORT DEADZONE = this->DeadZone;
double Kp = (double)32767 / (32767 - DEADZONE);
double Kn = (double)32768 / (32768 - DEADZONE - 1);
if (DEADZONE == 32767) { Kp = 0; Kn = 0; }
Coordinate pos = Coordinate::Coordinate(posX, posY);
if (IsNotNegative(posX)) {
if (posX <= DEADZONE) {
posX = 0;
}
else if (posX > DEADZONE) {
posX = (posX - DEADZONE)*Kp;
}
}
else if (IsNegative(posX)) {
if (posX >= -DEADZONE - 1) {
posX = 0;
}
else if (posX < -DEADZONE - 1) {
SHORT tempPosX = posX;
posX = (posX + DEADZONE + 1)*Kn;
if (tempPosX == -32768) {
posX = -32768;
}
}
}
if (IsNotNegative(posY)) {
if (posY <= DEADZONE) {
posY = 0;
}
else if (posY > DEADZONE) {
posY = (posY - DEADZONE)*Kp;
}
}
else if (IsNegative(posY)) {
if (posY >= -DEADZONE - 1) {
posY = 0;
}
else if (posY < -DEADZONE - 1) {
SHORT tempPosY = posY;
posY = (posY + DEADZONE + 1)*Kn;
if (tempPosY == -32768) {
posY = -32768;
}
}
}

pos = Coordinate::Coordinate(posX, posY);

return pos;
*/

/*XINPUT_STATE State;
	this->xinput->XInputGetState(this->index, &State);
	SHORT posX = State.Gamepad.sThumbRX;
	SHORT posY = State.Gamepad.sThumbRY;
	SHORT DEADZONE = this->DeadZone;
	double Kp = (double)32767 / (32767 - DEADZONE);
	double Kn = (double)32768 / (32768 - DEADZONE - 1);
	if (DEADZONE == 32767) { Kp = 0; Kn = 0; }
	Coordinate pos = Coordinate::Coordinate(posX, posY);
	if (IsNotNegative(posX)) {
		if (posX <= DEADZONE) {
			posX = 0;
		}
		else if (posX > DEADZONE) {
			posX = (posX - DEADZONE)*Kp;
		}
	}
	else if (IsNegative(posX)) {
		if (posX >= -DEADZONE - 1) {
			posX = 0;
		}
		else if (posX < -DEADZONE - 1) {
			SHORT tempPosX = posX;
			posX = (posX + DEADZONE + 1)*Kn;
			if (tempPosX == -32768) {
				posX = -32768;
			}
		}
	}
	if (IsNotNegative(posY)) {
		if (posY <= DEADZONE) {
			posY = 0;
		}
		else if (posY > DEADZONE) {
			posY = (posY - DEADZONE)*Kp;
		}
	}
	else if (IsNegative(posY)) {
		if (posY >= -DEADZONE - 1) {
			posY = 0;
		}
		else if (posY < -DEADZONE - 1) {
			SHORT tempPosY = posY;
			posY = (posY + DEADZONE + 1)*Kn;
			if (tempPosY == -32768) {
				posY = -32768;
			}
		}
	}
	pos = Coordinate::Coordinate(posX, posY);

	return pos;*/