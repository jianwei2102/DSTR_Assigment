#pragma once

#include "mainMenuUI.h"
#include "adminMenu.h"
#include "userMenu.h"
#include "guestMenu.h"

using namespace std;

static void mainMenu() {
    while (true)
    {
        // call the functions declared in views.
        system("cls");
        int choice = mainMenu_UI();

        switch (choice)
        {
        case 1:
            adminMenu::adminLogin();
            break;
        case 2:
            userMenu::userLogin();
            // user sign in
            break;
        case 3:
            // register
            guestMenu::registerMenu();
            break;
        case 4:
            // guest
            guestMenu::mainMenu();
            break;
        case 5:
            // exit system
            return;
        default:
            mainMenu();
            break;
        }
    }
}