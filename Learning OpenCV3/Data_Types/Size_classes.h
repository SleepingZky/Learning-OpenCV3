#ifndef __SIZE_CLASS__
#define __SIZE_CLASS__

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;


namespace test_size {

	void test_size() {

		cv::Size   sz1(10, 20);
		cv::Size2i sz2(40, 60);
		cv::Size2f sz3(32.5, 56.9);
		cv::Size   sz4(24.6, 89.6);//cast to int value

		cout << "sz1 : " << sz1 << endl;
		cout << "sz2 : " << sz2 << endl;
		cout << "sz3 : " << sz3 << endl;
		cout << "sz4 : " << sz4 << endl;
		cout << "sz1.width : " << sz1.width << "	sz1.height : " << sz1.height << endl;

		//area
		cout << "sz1.area() : " << sz1.area() << endl;
	}
}


#endif

