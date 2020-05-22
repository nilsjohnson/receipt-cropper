/*
 * ReceiptCropper.h
 *
 *  Created on: May 22, 2020
 *      Author: nils
 */

#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

#ifndef RECEIPTCROPPER_H_
#define RECEIPTCROPPER_H_

// if DEBUG, you may print images for each step of the way.
const string PICTURE_DIR = "/home/nils/eclipse-cpp-ws/receipt-cropper/out/";
const bool DEBUG = true;

class ReceiptCropper {
private:
	// The original receipt
	Mat* receipt;
	// the cropped receipt
	Mat* cropped;
	// values to set the threshold to when finding the receipt
	const int THRESH_BRIGHT = 200;
	const int THRESH_NORMAL = 150;

	// max brightness level before toggle to THRESH_BRIGHT
	const int BRIGHT = 110;
	bool hasBrightEdges(Mat* mat);

	void swap(int &a, int &b);
	static bool compareContourAreas(vector<Point> contour_1, vector<Point> contour_2);
	void crop(Mat* mat, bool brightEdges);
	void setPortrait();
public:
	ReceiptCropper(Mat* receipt);
	Mat* getCropped();

	virtual ~ReceiptCropper();
};

#endif /* RECEIPTCROPPER_H_ */
