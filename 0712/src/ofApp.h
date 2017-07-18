#pragma once

#include "Cshape.h"
#include "ofMain.h"
#include <deque>
#include <tuple>


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


		void onMouseInCircle(ofVec2f & e);
		void onMouseInAnyCircle(ofColor & c);


		ofTrueTypeFont font;
		char msg[255];

		ofColor bg;

		std::deque<Cshape*>  deq;

};
