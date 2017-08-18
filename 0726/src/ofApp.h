#pragma once

#include "ofMain.h"
#include <vector>
#include "RectButton.h"
#include "PenRectangle.h"
#include "PenSt.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		//std::vector<ofRectangle> v_position;
		//std::vector<ofColor> v_color;
		
	
		bool bDrawButton;
		bool bClearButton;
		bool bMyButton;
		bool bStButton;
		bool bPolyButton;

		//bool inside(ofRectangle buttonRect, int x, int y);

		RectButton drawButton;
		RectButton clearButton;
		RectButton myButton;
		RectButton stButton;
		RectButton polyButton;

		PenRectangle* penRectangle;
		PenSt* penSt;
		PenSt* penpoly;
};
