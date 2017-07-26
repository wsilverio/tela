#include <iostream>
#include <string>
#include <vector>

#include "ofMain.h"
#include "ofApp.h"
#include "GuiApp.h"
#include "ofAppGLFWWindow.h"

void argParse(const int argc, char **argv){
    const auto argVector = std::vector<std::string>(argv + 1, argv + argc);

    for(auto it = argVector.begin(); it != argVector.end(); ++it){
        if(*it == "-h" || *it == "-help"){
            std::cout << "Help message." << '\n';
            exit(EXIT_SUCCESS);
        }
    }
}

//========================================================================
int main(int argc, char **argv){

    argParse(argc, argv);

    ofGLFWWindowSettings settings;
    settings.width = 1024;
    settings.height = 768;
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

    settings.setPosition(ofVec2f(settings.width + 10, 0));
    settings.width = 225;
    settings.height = 340;
    settings.resizable = false;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);

    shared_ptr<GuiApp> guiApp(new GuiApp);
    shared_ptr<ofApp> mainApp(new ofApp);
    
    mainApp->gui = guiApp;

    ofRunApp(mainWindow, mainApp);
    ofRunApp(guiWindow, guiApp);
    ofRunMainLoop();
}
