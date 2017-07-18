#include "Cshape.h"

ofEvent<ofColor> Cshape::clickedInsideGlobal = ofEvent<ofColor>();

Cshape::Cshape()
{
	//ofRegisterMouseEvents(this);
	isRegistered = false;
}

Cshape::Cshape(ofPoint p, ofColor c, float r, float _x, float _y)
{
	//ofRegisterMouseEvents(this);
	point = p; color = c; rad = r; x = _x; y = _y;
	isRegistered = false;
}

Cshape::~Cshape()
{
	if (isRegistered)
	{
		ofUnregisterMouseEvents(this); // disable litening to mouse events.
		isRegistered = false;
	}
}

void Cshape::setUp()
{
	if (isRegistered == false)
	{
		isRegistered = true;
		ofRegisterMouseEvents(this);
	}
}

void Cshape::draw()
{
	ofPushStyle();

	ofSetColor(color);
	ofDrawCircle(point, rad);

	ofPopStyle();
}

void Cshape::mouseMoved(ofMouseEventArgs & args) {}
void Cshape::mouseDragged(ofMouseEventArgs & args){}
void Cshape::mousePressed(ofMouseEventArgs & args){}

void Cshape::mouseReleased(ofMouseEventArgs & args)
{
	std::cout << "mouseReleased" << std::endl;

	ofVec2f position = ofVec2f(args.x, args.y);

	if ( inside(args.x, args.y) )
	{
		std::cout << "mouseReleased if µé¾î¿È" << std::endl;

		ofColor newC = { ofRandom(255), ofRandom(255), ofRandom(255) }; 
		float newR = ofRandom(80);

		color = newC;
		rad = newR;
		
		ofNotifyEvent(clickedInside, position, this);
		ofNotifyEvent(clickedInsideGlobal, newC);
	}

	//ofNotifyEvent(clickedInsideGlobal, color);
}

void Cshape::mouseScrolled(ofMouseEventArgs & args){}
void Cshape::mouseEntered(ofMouseEventArgs & args){}
void Cshape::mouseExited(ofMouseEventArgs & args){}

bool Cshape::inside(float _x, float _y)
{
	std::cout << "inside ÇÔ¼ö" << std::endl;

	bool ret = ofVec2f(_x, _y).distance(ofVec2f(x, y)) < rad;

	std::cout << "¸¶¿ì½º ÁÂÇ¥ _x, _y : " << _x << " , " << _y << " " << std::endl;
	std::cout << " ¿øÀÇ ÁÂÇ¥ x, y : " << x << " , " << y << " " << std::endl;

	std::cout << "bool °ª : " << ret << std::endl;

	return ret;
}