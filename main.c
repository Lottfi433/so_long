#include "mlx.h"

int main(void)
{
    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
    (void)mlx_win;  // Suppresses the unused variable warning

    mlx_loop(mlx);  // Keeps the window open and listens for events
    return (0);
}
