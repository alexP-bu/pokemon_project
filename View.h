#ifndef VIEW_H
#define VIEW_H

#include "Point2D.h"

using namespace std;

const int view_maxsize = 20;

class View {
	
	private:
	
	int size;
	double scale;
	Point2D origin;
	char grid;
	bool GetSubscripts;
	
	public:
	
	View();
	void Clear();
	void Plot(GameObject* ptr);
	void Draw();
	
};

#endif