#pragma once

#include "lib/console/console.h"
#include "lib/entity/entity.h"
#include "lib/point/point.h"
#include <Windows.h>
#include <iostream>

namespace p04
{

int size_x = 120;
int size_y = 25;
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
    if (value.x >= p04::size_x - p04::margin_x)
        value.x = p04::margin_x;
    if (value.x < p04::margin_x)
        value.x = p04::size_x - p04::margin_x - 1;

    if (value.y >= p04::size_y - p04::margin_y)
        value.y = p04::margin_y;
    if (value.y < p04::margin_y)
        value.y = p04::size_y - p04::margin_y - 1;
}

} // namespace p04

void run_practica_04()
{

    delegate del_01[2] = {&p04::draw_01, &p04::move_01};
    delegate del_02[2] = {&p04::draw_02, &p04::move_02};
    delegate del_03[2] = {&p04::draw_03, &p04::move_03};
    delegate del_04[2] = {&p04::draw_04, &p04::move_04};

    std::unique_ptr<entity> entities[4] = {
        std::make_unique<entity>(point_i(18, 20), del_01), std::make_unique<entity>(point_i(36, 8), del_02),
        std::make_unique<entity>(point_i(57, 15), del_03), std::make_unique<entity>(point_i(75, 25), del_04)};

    while (true)
    {
        const char *lri = "La rica interfaz";
        int y = p04::margin_y - 2;
        int x = (int)floor(static_cast<unsigned long long>(p04::margin_x + (float)(p04::size_x / 2) - strlen(lri)));

        for (int i = 0; i < y; i++)
            std::cout << std::endl;
        for (int i = 0; i < x; i++)
            std::cout << ' ';
        std::cout << lri << std::endl;

        for (y = 0; y < p04::size_y; y++)
            for (x = 0; x < p04::size_x; x++)
            {
                if (x == p04::margin_x - 1 && y >= p04::margin_y - 1 && y <= p04::size_y - p04::margin_y)
                {
                    clsw::gotoxy(x, y);
                    std::cout << (unsigned char)124;
                }
                else if (x == p04::size_x - p04::margin_x && y >= p04::margin_y - 1 && y <= p04::size_y - p04::margin_y)
                {
                    clsw::gotoxy(x, y);
                    std::cout << (unsigned char)124;
                }
                else if (y == p04::margin_y - 1 && x > p04::margin_x - 1 && x < p04::size_x - p04::margin_x)
                {
                    clsw::gotoxy(x, y);
                    std::cout << (unsigned char)45;
                }
                else if (y == p04::size_y - p04::margin_y && x > p04::margin_x - 1 && x < p04::size_x - p04::margin_x)
                {
                    clsw::gotoxy(x, y);
                    std::cout << (unsigned char)45;
                }
            }

        for (size_t i = 0; i < 4; i++)
        {
            entities[i]->behaviour[1](*entities[i]);
            p04::validate_pos(entities[i]->position);
            entities[i]->behaviour[0](*entities[i]);
        }

        clsw::hidecursor(); // no funca
        Sleep(60);
        clsw::clear();
    }
}
