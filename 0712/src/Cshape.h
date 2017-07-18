#pragma once

#include <ofMain.h>


class Cshape
{
public:
	Cshape();
	Cshape(ofPoint p, ofColor c, float r, float _x, float _y);
	~Cshape();

	void setUp();
	void draw();


	ofPoint point;
	ofColor	color;
	float rad;
	float x;
	float y;

	ofEvent<ofVec2f> clickedInside;
	static ofEvent<ofColor> clickedInsideGlobal;

	//We need to declare all this mouse events methods to be able to listen to mouse events.
	//All this must be declared even if we are just going to use only one of this methods.
	void mouseMoved(ofMouseEventArgs & args);
	void mouseDragged(ofMouseEventArgs & args);
	void mousePressed(ofMouseEventArgs & args);
	void mouseReleased(ofMouseEventArgs & args);
	void mouseScrolled(ofMouseEventArgs & args);
	void mouseEntered(ofMouseEventArgs & args);
	void mouseExited(ofMouseEventArgs & args);


	//this function checks if the passed arguments are inside the circle.
	bool inside(float _x, float _y);

private:

	bool isRegistered = false;

};

