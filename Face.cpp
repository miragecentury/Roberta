#include "Face.hpp"

PROFOND::Face::Face(PROFOND::Vertice* v1, PROFOND::Vertice* v2, PROFOND::Vertice* v3) {
    v1->addFace(this);
    v2->addFace(this);
    v3->addFace(this);
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
}

PROFOND::Face::~Face() {
    this->v1->delFace(this);
    this->v2->delFace(this);
    this->v3->delFace(this);
}

PROFOND::Vertice* PROFOND::Face::get_v1() {
    return this->v1;
}

PROFOND::Vertice* PROFOND::Face::get_v2() {
    return this->v2;
}

PROFOND::Vertice* PROFOND::Face::get_v3() {
    return this->v3;
}
