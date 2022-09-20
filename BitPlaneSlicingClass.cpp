//
//  BitPlaneSlicingClass.cpp
//  OpenCv
//
//  Created by Shokhina Badrieva on 3/22/21.
//  Copyright © 2021 Shokhina Badrieva. All rights reserved.
//

#include "BitPlaneSlicingClass.hpp"
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



void createBitPlanes(Mat &src,Mat& bitPlane1,Mat& bitPlane2,Mat& bitPlane3,Mat& bitPlane4,Mat& bitPlane5,Mat& bitPlane6,Mat& bitPlane7,Mat& bitPlane8){
    
    
    int val;
    int imgRows = src.size().height;
    int imgCols = src.size().width;
    int size=8; //8 bits in binary number
    int binaryNum[size]; //will hold binary representation of pixel
    
    //initialize bit planes
    bitPlane1=Mat::zeros(imgRows, imgCols, CV_8UC1);//least significant
    bitPlane2=Mat::zeros(imgRows, imgCols, CV_8UC1);
    bitPlane3=Mat::zeros(imgRows, imgCols, CV_8UC1);
    bitPlane4=Mat::zeros(imgRows, imgCols, CV_8UC1);
    bitPlane5=Mat::zeros(imgRows, imgCols, CV_8UC1);
    bitPlane6=Mat::zeros(imgRows, imgCols, CV_8UC1);
    bitPlane7=Mat::zeros(imgRows, imgCols, CV_8UC1);
    bitPlane8=Mat::zeros(imgRows, imgCols, CV_8UC1);//most significant
    
    
    
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            
            //find binary number of value
            val=src.at<uchar>(i,j);
            //cout<<"Val: "<<val<<endl;
            for(int k=7;k>=0;k--){
                int remainder=0;
                remainder=val%2;
                val=val/2;
                binaryNum[k]=remainder;
            }
            /*
             for(int k=0;k<size;k++){
             cout<<binaryNum[k]<<" ";
             }
             cout<<endl;
             */
            
            //fill each bit plane with corresponsing binary digit
            bitPlane1.at<uchar>(i,j)=binaryNum[7];
            val=bitPlane1.at<uchar>(i,j);
            //cout<<"val in bitplane 1 is "<<val<<endl;
            
            
            bitPlane2.at<uchar>(i,j)=binaryNum[6];
            val=bitPlane2.at<uchar>(i,j);
            //cout<<"val in bitplane 2 is "<<val<<endl;
            
            
            bitPlane3.at<uchar>(i,j)=binaryNum[5];
            val=bitPlane3.at<uchar>(i,j);
            //cout<<"val in bitplane 3 is "<<val<<endl;
            
            
            bitPlane4.at<uchar>(i,j)=binaryNum[4];
            val=bitPlane4.at<uchar>(i,j);
            //cout<<"val in bitplane 4 is "<<val<<endl;
            
            
            bitPlane5.at<uchar>(i,j)=binaryNum[3];
            val=bitPlane5.at<uchar>(i,j);
            //cout<<"val in bitplane 5 is "<<val<<endl;
            
            
            bitPlane6.at<uchar>(i,j)=binaryNum[2];
            val=bitPlane6.at<uchar>(i,j);
            //cout<<"val in bitplane 6 is "<<val<<endl;
            
            
            bitPlane7.at<uchar>(i,j)=binaryNum[1];
            val=bitPlane7.at<uchar>(i,j);
            //cout<<"val in bitplane 7 is "<<val<<endl;
            
            
            bitPlane8.at<uchar>(i,j)=binaryNum[0];
            val=bitPlane8.at<uchar>(i,j);
            //cout<<"val in bitplane 8 is "<<val<<endl;
            
            
        }
        
    }
    
    //convert binary digits to black or white value to get binary image
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            if(bitPlane1.at<uchar>(i,j)==0){
                bitPlane1.at<uchar>(i,j)=0;
            }
            if(bitPlane1.at<uchar>(i,j)==1){
                bitPlane1.at<uchar>(i,j)=255;
            }
        }
    }
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            if(bitPlane2.at<uchar>(i,j)==0){
                bitPlane2.at<uchar>(i,j)=0;
            }
            if(bitPlane2.at<uchar>(i,j)==1){
                bitPlane2.at<uchar>(i,j)=255;
            }
        }
    }
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            if(bitPlane3.at<uchar>(i,j)==0){
                bitPlane3.at<uchar>(i,j)=0;
            }
            if(bitPlane3.at<uchar>(i,j)==1){
                bitPlane3.at<uchar>(i,j)=255;
            }
        }
    }
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            if(bitPlane4.at<uchar>(i,j)==0){
                bitPlane4.at<uchar>(i,j)=0;
            }
            if(bitPlane4.at<uchar>(i,j)==1){
                bitPlane4.at<uchar>(i,j)=255;
            }
        }
    }
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            if(bitPlane5.at<uchar>(i,j)==0){
                bitPlane5.at<uchar>(i,j)=0;
            }
            if(bitPlane5.at<uchar>(i,j)==1){
                bitPlane5.at<uchar>(i,j)=255;
            }
        }
    }
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            if(bitPlane6.at<uchar>(i,j)==0){
                bitPlane6.at<uchar>(i,j)=0;
            }
            if(bitPlane6.at<uchar>(i,j)==1){
                bitPlane6.at<uchar>(i,j)=255;
            }
        }
    }
    
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            if(bitPlane7.at<uchar>(i,j)==0){
                bitPlane7.at<uchar>(i,j)=0;
            }
            if(bitPlane7.at<uchar>(i,j)==1){
                bitPlane7.at<uchar>(i,j)=255;
            }
        }
    }
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            if(bitPlane8.at<uchar>(i,j)==0){
                bitPlane8.at<uchar>(i,j)=0;
            }
            if(bitPlane8.at<uchar>(i,j)==1){
                bitPlane8.at<uchar>(i,j)=255;
            }
        }
    }

}

