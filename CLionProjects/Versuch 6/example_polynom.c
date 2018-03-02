#include <stdio.h>
#include <stddef.h>
#include "polynom.h"

int main(){
	double data_x[] = {-2.0, -1.0, 0.0, 1.0, 2.0};
	double data_y[] = { 5.0,  2.0, 1.0, 2.0, 5.0};
	double x;
	double dx = 2e-1;
	double min_x = -3.0;
	double max_x = 3.0;
	polynom_t p;
	if( polynom_initialize (&p,3) == 0){
		return 1;
	}
	polynom_least_sqares(&p, &data_x[0], &data_y[0], sizeof(data_x) / sizeof(data_x[0]));

	printf("p(x) = ");
	polynom_print(&p, 1e-9, "x");
	printf("\n\n");

	for(x = min_x; x < max_x+0.5*dx; x += dx){
		printf("p(%5.2f) = %.2f\n",x,polynom_evaluate(&p, x));
	}

	polynom_destroy(&p);
	return 0;
}
