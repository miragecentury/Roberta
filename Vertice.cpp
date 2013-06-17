#include "Vertice.hpp"

//Constructeur

PROFOND::Vertice::Vertice(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->tag = PROFOND::Vertice::NOTAGGED;
};

//Destructeur

PROFOND::Vertice::~Vertice() {

};

//Getter

float PROFOND::Vertice::get_x() {
    return this->x;
};

float PROFOND::Vertice::get_y() {
    return this->y;
};

float PROFOND::Vertice::get_z() {
    return this->z;
};

PROFOND::Vertice::TAG PROFOND::Vertice::get_tag() {
    return this->tag;
};

//Setter

void PROFOND::Vertice::set_x(float x) {
    this->x = x;
};

void PROFOND::Vertice::set_y(float y) {
    this->y = y;
};

void PROFOND::Vertice::set_z(float z) {
    this->z = z;
};

void PROFOND::Vertice::set_tag(PROFOND::Vertice::TAG tag) {
    this->tag = tag;
};

//

/**
 *      Si la face n'est pas dans la liste des faces utilisant le vertice l'ajouter 
 */
void PROFOND::Vertice::addFace(PROFOND::Face* face) {
};

/**
 *      Supprimer la face dans la liste des faces utilisant le vertice
 */
void PROFOND::Vertice::delFace(PROFOND::Face* face) {

};

//

/**
 *      Retourne la liste des vertex à proximité du vertice
 */
std::vector<PROFOND::Vertice*> PROFOND::Vertice::getProximityVertices() {
    std::vector<PROFOND::Vertice*> returnVector;
    //population
    return returnVector;
}

