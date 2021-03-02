/*
 * Main.cpp
 *
 *  Created on: 2 mrt. 2021
 *      Author: na_le
 */


#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
    int sum = 0;
    int x;
    char name[256];
    std::cout << "Enter the file name:";
    std::cin.getline(name, 256);
    std::cout << name << std::endl;
    std::ifstream istrm;
    istrm.open(name);

    while (istrm >> x)
    {
    std::cout << x << std::endl;
    }

    istrm.close();
    std::cout << "Sum = " << sum << std::endl;
    return 0;
}
