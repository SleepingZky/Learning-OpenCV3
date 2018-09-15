#ifndef __RECT_CLASS__
#define __RECT_CLASS__

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

namespace test_Rect {

	void test_Rect() {
		
		//typedef Rect_<int> Rect2i;
		//typedef Rect_<float> Rect2f;
		//typedef Rect_<double> Rect2d;
		//typedef Rect2i Rect;

		cv::Rect r1(21, 12, 4, 6);
		cv::Rect r2(10.4, 12.6, 5.3, 8.9);//cast to int (10,12,5,8)
		
		cv::Point2f p1(10.5, 23.7);
		cv::Size2f sz1(15.7, 20.6);
		cv::Rect r3(p1, sz1); //cast to (10,24,16,21)

		cv::Point2i p2(14, 100);
		cv::Size2i sz2(15, 20);
		cv::Rect r4(p2, sz2);

		cout << "r1 : " << r1 << endl;
		cout << "r2 : " << r2 << endl;
		cout << "r3 : " << r3 << endl;
		cout << "r4 : " << r4 << endl;

		//member access
		cout << "r3.x : " << r3.x << "	r3.y : " << r3.y << "	r3.width : " << r3.width << "	r3.height : " << r3.height << endl;

		//area
		cout << "r1.area() : " << r1.area() << endl;
		cout << "r2.area() : " << r2.area() << endl;
		cout << "r3.area() : " << r3.area() << endl;
		cout << "r4.area() : " << r4.area() << endl;

		// upper-left conrner
		cout << "r1.tl() : " << r1.tl() << endl;
		cout << "r2.tl() : " << r2.tl() << endl;
		cout << "r3.tl() : " << r3.tl() << endl;
		cout << "r4.tl() : " << r4.tl() << endl;

		//bottom-right corner
		cout << "r1.br() : " << r1.br() << endl;
		cout << "r2.br() : " << r2.br() << endl;
		cout << "r3.br() : " << r3.br() << endl;
		cout << "r4.br() : " << r4.br() << endl;

		//Rect intersection
		cv::Rect r5 = r2 & r4;
		cv::Rect r6 = r3 | r1;//?Rect2f 没有这种操作么？ 需要同类型的，才能互相 与or或

		cout << "r5 : " << r5 << endl;
		cout << "r6 : " << r6 << endl;

		//Translate ractangle by an amount x; just move
		cv::Rect rx = r1 + cv::Point(10,12);
		//Rect_<_Tp> operator + (const Rect_<_Tp>& a, const Point_<_Tp>& b)
		//{
		//	return Rect_<_Tp>(a.x + b.x, a.y + b.y, a.width, a.height);
		//}

		cv::Rect ry = r1 + cv::Size(4, 9);
	}
}

#endif
