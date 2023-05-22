#include "project.h"

Shape *create_empty_shape(SHAPE_TYPE shape_type)
{
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = 1; // plus tard on appelera get_next_id();
    shp->shape_type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py)
{
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2)
{
    Shape *shp = create_empty_shape(LINE);
    Line *p = create_line(create_point(px1, py1), create_point(px2, py2));
    shp->ptrShape = p;
    return shp;
}

Shape *create_square_shape(int px, int py, int length)
{
    Shape *shp = create_empty_shape(SQUARE);
    Square *p = create_square(create_point(px, py), length);
    shp->ptrShape = p;
    return shp;
}

Shape *create_rectangle_shape(int px, int py, int width, int height)
{
    Shape *shp = create_empty_shape(RECTANGLE);
    Rectangle *p = create_rectangle(create_point(px, py), width, height);
    shp->ptrShape = p;
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius)
{
    Shape *shp = create_empty_shape(CIRCLE);
    Circle *p = create_circle(create_point(px, py), radius);
    shp->ptrShape = p;
    return shp;
}

// Shape *create_polygon_shape(int n)
// {
//     Shape *shp = create_empty_shape(POLYGON);
//     Polygon *p = create_polygon(n);
//     shp->ptrShape = p;
//     return shp;
// }

void print_shape(Shape *shape)
{
    switch (shape->shape_type)
    {
        case 0:
            printf("POINT ->\n");
            print_point(shape->ptrShape);
            break;
        case 1:
            printf("LINE ->\n");
            print_line(shape->ptrShape);
            break;
        case 2:
            printf("RECTANGLE ->\n");
            break;
        case 3:
            printf("SQUARE ->\n");
            break;
        case 4:
            printf("CIRCLE ->\n");
            print_circle(shape->ptrShape);
            break;
        case 5:
            printf("POLYGON ->\n");
            print_polygon(shape->ptrShape);
            break;
        default:
            break;
    }
}

void delete_shape(Shape *shape)
{
    free(shape);
}