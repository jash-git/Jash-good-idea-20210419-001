// 车牌轮廓点
Point2f(*choose_contour(vector<vector<Point>> contours))[2] {
 int size = (int)contours.size();
 int i_init = 0;
 Point2f (*contours_result)[2] = new Point2f[size][2];
 for (int i = 0; i < size; i++){
  // 获取边框数据
  RotatedRect number_rect = minAreaRect(contours[i]);
  Point2f rect_point[4];
  number_rect.points(rect_point);
  float width = rect_point[0].x - rect_point[1].x;
  float height = rect_point[0].y - rect_point[3].y;
  // 用宽高比筛选
  if (width < height) {
   float temp = width;
   width= height;
   height = temp;
  }
  float ratio = width / height;
  if (2.5 < ratio && ratio < 5.5) {
   contours_result[i_init][0] = rect_point[0];
   contours_result[i_init][1] = rect_point[2];
   i_init++;
  }
  
 }
 return contours_result;
}

// 截取车牌区域
int license_gain(Point2f (*choose_license)[2], Mat img) {
 int size = (int)(_msize(choose_license) / sizeof(choose_license[0]));
 // 绘制方框
 for (int i = 0; i < size; i++) {
  if ((int)choose_license[i][0].x > 1 && (int)choose_license[i][0].y > 1) {
   int x = (int)choose_license[i][1].x;
   int y = (int)choose_license[i][1].y;
   int width = (int)(choose_license[i][0].x) - (int)(choose_license[i][1].x);
   int height = (int)(choose_license[i][0].y) - (int)(choose_license[i][1].y);
   Rect choose_rect(x, y, width, height);
   Mat number_img = img(choose_rect);
   rectangle(img, choose_license[i][0], choose_license[i][1], Scalar(0, 0, 255), 2, 1, 0);
   imshow("车牌单独显示" + to_string(i), number_img);
  }
 }
 imshow("绘制方框", img);
 return 0;
}