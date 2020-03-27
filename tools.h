#ifndef TOOLS_H
#define TOOLS_H

class Point {
	public:
	Point(double x,double y)
	: x(x), y(y)
	{}
	double GetX () const {return x;}
	double GetY () const {return y;}
	
	private:
	double x,y;
};


class Segment {
	public:
	Segment(double x1,double y1,double x2,double y2)
	: point1(x1,y1),point2(x2,y2)
	{}
	
	private:
	Point point1;
	Point point2;
};

class Vecteur {
	public:
	
	private:
	Segment seg;
	
};

class Cercle {
	public:
	Cercle(double x,double y,double r)
	: centre(x,y),rayon(r)
	{}
	
	private:
	Point centre;
	double rayon;
};

#endif
