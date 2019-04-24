#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();
    light.setAmbientColor(ofFloatColor::white);
    light.setup();
    light.setPosition(200,600,400);
    light.enable();
    
    ofDisableArbTex();
    int h = ofGetHeight();
    int w = ofGetWidth();

    shader.load("shaders/vert.glsl", "shaders/frag.glsl", "");

    plane.set(w, h, w/4, h/4, OF_PRIMITIVE_TRIANGLES);
    plane.setPosition(0, 0, 0);
    plane.rotateDeg(90, glm::vec3(1.0f,0.0f,0.0f));
    cam.setup(640, 480);

    // TODO 02. Move noise to the GPU.
    // Measure the FPS, see the difference before and after.
    //
    noisedImg.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);


    for (int y=0; y<h; y++) {
        for (int x=0; x<w; x++) {

            float a = x * .01;
            float b = y * .01;
            float c = ofGetFrameNum() / 50.0;
            float noise = ofNoise(a,b,c) * 255;
            float color = ofMap(noise,0,255,0,255);

            noisedImg.getPixels()[y*w+x] = color;
        }
    }
    noisedImg.update();

    // TODO 01 SKY
    shaderSky.load("shaders/sky_vert.glsl", "shaders/sky_frag.glsl", "");

    sky.set(w*1.5, ofGetHeight(), 2, 2, OF_PRIMITIVE_TRIANGLES);
    sky.setPosition(0, ofGetHeight()/4, -ofGetHeight()/2);
    //sky.rotateDeg(90, glm::vec3(0.0f,0.0f,1.0f));
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

        // TODO 02
        camera.begin();
        ofDrawAxis(200);

        // terrain
        shader.begin();
        // TODO 02 Noise in GPU
        shader.setUniformTexture("tex0", noisedImg.getTexture(), 0);
        shader.setUniform2f("uMousePos", mouseX, mouseY);
        shader.setUniform1f("uTime", ofGetElapsedTimef());
        shader.setUniform2f("uResolution", ofGetWidth(), ofGetHeight());

        plane.draw();
        shader.end();

        // TODO 01 SKY
        shaderSky.begin();
        shaderSky.setUniform2f("uResolution", ofGetWidth(), ofGetHeight());
        sky.draw();
        shaderSky.end();

        camera.end();
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
