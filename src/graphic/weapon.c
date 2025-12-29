#include "weapon_bonus.h"


static void put_pixel(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int *)dst = color;
}

static int get_pixel(t_img *img, int x, int y)
{
    return (*(int *)(img->addr + (y * img->linelen + x * (img->bpp / 8))));
}
void load_gun(t_game *game)
{
    game->gun.img.img = mlx_xpm_file_to_image(
        game->mlx;
        "../../asset/bonus_asset/gun.xpm",
        &game->gun.img.w,
        &game->gun.img.h
    );
    if (!game->gun.img.img)
        write(1, "error\n",7);
    game->gun.img.addr = mlx_get_data_addr(
        game->gun.img.img,
        &game->gun.img.bpp,
        &game->gun.img.line_len,
        &game->gun.img.endian
    );
}

void draw_gun(t_game *game)
{
    int x;
    int y;
    int sx;
    int sy;
    int color;

    sx = (game->width - game->gun.img.w / 2);
    sy = (WIN_HEIGHT - game->gun.img.h);
    y = 0;
    while (y < game->gun.img.h)
    {
        x = 0;
        while (x < game->gun.img.w)
        {
            color = get_pixel(&game->gun.img, x, y);
            if (color != 0x2D992C)
                put_pixel(gun.img, sx + x,sy + y,color);
            x++;
        }
        y++;
    }
}