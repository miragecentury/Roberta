#include "Mesh.hpp"

PROFOND::Mesh::Mesh() {

};

PROFOND::Mesh::~Mesh() {

};

void PROFOND::Mesh::addFace(PROFOND::Vertice* v1, PROFOND::Vertice* v2, PROFOND::Vertice* v3) {
    this->faces.insert(new PROFOND::Face(v1, v2, v3));
};

void PROFOND::Mesh::addFace(int indice_v1, int indice_v2, int indice_v3) {
    if (
            this->vertices.find(indice_v1) != this->vertices.end() &&
            this->vertices.find(indice_v2) != this->vertices.end() &&
            this->vertices.find(indice_v3) != this->vertices.end()
            ) {
        this->faces.insert(new PROFOND::Face(this->vertices[indice_v1], this->vertices[indice_v2], this->vertices[indice_v3]));
    } else {
        std::cout << "erreur indice(s) de vertice inconnu" << std::endl;
    }
};

void PROFOND::Mesh::addVertice(float x, float y, float z) {
    this->vertices.insert(new PROFOND::Vertice(x, y, z));
};

void PROFOND::Mesh::delFace(int indice) {
    if (this->faces.find(indice) != this->faces.end()) {
        delete(this->faces[indice]);
        this->faces.erase(indice);
    } else {
        std::cout << "erreur indice de face inconnu" << std::endl;
    }
};

void PROFOND::Mesh::delvertice(int indice) {
    if (this->vertices.find(indice) != this->vertices.end()) {
        delete(this->vertices[indice]);
        this->faces.erase(indice);
    } else {
        std::cout << "erreur indice de vertice inconnu" << std::endl;
    }
};

void PROFOND::Mesh::delFaceWithVertice(int indice_vertices) {

};

void PROFOND::Mesh::delFaceWithVertice(PROFOND::Vertice* v) {

};

void PROFOND::Mesh::populeJSON(std::string pathToJSON) {

};

void PROFOND::Mesh::generateJSON(std::string pathToJSON) {

};