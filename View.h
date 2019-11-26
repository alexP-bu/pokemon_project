#ifndef VIEW_H
#define VIEW_H

#include "Point2D.h"
#include "GameObject.h"

using namespace std;

const int view_maxsize = 20;

class View {
	//private members
	private:
	
	int size;
	double scale;
	Point2D origin;
	char grid[view_maxsize][view_maxsize][2];
	bool GetSubscripts(int&, int&, Point2D);
	
	public:
	
	View();
	void Clear();
	void Plot(GameObject* ptr);
	void Draw();
	
};

#endif