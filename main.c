#include "mlx.h"
#include "libft/includes/libft.h"

typedef struct s_data
{
	void *mlx;
	void *win;
	int x;
	int y;
	int a;
	int b;
	int dist;
	int zoom;
}				t_data;
//utiliser mlx_clear_window a la place OMFG
void aff(t_data *data)
{
	data->y = 0;
	while (data->y <= 400)
	{
		data->x = 0;
		while (data->x <= 400)
		{
			data->dist =  (data->x - data->a) * (data->x - data->a) + (data->y - data->b) * (data->y - data->b);
			if ( data->dist == data->zoom * (50 * 50))
				mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0xFFFFFF);
			data->x++;
		}
		data->y++;
	}
}

int	expose_hook(t_data *data)
{
	return (0);
}

int my_key_funct(int keycode, t_data *data)
{
	ft_putstr("key event : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
	{
		ft_putendl("exit");
		exit(0);
	}
	if (keycode == 35)
	{
		ft_putendl("zoom");
		(data->zoom)++;
		ft_putnbr(data->zoom);
		ft_putendl("");
		mlx_put_image_to_window(data->mlx, data->win, mlx_new_image(data->mlx, 400, 400), 0 ,0);
		aff(data);
	}
	return (0);
}

int main()
{
	void *mlx;
	void *win;
	int x;
	int y;
	int a;
	int b;
	int dist;
	int zoom;
	t_data *data;

	data = (t_data*)ft_memalloc(sizeof(t_data));
	a = 200;
	b = 200;
	ft_putendl("X");
	zoom = 1;
	ft_putendl("Z");

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");

	mlx_pixel_put(mlx, win, a, b, 0xFFFFFF);

	data->x = x;
	data->y = y;
	data->a = a;
	data->b = b;
	data->win  = win;
	data->mlx  = mlx;
	data->zoom  = zoom;
	data->dist  = dist;
	aff(data);
	mlx_key_hook(win, my_key_funct, data);
	mlx_loop(mlx);
	return (0);
}