void reconstructBitPlanes(Mat &bitPlane1,Mat &bitPlane2,Mat &bitPlane3,Mat &bitPlane4,Mat &bitPlane5,Mat &bitPlane6,Mat &bitPlane7,Mat &bitPlane8,Mat& dst){
    
    int size=8;
    int binary[size];
    int imgRows = bitPlane1.size().height;
    int imgCols = bitPlane1.size().width;
    
    dst=Mat::zeros(imgRows, imgCols, CV_8UC1);
    
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            int val;
            val=bitPlane1.at<uchar>(i,j)/255;
            binary[7]=val;
            val=bitPlane2.at<uchar>(i,j)/255;
            binary[6]=val;
            val=bitPlane3.at<uchar>(i,j)/255;
            binary[5]=val;
            val=bitPlane4.at<uchar>(i,j)/255;
            binary[4]=val;
            val=bitPlane5.at<uchar>(i,j)/255;
            binary[3]=val;
            val=bitPlane6.at<uchar>(i,j)/255;
            binary[2]=val;
            val=bitPlane7.at<uchar>(i,j)/255;
            binary[1]=val;
            val=bitPlane8.at<uchar>(i,j)/255;
            binary[0]=val;
            
            /*
             for (int j=0;j<size;j++){
             cout<<binary[j]<<" ";
             
             }
             cout<<endl;
             */
            
            int sum=0;
            sum+=(binary[0]*pow(2,7))+(binary[1]*pow(2,6))+(binary[2]*pow(2,5))+(binary[3]*pow(2,4))+(binary[4]*pow(2,3))+(binary[5]*pow(2,2))+(binary[6]*pow(2,1))+(binary[7]*pow(2,0));
            
            //cout<<"decimal: "<<sum<<endl;
            
            dst.at<uchar>(i,j)=sum;
            
            
            
        }
    }
}


