#ifndef PROJECT_AREA_H
#define PROJECT_AREA_H

#include "project.h"

#define SHAPE_MAX 100
#define BOOL int

typedef struct shape Shape;

struct area {
    unsigned int width;
    unsigned int height;
    BOOL** mat;
    Shape** shapes;
    int nb_shape;
};

typedef struct area Area;
typedef struct point Point;
typedef struct line Line;
typedef struct circle Circle;
typedef struct square Square;
typedef struct rectangle Rectangle;
typedef struct polygon Polygon;

Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area* area, Shape* shape);
void clear_area(Area* area);
void erase_area(Area* area);
void delete_area(Area* area);
// void draw_area(Area* area);
void print_area(Area* area);

// command.c
struct command {
    char name[50];
    int int_size;
    int* int_params;
    int str_size;
    char** str_params;
};
typedef struct command Command;

Command* create_commande();
void add_str_param(Command* cmd, char* p);
void add_int_param(Command* cmd, int p);
void free_cmd(Command* cmd);
int read_exec_command(Command* cmd, Area* area);
void read_from_stdin(Command* cmd);


void write_point(Area *area, Point *point);
void write_line(Area *area, Line *line);
void write_circle(Area *area, Circle *circle);
void write_square(Area *area, Square *square);
void write_rect(Area *area, Rectangle *rect);
void write_poly(Area *area , Polygon *poly);

#endif
