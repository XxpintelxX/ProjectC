#include "project.h"
#include "area.h"

Command* create_commande()
{
    Command* cmd = (Command*) malloc(sizeof(Command));
    cmd->int_size = 0;
    cmd->int_params = (int*) malloc(sizeof(int) * 10);
    cmd->str_size = 0;
    // cmd->str_params = (char*) malloc(sizeof(char) * 50);
    return cmd;
}

void add_str_param(Command* cmd, char* p)
{
    cmd->str_size += 1;
}

void add_int_param(Command* cmd, int p)
{
    cmd->int_params[cmd->int_size] = p;
    cmd->int_size += 1;
}

void free_cmd(Command* cmd)
{
    free(cmd);
}

int read_exec_command(Command* cmd, Area* area)
{
    if (strcmp(cmd->name, "exit") == 0){
        return 0;
    }
    else if (strcmp(cmd->name, "clear") == 0){
        return 1;
    }
    else if (strcmp(cmd->name, "point") == 0){
        int px = cmd->int_params[0];
        int py = cmd->int_params[1];
        add_shape_to_area(area, create_point_shape(px, py));
        write_point(area, create_point(px, py));
        return 1;   
    }
    else if (strcmp(cmd->name, "line") == 0){
        int x1 = cmd->int_params[0];
        int y1 = cmd->int_params[1];
        int x2 = cmd->int_params[2];
        int y2 = cmd->int_params[3];
        add_shape_to_area(area, create_line_shape(x1, y1, x2, y2));
        write_line(area, create_line(create_point(x1, y1), create_point(x2, y2)));
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
        write_square(area, create_square(create_point(x, y), length));
        return 1;
    }
    else if (strcmp(cmd->name, "rectangle") == 0){
        int x = cmd->int_params[0];
        int y = cmd->int_params[1];
        int width = cmd->int_params[2];
        int height = cmd->int_params[3];
        add_shape_to_area(area, create_rectangle_shape(x, y, width, height));
        write_rect(area, create_rectangle(create_point(x, y), width, height));
        return 1;
    }
    else if (strcmp(cmd->name, "polygon") == 0){
        // int x1 = cmd->int_params[0];
        // int y1 = cmd->int_params[2];
        // int x2 = cmd->int_params[3];
        // int y2 = cmd->int_params[4];
        // int x3 = cmd->int_params[5];
        // int y3 = cmd->int_params[6];
        // add_shape_to_area(area, create_polygon_shape())
        write_poly(area, create_polygon(cmd->int_params[0]));
        return 1;
    }
    else if (strcmp(cmd->name, "plot") == 0){
        system("clear");
        print_area(area);
        return 1;
    }
    else if (strcmp(cmd->name, "list") == 0){
        printf("Voici les differentes shapes que vous avez dans aire: \n");
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
        return 1;
    }
    else if (strcmp(cmd->name, "delete") == 0){
        for (int i = 0; i < area->nb_shape; i++){
            if (area->shapes[i]->id == cmd->int_params[0])
            {
                printf("On enleve la figure %d\n\n", cmd->int_params[0]);
            }
        }
        return 1;
    }
    else if (strcmp(cmd->name, "erase") == 0){
        clear_area(area);
        return 1;
    }
    else if (strcmp(cmd->name, "help") == 0){
        printf("Voici les differentes commandes disponibles:\n"
               "\t- clear\n"
               "\t- exit\n"
               "\t- point x y\n"
               "\t- line x1 y1 x2 y2\n"
               "\t- circle x y radius\n"
               "\t- square x y length\n"
               "\t- rectangle x y width height\n"
               "\t- polygon number of vertexes\n"
               "\t- plot\n"
               "\t- list\n"
               "\t- delete id\n"
               "\t- erase\n"
               "\t- help\n");
        return 1;
    }
    else{
        printf("The command enter isn't valid\n");
        return 1;
    }
}

void read_from_stdin(Command* cmd)
{
    char input[50];
    int i = 0;

    printf(">>>");
    fgets(input, sizeof(input), stdin);

    // Supprime le caractère de saut de ligne ('\n') à la fin de la chaîne si présent
    size_t inputLength = strlen(input);
    if (inputLength > 0 && input[inputLength - 1] == '\n') {
        input[inputLength - 1] = '\0';
    }

    char* token;
    char* rest = input;

    while ((token = strtok_r(rest, " ", &rest))) {
        if (i == 0){
            strcpy(cmd->name, token);
            i = 1;
        }
        else if (atoi(token) != 0){
            add_int_param(cmd, atoi(token));
        }
        else{
            add_str_param(cmd, token);
        }

    }
}