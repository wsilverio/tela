#include "GuiApp.h"

void GuiApp::setup(){
    parameters.setName("parameters");
    parameters.add(acc.set("acc", 0.0, 0, 2.0));
    parameters.add(speed.set("speed", 15, 0, 50));
    parameters.add(width.set("width", 150, 1, 500));
    parameters.add(color1.set("color 1", ofColor(50, 200, 150), ofColor(0, 0), 255));
    parameters.add(color2.set("color 2", ofColor(200, 50, 150), ofColor(0, 0), 255));
    parameters.add(lerp.set("lerp color", false));
    parameters.add(position.set("position", ofToString(0)));
    gui.setup(parameters);

    ofSetVerticalSync(false);
}

void GuiApp::update(){

}

void GuiApp::draw(){
    ofBackgroundGradient(ofColor::white, ofColor::grey, OF_GRADIENT_CIRCULAR);
    gui.draw();
}
