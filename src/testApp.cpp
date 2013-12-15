#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableDepthTest();
    camera.enable();
    camera.setup(&cam);
}

//--------------------------------------------------------------
void testApp::update(){
    camera.update();
//    if(ofGetMousePressed()){
//        cam.disableMouseInput();
//    }else{
//        cam.enableMouseInput();
//    }
    
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){

    camera.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
