void	add_rays(t_data *data)
{
	while (angle >= data->player.angle - 0.5)
	{
		i = 0;
		x = data->player.x;
		y = data->player.y;
		while (i <= 500)
		{
			// put_pixel_img(data->background, x, y, 0xcd5c5c);
			delta_x = cos(angle);
			delta_y = sin(angle);
			x += delta_x;
			y += delta_y;
			if (check_wall(data, x, y) == 1)
			{
				add_wall(data, x, y, angle);
				break ;
			}
			i++;
		}
		angle -= 0.01;
	}
	angle = data->player.angle;
	while (angle <= data->player.angle + 0.5)
	{
		i = 0;
		x = data->player.x;
		y = data->player.y;
		while (i <= 500)
		{
			// put_pixel_img(data->background, x, y, 0xcd5c5c);
			delta_x = cos(angle);
			delta_y = sin(angle);
			x += delta_x;
			y += delta_y;
			if (check_wall(data, x, y) == 1)
			{
				add_wall(data, x, y, angle);
				break ;
			}
			i++;
		}
		angle += 0.01;
	}
}

void	add_ceiling(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x <= WIDTH)
		{
			put_pixel_img(data->background, x, y, 0x87ceeb);
			x++;
		}
		y++;
	}
}

void	add_floor(t_data *data)
{
	int	x;
	int	y;

	y = HEIGHT / 2;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			put_pixel_img(data->background, x, y, 0x2f4f4f);
			x++;
		}
		y++;
	}
}

void	print_line(t_data *data, float x, float y, float size)
{
	while (y <= size)
	{
		put_pixel_img(data->background, x, y, 0xf8f8ff);
		y++;
	}
}

void	add_wall(t_data *data, float x, float y, float angle)
{
	double	dx;
	double	dy;
	double	distance;
	float	delta;

	printf("welcome\n");
	dx = x - data->player.x;
	dy = y - data->player.y;
	distance = sqrt(dx * dx + dy * dy);
	delta = (data->player.angle - angle) * 500;
	printf("distance: %f\n", distance);
	printf("x: %f\n", WIDTH / 2 - delta);
	printf("y: %f\n", HEIGHT / 2 - distance / 2);
	print_line(data, WIDTH / 2 - delta, HEIGHT / 2 - distance / 2, distance);
}

int	check_wall(t_data *data, float x, float y)
{
	int	xx;
	int	yy;

	xx = (int)x;
	yy = (int)y;
	if (data->map.tab[yy / 64][xx / 64] == '1')
		return (1);
	return (0);
}
