#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();
    camera.setup(ofxCubeCamera::QUINCUNCIAL);
    camera.setMeshScale(0.18);
    #ifdef EMSCRIPTEN
        cubeMapShader.load("webgl/reflection");
    #else
        cubeMapShader.load("opengl/reflection");
    #endif

    cubeMap.loadImages("deeper/right.jpg",
                       "deeper/left.jpg",
                       "deeper/top.jpg",
                       "deeper/bottom.jpg",
                       "deeper/front.jpg",
                       "deeper/back.jpg");
    sphere.setRadius(1000);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<camera.renderCount; i++){
        camera.begin(i);
        cubeMap.bind();
        
        cubeMapShader.begin();
        cubeMapShader.setUniform1i("EnvMap", 0);
        sphere.draw();
        cubeMapShader.end();
        
        cubeMap.unbind();
        camera.end(i);
    }
    camera.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

float ofApp::toRadians(float angle) {
    return angle * (M_PI / 180);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    float deltaX = x-prevMouseX;
    float deltaY = y-prevMouseY;
    
    ofQuaternion deltaRotationQuaternion;
    deltaRotationQuaternion.makeRotate(toRadians(deltaY * 50), ofVec3f(1, 0, 0), toRadians(deltaX * 50), ofVec3f(0, 1, 0), 0, ofVec3f(0, 0, 1));
    
    sphere.setOrientation(deltaRotationQuaternion * sphere.getOrientationQuat());
    
    prevMouseX = x;
    prevMouseY = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    prevMouseX = x;
    prevMouseY = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
