#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include "gui.h"

#include "seam_carv.h"
#include "seam_carv_random.h"

using namespace cv;
using namespace std;







int main()
{
	
//	init_gui();

	Mat A = imread("Broadway_tower_edit.jpg");
	namedWindow("images");
	imshow("images", A);	waitKey();
	Mat I;
	cvtColor(A, I, CV_RGB2GRAY);
	namedWindow("images");
	imshow("images", I);	waitKey();
	imshow("images", toGrad(I));   waitKey();
    
	imshow("images", show_all_path(I));   waitKey();
	imshow("images", A);	waitKey();
	Mat resize_A;
	resize_seam_carv_random(A, resize_A, 0.95, 1,1);
	imshow("carved image", resize_A);	waitKey();
    //dsc(I);

}
