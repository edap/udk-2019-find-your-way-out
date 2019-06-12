#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    light.setup();
    light.setPosition(-200, 200,0);
    // we set up a plane on which the car will move
    plane.set(10000, 10000);
    plane.rotateDeg(270, 1, 0 , 0);
    plane.move(0, -49, 0);
    planeMaterial.setDiffuseColor(ofFloatColor::gray);
    planeMaterial.setShininess(0.01);

    cubeMaterial.setDiffuseColor(ofFloatColor::orange);
    cubeMaterial.setShininess(0.09);


    ofEnableDepthTest();

    //Set our camera up in a nice location to view our awesome car
    cam.setPosition(700, 0, 700);
    cam.lookAt(glm::vec3(0.0f,0.0f,0.0f), {0.f, 1.f, 0.f});
    cam.setFarClip(10000);

    for(unsigned int i =0; i < 50; i++){
        auto box = ofBoxPrimitive(50, 50, 50);
        box.setPosition(ofRandom(-500, 500), 0, ofRandom(-500, 500));
        cubes.push_back(box);

    }
}

//--------------------------------------------------------------
void ofApp::update(){
    camVel += camAcceleration;
    camVel *= 0.2;
    camAcceleration *= 0.99;
    // here we are defining the vector that contains the direction
    // in which the car should move, that is defined by the z-axis of the car and the velocity
    auto velVector = cam.getZAxis() * -camVel;
    cam.move(velVector);
}

//--------------------------------------------------------------
void ofApp::draw(){
    //came.begin();
    cam.begin();
    ofDrawAxis(100); // useful

    cubeMaterial.begin();
    for(auto cube:cubes){
        cube.draw();
    }
    //light.draw();
    cubeMaterial.end();
    planeMaterial.begin();
    plane.draw();
    planeMaterial.end();
    //cam.draw();
    cam.end();
    //came.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_UP){
        camAcceleration += 0.1;
    }else if(key == OF_KEY_DOWN){
        camAcceleration -= 0.1;
    }else if(key== OF_KEY_LEFT){
        cam.rotateDeg(+0.5f, 0, 1, 0);
    }else if(key==OF_KEY_RIGHT){
        cam.rotateDeg(-0.5f, 0, 1, 0);
    }

}
