#include "PenRectangle.h"

PenRectangle::PenRectangle()
{
}

PenRectangle::~PenRectangle()
{
}

void PenRectangle::setup()
{
	position.clear();
	color.clear();
}

void PenRectangle::add(ofRectangle rect, ofColor c)
{
	position.push_back(rect);
	color.push_back(c);
}

void PenRectangle::draw()
{
	for (int i = 0; i < position.size(); i++) 
	{
		ofSetColor(color[i]);
		ofSetRectMode(OF_RECTMODE_CORNER);
		ofDrawRectangle(position[i]);
	}
}

void PenRectangle::clear()
{
	position.clear();
	color.clear();
}

void PenRectangle::pop_back()
{
	if (position.empty() == false && color.empty() == false)
	{
		position.pop_back();
		color.pop_back();
	}

}
