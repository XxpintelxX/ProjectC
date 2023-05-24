// file that manages the user's commands

#include "project.h"
#include "area.h"

// function that create a command
Command* create_commande()
{
    Command* cmd = (Command*) malloc(sizeof(Command)); // allocate memory for a command
    cmd->int_size = 0; // initialize the variable that contain the number of parameters
    cmd->int_params = (int*) malloc(sizeof(int) * 10); // allocate memory for parameter
    return cmd;
}

// function that add a parameter given in the list of parameters
void add_int_param(Command* cmd, int p)
{
    cmd->int_params[cmd->int_size] = p; // add the parameter in the list
    cmd->int_size += 1; // add 1 because we have add a parameter
}

// free the memory allocated
void free_cmd(Command* cmd)
{
    free(cmd);
}

// function that ask to the user to enter a command
void read_from_stdin(Command* cmd)
{
    char input[50];
    int i = 0;

    printf(">>>");
    fgets(input, sizeof(input), stdin); // allows to recup the command of the user

    // Removes the line feed character ('\n') at the end of the string if present
    size_t inputLength = strlen(input);
    if (inputLength > 0 && input[inputLength - 1] == '\n') {
        input[inputLength - 1] = '\0';
    }

    char* token;
    char* rest = input;

    // split the command into severals string to analyse one by one
    while ((token = strtok_r(rest, " ", &rest))) {
        if (i == 0){
            strcpy(cmd->name, token);
            i = 1;
        }
        else if (atoi(token) != 0){
            add_int_param(cmd, atoi(token));
        }
    }
}

