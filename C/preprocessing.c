#include <stdio.h>
#define PI 3.14
// dùng tiền xử lí để tính
#define CIRCUMFERENCE(x) (2.0 * (x) * PI)
#define AREA(x) ((x) * (x) * PI)
#define VOLUME(x) (4.0 / 3.0 * (x) * (x) * (x) * PI)
#define SURFACE_AREA(x) (4.0 * (x) * (x) * PI)

// dùng hàm để tính
//  double circumference(double r)
//  {
//      return 2.0 * r * PI;
//  }
//  double area(double r)
//  {
//      return r * r * PI;
//  }
//  double volume(double r)
//  {
//      return 4.0 / 3.0 * r * r * r * PI;
//  }
//  double surface_area(double r)
//  {
//      return 4.0 * r * r * PI;
//  }

int main()
{
    double r;
    printf("반지름을 입력 하세요 : ");
    scanf("%lf", &r);
    printf("r : %.3f\n", r);
    // printf("cir : %.3f\n", circumference(r));
    // printf("area : %.3f\n", area(r));
    // printf("volume : %.3f\n", volume(r));
    // printf("surface_area : %.3f\n", surface_area(r));
    printf("cir : %.3f\n", CIRCUMFERENCE(r));
    printf("area : %.3f\n", AREA(r));
    printf("volume : %.3f\n", VOLUME(r));
    printf("surface_area : %.3f\n", SURFACE_AREA(r));
}