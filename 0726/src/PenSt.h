#include "ofMain.h"

class PenSt {
public:
	PenSt();
	~PenSt();
	void setup();
	void draw();
	void add(ofPoint point);
	//void clear();
	//void pop_back();

	//std::vector<ofRectangle> position;
	//std::vector<ofColor> color;

	void setColor(ofColor col);

	ofPolyline line;

	
public:
	ofColor color;
	
};