#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(3);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);

	this->font.loadFont("fonts/Kazesawa-Bold.ttf", 50, true, true, true);
	this->word = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

//--------------------------------------------------------------
void ofApp::update() {


}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofSeedRandom(39);
	for (int i = 0; i < 400; i++) {

		auto deg = ofRandom(360);
		auto radius = int(ofRandom(720) + ofGetFrameNum() * ofRandom(3, 8)) % 720;
		auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		
		ofPushMatrix();
		ofTranslate(location);
		ofRotate(ofRandom(360));

		ofPath chara_path = this->font.getCharacterAsPoints(this->word[(int)ofRandom(this->word.size())], true, false);
		vector<ofPolyline> outline = chara_path.getOutline();

		ofNoFill();
		ofSetColor(39);
		ofBeginShape();
		for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

			ofNextContour(true);

			auto vertices = outline[outline_index].getVertices();
			for (auto& vertex : vertices) {

				ofVertex(vertex);
			}
		}
		ofEndShape(true);

		ofPopMatrix();
	}

	ofSeedRandom(39);
	for (int i = 0; i < 400; i++) {

		auto deg = ofRandom(360);
		auto radius = int(ofRandom(720) + ofGetFrameNum() * ofRandom(3, 8)) % 720;
		auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

		ofPushMatrix();
		ofTranslate(location);
		ofRotate(ofRandom(360));

		ofPath chara_path = this->font.getCharacterAsPoints(this->word[(int)ofRandom(this->word.size())], true, false);
		vector<ofPolyline> outline = chara_path.getOutline();

		ofFill();
		ofSetColor(239);
		ofBeginShape();
		for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

			ofNextContour(true);

			auto vertices = outline[outline_index].getVertices();
			for (auto& vertex : vertices) {

				ofVertex(vertex);
			}
		}
		ofEndShape(true);

		ofPopMatrix();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}