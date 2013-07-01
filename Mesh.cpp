#include "Mesh.hpp"
#include <exception>

PROFOND::Mesh::Mesh() {
    this->nbfaces = 0;
    this->nbvertices = 0;
};

PROFOND::Mesh::~Mesh() {
    //Delete all faces
    this->faces.erase(this->faces.begin(), this->faces.end());
    this->nbfaces = 0;
    //Delete all vertices
    for (std::map<int, PROFOND::Vertice*>::iterator itr_tmp_faces = this->vertices.begin(); itr_tmp_faces != this->vertices.end(); itr_tmp_faces++) {
        delete(itr_tmp_faces->second);
        this->vertices.erase(itr_tmp_faces);
    }
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
                std::cout << "vertices trouves" << std::endl;
                vertices = i->second.getArray();
            }
            if (i->first == "indices") {
                std::cout << "indices trouves" << std::endl;
                indices = i->second.getArray();
            }
        }
        jsonFile.close();

        //Parcours des tableaux pour populer l'objet Mesh
        std::cout << "Nb Vertices : " << vertices.size() << std::endl;
        int cpt = 0;
        for (int j = 0; j < vertices.size(); j = j + 3) {
            float tmp_float_1 = vertices[j].getReal();
            float tmp_float_2 = vertices[j + 1].getReal();
            float tmp_float_3 = vertices[j + 2].getReal();
            this->addVertice(cpt, tmp_float_1, tmp_float_2, tmp_float_3);
            cpt++;
        }

        std::cout << "Nb Indices : " << indices.size() << std::endl;
        cpt = 0;
        for (int k = 0; k < indices.size(); k = k + 3) {
            int tmp_int_1 = indices[k].getInt();
            int tmp_int_2 = indices[k + 1].getInt();
            int tmp_int_3 = indices[k + 2].getInt();
            this->addFace(cpt, this->vertices[tmp_int_1], this->vertices[tmp_int_2], this->vertices[tmp_int_3]);
            cpt++;
        }


    } else {
        std::cout << "Erreur d'ouverture du fichier : " << pathToJSON << std::endl;
    }
};

void PROFOND::Mesh::generateJSON(std::string pathToJSON) {
};
