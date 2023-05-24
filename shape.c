// This file contains all the functions to create a figure.

#include "project.h"

// function that change any type of shape in a shape type
Shape *create_empty_shape(SHAPE_TYPE shape_type)
{
    Shape *shp = (Shape *) malloc(sizeof(Shape)); // allocates the necessary memory
    shp->ptrShape = NULL; // pointer of the shape
    shp->id = get_next_id(); // create the id of the shape
    shp->shape_type = shape_type; // keeps the type of the shape (point, line, ...)
    return shp;
}

// function that change a point in a shape type
Shape *create_point_shape(int px, int py)
{
    Shape *shp = create_empty_shape(POINT); // generate a shape
    Point *p = create_point(px, py); // create a point
    shp->ptrShape = p; //transform the point on a shape
    return shp;
}

// function that change a line in a shape type
Shape *create_line_shape(int px1, int py1, int px2, int py2)
{
    Shape *shp = create_empty_shape(LINE);
    Line *p = create_line(create_point(px1, py1), create_point(px2, py2));
    shp->ptrShape = p;
    return shp;
}

// function that change a square in a shape type
Shape *create_square_shape(int px, int py, int length)
{
    Shape *shp = create_empty_shape(SQUARE);
    Square *p = create_square(create_point(px, py), length);
    shp->ptrShape = p;
    return shp;
}

// function that change a rectangle in a shape type
Shape *create_rectangle_shape(int px, int py, int width, int height)
{
    Shape *shp = create_empty_shape(RECTANGLE);
    Rectangle *p = create_rectangle(create_point(px, py), width, height);
    shp->ptrShape = p;
    return shp;
}

// function that change a circle in a shape type
Shape *create_circle_shape(int px, int py, int radius)
{
    Shape *shp = create_empty_shape(CIRCLE);
    Circle *p = create_circle(create_point(px, py), radius);
    shp->ptrShape = p;
    return shp;
}

// function that change a polygon in a shape type
Shape *create_polygon_shape(int n)
{
     Shape *shp = create_empty_shape(POLYGON);
     Polygon *p = create_polygon(n);
     shp->ptrShape = p;
     return shp;
}
