//
// Created by 邓昊晴 on 14/6/2020.
//

#ifndef YOLOV5_H
#define YOLOV5_H

#include "ncnn/net.h"

namespace cv{
    typedef struct{
        int width;
        int height;
    }Size;
}

typedef struct {
    std::string name;
    int stride;
    std::vector<cv::Size> anchors;
}YoloLayerData;

typedef struct BoxInfo {
    float x1;
    float y1;
    float x2;
    float y2;
    float score;
    int label;
} BoxInfo;

class YoloV5 {
public:
    YoloV5(AAssetManager* mgr, const char* param, const char* bin);
    ~YoloV5();
    std::vector<BoxInfo> detect(JNIEnv* env, jobject image);
    std::vector<std::string> labels{"r", "g", "b"};
private:
    static std::vector<BoxInfo> decode_infer(ncnn::Mat &data,const cv::Size& frame_size);
    ncnn::Net* Net;
    int input_size = 416;
public:
    static YoloV5 *detector;
    static bool hasGPU;
};


#endif //YOLOV5_H
