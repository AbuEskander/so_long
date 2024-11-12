#include "so_long.h"

int main(void)
{
    void *mlx;          // Pointer for mlx instance
    void *mlx_win;      // Pointer for mlx window

    // Initialize mlx
    ft_printf("Hey!");
    mlx = mlx_init();
    if (mlx == NULL)
        return (1); // Handle initialization error

    // Create a new window
    mlx_win = mlx_new_window(mlx, 800, 600, "My First MLX Window");
    if (mlx_win == NULL)
    {
        return (1); // Handle window creation error
    }

    // Loop to keep the window open
    mlx_loop(mlx);

    return (0);
}
