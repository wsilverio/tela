#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define PORT 12345

class ofApp : public ofBaseApp{

        public:
        void setup();
        void update();
        void draw();

        void exit();

        void keyPressed(int key);
        void floatChanged(float &mFloat);
        void intChanged(int &mInt);

        std::string mString;

        ofxFloatSlider myFloat;
        ofxIntSlider myInt;
        ofxLabel myString;
        ofxPanel gui;

        ofxOscSender sender;
};
