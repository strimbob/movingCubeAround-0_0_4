#pragma once
#include "ofMain.h"
#include "rotation.h"

class ofxCamera: public ofBaseApp{
    public:

    void setup(ofEasyCam *_cam);
    void update();
    void draw();
    ofxCamera();
    
    void disable();
    void enable();
    bool active;
    rotation rotation;
 
};