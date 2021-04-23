int main() {
 // 读入原图
 Mat img = imread("license.jpg");
 Mat gray_img;
 // 生成灰度图像
 cvtColor(img, gray_img, CV_BGR2GRAY);
 // 得出轮廓
 vector<vector<Point>> contours;
 vector<Vec4i> hierarchy;
 contour(gray_img, contours, hierarchy);
 // 截取车牌
 Point2f (*choose_license)[2] = choose_contour(contours);
 license_gain(choose_license, img);
 delete [] choose_license;
 waitKey(0);
 return 0;
}