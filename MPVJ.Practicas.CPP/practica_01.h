#pragma once

#include "lib/player/player.h"
#include <iostream>

void run_practica_01()
{

    player::player p;

    //  Test Health

    std::cout << "set_health(30)" << std::endl;
    p.save_data->set_health(30);
    std::cout << "    get_health(): " << p.save_data->get_health() << std::endl;

    std::cout << "set_health(25)" << std::endl;
    p.save_data->set_health(25);
    std::cout << "    get_health(): " << p.save_data->get_health() << std::endl;

    std::cout << std::endl;

    //  Test Bullets

    std::cout << "add_bullets(30)" << std::endl;
    p.save_data->add_bullets(30);
    std::cout << "    get_bullets(): " << p.save_data->get_bullets() << std::endl;

    std::cout << "add_bullets(25)" << std::endl;
    p.save_data->add_bullets(25);
    std::cout << "    get_bullets(): " << p.save_data->get_bullets() << std::endl;

    std::cout << std::endl;

    //  Test Brothers

    std::cout << "set_brothers(4)" << std::endl;
    p.save_data->set_brothers(4);
    std::cout << "    get_brothers(): " << p.save_data->get_brothers() << std::endl;

    std::cout << "set_brothers(11)" << std::endl;
    p.save_data->set_brothers(11);
    std::cout << "    get_brothers(): " << p.save_data->get_brothers() << std::endl;

    std::cout << std::endl;

    //  Test Berserk

    std::cout << "set_berserker(true)" << std::endl;
    p.save_data->set_berserker(true);
    std::cout << "    is_berserker(): " << p.save_data->is_berserker() << std::endl;

    std::cout << "set_berserker(false)" << std::endl;
    p.save_data->set_berserker(false);
    std::cout << "    is_berserker(): " << p.save_data->is_berserker() << std::endl;

    std::cout << std::endl;

    //  Test shield

    std::cout << "set_shield(true)" << std::endl;
    p.save_data->set_shield(true);
    std::cout << "    is_shield(): " << p.save_data->is_shield() << std::endl;

    std::cout << "set_shield(false)" << std::endl;
    p.save_data->set_shield(false);
    std::cout << "    is_shield(): " << p.save_data->is_shield() << std::endl;

    std::cout << std::endl;

    //  Test InfBullets

    std::cout << "set_infBullets(true)" << std::endl;
    p.save_data->set_infBullets(true);
    std::cout << "    is_infBullets(): " << p.save_data->is_infBullets() << std::endl;

    std::cout << "set_infBullets(false)" << std::endl;
    p.save_data->set_infBullets(false);
    std::cout << "    is_infBullets(): " << p.save_data->is_infBullets() << std::endl;

    std::cout << std::endl;

    //  Test God

    std::cout << "set_god(true)" << std::endl;
    p.save_data->set_god(true);
    std::cout << "    is_god(): " << p.save_data->is_god() << std::endl;

    std::cout << "set_god(false)" << std::endl;
    p.save_data->set_god(false);
    std::cout << "    is_god(): " << p.save_data->is_god() << std::endl;

    std::cout << std::endl;
}
