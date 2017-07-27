#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class GuiApp: public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    ofParameterGroup parameters;
    ofParameter<float> speed;
    ofParameter<float> acc;
    ofParameter<int> width;
    ofParameter<ofColor> color1;
    ofParameter<ofColor> color2;
    ofParameter<bool> lerp;
    ofParameter<std::string> position;
    ofParameter<std::string> fps;

    ofxPanel gui;
};

