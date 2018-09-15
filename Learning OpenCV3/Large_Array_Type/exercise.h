#ifndef __EXERCISE_FOUR__
#define __EXERCISE_FOUR__

#include<iostream>
#include<opencv2/opencv.hpp>
#include<time.h>

using namespace std;

namespace exercise_one {

	void typewriter(cv::Mat& m, const char& number) {

		cv::Mat all(m, cv::Rect(cv::Point(1, 1), cv::Size(8, 18)));
		all += 255;
		switch (number)
		{
			case '0':{
				cv::Mat blank(m, cv::Rect(cv::Point(3, 3), cv::Size(4, 14)));
				blank -= 255;
				break; 
			}
			case '1': {
				cv::Mat blank(m, cv::Rect(cv::Point(1, 1), cv::Size(6, 18)));
				blank -= 255;
				break;
			}
			case '2': {
				cv::Mat blank1(m, cv::Rect(cv::Point(1, 3), cv::Size(6, 6)));
				cv::Mat blank2(m, cv::Rect(cv::Point(3, 11), cv::Size(6, 6)));
				blank1 -= 255;
				blank2 -= 255;
				break;
			}
			case '3': {
				cv::Mat blank1(m, cv::Rect(cv::Point(1, 3), cv::Size(6, 6)));
				cv::Mat blank2(m, cv::Rect(cv::Point(1, 11), cv::Size(6, 6)));
				blank1 -= 255;
				blank2 -= 255; 
				break;
			}
			case '4': {
				cv::Mat blank1(m, cv::Rect(cv::Point(3, 1), cv::Size(4, 8)));
				cv::Mat blank2(m, cv::Rect(cv::Point(1, 11), cv::Size(6, 8)));
				blank1 -= 255;
				blank2 -= 255; 
				break;
			}
			case '5': {
				cv::Mat blank1(m, cv::Rect(cv::Point(3, 3), cv::Size(6, 6)));
				cv::Mat blank2(m, cv::Rect(cv::Point(1, 11), cv::Size(6, 6)));
				blank1 -= 255;
				blank2 -= 255; 
				break;
			}
			case '6': {
				cv::Mat blank1(m, cv::Rect(cv::Point(3, 3), cv::Size(6, 6)));
				cv::Mat blank2(m, cv::Rect(cv::Point(3, 11), cv::Size(4, 6)));
				blank1 -= 255;
				blank2 -= 255; 
				break;
			}
			case '7': {
				cv::Mat blank(m, cv::Rect(cv::Point(1, 3), cv::Size(6, 16)));
				blank -= 255;
				break;
			}
			case '8': {
				cv::Mat blank1(m, cv::Rect(cv::Point(3, 3), cv::Size(4, 6)));
				cv::Mat blank2(m, cv::Rect(cv::Point(3, 11), cv::Size(4, 6))); 
				blank1 -= 255;
				blank2 -= 255; 
				break;
			}
			case '9': {
				cv::Mat blank1(m, cv::Rect(cv::Point(3, 3), cv::Size(4, 7)));
				cv::Mat blank2(m, cv::Rect(cv::Point(1, 12), cv::Size(6, 7))); 
				blank1 -= 255;
				blank2 -= 255; 
				break;
			}
			case '\b': {
				all -= 255;
				break;
			}
			case '\t': {
				cv::Mat blank(m, cv::Rect(cv::Point(1, 1), cv::Size(8, 16)));
				blank -= 255; 
				break;
			}
			default:
				break;
		}
	}
	void convert_color(const cv::Mat& m, cv::Mat& colorm) {

	}

	void exerice_one() {

		cout << "exercise_one.............." << endl;

		cv::Mat m(500, 500, CV_8UC1, cv::Scalar::all(0));
		cv::Mat colorm(500, 500, CV_8UC3, cv::Scalar::all(0));
		int times = 0;
		cv::Point location(0,0);
		cv::namedWindow("Screen", cv::WINDOW_AUTOSIZE);
		cv::namedWindow("Color", cv::WINDOW_AUTOSIZE);

		while (1) {

			cv::Mat roi(m, cv::Rect(location, cv::Size(10, 20)));
			if (times % 2 == 0) {
				typewriter(roi, '\t');
			}
			else {
				typewriter(roi, '\b');
			}
			++times;
			cv::imshow("Sreen", m);

			uchar key = cv::waitKey(50);			
			typewriter(roi, '\b');

			if ('0' <= key && key <= '9') {
				typewriter(roi, key);
				location.x += 10;
			}
			if (key == '\r') {
				location.y += 20;
				location.x = 0;
			}
			if (key == '\b') {
				if (location.x == 0) {
					if (location.y == 0) {
						continue;
					}
					else {
						location.y -= 20;
					}
				}
				else {
					location.x -= 10;
				}
				cv::Mat roi(m, cv::Rect(location, cv::Size(10, 20)));
				typewriter(roi, key);
			}
			/*if (key == '\224') {
				key = cv::waitKey(0);
				if (key == '\72') {
					location.y = location.y - 20 >= 0 ? location.y - 20 : location.y;
				}
				if (key == '\80') {
					location.y = location.y + 20 <= 500 ? location.y + 20 : location.y;
				}
				if (key == '\75') {
					location.x = location.x - 10 >= 0 ? location.x - 10 : location.x;
				}
				if (key == '\77') {
					location.x = location.x + 10 <= 500 ? location.x + 10 : location.x;
				}
			}*/ //为什么无法读入方向键？？
			if (key == 'r') {
				convert_color(m, colorm);
				cv::imshow("Color", colorm);
			}

			if (key == 'z') {
				break;
			}
			if (location.x+10<=500 && location.y+20<=500){
				continue;
			}
			else {
				cout << " Hit the end of the image...........\nquit\n";
				break;
			}
		}

		cv::destroyWindow("Sreen");
	}
}

namespace exercise_two {

	void exercise_two() {

		cv::Mat m(10, 20, CV_8UC1);
		cv::randu(m, 1.0f, 10.0f);
		cv::Mat Intm(10, 20, CV_32FC1, cv::Scalar::all(0));

		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 20; ++j) {
				if(i>=1 && j>=1)
					Intm.at<float>(i, j) = Intm.at<float>(i-1,j)+Intm.at<float>(i,j-1)-Intm.at<float>(i-1,j-1) +(float)m.at<uchar>(i, j);
				else if(i<1 && j>=1)
					Intm.at<float>(i, j) = Intm.at<float>(i,j-1)+(float)m.at<uchar>(i, j);
				else if (i>=1 && j<1)
					Intm.at<float>(i, j) = Intm.at<float>(i-1,j)+(float)m.at<uchar>(i, j);
				else
					Intm.at<float>(i, j) = (float)m.at<uchar>(i, j);
			}
		}

		int i, j;
		cout << "m:\n" << m << endl;
		cout << "(x,y):" << endl;
		cin >> i >> j;
		cout << "sum to the point ( " << i << " , " << j << " ) : " << Intm.at<float>(i, j) << endl;
	}
}

#endif
