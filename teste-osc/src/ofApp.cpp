#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sender.setup(HOST, PORT);

    myFloat.addListener(this, &ofApp::floatChanged);
    myInt.addListener(this, &ofApp::intChanged);

    mString = "type something";

    gui.setup();
    gui.setSize(gui.getWidth() + 20, gui.getHeight());
    gui.setDefaultWidth(gui.getWidth());
    gui.add(myFloat.setup("my float", 0.1, 0, 1));
    gui.add(myInt.setup("my int", 5, 0, 10));
    gui.add(myString.setup("my string", mString + '_'));

    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(ofColor::yellow);
}

//--------------------------------------------------------------
void ofApp::exit(){
    myFloat.removeListener(this, &ofApp::floatChanged);
    myInt.removeListener(this, &ofApp::intChanged);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::grey, ofColor::black);

    ofPushMatrix();
    ofTranslate(ofMap(myInt, 0, 10, 0, ofGetWidth()), ofGetHeight()/2.0);
    ofRotate(100*myFloat*ofGetElapsedTimef());
    ofDrawRectangle(0, 0, 300, 300);
    ofPopMatrix();

    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (OF_KEY_BACKSPACE == key) {
        if (mString.size() > 0) {
            mString.pop_back();
        }
    } else if (' ' <= key && '~' >= key) {
        if (mString.size() < 14) {
            mString += key;
        }
    } else if (OF_KEY_RETURN == key){
        ofxOscMessage m;
        m.setAddress("/myString");
        m.addStringArg(mString);
        sender.sendMessage(m, false);
    }

    myString = mString + '_';
}

//--------------------------------------------------------------
void ofApp::floatChanged(float &value){
    ofxOscMessage m;
    m.setAddress("/myFloat");
    m.addFloatArg(value);
    sender.sendMessage(m, false);
}

//--------------------------------------------------------------
void ofApp::intChanged(int &value){
    ofxOscMessage m;
    m.setAddress("/myInt");
    m.addIntArg(value);
    sender.sendMessage(m, false);
}
