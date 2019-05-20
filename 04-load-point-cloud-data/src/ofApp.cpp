#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();
    model.loadModel("statua.obj");

    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.append(model.getMesh(model.getMeshNames()[0]));
    glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
    //glPointSize(10); // make the points bigger
    mat.setAmbientColor(ofFloatColor::lightCoral);
    light.enable();
    light.setPosition(glm::vec3(100,-600,100));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    // note that the model has a different scale than the point mesh
    // this is because ofxAssimpModel is scaling it.
    if(drawPointCloud){
        light.draw();
        mat.begin();
        mesh.draw();
        mat.end();
    }else{
        model.drawFaces();
    }
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'p'){
        drawPointCloud = !drawPointCloud;
    }
}
