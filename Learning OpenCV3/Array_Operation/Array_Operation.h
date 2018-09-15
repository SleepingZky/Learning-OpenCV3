#ifndef __ARRAY_OPERATIONS__
#define __ARRAY_OPERATIONS__

#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>

using namespace std;

namespace test_array_operations {

	void test_addWeighted() {

		cv::Mat m1 = cv::imread("D:\\DigitalImageProcess\\example.jpg", 2 | 4);
		cv::Mat m2 = cv::imread("D:\\DigitalImageProcess\\logo.jpg", 2 | 4);
		cv::Mat Roi = m1(cv::Rect(cv::Point(100, 200), m2.size()));
		cv::namedWindow("Result", cv::WINDOW_AUTOSIZE);

		cv::addWeighted(Roi, 0.3, m2, 0.7, 0, Roi);//混合完毕 替代原图像

		cv::imshow("Result", m1);

		cv::waitKey(0);
		cv::destroyWindow("Result");
	}

	void test_bitwise() {

		cv::Mat m1 = cv::imread("D:\\DigitalImageProcess\\example.jpg", 2 | 4);
		cv::Mat m2 = cv::imread("D:\\DigitalImageProcess\\logo.jpg", 2 | 4);
		cv::Mat m3;
		if (m1.empty() || m2.empty()) {
			cout << "picture is empty" << endl;
		}

		cv::namedWindow("Result", cv::WINDOW_AUTOSIZE);

		cv::Mat Roi1 = m1(cv::Rect(cv::Point(100, 200), m2.size()));
		cv::Mat Roi2 = m1(cv::Rect(cv::Point(500, 200), m2.size()));
		cv::Mat Roi3 = m1(cv::Rect(cv::Point(100, 800), m2.size()));
		cv::Mat Roi4 = m1(cv::Rect(cv::Point(500, 800), m2.size()));

		cv::bitwise_and(Roi1, m2, Roi1);
		cv::bitwise_or(Roi2, m2, Roi2);
		cv::bitwise_xor(Roi3, m2, Roi3);
		cv::bitwise_not(Roi4, Roi4);


		cv::imshow("Result", m1);
		cv::waitKey(0);
		cv::destroyWindow("Result");
	}

	void test_calcCovarMatrix() {

		cv::Mat m(6, 1, CV_8UC1);
		cv::randu(m, 1, 255);
		cv::Mat covar, mean;

		cout << "m:\n" << m << endl;


		cv::calcCovarMatrix(m, covar, mean, cv::COVAR_ROWS | cv::COVAR_NORMAL);

		cout << "covarians : \n" << covar << endl;
		cout << "mean : \n" << mean << endl;
	}

	void test_cartToPolar() {

		cv::Mat m1(1, 6, CV_32F);//不能用整形 short int， unsigned 也不行
		cv::Mat m2(1, 6, CV_32F);
		cv::Mat magnitude, angle;

		cv::randu(m1, 1, 255);
		cv::randu(m2, 1, 255);

		cv::cartToPolar(m1, m2, magnitude, angle);

		cout << "m1:\n" << m1 << endl;
		cout << "m2:\n" << m2 << endl;
		cout << "magnitude:\n" << magnitude << endl;
		cout << "angle:\n" << angle << endl;

	}

	void test_completeSymm() {

		cv::Mat m1(3, 3, CV_8UC1);
		cv::randu(m1, 1, 255);

		cout << "m1:\n" << m1 << endl;

		cv::completeSymm(m1);

		cout << "m1:\n" << m1 << endl;
	}

	void test_dct() {

		//cv::Mat all(1000, 1000, CV_32FC3,cv::Scalar::all(0));
		cv::Mat m1 = cv::imread("D:\\DigitalImageProcess\\example.jpg", 2 | 4);
		//cv::Mat Roi = all(cv::Rect(cv::Point(20, 20), m1.size()))

		int height = m1.rows;
		int width = m1.cols;

		cv::Mat m2(m1.size(), CV_8UC3);
		cv::cvtColor(m1, m2, CV_BGR2YUV);

		cv::Mat result(m1.size(), CV_64FC3);

		vector<cv::Mat> channels;
		cv::split(m2, channels);

		cv::Mat b = channels.at(0); cv::imshow("B", b);//拆分成了三个独立的array
		cv::Mat g = channels.at(1); cv::imshow("G", g);
		cv::Mat r = channels.at(2); cv::imshow("R", r);

		cv::Mat DCTY(m1.size(), CV_64FC1);
		cv::Mat DCTU(m1.size(), CV_64FC1);
		cv::Mat DCTV(m1.size(), CV_64FC1);

		cv::dct(cv::Mat_<double>(b), DCTY);
		cv::dct(cv::Mat_<double>(g), DCTU);
		cv::dct(cv::Mat_<double>(r), DCTV);

		channels.at(0) = cv::Mat_<uchar>(DCTY);
		channels.at(1) = cv::Mat_<uchar>(DCTU);
		channels.at(2) = cv::Mat_<uchar>(DCTV);

		cv::merge(channels, result);

		cv::imshow("result", result);

		cv::waitKey(0);

		cv::destroyAllWindows();
	}

	void test_cvtColor() {

		cv::Mat m1(3, 3, CV_8UC3, cv::Scalar::all(0));

		cv::randu(m1, 1, 50);

		cout << "m1: \n" << m1 << endl;

		cv::cvtColor(m1, m1, cv::COLOR_BGR2GRAY);

		cout << "m1: \n" << m1 << endl;

	}

