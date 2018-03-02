#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include "simple_rgb_image.h"
#include "screen_transform.h"

void draw_sinus(simple_rgb_image_t* image, screen_transform_t* transform){
	unsigned char red = 255;
	unsigned char green = 0;
	unsigned char blue = 0;
	int line_width = 3;
	int screen_x;
	for(screen_x = 0; screen_x < image->width; ++screen_x){
		double world_x = screen_transform_get_world_x(transform,screen_x);
		double world_y = sin(world_x);
		int screen_y = screen_transform_get_screen_y(transform,world_y);
		simple_rgb_image_fill_circle(image, screen_x, screen_y, line_width, red, green, blue);
	}
}

int main(){
	const char* image_file = "example_transform.bmp";
	FILE* file = fopen(image_file,"wb");
	simple_rgb_image_t image;
	int image_width = 2048;
	int image_height = 2048;
	screen_transform_t transform;
	screen_transform_set_screen_range_x(&transform, 0, image_width-1);
	screen_transform_set_screen_range_y(&transform, 0, image_height - 1);
	screen_transform_set_world_range_x(&transform, 0.0, 2.0*M_PI);
	screen_transform_set_world_range_y(&transform, -1.05, 1.05);
	simple_rgb_image_init(&image, image_width, image_height);
	draw_sinus(&image,&transform);
	simple_rgb_image_to_bitmap_stream(&image, file);
	simple_rgb_image_clear(&image);
	fclose(file);
	return 0;
}
