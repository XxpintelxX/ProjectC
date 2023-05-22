#ifndef PROJECT_H
# define PROJECT_H

// INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "area.h"
#include "id.h"

// STRUCTURES

#define SHAPE_MAX 100 // Maximum number of shapes
#define BOOL int
typedef unsigned int ui;

typedef enum {POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;

struct point {
    int x;
    int y;
};
typedef struct point Point;

struct line{
    Point *p1;
    Point *p2;
};
typedef struct line Line;

struct circle{
    Point* center;
    int radius;
};
typedef struct circle Circle;

struct square{
    Point *point;
    int length;
};
typedef struct square Square;

struct rectangle{
    Point *point;
    int width;
    int length;
};
typedef struct rectangle Rectangle;

struct polygon{
    int nbSommets;
    Point **sommets;
};
typedef struct polygon Polygon;

typedef struct node{
    void *data;
    struct node* next;
}NODE;

struct shape {
    int id;
    SHAPE_TYPE shape_type;
    void *ptrShape;
};

//TYPEDEFS

typedef struct area Area;
typedef struct shape Shape;
typedef NODE* LIST;

// project.c

int menu(Area *area);
void print_grid(BOOL **grid);
BOOL **createGrid(BOOL **grid, ui *rows, ui *columns);

// addShape.c

// void addShape(Area *area);
// void drawShape();
// void displayHelp(Area *area);
// void deleteShape();
// void displayListShapes(Area *area);
// char upper(char c);

// shapefcts.c

// void addPoint(Area *area);
// void addLine(Area *area);
// void addSquare(Area *area);
// void addCircle(Area *area);
// void addPolygon(Area *area);
// void addRectangle(Area *area);

// manage_shapes

Point* create_point(int px, int py);
void print_point(Point *point);
void delete_point(Point *point);

Line* create_line(Point *p1, Point *p2);
void print_line(Line *line);
void delete_line(Line* line);

Square* create_square(Point * point, int length);
void print_square(Square * square);
void delete_square(Square *square);

Rectangle* create_rectangle(Point *point, int width, int length);
void print_rectangle(Rectangle * rectangle);
void delete_rectangle(Rectangle * rectangle);

Circle* create_circle(Point* c, int r);
void print_circle(Circle *circle);
void delete_circle(Circle *circle);

Polygon* create_polygon(int nbs);
void print_polygon(Polygon* polygon);
void delete_polygon(Polygon* polygon);

//shape.c

Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_circle_shape(int px, int py, int radus);
Shape *create_polygon_shape(int n);
void delete_shape(Shape * shape);
void print_shape(Shape * shape);

#endif