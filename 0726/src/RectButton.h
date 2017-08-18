#include "ofMain.h"

class RectButton {
public:
	RectButton();
	~RectButton();
	void setup(ofRectangle _rect, ofColor _color, string _name);
	void draw();
	bool inside(float x, float y);
	string getName();

public:
	std::string name;
	ofRectangle rect;
	ofColor color;
	bool bPressed;
};