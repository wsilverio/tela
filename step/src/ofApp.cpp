#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    objPos.set(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

    gui->speed += gui->acc;

    objPos.x += gui->speed;

    if(objPos.x > ofGetWidth()){
        objPos.x = -gui->width;

        if (gui->acc != 0){
            gui->speed = 0;
        }

    }

    obj.setSize(gui->width, ofGetWidth());
    obj.setPosition(objPos);

    float value = objPos.x;
    if(value < 0) value = 0;
    else if(value > (ofGetWidth()-gui->width)) value = ofGetWidth()-gui->width;

    float lerp = (gui->lerp) ? ofMap(value, 0, ofGetWidth()-gui->width , 0.0, 1.0) : 0.0;
    lerpC = gui->color1->getLerped(gui->color2, lerp);

    gui->position = ofToString(objPos.x);
    gui->fps = ofToString(ofGetFrameRate());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::black);

    ofSetColor(lerpC);
    ofDrawRectangle(obj);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case 'f':
        case 'F':
            // ofToggleFullscreen();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