//function used to only add most significant bit planes
void reconstructXORBitplanes(Mat &bitPlane1,Mat &bitPlane2,Mat &bitPlane3,Mat &bitPlane4,Mat &bitPlane5,Mat &bitPlane6,Mat &bitPlane7,Mat &bitPlane8,Mat& dst){
    int size=8;
    int binary[size];
    int imgRows = bitPlane1.size().height;
    int imgCols = bitPlane1.size().width;
    
    dst=Mat::zeros(imgRows, imgCols, CV_8UC1);
    
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            int val;
            val=bitPlane1.at<uchar>(i,j)/255;
            binary[7]=val;
            val=bitPlane2.at<uchar>(i,j)/255;
            binary[6]=val;
            val=bitPlane3.at<uchar>(i,j)/255;
            binary[5]=val;
            val=bitPlane4.at<uchar>(i,j)/255;
            binary[4]=val;
            val=bitPlane5.at<uchar>(i,j)/255;
            binary[3]=val;
            val=bitPlane6.at<uchar>(i,j)/255;
            binary[2]=val;
            val=bitPlane7.at<uchar>(i,j)/255;
            binary[1]=val;
            val=bitPlane8.at<uchar>(i,j)/255;
            binary[0]=val;
            
            /*
             for (int j=0;j<size;j++){
             cout<<binary[j]<<" ";
             
             }
             cout<<endl;
             */
            
            int sum=0;
            sum+=(binary[0]*pow(2,7))+(binary[1]*pow(2,6))+(binary[2]*pow(2,5))+(0*pow(2,4))+(0*pow(2,3))+(0*pow(2,2))+(0*pow(2,1))+(0*pow(2,0));
            
            //cout<<"decimal: "<<sum<<endl;
            
            dst.at<uchar>(i,j)=sum;
            
            
            
        }
    }
}


void bitPlaneFilter(Mat &src,Mat& dst){
    
    Mat bitPlane1,bitPlane2,bitPlane3,bitPlane4,bitPlane5,bitPlane6,bitPlane7,bitPlane8;
    int size=8;
    int binary[size];
    int imgRows = src.size().height;
    int imgCols = src.size().width;
    
    createBitPlanes(src, bitPlane1, bitPlane2, bitPlane3, bitPlane4, bitPlane5, bitPlane6, bitPlane7, bitPlane8);
    dst=Mat::zeros(imgRows, imgCols, CV_8UC1);

    
    
    
    medianFilter(bitPlane1, bitPlane1, 5);
    medianFilter(bitPlane2, bitPlane2, 5);
    medianFilter(bitPlane3, bitPlane3, 5);
    medianFilter(bitPlane4, bitPlane4, 5);
    medianFilter(bitPlane5, bitPlane5, 5);
    medianFilter(bitPlane6, bitPlane6, 5);
    medianFilter(bitPlane7, bitPlane7, 5);
    medianFilter(bitPlane8, bitPlane8, 5);
    
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            int val;
            val=bitPlane1.at<uchar>(i,j)/255;
            binary[7]=val;
            val=bitPlane2.at<uchar>(i,j)/255;
            binary[6]=val;
            val=bitPlane3.at<uchar>(i,j)/255;
            binary[5]=val;
            val=bitPlane4.at<uchar>(i,j)/255;
            binary[4]=val;
            val=bitPlane5.at<uchar>(i,j)/255;
            binary[3]=val;
            val=bitPlane6.at<uchar>(i,j)/255;
            binary[2]=val;
            val=bitPlane7.at<uchar>(i,j)/255;
            binary[1]=val;
            val=bitPlane8.at<uchar>(i,j)/255;
            binary[0]=val;
            
            /*
             for (int j=0;j<size;j++){
             cout<<binary[j]<<" ";
             
             }
             cout<<endl;
             */
            
            int sum=0;
            sum+=(binary[0]*pow(2,7))+(binary[1]*pow(2,6))+(binary[2]*pow(2,5))+(binary[3]*pow(2,4))+(binary[4]*pow(2,3))+(binary[5]*pow(2,2))+(binary[6]*pow(2,1))+(binary[7]*pow(2,0));
            
            //cout<<"decimal: "<<sum<<endl;
            
            dst.at<uchar>(i,j)=sum;
            
            
            
        }
    }
}

