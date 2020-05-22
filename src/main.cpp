
#include <opencv2/core/core.hpp>
#include <vector>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "ReceiptCropper.h"

using namespace cv;
using namespace std;

const string src = "/home/nils/eclipse-cpp-ws/receipt-cropper/darkbg.jpg";

int main(int numArgs, char** args )
{
	Mat input = imread(src);
	ReceiptCropper *cropper = new ReceiptCropper(&input);
	Mat* cropped = cropper->getCropped();
	imwrite("result.jpg", *cropped);


	return 0;
}

