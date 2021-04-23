#include <iostream>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>

using namespace std;
using namespace cv;

int main() {
 // 读入原图
 Mat img = imread("license.jpg");
 Mat gray_img;
 // 生成灰度图像
 cvtColor(img, gray_img, CV_BGR2GRAY);
 // 在窗口中显示游戏原画
 imshow("原图", img);
 imshow("灰度图", gray_img);
 waitKey(0);
 return 0;
}