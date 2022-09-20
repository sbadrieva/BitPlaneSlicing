//
//  BitPlaneSlicingClass.hpp
//  OpenCv
//
//  Created by Shokhina Badrieva on 3/22/21.
//  Copyright © 2021 Shokhina Badrieva. All rights reserved.
//

#ifndef BitPlaneSlicingClass_hpp
#define BitPlaneSlicingClass_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "MeanFilteringClass.hpp"
#include "NoiseClass.hpp"
#include "QualityMetricsClass.hpp"
#include "OrderStatisticFiltersClass.hpp"
#include "SharpeningFiltersClass.hpp"

using namespace std;
using namespace cv;


void createBitPlanes(Mat &src,Mat& bitPlane1,Mat& bitPlane2,Mat& bitPlane3,Mat& bitPlane4,Mat& bitPlane5,Mat& bitPlane6,Mat& bitPlane7,Mat& bitPlane8);

void reconstructBitPlanes(Mat &bitPlane1,Mat &bitPlane2,Mat &bitPlane3,Mat &bitPlane4,Mat &bitPlane5,Mat &bitPlane6,Mat &bitPlane7,Mat &bitPlane8,Mat& dst);

void reconstructXORBitplanes(Mat &bitPlane1,Mat &bitPlane2,Mat &bitPlane3,Mat &bitPlane4,Mat &bitPlane5,Mat &bitPlane6,Mat &bitPlane7,Mat &bitPlane8,Mat& dst);

void bitPlaneFilter(Mat &src,Mat& dst);

void compressBitplane(Mat &bitPlane1,Mat &bitPlane2,Mat &bitPlane3,Mat &bitPlane4,Mat &bitPlane5,Mat &bitPlane6,Mat &bitPlane7,Mat &bitPlane8,Mat& dst);

void encryptBitplane(Mat& src,Mat& encryptImg,Mat& dst);

void binaryToDecimal();

void bitPlaneObjectDetection(Mat& frame1, Mat& frame2);



#endif /* BitPlaneSlicingClass_hpp */