void compressBitplane(Mat &bitPlane1,Mat &bitPlane2,Mat &bitPlane3,Mat &bitPlane4,Mat &bitPlane5,Mat &bitPlane6,Mat &bitPlane7,Mat &bitPlane8,Mat& dst){
    
    int size=8;
    int binary[size];
    int imgRows = bitPlane1.size().height;
    int imgCols = bitPlane1.size().width;
    
    dst=Mat::zeros(imgRows, imgCols, CV_8UC1);
    
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            int val;
            val=bitPlane1.at<uchar>(i,j)/255;
            binary[7]=val;
            val=bitPlane2.at<uchar>(i,j)/255;
            binary[6]=val;
            val=bitPlane3.at<uchar>(i,j)/255;
            binary[5]=val;
            val=bitPlane4.at<uchar>(i,j)/255;
            binary[4]=val;
            val=bitPlane5.at<uchar>(i,j)/255;
            binary[3]=val;
            val=bitPlane6.at<uchar>(i,j)/255;
            binary[2]=val;
            val=bitPlane7.at<uchar>(i,j)/255;
            binary[1]=val;
            val=bitPlane8.at<uchar>(i,j)/255;
            binary[0]=val;
            
            /*
             for (int j=0;j<size;j++){
             cout<<binary[j]<<" ";
             
             }
             cout<<endl;
             */
            
            int sum=0;
            sum+=(binary[0]*pow(2,7))+(binary[1]*pow(2,6))+(binary[2]*pow(2,5))+(binary[3]*pow(2,4))+(binary[4]*pow(2,3))+(0*pow(2,2))+(0*pow(2,1))+(0*pow(2,0));
            
            //cout<<"decimal: "<<sum<<endl;
            
            dst.at<uchar>(i,j)=sum;
            
            
            
        }
    }
}


void encryptBitplane(Mat& src,Mat& encryptImg,Mat& dst){
    Mat bitPlane1,bitPlane2,bitPlane3,bitPlane4,bitPlane5,bitPlane6,bitPlane7,bitPlane8;
    createBitPlanes(src,bitPlane1,bitPlane2,bitPlane3,bitPlane4,bitPlane5,bitPlane6,bitPlane7,bitPlane8);
    int size=8;
    int binary[size];
    int imgRows = src.size().height;
    int imgCols = src.size().width;
    Mat resizedImg;
    resize(encryptImg,resizedImg,Size(imgCols,imgRows));

    //make img binary
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            
            //int val=resizedImg.at<uchar>(i,j);
            //cout<<"val in ecrypted img: "<<val<<endl;
            
            if(resizedImg.at<uchar>(i,j)>=100){
                resizedImg.at<uchar>(i,j)=1;
            }
            else{
                resizedImg.at<uchar>(i,j)=0;
            }
        }
    }
    
    dst=Mat::zeros(imgRows, imgCols, CV_8UC1);
    
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            int val;
            val=resizedImg.at<uchar>(i,j);
            binary[7]=val;
            val=bitPlane2.at<uchar>(i,j)/255;
            binary[6]=val;
            val=bitPlane3.at<uchar>(i,j)/255;
            binary[5]=val;
            val=bitPlane4.at<uchar>(i,j)/255;
            binary[4]=val;
            val=bitPlane5.at<uchar>(i,j)/255;
            binary[3]=val;
            val=bitPlane6.at<uchar>(i,j)/255;
            binary[2]=val;
            val=bitPlane7.at<uchar>(i,j)/255;
            binary[1]=val;
            val=bitPlane8.at<uchar>(i,j)/255;
            binary[0]=val;
            
            /*
             for (int j=0;j<size;j++){
             cout<<binary[j]<<" ";
             
             }
             cout<<endl;
             */
            
            int sum=0;
            sum+=(binary[0]*pow(2,7))+(binary[1]*pow(2,6))+(binary[2]*pow(2,5))+(binary[3]*pow(2,4))+(binary[4]*pow(2,3))+(binary[5]*pow(2,2))+(binary[6]*pow(2,1))+(binary[7]*pow(2,0));
            
            //cout<<"decimal: "<<sum<<endl;
            
            dst.at<uchar>(i,j)=sum;
            
            
            
        }
    }
}

void binaryToDecimal(){
    int binary[8]={0,0,0,0,1,1,1,1};
    int sum=0;
    int val;
    for (int j=0;j<8;j++){
        cout<<binary[j]<<endl;
        if (binary[j]==0){
            continue;
        }
        else{
            val=pow(2,j);
            sum+=val;
        }
        
    }
    cout<<sum<<endl;
}



