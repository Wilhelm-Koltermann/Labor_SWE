#include <stdio.h>
#include "screen_transform.h"
#include "polynom.h"
#include "simple_rgb_image.h"
#include <stdlib.h>
#include <math.h>

void find_min_max(double *min, double *max, double *x, size_t size);
size_t get_number_of_lines_in_file(FILE *file);

int main(){
  
  simple_rgb_image_t image;
  screen_transform_t trans;
  FILE *file,*file1;
  polynom_t poly;
  int i,k = 0,j = 0, image_width = 600, image_height = 800;

  file = fopen("labor.data","rb");
  file1 = fopen("punktwolke.bmp","wb");
  if(file == NULL || file1 == NULL) printf("error/n");
  
  size_t dnol = get_number_of_lines_in_file(file),igrad;
  double dxval[dnol],dyval[dnol],maxy,maxx,minx,miny; 
  
  for(i = 0; i < 2*dnol; i++){

   if(i%2 == 0) { fscanf(file,"%lf",&dxval[k]); k++; }

   else{ fscanf(file,"%lf",&dyval[j]); j++; }
  }

  find_min_max(&minx,&maxx,dxval,(sizeof(dxval)/8));
  find_min_max(&miny,&maxy,dyval,(sizeof(dxval)/8));

  
  screen_transform_set_screen_range_x (&trans, 0, 599);
  screen_transform_set_screen_range_y (&trans, 0, 799);
  screen_transform_set_world_range_x (&trans, minx, maxx);
  screen_transform_set_world_range_y (&trans, miny, maxy);
  
  simple_rgb_image_init(&image, image_width, image_height);

  for(i = 0; i < dnol; i++ ){
      
    simple_rgb_image_put_pixel(&image, screen_transform_get_screen_x(&trans, dxval[i]),
    screen_transform_get_screen_y(&trans, dyval[i]), 255, 255, 255);

    }

  printf("Grad des Polynoms: ");
  scanf("%u",&igrad);

  if(polynom_initialize (&poly,(igrad+1)) == NULL) printf("error\n");
  
  polynom_least_sqares(&poly, dxval, dyval, dnol);

   for(i = 0; i < dnol; i++ ){
      
    simple_rgb_image_put_pixel(&image, screen_transform_get_screen_x(&trans, dxval[i]),
    screen_transform_get_screen_y(&trans,polynom_evaluate(&poly, dxval[i])), 255, 0, 0);

    }

  
  simple_rgb_image_to_bitmap_stream(&image, file1);

  simple_rgb_image_clear(&image);
  polynom_destroy(&poly);
  fclose(file);
  fclose(file1);
    
  }




//Funktionen

//Min/Max eines Zahlen-Arrays finden

void find_min_max(double *min, double *max, double *x, size_t size){
size_t i;
*min = x[0];
*max = x[0];
for(i = 1; i < size; ++i){
if(x[i] < *min){
*min = x[i];
}
if(x[i] > *max){
*max = x[i];
}
}
}

//Anzhal der Zeilen einer Datei finden

size_t get_number_of_lines_in_file(FILE *file)
{
size_t cnt=0;
char line[1024];
while (fgets(line, sizeof(line), file) != NULL) cnt++;
rewind(file);
return cnt;
}
