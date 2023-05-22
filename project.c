#include "project.h"

int main()
{
    int rows = 0, columns = 0;

    printf("What size do you want for the grid (recommended at least : 40/40) ? (columns/rows) : ");
    fflush(stdin);
    scanf("%d/%d", &columns, &rows);
    Area *area = create_area(columns, rows);

    area->mat = createGrid(area->mat, &area->height, &area->width);
    print_grid(area->mat);

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
        Command *cmd = create_commande();
        read_from_stdin(cmd);

        run = read_exec_command(cmd, area);
        free_cmd(cmd);
    }

    for (ui i = 0; i < area->height; i++)
    {
        free(area->mat[i]);
    }
    free(area->mat);
    return 0;
}

void print_grid(BOOL **grid)
{
    system("cls||clear");
    for (int i = 0; grid[i]; i++)
    {
        for (int j = 0; grid[i][j]; j++)
        {
            if (grid[i][j] == 0)
                printf(".");
            else
                printf("#");
        }
        printf("\n");
    }
    printf("\n");
}

BOOL **createGrid(BOOL **grid, ui *rows, ui *columns)
{
    grid = (BOOL**)malloc(sizeof(BOOL *) * ((*columns) + 1));
    if (grid == NULL)
        return NULL;
    for (ui i = 0; i < *columns; i++)
    {
        grid[i] = (BOOL*)malloc(sizeof(BOOL) * ((*rows) + 1));
        if (grid[i] == NULL)
            return NULL;
        for (ui j = 0; j < *rows; j++)
        {
            grid[i][j] = 0;
        }
    }
    return grid;
}