void bitPlaneObjectDetection(Mat& frame1, Mat& frame2){
    
    
    int imgRows = frame1.size().height;
    int imgCols = frame1.size().width;
    resize(frame2, frame2, Size(imgCols,imgRows));
    Mat b1,b2,b3,b4,b5,b6,b7,b8,b11,b22,b33,b44,b55,b66,b77,b88,b111,b222,b333,b444,b555,b666,b777,b888;
    b111=Mat::zeros(imgRows, imgCols, CV_8UC1);
    b222=Mat::zeros(imgRows, imgCols, CV_8UC1);
    b333=Mat::zeros(imgRows, imgCols, CV_8UC1);
    b444=Mat::zeros(imgRows, imgCols, CV_8UC1);
    b555=Mat::zeros(imgRows, imgCols, CV_8UC1);
    b666=Mat::zeros(imgRows, imgCols, CV_8UC1);
    b777=Mat::zeros(imgRows, imgCols, CV_8UC1);
    b888=Mat::zeros(imgRows, imgCols, CV_8UC1);
    
    createBitPlanes(frame1, b1, b2, b3, b4, b5, b6, b7, b8);
    createBitPlanes(frame2, b11,b22 ,b33,b44,b55 ,b66,b77,b88);
    imshow("b1",b1);
    imshow("b2",b2);
    imshow("b3",b3);
    imshow("b4",b4);
    imshow("b5",b5);
    imshow("b6",b6);
    imshow("b7",b7);
    imshow("b8",b8);
    
    imshow("b11",b11);
    imshow("b22",b22);
    imshow("b33",b33);
    imshow("b44",b44);
    imshow("b55",b55);
    imshow("b66",b66);
    imshow("b77",b77);
    imshow("b88",b88);
    
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            int val1=b1.at<uchar>(i,j);
            int val2=b11.at<uchar>(i,j);
            int val3=val1^val2;
            b111.at<uchar>(i,j)=val3;
        }
    }
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            int val1=b2.at<uchar>(i,j);
            int val2=b22.at<uchar>(i,j);
            int val3=val1^val2;
            b222.at<uchar>(i,j)=val3;
        }
    }
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            int val1=b3.at<uchar>(i,j);
            int val2=b33.at<uchar>(i,j);
            int val3=val1^val2;
            b333.at<uchar>(i,j)=val3;
        }
    }
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            int val1=b4.at<uchar>(i,j);
            int val2=b44.at<uchar>(i,j);
            int val3=val1^val2;
            b444.at<uchar>(i,j)=val3;
        }
    }
    
    
    
    
    
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            int val1=b5.at<uchar>(i,j);
            int val2=b55.at<uchar>(i,j);
            int val3=val1^val2;
            b555.at<uchar>(i,j)=val3;
        }
    }
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            int val1=b6.at<uchar>(i,j);
            int val2=b66.at<uchar>(i,j);
            int val3=val1^val2;
            b666.at<uchar>(i,j)=val3;
        }
    }
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            int val1=b7.at<uchar>(i,j);
            int val2=b77.at<uchar>(i,j);
            int val3=val1^val2;
            b777.at<uchar>(i,j)=val3;
        }
    }
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            int val1=b8.at<uchar>(i,j);
            int val2=b88.at<uchar>(i,j);
            int val3=val1^val2;
            b888.at<uchar>(i,j)=val3;
        }
    }
    
    Mat reconstructedXorImg;
    //reconstructs with only four main bitplanes
    reconstructXORBitplanes(b111,b222,b333,b444,b555,b666,b777,b888,reconstructedXorImg);
    imshow("reconstrcuted XOR image with weights:",reconstructedXorImg);
    
    
    Mat medianFilteredImg;
    medianFilter(reconstructedXorImg, medianFilteredImg,3);
    imshow("xor filtered img: ",medianFilteredImg);
    
    
    //make img binary
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            
            //int val=resizedImg.at<uchar>(i,j);
            //cout<<"val in ecrypted img: "<<val<<endl;
            
            if(medianFilteredImg.at<uchar>(i,j)>=100){
                medianFilteredImg.at<uchar>(i,j)=255;
            }
            else{
                medianFilteredImg.at<uchar>(i,j)=0;
            }
        }
    }
    imshow("reconstrcuted XOR image binary:",medianFilteredImg);
    
    
}



