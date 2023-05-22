#include "area.h"

Area* create_area(unsigned int width, unsigned int height)
{
    Area* area = (Area*) malloc(sizeof(Area));
    area->width = width;
    area->height = height;
    area->shapes = (Shape**) malloc(SHAPE_MAX * sizeof(Shape*));
    area->nb_shape = 0;
    area->mat = (BOOL**) malloc(width * sizeof(BOOL*));
    for (ui i = 0; i < width; i++)
    {
        area->mat[i] = (BOOL*) malloc(height * sizeof(BOOL));
    }
    return area;
}

void add_shape_to_area(Area* area, Shape* shape)
{
    area->shapes[area->nb_shape] = shape;
    area->nb_shape += 1;
}

void clear_area(Area* area)
{
    for (ui i =0; i<area->width; i++)
    {
        for (ui j = 0; j<area->height; j++)
        {
            area->mat[i][j] = 0;
        }
    }
}

void erase_area(Area* area)
{
    clear_area(area);
    free(area->shapes);
    area->nb_shape = 0;
}

void delete_area(Area* area)
{
    clear_area(area);
}

// void draw_area(Area* area)
// {
//     return;
// }

void print_area(Area* area)
{
    printf("   ");
    for (ui k = 0; k < area->width; k++)
    {
        if (k < 10)
            printf("%u  ", k);
        else
            printf("%u ", k);
    }
    printf("\n   ");
    for (ui k = 0; k < area->width; k++)
    {
        printf("---");
    }
    printf("\n");
    for (ui i = 0; i < area->height; i++)
    {
        for (ui j = 0; j < area->width; j++)
        {
            if (j == 0)
            {
                if (i < 10)
                    printf("%u |", i);
                else
                    printf("%u|", i);
            }
            if (area->mat[i][j] == 0)
            {
                printf(".  ");
            }
            else
            {
                printf("#  ");
            }
        }
        printf("\n");
    }
}

void write_point(Area *area, Point *point)
{
    area->mat[point->x][point->y] = 1;
}

void write_line(Area *area, Line *line)
{
    int dx = line->p2->x - line->p1->x;
    int dy = line->p2->y - line->p1->y;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = (float)dx / (float)steps;
    float yIncrement = (float)dy / (float)steps;

    float x = (float)line->p1->x;
    float y = (float)line->p1->y;

    for (int i = 0; i <= steps; i++) {
        area->mat[(int)x][(int)y] = 1; // Dessine le point dans la matrice
        x += xIncrement;
        y += yIncrement;
    }
}

void write_circle(Area *area, Circle *circle)
{
    int x = circle->radius;
    int y = 0;
    int decisionOver2 = 1 - x;

    while (y <= x) {
        area->mat[circle->center->x + x][circle->center->y + y] = 1;
        area->mat[circle->center->x + y][circle->center->y + x] = 1;
        area->mat[circle->center->x - x][circle->center->y + y] = 1;
        area->mat[circle->center->x - y][circle->center->y + x] = 1;
        area->mat[circle->center->x - x][circle->center->y - y] = 1;
        area->mat[circle->center->x - y][circle->center->y - x] = 1;
        area->mat[circle->center->x + x][circle->center->y - y] = 1;
        area->mat[circle->center->x + y][circle->center->y - x] = 1;

        y++;

        if (decisionOver2 <= 0) {
            decisionOver2 += 2 * y + 1;
        } else {
            x--;
            decisionOver2 += 2 * (y - x) + 1;
        }
    }
}

void write_square(Area *area, Square *square)
{
    int endX = square->point->x + square->length - 1;
    int endY = square->point->y + square->length - 1;

    // Dessine les côtés horizontaux du carré
    for (int i = square->point->x; i <= endX; i++) {
        area->mat[i][square->point->y] = 1;         // Dessine le côté supérieur
        area->mat[i][endY] = 1;           // Dessine le côté inférieur
    }

    // Dessine les côtés verticaux du carré
    for (int j = square->point->y; j <= endY; j++) {
        area->mat[square->point->x][j] = 1;         // Dessine le côté gauche
        area->mat[endX][j] = 1;           // Dessine le côté droit
    }
}

void write_rect(Area *area, Rectangle *rect)
{
    int endX = rect->point->x + rect->length - 1;
    int endY = rect->point->y + rect->width - 1;

    // Dessine les côtés horizontaux du rectangle
    for (int i = rect->point->x; i <= endX; i++) {
        area->mat[i][rect->point->y] = 1;         // Dessine le côté supérieur
        area->mat[i][endY] = 1;           // Dessine le côté inférieur
    }

    // Dessine les côtés verticaux du rectangle
    for (int j = rect->point->y; j <= endY; j++) {
        area->mat[rect->point->x][j] = 1;         // Dessine le côté gauche
        area->mat[endX][j] = 1;           // Dessine le côté droit
    }
}

void write_poly(Area *area , Polygon *poly)
{
    for (int i = 0; i < poly->nbSommets-1; i++)
    {
        write_line(area, create_line(poly->sommets[i], poly->sommets[i+1]));
    }
    write_line(area, create_line(poly->sommets[poly->nbSommets-1], poly->sommets[0]));
}