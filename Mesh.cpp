#include "Mesh.hpp"

PROFOND::Mesh::Mesh() {
    this->nbfaces = 0;
    this->nbvertices = 0;
};

PROFOND::Mesh::~Mesh() {

};

void PROFOND::Mesh::addFace(PROFOND::Vertice* v1, PROFOND::Vertice* v2, PROFOND::Vertice* v3) {

};

void PROFOND::Mesh::addFace(int indice_v1, int indice_v2, int indice_v3) {
    if (
            this->vertices.find(indice_v1) != this->vertices.end() &&
            this->vertices.find(indice_v2) != this->vertices.end() &&
            this->vertices.find(indice_v3) != this->vertices.end()
            ) {
        this->faces.insert(std::pair<int, PROFOND::Face*>(this->nbfaces++, new PROFOND::Face(this->vertices[indice_v1], this->vertices[indice_v2], this->vertices[indice_v3])));
    } else {
        std::cout << "erreur indice(s) de vertice inconnu" << std::endl;
    }
};

void PROFOND::Mesh::addVertice(float x, float y, float z) {
    this->vertices.insert(std::pair<int, PROFOND::Vertice*>(this->nbvertices++, new PROFOND::Vertice(x, y, z)));
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

void PROFOND::Mesh::delFacesWithVertice(int indice_vertices) {

};

void PROFOND::Mesh::delFacesWithVertice(PROFOND::Vertice* v) {

};

void PROFOND::Mesh::populeJSON(std::string pathToJSON) {
    json_spirit::Array indices;
    json_spirit::Array vertices;
    std::ifstream jsonFile(pathToJSON.c_str());
    json_spirit::Value value;
    if (jsonFile) {
        json_spirit::read(jsonFile, value);

        const json_spirit::Object& Tab = value.getObject();
        for (json_spirit::Object::const_iterator i = Tab.begin(); i != Tab.end(); ++i) {
            if (i->first == "vertices") {
                std::cout << "vertices trouvés" << std::endl;
                vertices = i->second.getArray();
            }
            if (i->first == "indices") {
                std::cout << "indices trouvés" << std::endl;
                indices = i->second.getArray();
            }
        }
        jsonFile.close();

        //Parcours des tableaux pour populer l'objet Mesh
        for (int j = 0; j < vertices.size(); j++) {
            std::cout << vertices[j].getReal() << std::endl;
        }


    } else {
        std::cout << "Erreur d'ouverture du fichier : " << pathToJSON << std::endl;
    }
};

void PROFOND::Mesh::generateJSON(std::string pathToJSON) {

};