	void test_eigen() {//计算特征值和特征向量

		cv::Mat m1(3, 3, CV_32FC1, cv::Scalar::all(0));

		cv::randu(m1, 1.0, 10.0);

		cv::Mat m2;

		cv::eigen(m1, m2);

		cout << "m1 : \n" << m1 << endl;
		cout << "m2 : \n" << m2 << endl;
	}

	void test_flip() {

		cv::Mat m1(3, 3, CV_32FC1, cv::Scalar::all(0));

		cv::randu(m1, 1.0, 10.0);

		cv::Mat m2;
		cv::Mat m3;
		cv::Mat m4;

		cv::flip(m1, m2, 0);
		cv::flip(m1, m3, 1);
		cv::flip(m1, m4, -1);

		cout << "m1 : \n" << m1 << endl;
		cout << "m2 : \n" << m2 << endl;
		cout << "m3 : \n" << m3 << endl;
		cout << "m4 : \n" << m4 << endl;
	}

	void test_getConvertElem(){

		cv::Mat m(6, 6, CV_8UC1);
		cv::randu(m, 1, 10);

		

		cout << "m:\n" << m << endl;
	}

	void test_invert(){


		cv::Mat m1(5, 5, CV_32FC1);
		cv::Mat result;

		cv::randu(m1, 1.0, 10.0);
		double n;
		n = cv::invert(m1, result);
		cout << "m1 : \n" << m1 << endl;
		cout << "n : " << n << endl;

		n = cv::invert(m1, result, cv::DECOMP_SVD);
		cout << "m1 : \n" << m1 << endl;
		cout << "n : " << n << endl;

		n = cv::invert(m1, result,cv::DECOMP_CHOLESKY);
		cout << "m1 : \n" << m1 << endl;
		cout << "n : " << n << endl;
	}

	void test_Mahalanobis(){
		//The vector vec1 is presumed to be the point x, 
		//the vector vec2 is taken to be the distribution’s mean.
		//That matrix icovar is the inverse covariance
		cv::Mat m1(3, 1, CV_32FC1);
		cv::Mat group(3, 50, CV_32FC1);
		cv::Mat mean;
		cv::Mat covariance;

		cv::randu(m1, 1.0, 10.0);
		cv::randu(group, 10.0, 15.0);
		cv::calcCovarMatrix(group, covariance, mean, cv::COVAR_COLS | cv::COVAR_NORMAL);
		cv::invert(covariance, covariance, cv::DECOMP_SVD);

		cout << "m1 : \n" << m1 << endl;
		cout << "mean : \n" << mean << endl;
		cout << "covariance : \n" << covariance << endl;

		double result;
		result = cv::Mahalanobis(m1, mean, covariance);
		cout << "result : \n" << result << endl;
	}

	void test_minMaxIdx(){
		//location needs at least two coordinates
		cout << "test_minMaxIdx................" << endl;

		//cv::Vec<int, 10> source;
		cv::Mat source(4, 10, CV_16UC1);
		cv::randu(source, 10, 40);

		double minVal=0.0, maxVal=0.0;
		int minIdx[2] = { 0 };
		int maxIdx[2] = { 0 };

		cv::minMaxIdx(source, &minVal, &maxVal, minIdx, maxIdx);

		cout << "source:\n" << source << endl;
		cout << "minval: " << minVal << endl;
		cout << "maxval: " << maxVal << endl;
		cout << "minIdx: " << minIdx[0] << endl;
		cout << "minIdx: " << minIdx[1] << endl;
		cout << "maxIdx: " << maxIdx[0] << endl;
		cout << "maxIdx: " << maxIdx[1] << endl;

		//不明白为什么会报错
		//stack around variable was corrupted？？？
		//堆栈内存出错了？
		//因为所有的location 至少是二维的 用一维的int 去接受会出错
	}

	void test_minMaxLoc(){
		//When a single-dimensional array is supplied, the arrays for the
		//locations must still have memory allocated for two integers.This is
		//because cv::minMaxLoc() uses the convention that even a singledimensional
		//array is, in essence, an N×1 matrix.The second value
		//returned will always be 0 for each location in this case.
		//only for 2d
	}
	void test_mixChannels(){
		//Unlike most other functions in the post–version 2.1 library,
		//cv::mixChannels() does not allocate the output arrays.They must
		//be preallocated and have the same size and dimensionality as the
		//input arrays.

		
		cv::Mat source(3, 3, CV_16UC4, cv::Scalar::all(0));

		cv::randu(source, 1, 20);

		cv::Mat dest1(source.size(), CV_16UC3);
		cv::Mat dest2(source.size(), CV_16UC1);
		vector<cv::Mat> dest;
		dest.push_back(dest1);
		dest.push_back(dest2);

		int pair[8] = { 0, 2, 1, 1, 2, 0, 3, 3 };
		//channels number is from 0!! not 1
		cv::mixChannels(source, dest, pair, 4);

		cout << "source:\n" << source << endl;
		cout << "dest1:\n" << dest1 << endl;
		cout << "dest2:\n" << dest2 << endl;
	}

	void test_mulSpectrums(){
		//too complicated for me now
	}

	void test_norm(){

		cv::Mat src1(1, 3, CV_16SC1,cv::Scalar::all(1));

		cv::randu(src1, -10, 10);
		double result;
		result = cv::norm(src1, cv::NORM_INF);

		cout << "src1 :\n" << src1 << endl;
		cout << result << endl;
	}
}

#endif
