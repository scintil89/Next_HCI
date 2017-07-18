#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	font.loadFont("HMFMPYUN.TTF", 32);

	ofBackground(50, 50, 50);

	ofAddListener(Cshape::clickedInsideGlobal, this, &ofApp::onMouseInAnyCircle);

	ofPoint newP = { (float)50, (float)50 };
	ofColor newC = { ofRandom(255), ofRandom(255), ofRandom(255)};
	Cshape* first = new Cshape(newP, newC, 50, 50.f, 50.f);

	deq.push_back(first);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(bg);

	for (auto d : deq)
	{
		ofSetColor(d->color);
		ofDrawCircle(d->point, d->rad);
		//d.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	//std::cout << "key press" << std::endl;
	//sprintf(msg, "key press : %d ", key);
	switch (key)
	{
	case 1:
		std::cout << "1" << std::endl;

	default:
		break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	std::cout << "key release" << key << std::endl;

	if (key == 97) //a
	{
		deq.clear();
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	switch (button)
	{
	case 1:
		break;

	case 0:		
	{
		//sprintf(msg, "left button press : %d, %d ", x, y);

		ofPoint newP = ofPoint(x, y);
		ofColor newC = { ofRandom(255), ofRandom(255), ofRandom(255) };
		
		float newR = ofRandom(80);

		Cshape* newShape = new Cshape(newP, newC, newR, (float)x, (float)y);
		newShape->setUp();

		ofAddListener(newShape->clickedInside, this, &ofApp::onMouseInCircle);

		deq.push_back(newShape);
	}
		break;

	case 2:
		sprintf(msg, "right button press : %d, %d ", x, y);
		{
			if(deq.empty() == false)
			deq.pop_back();
		}
		break;

	default:
		//sprintf(msg, "mouse press press : %d, %d ", x, y);
		break;
	}

}

void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){ }



void ofApp::onMouseInCircle(ofVec2f & e)
{
	std::cout << "onMouseInCircle" << std::endl;
	//clickedPoint.set(e);
}

void ofApp::onMouseInAnyCircle(ofColor & c) 
{
	std::cout << "onMouseInAnyCircle" << std::endl;
	ofColor newC = ofColor(c.b, 255.f - c.g, c.r );

	bg.set(newC);
}