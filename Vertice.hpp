/* 
 * File:   Vertice.hpp
 * Author: zeus
 *
 * Created on 17 juin 2013, 09:54
 */

// #include "Mesh.hpp" (récurcive)

#include <map>
#include <vector>

#ifndef VERTICE_HPP
#define	VERTICE_HPP

namespace PROFOND {

    class Mesh;
    class Face;

    class Vertice {

        enum TAG {
            NOTAGGED,
            TAGGED
        };

    public:
        //Contructeur
        Vertice(float x, float y, float z);
        //Destructeur
        ~Vertice();
        //Getter
        float get_x();
        float get_y();
        float get_z();
        TAG get_tag();
        //Setter
        void set_x(float x);
        void set_y(float y);
        void set_z(float z);
        void set_tag(PROFOND::Vertice::TAG tag);
        //
        void addFace(PROFOND::Face * face);
        void delFace(PROFOND::Face * face);
        std::vector<PROFOND::Face*> getFaces();
        //
        std::vector<PROFOND::Vertice* > getProximityVertices();
    private:
        PROFOND::Vertice::TAG tag;
        float x;
        float y;
        float z;
        std::vector<PROFOND::Face*> Faces; //Face prenant ce vertice
    };
};

#include "Mesh.hpp"
#include "Face.hpp"


#endif	
/* VERTICE_HPP */


