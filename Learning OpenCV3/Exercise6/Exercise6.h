#ifndef __EXERCISE_7__
#define __EXERCISE_7__

#include<iostream>
#include<opencv2/opencv.hpp>
#include<ctime>

using namespace std;

namespace test_exercise {

	void test_exercise2() {

		cv::Mat m = cv::imread("D:\\file\\DigitalImageProcess\\example.jpg", 2 | 4);

		cv::Mat gray;

		cv::cvtColor(m, gray, cv::COLOR_BGR2GRAY);

		cv::namedWindow("Gray", cv::WINDOW_AUTOSIZE);
		cv::imshow("Gray", gray);
		cv::waitKey(0);
		cv::destroyWindow("Gray");
		
		cv::cvtColor(gray, gray, cv::COLOR_GRAY2BGR);//without this transfer, the 3channel's data will be forced to be the same! the result is gray

		cv::circle(gray, cv::Point2i(100, 100), 100, cv::Scalar(0, 255, 255), 2, cv::LINE_AA);

		cv::putText(gray, "Hello World", cv::Point2i(300, 300), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 0, 255), 1);

		cv::namedWindow("Modified", cv::WINDOW_AUTOSIZE);
		cv::imshow("Modified", gray);
		cv::waitKey(0);
		cv::destroyWindow("Modified");
	}

	void test_exercise3() {

		cv::VideoCapture video;
		video.open("D:\\file\\Video\\IMG_0845.MOV");

		cv::Mat frame;
		cv::namedWindow("Framespeed", cv::WINDOW_AUTOSIZE);

		clock_t timer = clock();
		clock_t differ;
		double rate = 0.0;
		char key = 0;

		ostringstream stream;
		while (1) {

			video >> frame;
			if (frame.empty()) break;
			//string Rate = to_string(rate);//double 转 string 有什么更好的方法吗？
			//Rate += "FPS";
			stream << "FPS:";
			stream << rate;
			cv::putText(frame, stream.str(), cv::Point2i(10, 50), cv::FONT_HERSHEY_PLAIN, 2, cv::Scalar(0, 255, 255), 2,0);
			stream.str("");

			timer = clock();

			cv::imshow("Framespeed", frame);

			key = cv::waitKey(30);
			if (key == 'q') {
				break;
			}
			differ = clock() - timer;
			cout << differ << "	";
			rate = 1000.0 / differ;
			cout << rate << endl;

		}

		cv::destroyWindow("Framespeed");
	}

	void test_example4() {
		// a litte bit difficult
	}

	void test_example5() {
		// difficult
	}
}

#endif
