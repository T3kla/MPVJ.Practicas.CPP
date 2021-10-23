#pragma once

#include "lib/console/console.h"
#include "lib/entity/entity.h"
#include "lib/point/point.h"
#include <Windows.h>
#include <iostream>

int boundary_x = 80;
int boundary_y = 25;
int margin_x = 10;
int margin_y = 4;

void draw_01(entity &value)
{
    clsw::gotoxy(value.position.x, value.position.y);
    std::cout << '*';
}

void move_01(entity &value)
{
    value.position.x++;
    value.position.y++;
}

void draw_02(entity &value)
{
    clsw::gotoxy(value.position.x, value.position.y);
    std::cout << '&';
}

void move_02(entity &value)
{
    value.position.x++;
    value.position.y--;
}

void draw_03(entity &value)
{
    clsw::gotoxy(value.position.x, value.position.y);
    std::cout << '~';
}

void move_03(entity &value)
{
    value.position.x--;
    value.position.y++;
}

void draw_04(entity &value)
{
    clsw::gotoxy(value.position.x, value.position.y);
    std::cout << '#';
}

void move_04(entity &value)
{
    value.position.x--;
    value.position.y--;
}

void validate_pos(point_i &value)
{
    if (value.x >= boundary_x - margin_x)
        value.x = margin_x;
    if (value.x < margin_x)
        value.x = boundary_x - margin_x - 1;

    if (value.y >= boundary_y - margin_y)
        value.y = margin_y;
    if (value.y < margin_y)
        value.y = boundary_y - margin_y - 1;
}

void run_practica_04()
{

    delegate del_01[2] = {&draw_01, &move_01};
    delegate del_02[2] = {&draw_02, &move_02};
    delegate del_03[2] = {&draw_03, &move_03};
    delegate del_04[2] = {&draw_04, &move_04};

    std::unique_ptr<entity> entities[4] = {
        std::make_unique<entity>(point_i(18, 20), del_01), std::make_unique<entity>(point_i(36, 8), del_02),
        std::make_unique<entity>(point_i(57, 15), del_03), std::make_unique<entity>(point_i(75, 25), del_04)};

    while (true)
    {
        std::cout << "la rica interfaz" << std::endl;

        for (size_t y = 0; y < boundary_y; y++)
            for (size_t x = 0; x < boundary_x; x++)
            {
                if (x == margin_x - 1 && y >= margin_y - 1 && y <= boundary_y - margin_y)
                {
                    clsw::gotoxy(x, y);
                    std::cout << (unsigned char)124;
                }
                else if (x == boundary_x - margin_x && y >= margin_y - 1 && y <= boundary_y - margin_y)
                {
                    clsw::gotoxy(x, y);
                    std::cout << (unsigned char)124;
                }
                else if (y == margin_y - 1 && x > margin_x - 1 && x < boundary_x - margin_x)
                {
                    clsw::gotoxy(x, y);
                    std::cout << (unsigned char)45;
                }
                else if (y == boundary_y - margin_y && x > margin_x - 1 && x < boundary_x - margin_x)
                {
                    clsw::gotoxy(x, y);
                    std::cout << (unsigned char)45;
                }
            }

        for (size_t i = 0; i < 4; i++)
        {
            entities[i]->behaviour[1](*entities[i]);
            validate_pos(entities[i]->position);
            entities[i]->behaviour[0](*entities[i]);
        }

        clsw::hidecursor(); // no funca
        Sleep(60);
        clsw::clear();
    }
}
