#include "Mesh.hpp"

PROFOND::Mesh::Mesh() {
    this->nbfaces = 0;
    this->nbvertices = 0;
};

PROFOND::Mesh::~Mesh() {
    //Delete all faces

    //Delete all vertices

};

void PROFOND::Mesh::addFace(PROFOND::Vertice* v1, PROFOND::Vertice* v2, PROFOND::Vertice* v3) {
    PROFOND::Face* tmp_face;
    tmp_face = new PROFOND::Face(v1, v2, v3);
    this->faces.push_back(tmp_face);
    v1->addFace(tmp_face);
    v2->addFace(tmp_face);
    v3->addFace(tmp_face);
};

void PROFOND::Mesh::addVertice(float x, float y, float z) {
    this->vertices.push_back(new PROFOND::Vertice(x, y, z));
};

void PROFOND::Mesh::delFacesWithVertice(PROFOND::Vertice* v) {
    std::vector<PROFOND::Face*> tmp_faces = v->getFaces();
    std::vector<PROFOND::Face*>::iterator itr_tmp_faces;
    for (itr_tmp_faces = tmp_faces.begin(); itr_tmp_faces != tmp_faces.end(); itr_tmp_faces++) {
        delete(*itr_tmp_faces);
    }
};

void PROFOND::Mesh::populeJSON(std::string pathToJSON) {

};

void PROFOND::Mesh::generateJSON(std::string pathToJSON) {
    std::map<PROFOND::Vertice*, int>lstVertice;
    std::map<PROFOND::Face*, int>lstFace;
    int nbVertice = 0;
    int nbFace = 0;
};