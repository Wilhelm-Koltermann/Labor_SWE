#include <stdio.h>
#include "screen_transform.h"
#include "polynom.h"
#include "simple_rgb_image.h"
#include <stdlib.h>
#include <math.h>

int main(){

int ilength=100,jlength=100,i,j;

simple_rgb_image_t image;

FILE *file;

int image_width = 800;

int image_height = 800;

 if ((file = fopen("schach.bmp", "wb")) == NULL) {

        printf("open error\n");

        return -1;
    }

simple_rgb_image_init(&image,image_width,image_height);

for(j=0;j<(jlength*8);j++){

for(i=0;i<(ilength*8);i++){
	
	if((i/ilength+j/jlength)%2 == 0){
		
		simple_rgb_image_put_pixel(&image,i,j,0,0,0);
		
	}else{
		
		simple_rgb_image_put_pixel(&image,i,j,255,255,255);
	}
		
}
	
}

simple_rgb_image_to_bitmap_stream(&image, file);

simple_rgb_image_clear(&image);

fclose(file);

return 0;

}
