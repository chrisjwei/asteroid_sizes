/**
 *  ofxCsv
 *  Inspired and based on Ben Fry's [table class](http://benfry.com/writing/map/Table.pde)
 *
 *  
 *  The MIT License
 *
 *  Copyright (c) 2011-2014 Paul Vollmer, http://www.wng.cc
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 *
 *  
 *  @testet_oF          0071
 *  @testet_plattform   MacOs 10.6+
 *                      ??? Win
 *                      ??? Linux
 *  @dependencies       
 *  @modified           2012.06.28
 *  @version            0.1.3
 */

#include "myApp.h"

//--------------------------------------------------------------
void myApp::setup(){
	
	// Load a CSV File.
	csv.loadFile(ofToDataPath("meteorite.csv"));
	n = csv.numRows;
	scale = DEFAULT_SCALE;
	updated = true;
	grid.clear();

  int i;
  for (i=0; i<csv.numRows; i++){
  	double mass = stod(csv.data[i][2]);
		Meteorite m = Meteorite(mass);
		meteoriteVector.push_back(m);
  }
}

//--------------------------------------------------------------
void myApp::update(){
	int count;

	if (updated){
		cout << "Updated" << endl;
		grid.clear();

		hidden = 0;
		count = 0;
		for (std::vector<Meteorite>::iterator m = meteoriteVector.begin(); m != meteoriteVector.end(); m++){
			int result = grid.apply(&(*m), scale);
			if (result == RESULT_SUCCESS){
				m->show();
				count++;
			} else if (result == RESULT_FAILURE) {
				m->hide();
				hidden++;
			} else{
				m->hide();
				hidden++;
				break;
			}
		}
		updated = false;
	}

}

//--------------------------------------------------------------
void myApp::draw(){
	
	ofSetColor(0);
	ofFill();
	char s[128];
	sprintf(s, "Top %d largest meteorites", csv.numRows-hidden);
	ofDrawBitmapString(s, CANVAS_BORDER, CANVAS_BORDER-40);
	sprintf(s, "Hidden: %d", hidden);
	ofDrawBitmapString(s, CANVAS_BORDER, CANVAS_BORDER-20);
	for_each(meteoriteVector.begin(), meteoriteVector.end(), [&](Meteorite m){
		m.draw();
	});
	
}

//--------------------------------------------------------------
void myApp::keyPressed(int key){
	if (key == 'z'){
		scale = max(MIN_SCALE, scale-1.0);
		updated = true;
	} else if(key == 'x'){
		scale = min(MAX_SCALE, scale+1.0);
		updated = true;
	}
}

//--------------------------------------------------------------
void myApp::keyReleased(int key){	
}

//--------------------------------------------------------------
void myApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void myApp::mouseDragged(int x, int y, int button){		
}

//--------------------------------------------------------------
void myApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void myApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void myApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void myApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void myApp::dragEvent(ofDragInfo dragInfo){ 
	
}
