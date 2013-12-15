//
//  rotation.cpp
//  emptyExample
//
//  Created by strimbob on 05/12/2013.
//
//

#include "rotation.h"

rotation::rotation(){
    
    
    rotationTpye[0] = ofVec3f(0,1,2);
    rotationTpye[1] = ofVec3f(2,0,1);
    rotationTpye[2] = ofVec3f(1,2,0);
    
    rot[0] = ofVec3f( 0,0,1);
    rot[1] = ofVec3f( 1,0,0);
    rot[2] = ofVec3f( 0,1,0);
    
    degreeMuti [0] = 0;
    degreeMuti [1] = 90;
    degreeMuti [2] = 180;
    
    for(int s = 0;s<3;s++){
      //  makeRotationDot(80+(s*10), s, rotation[s]);
        tours[s] = makeTorus(80+(s*10),2 ,.05,rotationTpye[s]);
    }
}

void rotation::enable(){
    if(!active){

        ofAddListener(ofEvents().keyPressed, this, &rotation::keyPressed);
        ofAddListener(ofEvents().keyReleased, this, &rotation::keyReleased);
        ofAddListener(ofEvents().mouseMoved, this, &rotation::mouseMoved);
        ofAddListener(ofEvents().mouseDragged, this, &rotation::mouseDragged);
        ofAddListener(ofEvents().mousePressed, this, &rotation::mousePressed);
        ofAddListener(ofEvents().mouseReleased, this, &rotation::mouseReleased);
        active = true;
    }
    
}

void rotation::disable(){
    if(active){
        ofRemoveListener(ofEvents().keyPressed, this, &rotation::keyPressed);
        ofRemoveListener(ofEvents().keyReleased, this, &rotation::keyReleased);
        ofRemoveListener(ofEvents().mouseMoved, this, &rotation::mouseMoved);
        ofRemoveListener(ofEvents().mouseDragged, this, &rotation::mouseDragged);
        ofRemoveListener(ofEvents().mousePressed, this, &rotation::mousePressed);
        ofRemoveListener(ofEvents().mouseReleased, this, &rotation::mouseReleased);
        active = false;
    }
}


//--------------------------------------------------------------
void rotation::setup(ofEasyCam *_cam){
    
    cam = _cam;

    
    cameraProxy.set(80, 80, 80, 2, 2, 2);
}

//--------------------------------------------------------------
void rotation::update(){
    for(int s = 0;s<3;s++){
        makeRotationDot(80+(s*10), s, rotationTpye[s]);
     //   tours[s] = makeTorus(80+(s*10),2 ,.05,rotation[s]); // just only at setup but can be here to re-cal it
    }
}

//--------------------------------------------------------------
void rotation::draw(){
    
    
    ofEnableDepthTest();
    cam->begin();
    
    if(selected != -1){
        ofPushView();
        ofNoFill();
    ofCircle(point[selected], 5);
        ofPopView();
    }
    ofPushStyle();
    
    for(int s = 0;s<3;s++){
        if(selectedMouseOver == s){
            
        ofSetColor(230, 230, 2);
        }else{
        ofSetColor(255, 255, 255);
        }
        tours[s].draw();

    }
    ofPopStyle();
    cameraProxy.drawWireframe();
    cam->end();

}



int rotation::selectMeshMouseOver(ofMesh mesh,int x,ofVec2f mouse){

	for(int i = 0; i < mesh.getNumVertices(); i++) {
		ofVec3f cur = cam->worldToScreen(mesh.getVertex(i));
		float distance = cur.distance(mouse);
        if( cur.distance(mouse) < 10){
            return x;
        }
    }
}

void rotation::makeRotationDot(float diameter,int forLoop,ofVec3f r){
    
    ofVec2f mouseP = cam->worldToCamera(cam->screenToWorld(ofVec3f(ofGetMouseX(),ofGetMouseY())));
    float angleTemp = -mouseP.angleRad(ofVec2f(diameter,0));
    mDot[0] = cos(angleTemp-degreeMuti[forLoop]) * diameter;
    mDot[1] = sin(angleTemp-degreeMuti[forLoop]) * diameter;
    mDot[2] = 0;
    point[forLoop].set(mDot[(int)r.x]-angleTemp,mDot[(int)r.y]-angleTemp,mDot[(int)r.z]);
    angle[forLoop] = angleTemp;
    
}



ofMesh rotation::makeTorus(float diameter,float fatness , float res,ofVec3f r){
    
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    for(float x=0;x<TWO_PI+res;x+=res){ // + the res to close loop
        vectX[0] = ((diameter+fatness)*cos(x));
        vectX[1] = ((diameter+fatness)*sin(x));
        vectX[2] = 0;
        vectY[0] = (diameter*cos(x));
        vectY[1] = (diameter*sin(x));
        vectY[2] = 0;
        ofVec3f leftSide  = ofVec3f(vectX[(int)r.x],vectX[(int)r.y],vectX[(int)r.z]);
        ofVec3f rightSide = ofVec3f(vectY[(int)r.x],vectY[(int)r.y],vectY[(int)r.z]);
        mesh.addVertex(leftSide);
        mesh.addVertex(rightSide);
        }

return mesh;

}


//--------------------------------------------------------------
void rotation::keyPressed(ofKeyEventArgs &args){

    
}

//--------------------------------------------------------------
void rotation::keyReleased(ofKeyEventArgs &args){
    
}

//--------------------------------------------------------------
void rotation::mouseMoved(ofMouseEventArgs &args){

    ofVec2f mouse(args.x, args.y);

    for(int s = 0;s<3;s++){
       selectedMouseOver = selectMeshMouseOver(tours[s],s, mouse);
    }

}

//--------------------------------------------------------------
void rotation::mouseDragged(ofMouseEventArgs &args){
    if(selected != -1){
        cameraProxy.rotate(ofRadToDeg(angle[selected]-oldAngle), rot[selected]);
         oldAngle = angle[selected];
    }

}

//--------------------------------------------------------------
void rotation::mousePressed(ofMouseEventArgs &args){


    selected = selectedMouseOver;
    if(selected > 2){
        cam->enableMouseInput();
        selected = -1;
    }
    else{
    cam->disableMouseInput();
    oldAngle = angle[selected];
    }

}

//--------------------------------------------------------------
void rotation::mouseReleased(ofMouseEventArgs &args){

    cam->enableMouseInput();
    selected = -1;
}