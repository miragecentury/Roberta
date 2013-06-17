#include "Vertice.hpp"

PROFOND::Vertice::Vertice(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
};

PROFOND::Vertice::~Vertice() {

};

float PROFOND::Vertice::get_x() {
    return this->x;
};

float PROFOND::Vertice::get_y() {
    return this->y;
};

float PROFOND::Vertice::get_z() {
    return this->z;
};

void PROFOND::Vertice::set_x(float x) {
    this->x = x;
};

void PROFOND::Vertice::set_y(float y) {
    this->y = y;
};

void PROFOND::Vertice::set_z(float z) {
    this->z = z;
};