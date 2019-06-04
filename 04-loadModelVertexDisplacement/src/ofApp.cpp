#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // try to remove this line and see what happens
    // when you zoom in
    cam.setNearClip(0.1);

    ofEnableDepthTest();
    ofDisableArbTex();
    model.loadModel("statua.obj");


    if (usePoints) {
        mesh.setMode(OF_PRIMITIVE_POINTS);
        glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
        glPointSize(3); // make the points bigger
    } else {
        mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    }

    mesh.append(model.getMesh(model.getMeshNames()[0]));

    img.load("statua.jpg");
    shader.load("shaders/vert.glsl", "shaders/frag.glsl", "");

    gui.setup();
    gui.add(magNoise);
    gui.add(freqNoise);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();

    shader.begin();
    shader.setUniform1f("uTime", ofGetElapsedTimef());
    shader.setUniform1f("magNoise", magNoise.get());
    shader.setUniform1f("freqNoise", freqNoise.get());
    shader.setUniformTexture("uTex0",img.getTexture(),0);

    mesh.draw();
    shader.end();

    cam.end();

    ofDisableDepthTest();
    gui.draw();
    ofEnableDepthTest();
}
