#include "Face.hpp"

//Constructeur

PROFOND::Face::Face(PROFOND::Vertice* v1, PROFOND::Vertice* v2, PROFOND::Vertice* v3) {
    v1->addFace(this);
    v2->addFace(this);
    v3->addFace(this);
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
}

//Destructeur

PROFOND::Face::~Face() {
    this->v1->delFace(this);
    this->v2->delFace(this);
    this->v3->delFace(this);
}

//Getter

PROFOND::Vertice* PROFOND::Face::get_v1() {
    return this->v1;
}

PROFOND::Vertice* PROFOND::Face::get_v2() {
    return this->v2;
}

PROFOND::Vertice* PROFOND::Face::get_v3() {
    return this->v3;
}

//

std::set<PROFOND::Face*>PROFOND::Face::getProximityFaces() {
    std::set<PROFOND::Face*> returnFaces;
    std::set<PROFOND::Face*> tmp;
    std::set<PROFOND::Face*>::iterator it;

    tmp = this->v1->getFaces();
    for (it = tmp.begin(); it != tmp.end(); it++) {
        returnFaces.insert(*it);
    }
    tmp = this->v2->getFaces();
    for (it = tmp.begin(); it != tmp.end(); it++) {
        returnFaces.insert(*it);
    }
    tmp = this->v3->getFaces();
    for (it = tmp.begin(); it != tmp.end(); it++) {
        returnFaces.insert(*it);
    }
    return returnFaces;
}
