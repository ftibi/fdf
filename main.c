#include "mlx.h"
#include "libft/includes/libft.h"

int my_key_funct(int keycode, void *param)
{
    ft_putstr("key event :");
    ft_putnbr(keycode);
    ft_putchar('\n');
    if (keycode == 53)
    {
        ft_putendl("exit");
        exit(0);
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

	a = 200;
	b = 200;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 400, 400, "mlx 42");
    
	mlx_pixel_put(mlx, win, a, b, 0xFFFFFF);
    y = 0;
    while (y <= 400)
    {
    	x = 0;
		while (x <= 400)
		{
			dist = (x - a) * (x - a) + (y - b) * (y - b);
			if ( dist <= (50 * 50))
				mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			x++;
		}
		y++;
    }
    mlx_key_hook(win, my_key_funct, 0);
    mlx_loop(mlx);
    return (0);
}
