#include "opencv2/barcode.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
void main()
{
Ptr<barcode::BarcodeDetector> bardet = makePtr<barcode::BarcodeDetector>("sr.prototxt", "sr.caffemodel"); //如果不使用超分辨率则可以不指定模型路径
Mat input = imread("your file path");
Mat corners; //返回的检测框的四个角点坐标，如果检测到N个条码，那么维度应该是[N][4][2]
std::vector<std::string> decoded_info; //返回的解码结果，如果解码失败，则为空string
std::vector<barcode::BarcodeType> decoded_format; //返回的条码类型，如果解码失败，则为BarcodeType::NONE
bool ok = bardet->detectAndDecode(input, decoded_info, decoded_format, corners);	
}
