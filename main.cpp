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
    PROFOND::Mesh mesh;
    mesh.populeJSON("Eprouvette.json");
    return 0;
}