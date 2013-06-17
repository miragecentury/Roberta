#include "Mesh.hpp"


PROFOND::Mesh::Mesh() {

};

PROFOND::Mesh::~Mesh() {

};

void PROFOND::Mesh::addFace(PROFOND::Vertice* v1, PROFOND::Vertice* v2, PROFOND::Vertice* v3) {

};

void PROFOND::Mesh::addFace(int indice_v1, int indice_v2, int indice_v3) {

};

void PROFOND::Mesh::addVertice(float x, float y, float z) {

};

void PROFOND::Mesh::delFace(int indice) {
    if (this.faces.at(indice) != NULL) {

    } else {
        log("PROFOND::Mesh::delFace || indice " << indice << " inconnu.");
    }
};

void PROFOND::Mesh::delvertice(int indice) {

};

void PROFOND::Mesh::populeJSON(std::string pathToJSON) {

};

void PROFOND::Mesh::generateJSON(std::string pathToJSON) {

};