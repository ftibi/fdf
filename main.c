#include "mlx.h"
#include "libft/includes/libft.h"

int my_key_funct(int keycode, void *param)
{
    ft_putstr("key event :");
    ft_putnbr(keycode);
    ft_putchar('\n');
    return (0);
}

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 400, 400, "mlx 42");
    mlx_pixel_put(mlx, win, 200, 200, 0xFFFFFF);
    mlx_key_hook(win, my_key_funct, 0);
    mlx_loop(mlx);
    return (0);
}
