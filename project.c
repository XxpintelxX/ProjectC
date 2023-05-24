#include "project.h"
#include "area.h"

int main()
{
    system("clear");
    int rows = 0, columns = 0;

    printf("What size do you want for the grid (recommended at least : 40/40) ? (columns/rows) : ");
    fflush(stdin);
    scanf("%d/%d", &columns, &rows);
    Area *area = create_area(columns, rows);

    clear_area(area);
    print_area(area);

    if (menu(area) != 0)
        printf("Error");
    system("cls||clear");
    return 0;
}

int menu(Area *area)
{
    int run = 1;
    while (run)
    {
        fflush(stdin);
        Command *cmd = create_commande();
        read_from_stdin(cmd);
        if (verif_command(cmd) == 1){
            run = read_exec_command(cmd, area);
        }
        else{
            printf("Invalid command\n");
        }
        free_cmd(cmd);
    }

    for (ui i = 0; i < area->height; i++)
    {
        free(area->mat[i]);
    }
    free(area->mat);
    return 0;
}