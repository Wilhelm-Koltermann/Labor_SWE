#include <stdio.h>
#include "screen_transform.h"
#include "polynom.h"
#include "simple_rgb_image.h"
#include <stdlib.h>
#include <math.h>




int main(){
	
	polynom_t poly;
	
	screen_transform_t trans;
	
	simple_rgb_image_t image;

    FILE *file;
	
	int image_width = 600;

	int image_height = 800;
	
	int j;
	
	double i;
	
	double array[]={-2.7, -0.5, 1.2, 0.2, -0.1};
	
	double x[6000];
	
	double y[6000];
	
	size_t size = sizeof(array)/8;
	
	polynom_initialize (&poly, size);
	
	if(polynom_initialize (&poly, size)== NULL) printf("error");
	
	polynom_set_coefficients_from_array (&poly, array);
	
	for(i=-3,j=0; i<=3,j<6000; i=i+0.001,j++) {
		
	x[j]=i;

	y[j] = polynom_evaluate(&poly, i);
	
	}

	
	screen_transform_set_screen_range_x (&trans, 0, 599);
	
	screen_transform_set_screen_range_y (&trans, 0, 799); 
	
	screen_transform_set_world_range_x (&trans, -3, 3);

	screen_transform_set_world_range_y (&trans,  -4, 4);

    if ((file = fopen("plott.bmp", "wb")) == NULL) {

        printf("open error\n");

        return -1;
    }
	
	/* Initialisierung des Bildspeichers */

    simple_rgb_image_init(&image, image_width, image_height);
	
	for(j=0; j<6000; j++){ 
	
	simple_rgb_image_put_pixel(&image,screen_transform_get_screen_x(&trans, x[j]),screen_transform_get_screen_y(&trans,y[j]),0,0,255);
	
	}
	
	simple_rgb_image_to_bitmap_stream(&image, file);
	
	polynom_destroy(&poly);
	
	simple_rgb_image_clear(&image);
	
	fclose(file);
	
	return 0;
	}
	
	