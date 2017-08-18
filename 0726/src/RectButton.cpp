#include "RectButton.h"

RectButton::RectButton()
{

}

RectButton::~RectButton()
{
}

void RectButton::setup(ofRectangle _rect, ofColor _color, string _name)
{
	rect = _rect;
	color = _color;
	name = _name;
	bPressed = false;
}

void RectButton::draw()
{
	if (bPressed == false) {
		ofSetColor(color);
	}
	else {
		ofSetColor(30, 30, 30);
	}
	ofSetRectMode(OF_RECTMODE_CORNER);
	ofDrawRectangle(rect);
}

bool RectButton::inside(float x, float y)
{
	if (rect.inside(x, y)) {
		bPressed = true;
		return true;
	}
	else
	{
		bPressed = false;

		return false;
	}
}

string RectButton::getName()
{
	return name;
}

