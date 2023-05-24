// file that implements all structures, types and functions of project.c, manage_shape.c and shape.c

#ifndef PROJECT_H
# define PROJECT_H
#define BOOL int
typedef unsigned int ui;

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "id.h"

// TYPEDEF
typedef enum {POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;
typedef struct area Area;

// STRUCTURES
struct point {
    int x;          // coordinate of the point in the abciss
    int y;          // coordinate of the ordinates
};
typedef struct point Point;

struct line{
    Point *p1;      // coordinates of the first point
    Point *p2;      // coordinates of the second point
};
typedef struct line Line;

struct circle{
    Point* center;  // coordinate of the center
    int radius;     // value of the radius
};
typedef struct circle Circle;

struct square{
    Point *point;   // coordinate of the top left corner
    int length;     // size of the side
};
typedef struct square Square;

struct rectangle{
    Point *point;   // coordinate of the top left corner
    int width;      // value of the width
    int length;     // value of the height
};
typedef struct rectangle Rectangle;

struct polygon{
    int nbSommets;      // number of the sommets
    Point **sommets;    // list of all the corner point
};
typedef struct polygon Polygon;

struct shape {
    int id;                 // id of the shape
    SHAPE_TYPE shape_type;  // type of the shape (pont, circle, etc...)
    void *ptrShape;         // pointer of the shape
};
typedef struct shape Shape;

// project.c

int menu(Area *area);
void print_grid(BOOL **grid);

// manage_shapes

Point* create_point(int px, int py);
void print_point(Point *point);

Line* create_line(Point *p1, Point *p2);
void print_line(Line *line);

Square* create_square(Point * point, int length);
void print_square(Square * square);

Rectangle* create_rectangle(Point *point, int width, int length);
void print_rectangle(Rectangle * rectangle);

Circle* create_circle(Point* c, int r);
void print_circle(Circle *circle);

Polygon* create_polygon(int nbs);
void print_polygon(Polygon* polygon);

//shape.c

Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_circle_shape(int px, int py, int radus);
Shape *create_polygon_shape(int n);

#endif