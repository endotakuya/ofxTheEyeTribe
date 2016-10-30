#include "ofxTheEyeTribe.h"

void ofxTheEyeTribe::setup() {
	trackerSetup = client.setup(ADDRESS, PORT);
	client.setMessageDelimiter("\r\n");

	if (trackerSetup) {
		requestMsgVal.append("frame");
		requestMsg["category"] = "tracker";
		requestMsg["request"] = "get";
		requestMsg["values"] = requestMsgVal;

		requestTrackerStr = fastWritr.write(requestMsg);
		client.send(requestTrackerStr);
		start();
	}
}


void ofxTheEyeTribe::update(){
	if (client.isConnected()) {
		string getMsg = client.receiveRaw();
		
		if (getMsg.length() < TCP_MAX_MSG_SIZE && getMsg.length() > 0) {
			setGazeJson(getMsg);
		} else if (getMsg.length() == TCP_MAX_MSG_SIZE ) {
            /*
			char key = '\n';
			findLineEndKey = getMsg.find(key);
			if (getMsg.find(key) != string::npos) {
				getJson = getMsg.substr(sizeof(findKey), getMsg.size());
			} else {
                std::cout << "Not Found" << endl;
			}
            */
		}

	}
}

void ofxTheEyeTribe::threadedFunction() {
	while (isThreadRunning()) {
		update();
	}
}

void ofxTheEyeTribe::start(){
	startThread();
}

void ofxTheEyeTribe::exit() {
	client.close();
}

void ofxTheEyeTribe::setGazeJson(string json){
	getGazeMsg = json;
}

string ofxTheEyeTribe::getGazeJson(){
	return getGazeMsg;
}

