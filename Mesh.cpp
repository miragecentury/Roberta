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
         std::cout << "Nb Vertices : " << vertices.size() << std::endl;
        for (int j = 0; j < vertices.size(); j++) {
            float tmp_float = vertices[j].getReal();
            //std::cout << tmp_float << std::endl;
        }
        std::cout << "Nb Indices : " << indices.size() << std::endl;
        for (int j = 0; j < indices.size(); j++) {
            int tmp_int = indices[j].getInt();
            //std::cout << tmp_int << std::endl;
        }


    } else {
        std::cout << "Erreur d'ouverture du fichier : " << pathToJSON << std::endl;
    }
};

void PROFOND::Mesh::generateJSON(std::string pathToJSON) {
};
