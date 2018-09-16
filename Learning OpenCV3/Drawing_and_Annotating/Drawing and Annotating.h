#ifndef __DRAWING_AND_ANNOTATING__
#define __DRAWING_AND_ANNOTATING__

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

namespace test_drawing_annotating{

	void test_circle() {
		//void circle(
		//	cv::Mat& img, // Image to be drawn on
		//	cv::Point center, // Location of circle center
		//	int radius, // Radius of circle
		//	const cv::Scalar& color, // Color, RGB form
		//	int thickness = 1, // Thickness of line and cv::FILLED
		//	int lineType = 8, // Connectedness, 4 or 8 and cv::LINE_AA
		//	int shift = 0 // Bits of radius to treat as fraction
		//);
		cv::Mat m(301, 301, CV_8UC3 , cv::Scalar::all(255));
		
		cv::circle(m, cv::Point2i(150, 150), 100, cv::Scalar(255, 0, 0), 1, cv::LINE_AA);
		
		cv::namedWindow("Circle", cv::WINDOW_AUTOSIZE);

		cv::imshow("Circle", m);
		cv::waitKey(0);
	}

	void test_clipline() {
		//cv::clipLine()
		//	bool clipLine( // True if any part of line in 'imgRect'
		//		cv::Rect imgRect, // Rectangle to clip to
		//		cv::Point& pt1, // First endpoint of line, overwritten
		//		cv::Point& pt2 // Second endpoint of line, overwritten
		//	);
		//bool clipLine( // True if any part of line in image size
		//	cv::Size imgSize, // Size of image, implies rectangle at 0,0
		//	cv::Point& pt1, // First endpoint of line, overwritten
		//	cv::Point& pt2 // Second endpoint of line, overwritten
		//);
		cv::Rect rect(cv::Point2i(10, 20), cv::Point2i(40, 60));
		bool flag;
		cv::Point2i point1(30, 50);
		cv::Point2i point2(90,120);
		flag = cv::clipLine(rect, point1, point2);// if  any part of line in image size, then the out point will be replace with the intersection point
		cout << flag << endl;

		cv::Mat map(1000, 1000, CV_8UC3, cv::Scalar::all(20));
		cv::Mat ROI = map(rect);
		ROI.setTo(cv::Scalar(255, 0, 0));
		cv::circle(map, point1, 5, cv::Scalar(0, 255, 255), cv::FILLED, cv::LINE_AA);
		cv::circle(map, point2, 5, cv::Scalar(0, 255, 255), cv::FILLED, cv::LINE_AA);

		cv::namedWindow("Result", cv::WINDOW_AUTOSIZE);
		cv::imshow("Result", map);
		cv::waitKey(0);

		cv::destroyWindow("Result");
	}

	void test_ellipse() {

		//cv::ellipse()
		//	bool ellipse(
		//		cv::Mat& img, // Image to be drawn on
		//		cv::Point center, // Location of ellipse center
		//		cv::Size axes, // Length of major and minor axes
		//		double angle, // Tilt angle of major axis [0-360]  which is measured counterclockwise from horizontal
		//		double startAngle, // Start angle for arc drawing [0-360]
		//		double endAngle, // End angle for arc drawing [0-360]
		//		const cv::Scalar& color, // Color, BGR form
		//		int thickness = 1, // Thickness of line cv::FILLED
		//		int lineType = 8, // Connectedness, 4 or 8 cv::LINE_AA
		//		int shift = 0 // Bits of radius to treat as fraction
		//	);
		//bool ellipse(
		//	cv::Mat& img, // Image to be drawn on
		//	const cv::RotatedRect& rect, // Rotated rectangle bounds ellipse
		//	const cv::Scalar& color, // Color, BGR form
		//	int thickness = 1, // Thickness of line
		//	int lineType = 8, // Connectedness, 4 or 8
		//	int shift = 0 // Bits of radius to treat as fraction
		//);

		cv::Mat map(1000, 1000, CV_8UC3, cv::Scalar::all(0));

		cv::ellipse(map, cv::Point2i(500, 500), cv::Size(300, 50), 90, 0, 360, cv::Scalar(0, 255, 255), 10, cv::LINE_AA);

		cv::namedWindow("Ellipse", cv::WINDOW_AUTOSIZE);
		cv::imshow("Ellipse", map);
		cv::waitKey(0);

		cv::destroyWindow("Ellipse");
	}

	void test_ellipse2Poly() {
		//void ellipse2Poly(
		//	cv::Point center, // Location of ellipse center
		//	cv::Size axes, // Length of major and minor axes
		//	double angle, // Tilt angle of major axis
		//	double startAngle, // Start angle for arc drawing
		//	double endAngle, // End angle for arc drawing
		//	int delta, // Angle between sequential vertices
		//	vector<cv::Point>& pts // Result, STL-vector of points
		//);

		vector<cv::Point> points;
		cv::Point2i point(500, 500);
		cv::Mat map(1000, 1000, CV_8UC3, cv::Scalar::all(0));
		cv::ellipse(map, point, cv::Size(300, 50), 30, 0, 360, cv::Scalar(255, 0, 0), 5, cv::LINE_AA);
		cv::ellipse2Poly(point, cv::Size(300, 50), 30, 0, 360, 15, points);

		for (auto iter : points) {
			cv::circle(map, iter, 3, cv::Scalar(0, 255, 255), cv::FILLED, cv::LINE_AA);
		}

		cv::namedWindow("Ellipse", cv::WINDOW_AUTOSIZE);
		cv::imshow("Ellipse", map);
		cv::waitKey(0);

		cv::destroyWindow("Ellipse");

	}
	
