#include "PenSt.h"

PenSt::PenSt()
{

}

PenSt::~PenSt()
{
}

void PenSt::setup()
{
	color = {0.5f, 0.5f, 1.0f};
}

void PenSt::draw()
{
	ofSetColor(color);
	line.draw();
}

void PenSt::add(ofPoint point)
{
	line.addVertex(point);
}

void PenSt::setColor(ofColor col)
{
	color = col;
}
