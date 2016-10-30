#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"
#include "ofxTheEyeTribe.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

        void exit();
    
        ofxTheEyeTribe eyetribe;
    
};
