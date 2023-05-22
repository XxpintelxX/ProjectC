#include "project.h"

Point* create_point(int px, int py)
{
    Point* point = (Point*) malloc(sizeof(Point));
    point->x = px;
    point->y = py;
    return point;
}

void print_point(Point *point)
{
    printf("POINT -> x : %d | y : %d\n\n", point->x, point->y);
}

void delete_point(Point *point)
{
    free(point);
}

Line* create_line(Point *p_1, Point *p_2)
{
    Line* line = (Line*) malloc(sizeof(Line));
    line->p1 = p_1;
    line->p2 = p_2;
    return line;
}

void print_line(Line *line)
{
    printf("\nLINE ->\n\tPOINT 1 -> x : %d | y : %d\n\tPOINT 2 -> x : %d | y : %d\n\n", line->p1->x, line->p1->y, line->p2->x, line->p2->y);
}

void delete_line(Line* line)
{
    free(line);
}

Square* create_square(Point * point, int length)
{
    Square *square = (Square*) malloc(sizeof(Square));
    square->point = point;
    square->length = length;
    return square;
}

void print_square(Square * square)
{
    printf("SQUARE ->\n\tx : %d | y : %d \n\tx : %d | y : %d\n\tx : %d | y : %d\n\tx : %d | y : %d\n\n", square->point->x, square->point->y, square->point->x + square->length, square->point->y, square->point->x, square->point->y + square->length, square->point->x + square->length, square->point->y + square->length);
}

void delete_square(Square *square)
{
    free(square);
}

Rectangle* create_rectangle(Point *point, int width, int length)
{
    Rectangle *rectangle = (Rectangle*) malloc(sizeof(Rectangle));
    rectangle->point = point;
    rectangle->width = width;
    rectangle->length = length;
    return rectangle;
}

void print_rectangle(Rectangle * rectangle)
{
    printf("SQUARE ->\n\tx : %d | y : %d \n\tx : %d | y : %d\n\tx : %d | y : %d\n\tx : %d | y : %d\n\n", rectangle->point->x, rectangle->point->y, rectangle->point->x + rectangle->width, rectangle->point->y, rectangle->point->x, rectangle->point->y + rectangle->length, rectangle->point->x + rectangle->width, rectangle->point->y + rectangle->length);
}

void delete_rectangle(Rectangle * rectangle)
{
    free(rectangle);
}

Circle* create_circle(Point* c, int r)
{
    Circle* circle = (Circle*) malloc(sizeof(Circle));
    circle->center = c;
    circle->radius = r;
    return circle;
}

void print_circle(Circle *circle)
{
    printf("CIRCLE ->\n\tCenter -> x : %d | y : %d\n\tRadius -> %d\n", circle->center->x, circle->center->y, circle->radius);
}

void delete_circle(Circle *circle)
{
    free(circle);
}


Polygon* create_polygon(int nbs)
{
    Polygon *polygon = (Polygon*) malloc(sizeof(Polygon));
    int c, r;
    polygon->nbSommets = nbs;
    polygon->sommets = (Point**) malloc(sizeof(Point*)*nbs);

    for (int i = 0; i < nbs; i++)
    {
        printf("Enter the coordinates of the vertex n°%d (column/row) : ", i+1);
        fflush(stdin);
        scanf("%d/%d", &c, &r);
        polygon->sommets[i] = create_point(c, r);
    }
    return polygon;
}

void print_polygon(Polygon* polygon)
{
    printf("POLYGON ->\n\tNumber of vertexes : %d\n\tVERTEXES ->\n", polygon->nbSommets);
    for (int i = 0; i < polygon->nbSommets; i++)
    {
        printf("\t\t");
        print_point(polygon->sommets[i]);
        printf("\b\b");
    }
}

void delete_polygon(Polygon* polygon)
{
    free(polygon);
}