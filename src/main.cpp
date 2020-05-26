#include <vector>
#include <iostream>
#include <string>
#include <dirent.h>


#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

#include "ReceiptCropper.h"

using namespace cv;
using namespace std;

const char* TEST_DIR = "./test-in/";
const string OUT_DIR = "./test-out/";


int main(int numArgs, char** args )
{
	// the root for all the debugging images
	//string debugRoot = debugDir;

	if (auto dir = opendir(TEST_DIR))
	{
	    while (auto file = readdir(dir))
	    {
	        if (!file->d_name || file->d_name[0] == '.')
	        {
	        	// Skip everything that starts with a dot
	        	continue;
	        }

	        cout << "processing " << file->d_name << endl;
	        Mat input = imread(string(TEST_DIR) + string(file->d_name));

	        ReceiptCropper* cropper = new ReceiptCropper(&input);
	        Mat* output = cropper->getCropped();

	        string fileName(file->d_name);
	        imwrite(OUT_DIR + fileName, *output);

	        delete cropper;
	    }
	    closedir(dir);
	}

	return 0;
}


