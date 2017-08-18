#include "ofMain.h"
#include <vector>

class PenRectangle
{
public:
	PenRectangle();
	~PenRectangle();
	void setup();
	void add(ofRectangle rect, ofColor c);
	void draw();
	void clear();
	void pop_back();

	std::vector<ofRectangle> position;
	std::vector<ofColor> color;
};