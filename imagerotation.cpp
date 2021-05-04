#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat rotate(Mat srcimg, double angle)   //rotate function returning mat object with parametres imagefile and angle    
{
    Mat oprimg;      //Mat object for output image file
    Point2f pt((srcimg.cols-1) / 2.0, (srcimg.rows-1) / 2.0);          //point from where to rotate    
    Mat r = getRotationMatrix2D(pt, angle, 1.0);      //Mat object for storing after rotation
    Rect2f bbox = RotatedRect(Point2f(), srcimg.size(), angle).boundingRect2f();        // determine bounding rectangle, center not relevant



     // adjust transformation matrix

    r.at<double>(0, 2) += bbox.width / 2.0 - srcimg.cols / 2.0;
    r.at<double>(1, 2) += bbox.height / 2.0 - srcimg.rows / 2.0;
    warpAffine(srcimg, oprimg, r, bbox.size()); ///applie an affine transforation to image.
    return oprimg;         //returning Mat object for output image file
}

int main()
{
    Mat srcimg = imread("C:\\Users\\itsma\\OneDrive\\Pictures\\walli\\black-panther.jpg",IMREAD_UNCHANGED);           //reading image file in mat object

    Mat oprimg;      //Mat object for output image file
    double n;       //double variable for input angle
    cout << "enter angle";      //message for user
    cin >> n;                   //reading input angle
    oprimg = rotate(srcimg, n);       //rotating image with n degree angle
    namedWindow("input",WINDOW_NORMAL);
    imshow("input", srcimg);       //displaying input image file
    namedWindow("output", WINDOW_NORMAL);
    imshow("output", oprimg);         //displaying output image file
    waitKey(0);                     //to exit press escape
    return 0;
}
