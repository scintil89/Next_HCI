#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//v_position.clear();
	//v_color.clear();

	bDrawButton = false;
	bClearButton = false;

	drawButton.setup(ofRectangle(0, 0, 100, 100), ofColor(255, 0, 0), "pen1");
	clearButton.setup(ofRectangle(100, 0, 100, 100), ofColor(0, 255, 0), "clear");
	myButton.setup(ofRectangle(200, 0, 100, 100), ofColor(0, 0, 255), "my");
	stButton.setup(ofRectangle(300, 0, 100, 100), ofColor(0, 200, 255), "line");
	polyButton.setup(ofRectangle(400, 0, 100, 100), ofColor(100, 0, 255), "poly");

	penRectangle = new PenRectangle();
	penRectangle->setup();

	penSt = new PenSt();
	penSt->setColor( ofColor(0, 200, 255) );
	penpoly = new PenSt();
	penpoly->setColor(ofColor(100, 0, 255));
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (bClearButton) 
	{
		penRectangle->clear();
		bClearButton = false;
	}

	if (bMyButton)
	{
		penRectangle->pop_back();
		bMyButton = false;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(1, 1, 1);

	//if (bDrawButton) 
	//{
		penRectangle->draw();
		penSt->draw();
		penpoly->draw();
	//}

	drawButton.draw();
	clearButton.draw();
	myButton.draw();
	stButton.draw();
	polyButton.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
	if (bDrawButton) 
	{
		penRectangle->add(ofRectangle(x, y, ofRandom(30, 50), ofRandom(30, 50)), 
			ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)));
	}

	if (bPolyButton)
	{
		ofPoint pt;
		pt.set(x, y);
		penpoly->add(pt);
	}

	drawButton.inside(x, y);
	clearButton.inside(x, y);
	myButton.inside(x, y);
	stButton.inside(x, y);
	polyButton.inside(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	if (bStButton)
	{
		ofPoint pt;
		pt.set(x, y);
		penSt->add(pt);
	}

	if (drawButton.inside(x, y)) 
	{
		cout << "draw button" << endl;
		bDrawButton = true;
		bClearButton = false;
		bMyButton = false;
		bStButton = false;
		bPolyButton = false;
	}
	if (clearButton.inside(x, y))
	{
		cout << "clear button" << endl;
		bClearButton = true;
		bDrawButton = false;
		bMyButton = false;
		bStButton = false;
		bPolyButton = false;
	}
	if (myButton.inside(x, y))
	{
		cout << "my button" << endl;
		bMyButton = true;
		bClearButton = false;
		bDrawButton = false;
		bStButton = false;
		bPolyButton = false;
	}
	if (stButton.inside(x, y))
	{
		cout << "line button" << endl;
		bMyButton = false;
		bClearButton = false;
		bDrawButton = false;
		bStButton = true;
		bPolyButton = false;
	}
	if (polyButton.inside(x, y))
	{
		cout << "poly button" << endl;
		bMyButton = false;
		bClearButton = false;
		bDrawButton = false;
		bStButton = false;
		bPolyButton = true;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	drawButton.inside(x, y);
	clearButton.inside(x, y);
	myButton.inside(x, y);
	stButton.inside(x, y);
	polyButton.inside(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

/*
bool ofApp::inside(ofRectangle buttonRect, int x, int y)
{
	if ((buttonRect.x < x) && ((buttonRect.x + buttonRect.width) > x)) 
	{
		if ((buttonRect.y < y) && ((buttonRect.y + buttonRect.height) > y)) 
		{
			return true;
		}
	}

	return false;
}

*/