// function that verificate if the command entered is good or not, return 0 if bad, 1 else
int verif_command(Command* cmd){
    if (strcmp(cmd->name, "exit") == 0){
        if (cmd->int_size !=0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (strcmp(cmd->name, "clear") == 0){
        if (cmd->int_size !=0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (strcmp(cmd->name, "point") == 0){
        if (cmd->int_size !=2){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (strcmp(cmd->name, "line") == 0){
        if (cmd->int_size !=4){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (strcmp(cmd->name, "circle") == 0){
        if (cmd->int_size !=3){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (strcmp(cmd->name, "square") == 0){
        if (cmd->int_size !=3){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (strcmp(cmd->name, "rectangle") == 0){
        if (cmd->int_size !=4){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (strcmp(cmd->name, "polygon") == 0){
        return 1;
    }
    else if (strcmp(cmd->name, "plot") == 0){
        if (cmd->int_size !=0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (strcmp(cmd->name, "list") == 0){
        if (cmd->int_size !=0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (strcmp(cmd->name, "delete") == 0){
        if (cmd->int_size !=1){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (strcmp(cmd->name, "erase") == 0){
        if (cmd->int_size !=0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (strcmp(cmd->name, "help") == 0){
        if (cmd->int_size !=0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}

int read_exec_command(Command* cmd, Area* area){
    if (strcmp(cmd->name, "exit") == 0){
        return 0;
    }
    else if (strcmp(cmd->name, "clear") == 0){
        system("clear");
        clear_area(area);
        print_area(area);
    }
    else if (strcmp(cmd->name, "point") == 0){
        int px = cmd->int_params[0];
        int py = cmd->int_params[1];
        add_shape_to_area(area, create_point_shape(px, py));
        return 1;
    }
    else if (strcmp(cmd->name, "line") == 0){
        int x1 = cmd->int_params[0];
        int y1 = cmd->int_params[1];
        int x2 = cmd->int_params[2];
        int y2 = cmd->int_params[3];
        add_shape_to_area(area, create_line_shape(x1, y1, x2, y2));
        return 1;
    }
    else if (strcmp(cmd->name, "circle") == 0){
        int x = cmd->int_params[0];
        int y = cmd->int_params[1];
        int radius = cmd->int_params[2];
        add_shape_to_area(area, create_circle_shape(x, y, radius));
        write_circle(area, create_circle(create_point(x, y), radius));
        return 1;
    }
    else if (strcmp(cmd->name, "square") == 0){
        int x = cmd->int_params[0];
        int y = cmd->int_params[1];
        int length = cmd->int_params[2];
        add_shape_to_area(area, create_square_shape(x, y, length));
        return 1;
    }
    else if (strcmp(cmd->name, "rectangle") == 0){
        int x = cmd->int_params[0];
        int y = cmd->int_params[1];
        int width = cmd->int_params[2];
        int height = cmd->int_params[3];
        add_shape_to_area(area, create_rectangle_shape(x, y, width, height));
        return 1;
    }
    else if (strcmp(cmd->name, "polygon") == 0){
        add_shape_to_area(area, create_polygon_shape(cmd->int_params[0]));
        return 1;
    }
    else if (strcmp(cmd->name, "plot") == 0){
        system("clear");
        clear_area(area);
        draw_area(area);
        print_area(area);
        return 1;
    }
    else if (strcmp(cmd->name, "list") == 0){
        if (area->nb_shape == 0){
            printf("No shape in the area\n");
        }
        else{
            printf("Here are the different shapes you have in aire: \n");
            for (int i = 0 ; i < area->nb_shape; i++)
            {
                switch (area->shapes[i]->shape_type) {
                    case 0:
                        printf("id : %d ", area->shapes[i]->id);
                        print_point(area->shapes[i]->ptrShape);
                        break;
                    case 1:
                        printf("id : %d ", area->shapes[i]->id);
                        print_line(area->shapes[i]->ptrShape);
                        break;
                    case 2:
                        printf("id : %d ", area->shapes[i]->id);
                        print_square(area->shapes[i]->ptrShape);
                        break;
                    case 3:
                        printf("id : %d ", area->shapes[i]->id);
                        print_rectangle(area->shapes[i]->ptrShape);
                        break;
                    case 4:
                        printf("id : %d ", area->shapes[i]->id);
                        print_circle(area->shapes[i]->ptrShape);
                        break;
                    case 5:
                        printf("id : %d ", area->shapes[i]->id);
                        print_polygon(area->shapes[i]->ptrShape);
                        break;
                    default:
                        break;
                }
            }
        }
        return 1;
    }
    else if (strcmp(cmd->name, "delete") == 0){
        int i, j;
        for (i = 0; i < area->nb_shape; i++)
        {
            if(area->shapes[i]->id == cmd->int_params[0])
            {
                area->nb_shape -= 1;
                break;
            }
        }
        for (j = i; j < area->nb_shape; j++){
            area->shapes[j] = area->shapes[j+1];
        }
        system("clear");
        clear_area(area);
        draw_area(area);
        print_area(area);
    }
    else if (strcmp(cmd->name, "erase") == 0){
        system("clear");
        erase_area(area);
        draw_area(area);
        print_area(area);
        return 1;
    }
    else if (strcmp(cmd->name, "help") == 0){
        printf("Here are the different commands available:\n"
               "\t- clear: clear the screen\n"
               "\t- exit: exit the program\n"
               "\t- point x y: add a point with coordinate x and y\n"
               "\t- line x1 y1 x2 y2: add a segment connecting two points (x1, y1) and (x2, y2)\n"
               "\t- circle x y radius: add a circle of centre (x, y) and a radius radius\n"
               "\t- square x y length: add a square whose upper left conner is (x, y) and whose side is length\n"
               "\t- rectangle x y width height: add a rectangle whose upper left corner is (x, y), whose width is width and whose height is height\n"
               "\t- polygon number of vertexes: add a polygon with a number of vertexes\n"
               "\t- plot: refresh the screen to display all the geometric shapes in the image\n"
               "\t- list: display a list of all geometric shapes with all their information\n"
               "\t- delete id: delete a shape from its identifier id\n"
               "\t- erase: remove all shapes from an image\n"
               "\t- help: display the list of all the commands with how their works\n");
        return 1;
    }
    else{
        printf("The command enter isn't valid\n");
        return 1;
    }
    return 1;
}
