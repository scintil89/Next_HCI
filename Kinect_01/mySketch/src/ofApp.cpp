#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetLogLevel(OF_LOG_VERBOSE);

	openNIDevice.setup();
	openNIDevice.addImageGenerator();
	openNIDevice.addDepthGenerator();
	openNIDevice.setRegister(true);
	openNIDevice.setMirror(true);

	openNIDevice.addUserGenerator();
	openNIDevice.setMaxNumUsers(2);
	openNIDevice.start();

	// set properties for all user masks and point clouds
	//openNIDevice.setUseMaskPixelsAllUsers(true); // if you just want pixels, use this set to true
	openNIDevice.setUseMaskTextureAllUsers(true); // this turns on mask pixels internally AND creates mask textures efficiently
	openNIDevice.setUsePointCloudsAllUsers(true);
	openNIDevice.setPointCloudDrawSizeAllUsers(2); // size of each 'point' in the point cloud
	openNIDevice.setPointCloudResolutionAllUsers(2); // resolution of the mesh created for the point cloud eg., this will use every second depth pixel

	verdana.loadFont(ofToDataPath("verdana.ttf"), 24);

	effectList.push_back(DetectingEffect(0));
	effectList.push_back(DetectingEffect(1));

	degree = 0.0f;
	_bef_LEFT = 700;
	_bef_RIGHT = 700;

	left = { 100, 400 };
	right = { 500, 400 };
}

//--------------------------------------------------------------
void ofApp::update() {
	openNIDevice.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255, 255, 255);
	openNIDevice.drawDebug(); // draws all generators
							  //openNIDevice.drawDepth(0, 0);
							  //openNIDevice.drawImage(640, 0);
	ofShortPixels depthMap = openNIDevice.getDepthRawPixels();

	int l_depth = depthMap[left.x + left.y * 640];
	int r_depth = depthMap[right.x + right.y * 640];

	ofSetColor(0, 255, 0);
	string msg1 = "Position (" + ofToString(left.x) + "," + ofToString(left.y) + ") " +
		"Depth: " + ofToString(l_depth);
	verdana.drawString(msg1, 20, ofGetHeight() - 26);
	ofSetColor(200, 0, 0);

	ofSetColor(0, 255, 0);
	string msg2 = "Position (" + ofToString(right.x) + "," + ofToString(right.y) + ") " +
		"Depth: " + ofToString(r_depth);
	verdana.drawString(msg2, 20, ofGetHeight() - 52);
	ofSetColor(200, 0, 0);

	//ofCircle(100, selectedPoint.y, 10)

	if (l_depth - _bef_LEFT > 100)
	{
		degree += 1;
	}

	if (r_depth - _bef_RIGHT > 100)
	{
		degree -= 1;
	}

	//Circle 1
	ofPushMatrix();
	ofSetColor(0, 200, 200);
	ofCircle(left, 10.f);
	ofPopMatrix();

	//Circle 2
	ofPushMatrix();
	ofSetColor(0, 200, 200);
	ofCircle(right, 10.f);
	ofPopMatrix();

	
	//
	ofPushMatrix();
	ofTranslate(300, 200);
	ofRotate(degree);
	ofBox(ofPoint(0, 0), 50.f);
	ofSetColor(255,0, 0);
	ofPopMatrix();


	ofDisableBlendMode();
	ofPopMatrix();

	// draw some info regarding frame counts etc
	ofSetColor(0, 255, 0);
	//msg += " MILLIS: " + ofToString(ofGetElapsedTimeMillis()) + " FPS: " + ofToString(ofGetFrameRate()) + " Device FPS: " + ofToString(openNIDevice.getFrameRate());

	//verdana.drawString(msg, 20, openNIDevice.getNumDevices() * 480 - 20);
}

//--------------------------------------------------------------
void ofApp::userEvent(ofxOpenNIUserEvent & event) {
	// show user event messages in the console
	ofLogNotice() << getUserStatusAsString(event.userStatus) << "for user" << event.id << "from device" << event.deviceID;
}

//--------------------------------------------------------------
void ofApp::exit() {
	openNIDevice.stop();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
