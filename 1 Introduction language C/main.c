#include <stdio.h>

#include <kotes.h>
#include <polysqr.h>

double f(double x) {
	return x*x*x;
}

int main() {

	point poly[4];

	poly[0].x = 0.0; poly[0].y = 0.0;
	poly[1].x = 0.0; poly[1].y = 2.0;
	poly[2].x = 2.0; poly[2].y = 2.0;
	poly[3].x = 2.0; poly[3].y = 0.0;

	double sqrp = PolygonSquare(poly, 4);

	double integ = Kotes(f, 0, 4, 30);

	printf("%E %E\n",sqrp, integ);

}
