// 得出轮廓
bool contour(Mat image, vector<vector<Point>> &contours, vector<Vec4i> &hierarchy) {
 Mat img_gau, img_open, img_seg, img_edge;
 // 高斯模糊
 GaussianBlur(image, img_gau, Size(7, 7), 0, 0);
 // 开运算
 Mat element = getStructuringElement(MORPH_RECT, Size(23, 23));
 morphologyEx(img_gau, img_open, MORPH_OPEN, element);
 addWeighted(img_gau, 1, img_open, -1, 0, img_open);
 // 阈值分割
 threshold(img_open, img_seg, 0, 255, THRESH_BINARY + THRESH_OTSU);
 // 边缘检测
 Canny(img_seg, img_edge, 200, 100);
 element = getStructuringElement(MORPH_RECT, Size(22, 22));
 morphologyEx(img_edge, img_edge, MORPH_CLOSE, element);
 morphologyEx(img_edge, img_edge, MORPH_OPEN, element);
 findContours(img_edge, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
 return true;
}