	void test_fillConvexPoly() {

		//void fillConvexPoly(
		//	cv::Mat& img, // Image to be drawn on
		//	const cv::Point* pts, // C-style array of points
		//	int npts, // Number of points in 'pts'
		//	const cv::Scalar& color, // Color, BGR form
		//	int lineType = 8, // Connectedness, 4 or 8
		//	int shift = 0 // Bits of radius to treat as fraction
		//);
		//  This function draws a filled polygon
		//  the polygon you pass to it can't have self - intersections.
	}

	void test_fillPoly() {

		//void fillPoly(
		//	cv::Mat& img, // Image to be drawn on
		//	const cv::Point* pts, // C-style array of arrays of points
		//	int npts, // Number of points in 'pts[i]'
		//	int ncontours, // Number of arrays in 'pts'
		//	const cv::Scalar& color, // Color, BGR form
		//	int lineType = 8, // Connectedness, 4 or 8
		//	int shift = 0, // Bits of radius to treat as fraction
		//	cv::Point offset = Point() // Uniform offset applied to all points
		//);
		//  draws any number of filled polygons
		//  can handle polygons with self-intersections

	}

	void test_line() {

		//void line(
		//	cv::Mat& img, // Image to be drawn on
		//	cv::Point pt1, // First endpoint of line
		//	cv::Point pt2 // Second endpoint of line
		//	const cv::Scalar& color, // Color, BGR form
		//	int lineType = 8, // Connectedness, 4 or 8
		//	int shift = 0 // Bits of radius to treat as fraction
		//);

		// Lines are automatically clipped by the image boundaries

		cv::Mat map(1000, 1000, CV_8UC3, cv::Scalar::all(0));
		cv::Point2i point1(30, 50);
		cv::Point2i point2(90, 120);

		cv::line(map, point1, point2, cv::Scalar(0, 255, 255), 4);

		cv::namedWindow("Line", cv::WINDOW_AUTOSIZE);
		cv::imshow("Line", map);
		cv::waitKey(0);

		cv::destroyWindow("Line");
	}

	void test_rectangle() {
		//void rectangle(
		//	cv::Mat& img, // Image to be drawn on
		//	cv::Point pt1, // First corner of rectangle
		//	cv::Point pt2 // Opposite corner of rectangle
		//	const cv::Scalar& color, // Color, BGR form
		//	int lineType = 8, // Connectedness, 4 or 8
		//	int shift = 0 // Bits of radius to treat as fraction
		//);
		//void rectangle(
		//	cv::Mat& img, // Image to be drawn on
		//	cv::Rect r, // Rectangle to draw
		//	const cv::Scalar& color, // Color, BGR form
		//	int lineType = 8, // Connectedness, 4 or 8
		//	int shift = 0 // Bits of radius to treat as fraction
		//);
	}

	void test_polyLines() {
		//void polyLines(
		//	cv::Mat& img, // Image to be drawn on
		//	const cv::Point* pts, // C-style [array of arrays] of points
		//	int npts, // Number of points in 'pts[i]'
		//	int ncontours, // Number of arrays in 'pts'
		//	bool isClosed, // If true, connect last and first pts
		//	const cv::Scalar& color, // Color, BGR form
		//	int lineType = 8, // Connectedness, 4 or 8
		//	int shift = 0 // Bits of radius to treat as fraction
		//);
		//  draws any number of unfilled polygons
	}

	void test_LineIterator() {
		//LineIterator::LineIterator(
		//	cv::Mat& img, // Image to be drawn on
		//	cv::Point pt1, // First endpoint of line
		//	cv::Point pt2 // Second endpoint of line
		//	int lineType = 8, // Connectedness, 4 or 8
		//	bool leftToRight = false // If true, always start steps on the left
		//);

		cv::Mat map(500, 500, CV_8UC3, cv::Scalar::all(0));
		cv::Point2i pt1(40, 60);
		cv::Point2i pt2(300, 300);

		cv::line(map, pt1, pt2, cv::Scalar(0, 255, 255), 1,8);

		cv::namedWindow("Line", cv::WINDOW_AUTOSIZE);
		cv::imshow("Line", map);
		cv::waitKey(0);

		cv::LineIterator iter(map, pt1, pt2, 8);
		int i = 0;
		int increase = 3;
		while (i != iter.count) {
			**iter = i*increase;
			++i;
			++iter;
		}//only travel the line itself, not travel the thickness pixels

		cv::namedWindow("Result", cv::WINDOW_AUTOSIZE);
		cv::imshow("Result", map);
		cv::waitKey(0);
		cv::destroyWindow("Line");
		cv::destroyWindow("Result");
	}

	void test_putText() {

		//void cv::putText(
		//	cv::Mat& img, // Image to be drawn on
		//	const string& text, // write this (often from cv::format)
		//	cv::Point origin, // Upper-left corner of text box
		//	int fontFace, // Font (e.g., cv::FONT_HERSHEY_PLAIN)
		//	double fontScale, // size (a multiplier, not "points"!)
		//	cv::Scalar color, // Color, RGB form
		//	int thickness = 1, // Thickness of line
		//	int lineType = 8, // Connectedness, 4 or 8
		//	bool bottomLeftOrigin = false // true='origin at lower left'
		//);

		cv::Mat map(500, 500, CV_8UC3, cv::Scalar::all(0));
		cv::Point2i pt1(40, 60);

		cv::putText(map, "Hello world", pt1, cv::FONT_HERSHEY_PLAIN /*| cv::FONT_ITALIC*/, 1, cv::Scalar(0, 255, 255));
		//can't output chinese

		cv::namedWindow("Text", cv::WINDOW_AUTOSIZE);
		cv::imshow("Text", map);
		cv::waitKey(0);
		cv::destroyWindow("Text");
	}
}

#endif
