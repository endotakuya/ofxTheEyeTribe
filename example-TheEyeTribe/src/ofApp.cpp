#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    eyetribe.setup();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        std::cout << "[GazeData]: " << eyetribe.getGazeJson() << endl;
    }
}

//--------------------------------------------------------------
void ofApp::exit(){
    eyetribe.exit();
}
