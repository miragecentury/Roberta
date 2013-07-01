/* 
 * File:   main.cpp
 * Author: zeus
 *
 * Created on 17 juin 2013, 09:47
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <json_spirit/json_spirit.h>

#include "Mesh.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    PROFOND::Mesh* mesh = new PROFOND::Mesh();
    mesh->populeJSON("Eprouvette.json");
    delete mesh;
    std::cout << "End populeJSon" << std::endl;
    return 0;
}