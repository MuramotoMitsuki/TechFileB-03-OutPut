#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    
    //01.ofDrawRectangleと02.ofRateの時のコード
    ofSoundPlayer mySound;
    float *volume;
    float *fftSmoothed; //FFT解析結果を使うことを宣言
    int nBandsToGet; //FFT解析結果の精度
    
    
    //03.ofPlanePrimitiveと04.ofSpherePrimitiveの時のコード
    ofMesh myMesh;//3Dメッシュ
    ofEasyCam cam;//カメラ
    ofLight light;//ライト
};
