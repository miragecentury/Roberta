#include "Mesh.hpp"

PROFOND::Mesh::Mesh() {
    this->nbfaces = 0;
    this->nbvertices = 0;
};

PROFOND::Mesh::~Mesh() {
    //Delete all faces

    //Delete all vertices

};

void PROFOND::Mesh::addFace(int indice, PROFOND::Vertice* v1, PROFOND::Vertice* v2, PROFOND::Vertice* v3) {
    PROFOND::Face* tmp_face;
    tmp_face = new PROFOND::Face(v1, v2, v3);
    this->faces.insert(std::pair<int, PROFOND::Face*>(indice, tmp_face));
    v1->addFace(tmp_face);
    v2->addFace(tmp_face);
    v3->addFace(tmp_face);
};

void PROFOND::Mesh::addVertice(int indice, float x, float y, float z) {
    this->vertices.insert(std::pair<int, PROFOND::Vertice*>(indice, new PROFOND::Vertice(x, y, z)));
};

void PROFOND::Mesh::delFacesWithVertice(PROFOND::Vertice* v) {
    std::set<PROFOND::Face*> tmp_faces = v->getFaces();
    std::set<PROFOND::Face*>::iterator itr_tmp_faces;
    for (itr_tmp_faces = tmp_faces.begin(); itr_tmp_faces != tmp_faces.end(); itr_tmp_faces++) {
        delete(*itr_tmp_faces);
    }
};

void PROFOND::Mesh::populeJSON(std::string pathToJSON) {
    std::ifstream is("Eprouvette.json");
    json_spirit::Value value;
    read(is, value);
};

void PROFOND::Mesh::generateJSON(std::string pathToJSON) {
};
