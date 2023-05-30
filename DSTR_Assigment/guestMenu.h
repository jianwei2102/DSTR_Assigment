#pragma once

#include <iostream>

#include "guestMenuUI.h"
#include "repository.h"

struct guestMenu
{
	static void mainMenu() {
		Repository* r = Repository::getInstance();

		while (true) {
			system("cls");
			int choice = guestMenuUI::mainMenu_UI();

			switch (choice) {
				case 1:
					r->AllUniList->displayUniList();
					break;;
				case 2:
                    uniSortMenu();
					break;
				case 3:
					break;
				case 4:
					break;
                case 5:
                    return;
                default:
                    mainMenu();
                    break;
			}
			
		}
	}

	static void uniSortMenu() {
        system("cls");
		int choice = guestMenuUI::uniSort_UI();

		switch (choice)
		{
		case 1:
			mergeSortMenu();
			break;
		case 2:
			quickSortMenu();
			break;
		case 3:
			sortingComparision();
			break;
		case 4:
			return;
		default:
			return;
		}
	}

    static void quickSortMenu() {
        Repository* r = Repository::getInstance();

        while (true) {
            cout << endl;
            QuickSort::quickSort(r->AllUniList->UniArray, 0, 1421, "Institution");
            QuickSort::printByPagination(r->AllUniList->UniArray, "Institution");
            cout << endl;

            string input;
            cout << "Enter any other key to exit: ";
            cin >> input;

            break;
        }
        return;
    }

    static void mergeSortMenu() {
        Repository* r = Repository::getInstance();

        while (true) {
            cout << endl;
            MergeSort::mergeSort(r->AllUniList->UniArray, 0, 1421);
            MergeSort::printByPagination(r->AllUniList->UniArray);
            cout << endl;

            string input;
            cout << "Enter any other key to exit: ";
            cin >> input;

            break;
        }
        return;
    }

    static void sortingComparision() {
        Repository* r = Repository::getInstance();

        //quick sort
        auto startQuickSortTimer = chrono::high_resolution_clock::now();
        QuickSort::quickSort(r->AllUniList->UniArray, 0, 1421, "Ar");
        auto stopQuickSortTimer = chrono::high_resolution_clock::now();

        //TODO:: merge sort
        auto startMergeSortTimer = chrono::high_resolution_clock::now();
        MergeSort::mergeSort(r->AllUniList->UniArray, 0, 1421);
        auto stopMergeSortTimer = chrono::high_resolution_clock::now();

        //calculate quick sort duration
        auto quickSortDuration = chrono::duration_cast<chrono::microseconds>(stopQuickSortTimer - startQuickSortTimer);

        //calculate merge sort duration
        auto mergeSortDuration = chrono::duration_cast<chrono::microseconds>(stopMergeSortTimer - startMergeSortTimer);

        while (true) {
            cout << endl;
            cout << "Time consumption of quick sort: " << quickSortDuration.count() << " ms" << endl;
            cout << "Time consumption of merge sort: " << mergeSortDuration.count() << " ms" << endl;
            cout << endl;

            string input;
            cout << "Enter any other key to exit: ";
            cin >> input;

            break;
        }
        return;


    }
};