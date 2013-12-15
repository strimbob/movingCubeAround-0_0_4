//
//  ofxCamera.cpp
//  emptyExample
//
//  Created by strimbob on 15/12/2013.
//
//

#include "ofxCamera.h"

ofxCamera::ofxCamera(){
    
}

void ofxCamera::setup(ofEasyCam *_cam){
    
    rotation.setup(_cam);
    enable();
    

}


void ofxCamera::update(){
    rotation.update();

}

void ofxCamera::draw(){
    rotation.draw();
    
    
}

void ofxCamera::enable(){
    rotation.enable();
    
}

void ofxCamera::disable(){
    
}

