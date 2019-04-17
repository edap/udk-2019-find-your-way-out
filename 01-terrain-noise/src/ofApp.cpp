#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    light.setAmbientColor(ofFloatColor::white);
    light.setup();
    light.setPosition(200,600,400);
    light.enable();
    
    ofDisableArbTex();
    int h = ofGetHeight();
    int w = ofGetWidth();

    shader.load("shaders/vert.glsl", "shaders/frag.glsl", "");

    plane.set(w, h, w, h, OF_PRIMITIVE_TRIANGLES);
    plane.setPosition(0, 0, 0);
    plane.rotateDeg(180, glm::vec3(0.0f,0.0f,1.0f));
    cam.setup(640, 480);

    noisedImg.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);


    for (int y=0; y<h; y++) {
        for (int x=0; x<w; x++) {

            float a = x * .01;
            float b = y * .01;
            float c = ofGetFrameNum() / 50.0;
            
//            float noise = ofNoise(a,b,c) * 255;
//            float color = noise>200 ? ofMap(noise,200,255,0,255) : 0;


            float noise = ofNoise(a,b,c) * 255;
            float color = ofMap(noise,0,255,0,255);

            noisedImg.getPixels()[y*w+x] = color;
        }
    }
    noisedImg.update();
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (debug) {
        noisedImg.draw(0,0);
    } else {
        shader.begin();
        shader.setUniformTexture("tex0", noisedImg.getTexture(), 0);
        shader.setUniform2f("uMousePos", mouseX, mouseY);
        shader.setUniform2f("uResolution", ofGetWidth(), ofGetHeight());
        camera.begin();
        plane.draw();
        camera.end();
        shader.end();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='d') {
        debug=!debug;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
