#pragma once

#include "ofMain.h"

class rotation: public ofBaseApp{
public:
    
    rotation();
    void setup(ofEasyCam *_cam);
    void update();
    void draw();
    void disable();
    void enable();
    bool active;
    
private:
    ofEasyCam *cam;
    void keyPressed(ofKeyEventArgs &args);
    void keyReleased(ofKeyEventArgs &args);
    void mouseMoved(ofMouseEventArgs &args);
    void mouseDragged(ofMouseEventArgs &args);
    void mousePressed(ofMouseEventArgs &args);
    void mouseReleased(ofMouseEventArgs &args);
    void windowResized(ofMouseEventArgs &args);
    ofMesh makeTorus(float diameter,float fatness,float rotationSpeed,ofVec3f r);
    void makeRotationDot(float diameter,int forLoop,ofVec3f r);
    ofVec3f rotationTpye[3];
    float oldAngle;
    ofPoint point[3];
    ofMesh tours[3];
    ofBoxPrimitive cameraProxy;
    float angle[3];
    ofVec3f rot[3];
    float mDot[3];
    int selectMeshMouseOver(ofMesh mesh,int x,ofVec2f mouse);
    int selected;
    int selectedMouseOver;
    float vectX[3];
    float vectY[3];
    float degreeMuti[3];
};

