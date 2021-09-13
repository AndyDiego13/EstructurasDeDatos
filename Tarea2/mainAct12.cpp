/*
    Actividad 1.2 Algoritmos de Busqueda y Ordenamiento

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    8/Sept/2021
*/

#include <iostream>
#include <vector>
#include "Motocicleta.hpp"
#include "Camioneta.hpp"
#include "Dealership.hpp"
#include "Automovil.hpp"

std::vector <Dealership> users;

Dealership createAccount()
{
    std::cout << "------ Sign up -----" << std::endl;

    std::string n;
    std::cout << "Enter your name: " << std::endl;
    std::cin >> n;

    std::string l;
    std::cout << "Enter your last name: " << std::endl;
    std::cin >> l;

    std::string e;
    std::cout << "Enter your INE: " << std::endl;
    std::cin >> e;

    std::cout << "Complete your account has been saved." << std::endl;

    users.push_back(Dealership(n,l,e));
}

Dealership singUp()
{
    std::string nm;
    std::cout << "Login once you have registered" << std::endl;
    std::cout << "Enter your name: " << std::endl;
    std::cin >> nm;

    std::string ln;
    std::cout << "Enter your last name: " << std::endl;
    std::cin >> ln;

    bool existingUser = false;

    for (std::vector<Dealership>::iterator u = users.begin(); u != users.end(); ++u)
    {
        if (u -> getName() == nm)
        {
            existingUser = true;
            std::cout << "User found" << std::endl;
            std::cout << "----- Welcome -----" << std::endl;
            return *u;
        }
    }

    if (existingUser == false)
    {
        std::cout << "User not found. Try again" << std::endl;
        std::cout << "Opps... There was an error press 1 to try again or press 2 to register a new user." << std::endl;
        int op;
        std::cin >> op;
        if (op == 1)
        {
            return singUp();
        }
        else if (op == 2)
        {
            return createAccount();
        }
    }
}

Dealership actualUser = Dealership("user", "lastname", "ine");



int main()
{
    Automovil auts;
    Motocicleta motos;
    Camioneta camion;
    struct sales
    {
        int sale;
    };

    sales *s = new sales[20];
    
    int option;
    //Se muestran las opciones
    do
    {
        std::cout << "-----DEALERSHIP-----" << std::endl;
        std::cout << "Option menu:" << std::endl;
        std::cout << "1. Sign up" << std::endl;
        std::cout << "2. Select what type of car are you looking for" << std::endl;
        std::cout << "3. Buy a vehicle" << std::endl;
        std::cout << "4. Do another sale" << std::endl;
        std::cout << "5. Quit the program" << std::endl;
        std::cout << "Choose an option:" << std::endl;
        std::cin >> option;

        switch (option)
        {
        case 1:
            int op;
            std::cout << "Create an account" << std::endl;
            if(op == 1)
            {
                createAccount();
            }
            else if (op == 2)
            {
                actualUser = singUp();
            }
            break;
        case 2:
            int p;
            std::cout << "Select what are you looking for: " << std::endl;
            if (p == 1)
            {
                auts.showCars();
            }
            else if (p == 2)
            {
                motos.showMotocicletas();
            }
            else if (p == 3)
            {
                camion.showCamionetas();
            }
            break;
        
        case 3:
            
        
        default:
            break;
        }
        
    } while (option != 0);
    
    

    return 0;
}