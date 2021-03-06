//#include <cv.h>
//#include <highgui.h>
//
//int main()
//{
//	const char* filename ="D:\\doc\\Stars.jpg";
//	const char* wndname="Paoapo";
//	IplImage* pImage=cvLoadImage(filename);
//	cvShowImage(wndname,pImage);
//	cvWaitKey(0);
//
//	cvReleaseImage(&pImage);
//	cvDestroyWindow(wndname);
//	return 0;
//}

//#include <stdio.h>
//#include <iostream>
//#include <opencv2/opencv.hpp>
//using namespace cv;
//
//// argc 表示命令行输入参数的个数（以空白符分隔）， argv 中
//// 存储了所有的命令行参数
//int main(int argc, char **argv)
//{
//   int i;
//   for (i=0;i<argc;i++)
//   {
//	   printf("Argument %d is %s.\n",i,argv[i]);
//   }
//   system("pause");
//   return 0;
//}

//#include <iostream>
//#include <opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//
//// argc 表示命令行输入参数的个数（以空白符分隔）， argv 中
//// 存储了所有的命令行参数
//int main(int argc, char **argv)
//{
//	printf("Hello!\n");
//
//	Mat img=imread("D:\\doc\\Stars.jpg");
//	Mat gray;
//
//	//creat a red image
//	//Mat M(3,2,CV_8UC3,Scalar(0,0,255));
//	Mat M(2,2,CV_8UC3);//construct an image
//	cout <<"M= " <<endl<<" "<<M<<endl;
//
//	//Matlab-type
//	//单通道图像，元素类型为8U,16S,32F( uchar、 short、 float)
//	Mat Z=Mat::zeros(2,3,CV_8UC1);
//	cout <<"Z= " <<endl<<" "<<Z<<endl;
//
//	uchar value=Z.at<uchar>(1,1);
//	cout<<"Find vaue at Z(1,1) equals "<<value<<endl;
//	Z.at<uchar>(1,2)=128;
//	cout <<"After changes, Z= " <<endl<<" "<<Z<<endl;
//
//	Mat O = Mat::ones(2, 3, CV_32F);
//	cout << "O = " << endl << " " << O << endl;
//
//	Mat E = Mat::eye(2, 3, CV_64F);
//	cout << "E = " << endl << " " << E << endl;
//
//
//
//	//多通道图像，如RGB，图像可以视为二维矩阵
//	//矩阵的元素变成了向量
//	typedef Vec<uchar, 3> Vec3b;
//	Vec3b color; //用 color 变量描述一种 RGB 颜色
//	color[0]=255; //B 分量
//	color[1]=0; //G 分量
//	color[2]=0; //R 分量
//
//	//convert RGB color image to gery image
//	//cv::cvtColor(img,gray,CV_BGR2BGRA);
//
//	system("pause");
//	return 0;
//}

/*Create two images, processing */
//#include <iostream>
//#include "opencv2/opencv.hpp"
//using namespace std;
//using namespace cv;
//int main(int argc, char* argv[])
//{
//	//单通道
//	Mat grayim(600, 800, CV_8UC1);
//	//RGB三通道
//	Mat colorim(600, 800, CV_8UC3);
//
//	//遍历所有像素，并设置像素值
//	for( int i = 0; i < grayim.rows; ++i)
//		for( int j = 0; j < grayim.cols; ++j )
//			grayim.at<uchar>(i,j) = (i+j)%255;
//
//	//遍历所有像素，并设置像素值
//	for( int i = 0; i < colorim.rows; ++i)
//		for( int j = 0; j < colorim.cols; ++j )
//		{
//			Vec3b pixel;
//			pixel[0] = i%255; //Blue
//			pixel[1] = j%255; //Green
//			pixel[2] = 0; //Red
//			//function at lack of efficience
//			colorim.at<Vec3b>(i,j) = pixel;
//		}
//		//显示结果
//		imshow("grayim", grayim);
//		imshow("colorim", colorim);
//		waitKey(0);
//		return 0;
//}

//#include<iostream>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat grayim(600, 800, CV_8UC1);
//	Mat colorim(600, 800, CV_8UC3);
//
//	//遍历所有像素，并设置像素值
//	MatIterator_<uchar>grayit, grayend;
//	for (grayit=grayim.begin<uchar>(),grayend=grayim.end<uchar>();grayit!=grayend;++grayit)
//	{
//		*grayit=rand()%255;
//	}
//
//	//遍历所有像素，并设置像素值
//	typedef Vec<uchar, 3> Vec3b;
//	MatIterator_<Vec3b>colorit, colorend;
//	for (colorit=colorim.begin<Vec3b>(),colorend=colorim.end<Vec3b>();colorit!=colorend;colorit++)
//	{
//		(*colorit)[0]=rand()%255;
//		(*colorit)[1]=rand()%255;
//		(*colorit)[2]=rand()%255;
//	}
//
//	imshow("grayim",grayim);
//	imshow("colorim",colorim);
//	waitKey(0);
//
//	return 0;
//}

#include <iostream>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	Mat grayim(600, 800, CV_8UC1);
	Mat colorim(600, 800, CV_8UC3);

	for (int i=0;i<grayim.rows;i++)
	{
		//获取第 i 行首像素指针
		uchar *p=grayim.ptr<uchar>(i);
		//对第 i 行的每个像素(byte)操作
		for( int j = 0; j < grayim.cols; ++j )
			p[j] = (i+j)%255;
	}

	for (int i=0;i<colorim.rows;++i)
	{
		//获取第 i 行首像素指针
		Vec3b *p=colorim.ptr<Vec3b>(i);
		for (int j=0;j<colorim.cols;++j)
		{
			p[j][0]=i%255;
			p[j][1] = j%255; //Green
			p[j][2] = 0; //Red
		}
	}
 
	//显示结果
	imshow("grayim", grayim);
	imshow("colorim", colorim);
	waitKey(0);

	return 0;
}