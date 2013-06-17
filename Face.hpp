/* 
 * File:   Face.hpp
 * Author: zeus
 *
 * Created on 17 juin 2013, 09:54
 */

#include "Mesh.hpp"
#include "Vertice.hpp"

#ifndef FACE_HPP
#define	FACE_HPP

namespace PROFOND {

    class Face {
    public:
        //Constructeur
        Face(PROFOND::Vertice * v1, PROFOND::Vertice * v2, PROFOND::Vertice * v3);
        //Destructeur
        ~Face();
        //Getter
        PROFOND::Vertice * get_v1();
        PROFOND::Vertice * get_v2();
        PROFOND::Vertice * get_v3();

    private:
        PROFOND::Vertice* v1;
        PROFOND::Vertice* v2;
        PROFOND::Vertice* v3;
    };
};

#endif	/* FACE_HPP */

