#ifndef PROJECT_AREA_H
#define PROJECT_AREA_H

#include "project.h"

#define SHAPE_MAX 100
#define BOOL int

typedef struct shape Shape;

// area.c

// definition of the structure area
struct area {
    unsigned int width;   // width of the area
    unsigned int height;  // height of the area
    BOOL** mat;           // 2D list
    Shape** shapes;       // pointer that point a list that contains all the pointer of shape
    int nb_shape;         // number of shape in the previous list
};

// We define the structure area as a type
typedef struct area Area;


// We generalize all the function in area.c for use it in the project
Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area* area, Shape* shape);
void clear_area(Area* area);
void erase_area(Area* area);
void draw_area(Area* area);
void print_area(Area* area);

void write_point(Area *area, Point *point);
void write_line(Area *area, Line *line);
void write_circle(Area *area, Circle *circle);
void write_square(Area *area, Square *square);
void write_rect(Area *area, Rectangle *rect);
void write_poly(Area *area , Polygon *poly);

// command.c
// structure that stores information when the user orders
struct command {
    char name[50];   // name of the command
    int int_size;    // size of the list int_params
    int* int_params; // list that contain all the parameters of the command
};

typedef struct command Command;

// Implemante the function in the project
Command* create_commande();
void add_int_param(Command* cmd, int p);
void free_cmd(Command* cmd);
int read_exec_command(Command* cmd, Area* area);
void read_from_stdin(Command* cmd);
int verif_command(Command* cmd);

#endif
