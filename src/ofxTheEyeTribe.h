#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "ofxNetwork.h"

const int PORT = 6555;
const string ADDRESS = "localhost";

class ofxTheEyeTribe : public ofThread {

public:

	void setup();
	void update();
	void threadedFunction();
	void start();
	void exit();

	void   setGazeJson(string json);
	string getGazeJson();
	

private:
	/*
	* TheEyeTribeServer Connect, Get data
	*/
	ofxTCPClient client;
	bool trackerSetup;
	string requestTrackerStr;
	Json::Value requestMsg;
	Json::Value requestMsgVal = Json::arrayValue;
	Json::FastWriter fastWritr;
	ofBuffer dataBuffer;

	ofxJSONElement result;

	string findLineEndKey;
	string getGazeMsg;
	string prevGetGazeMsg;

	

};
