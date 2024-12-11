#include "fractol.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_position_a(int a, int i)
{
	int i_temp;
    int r;
    int nb;

    r = 0;
	i_temp = i; //juste au depart;
	if(i_temp < 0)
		i_temp -= i_temp;
    r = 2 * a * i; // r = 2
	i = (i * i) * -1; // i = -1;
	nb = (a * a) + i;
	nb = nb - 1;
	return(nb);
}

int	ft_position_b(int a, int i)
{
	int i_temp;
    int r;
    int nb;

    r = 0;
	i_temp = i; //juste au depart;
	if(i_temp < 0)
		i_temp -= i_temp;
    r = 2 * a * i; // r = 2
	i = (i * i) * -1; // i = -1;
	nb = (a * a) + i;
	nb = nb - 1;
	return(r);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int	x;
	int	y;
	int a;
	int b;
	int rgb;
	int	temp_a;
	int temp_b;
	int	count;
	int check;
	t_data	img;

	x = 0;
	y = 0;
	a = 0;
	b = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	/*while(a < 1920)
	{
		while(b < 1080)
		{
			temp_a = a;
			temp_b = b;
			printf("a = %d\n", a);
			printf("b = %d\n", b);
			x = ft_position_a(a, b);
			y = ft_position_b(a, b);
			printf("x= %d\n", x);
			printf("y = %d\n", y);
			count = 0;
			check = 0;
			while(count < 5)
			{
				if((ft_position_a(temp_a, temp_b) == ft_position_a(x, y)) && (ft_position_b(temp_a, temp_b) == ft_position_b(x, y)))
				{
					check = 1;
					printf("check = 1\n");
				}
				temp_a = ft_position_a(temp_a, temp_b);
				temp_b = ft_position_b(temp_a, temp_b);
				count ++;
			}
			if(check == 1)
			{
				rgb = (int)0x00FF0000;
				printf("bonjour\n");
			}
			else if (check != 1)
				rgb = (int)0x000000FF;
			if((x >= 0 && x <= 1920) && (y) >= 0 && y <= 1080)
			{
				my_mlx_pixel_put(&img, x, y, rgb);
				mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
			}
			b++;
		}
		b = 0;
		a++;
	}*/

	x = -0,8 ;
	y = 0,156;
	while(count < 200000)
	{
		x = ft_position_a(x, y);
		y = ft_position_b(x, y);
		count++;
	}
	if((x >= 0 && x <= 1920) && (y) >= 0 && y <= 1080)
	{
		my_mlx_pixel_put(&img, x, y, rgb);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	}

	mlx_loop(mlx);
}