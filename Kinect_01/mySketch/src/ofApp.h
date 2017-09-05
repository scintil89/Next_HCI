#pragma once

#include "ofxOpenNI.h"
#include "ofMain.h"
#include "DetectingEffect.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void userEvent(ofxOpenNIUserEvent & event);

	ofxOpenNI openNIDevice;

	ofTrueTypeFont verdana;

	vector<DetectingEffect> effectList;

	
	ofPoint left;
	ofPoint right;

	int _bef_LEFT;
	int _bef_RIGHT;

	float degree;

};
