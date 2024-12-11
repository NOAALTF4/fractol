#include <float.h>

void *ft_get_first_position(int *pos, int x, int y)
{
    pos[0] = (pos[0] * pos[0]) - (pos[1] * pos[1]);
    pos[1] = 2 * x * y;
}

void    ft_fractol(int x, int y)
{
    int position[1];
    float px;
    float py;

    ft_get_first_position(position, x, y);
    while(x < 1920)
    {
        px = (float)((x - (1920 / 2)) * 2);
        py = (float)((y - (1080 / 2)) * 2);
        ft_get_first_position(position, px, py);

        // si c'est inferieur a 0, on print pas. par contte si cest compris entre 0 et 960 par exemple, on print.

        x++;
    }


}