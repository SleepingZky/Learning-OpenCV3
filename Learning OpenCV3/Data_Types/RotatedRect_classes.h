#ifndef __ROTATEDRECT_CLASS__
#define __ROTATEDRECT_CLASS__

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

namespace test_rotatedrect {

	void test_rotatedrect()
	{
		//can't directly print itself
		//can be double

		cv::RotatedRect rr(cv::Point2f(12.6, 18.3), cv::Size2f(15.7, 14.9), 30);
		//cast to Point(12,18),Size(15,14)

		//cout << "rr : " << rr << endl;
		cout << "rr.center : " << rr.center << "	rr.size : " << rr.size << "		rr.angle : " << rr.angle << endl;

		cv::Point2f pts[4];
		rr.points(pts);//needs a pointer!
		cout << "point1 : " << pts[0] << "	point2 : " << pts[1] << "	point3 : " << pts[2] << "	point4 : " << pts[3] << endl;
		//** returns 4 vertices of the rectangle
		//@param pts The points array for storing rectangle vertices.The order is bottomLeft, topLeft, topRight, bottomRight.
		//	* /
		//	void points(Point2f pts[]) const;
	}
}

#endif
