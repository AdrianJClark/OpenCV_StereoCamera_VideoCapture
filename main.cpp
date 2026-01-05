#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "CaptureStereo.h"

void main() {
	bool running = true;

	CameraStereo *camera = new CameraStereo();

	CvVideoWriter *vwLeft = cvCreateVideoWriter("leftVideo.avi", -1, 25, cvGetSize(camera->getLeftFrame()));
	CvVideoWriter *vwRight = cvCreateVideoWriter("rightVideo.avi", -1, 25, cvGetSize(camera->getRightFrame()));
	
	while (running) {
		IplImage *imLeft = camera->getLeftFrame();
		IplImage *imRight = camera->getRightFrame();

		cvShowImage("Left Image", imLeft);
		cvShowImage("Right Image", imRight);

		cvWriteFrame(vwLeft, imLeft);
		cvWriteFrame(vwRight, imRight);

		switch (cvWaitKey(1)) {
			case 27:
				running = false;
		}

		cvReleaseImage(&imLeft); cvReleaseImage(&imRight);
	}

	cvReleaseVideoWriter(&vwLeft);
	cvReleaseVideoWriter(&vwRight);
	
	delete camera;
}
