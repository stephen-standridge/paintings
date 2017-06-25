#pragma once

#include "ofMain.h"
#include "ofxCubeCamera.h"
#include "ofxCubeMap.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
        float toRadians(float angle);

        ofxCubeCamera camera;
        ofxCubeMap cubeMap;
        ofShader cubeMapShader;
        ofSpherePrimitive sphere;
        float prevMouseX = 0;
        float prevMouseY = 0;
};
