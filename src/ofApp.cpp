#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //01.ofDrawRectangleと02.ofRateの時のコード
    //ofToggleFullscreen();
    //ofSetVerticalSync(true);//画面の垂直同期をonにする
    //ofEnableBlendMode(OF_BLENDMODE_ADD);//色を重ねるほど明るくなる
    //ofSetCircleResolution(60);//円の粗さを想定
    //ofSetBackgroundColor(0, 0, 0);
    
    //mySound.load("test.wav");
    //mySound.setLoop(true);
    //mySound.play();
    
    //FFT解析初期化
    //fftSmoothed = new float[8192];
    //for(int i=0; i<8192 ;i++ ){
        //fftSmoothed[i]=0;
    //}
    
    //nBandsToGet = 40;//01.ofDrawRectangle
    
    //nBandsToGet = 360;//02.ofRate
    
    
    
    //03.ofPlanePrimitiveの時のコード
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    
    ofEnableDepthTest();//深度のテストを有効にする
    
    light.enable();//ライトを使う
    light.setPosition(-100, 100, 500);//ライトの位置を決める
    glPointSize(3);
    
    //面からメッシュを作成
    //myMesh = ofPlanePrimitive(1000, 1000, 100, 100).getMesh();
    
    //球からメッシュを作成
    myMesh = ofSpherePrimitive(200, 70).getMesh();//半径と解像度
    
    //メッシュの色指定
    for(int i=0;i<myMesh.getVertices().size(); i++){
        myMesh.addColor(ofFloatColor(0.5,1.0,1.0,0.5));//メッシュの色指定
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    //01.ofDrawRectangleと02.ofRateの時のコード
    //ofSoundUpdate();
    //volume = ofSoundGetSpectrum(nBandsToGet);//音量を取得
    
    //FFT解析を行い、音量の平均を出す
    //for (int i=0; i<nBandsToGet; i++ ){
        //fftSmoothed[i] *= 0.96f;
        //if(fftSmoothed[i] < volume[i]){
            //fftSmoothed[i] = volume[i];
        //}}}
    
    
    //03.ofPlanePrimitiveの時のコード
    //for (int i=0; i<myMesh.getVertices().size();i++){//頂点の数だけ繰り返す
        //ofVec3f point = myMesh.getVertices()[i] / 400.0;//頂点の位置を取得
        //float z = ofNoise(point.x, point.y, ofGetElapsedTimef())*200.0;//経過時間の取得
        //myMesh.setVertex(i, ofVec3f(myMesh.getVertices()[i].x,myMesh.getVertices()[i].y,z));
    //}
    
    
    //04.ofPlanePrimitiveの時のコード
    for(int i=0; i<myMesh.getVertices().size();i++){
        ofVec3f point = myMesh.getVertices()[i] / 300.0;
        float size = 80 +100 * ofNoise(point.x,point.y,point.z,ofGetElapsedTimef());
        ofVec3f newPoint = point.normalize() * size;//新しい座標を作成
        myMesh.setVertex(i, newPoint);//新しい座標をセット
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //01.ofDrawRectangleと02.ofRateの時のコード
    //int start_x = 200;//一番左端の四角形のx座標
    //int base_y = 500;//四角形のy座標
    //float width = (float)(800) / nBandsToGet; //四角形の幅
    
    
    //01.ofDrawRectangleの時のコード
    //ofSetColor(55, 190, 260);//上向きの四角形の色を指定
    //for(int i=0; i<nBandsToGet;i++){
        //ofDrawRectangle(start_x + i * width, base_y, width, -(fftSmoothed[i]) * 400);//上向き
    //}
    
    //ofSetColor(200, 20, 105, 50);
        //for(int i=0 ; i<nBandsToGet ;i++ ){
            //ofDrawRectangle(start_x + i * width, base_y, width, (fftSmoothed[i]) * 300);//下向き
        //}
    
    
    //02.ofRateの時のコード
    //ofTranslate(ofGetWidth()/2, ofGetHeight()/2);//基準座標を変える
    
    //for(int i=0;i<nBandsToGet;i+=5){
        //ofPushMatrix();
        //ofSetBackgroundColor(ofColor::fromHsb((float)255/nBandsToGet *i, 100, 255));
        //float length = 300 * fftSmoothed[i%nBandsToGet];//四角形の幅
        //ofRotateZ(i);
        //ofDrawRectangle(0, 150, 5, length);//四角形を表示
        //ofPopMatrix();}
    
    
    cam.begin();
    
    //03.ofPlanePrimitiveの時のコード
    myMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    //04.ofSpherePrimitiveの時のコード
    myMesh.setMode(OF_PRIMITIVE_POINTS);
    myMesh.draw();
    
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
