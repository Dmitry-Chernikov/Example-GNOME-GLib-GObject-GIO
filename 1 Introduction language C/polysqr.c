#include <math.h>

#include "polysqr.h"

static double TriangleSquare(point* p1, point* p2, point* p3){

	double ax = p1->x - p2->x;
	double ay = p1->y - p2->y;

	double bx = p3->x - p2->x;
	double by = p3->y - p2->y;

	return fabs(ax*by - ay*bx)/2.0;
}

double PolygonSquare(point* poly, int n){

	point O = {0.0, 0.0};

	for (int i = 0; i < n - 1 ; i++){

		O.x = O.x + poly[i].x;
		O.y = O.y + poly[i].y;

	}

	O.x = O.x/n;
	O.y = O.y/n;

	double square = 0.0;

	for (int i = 0; i < n - 1; i++){
		square = square + TriangleSquare( &(poly[i]), &O, &(poly[i + 1]) );
	}

	square = square + TriangleSquare( &(poly[n - 1]), &O, &(poly[0]) );

	return square;
}
