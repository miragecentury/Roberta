/* 
 * File:   Mesh.hpp
 * Author: zeus
 *
 * Created on 17 juin 2013, 09:53
 */

#ifndef MESH_HPP
#define	MESH_HPP

//Dépendance

#include "Face.hpp"
#include "Vertice.hpp"

//Std
#include <boost/iterator.hpp>
#include <json_spirit/json_spirit.h>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <ios>
#include <iosfwd>
#include <fstream>
#include <list>

namespace PROFOND {

    class Mesh {
    public:
        Mesh();
        ~Mesh();

        //JSON
        void populeJSON(std::string pathToJSON);
        void generateJSON(std::string pathToJSON);

        //Add
        void addVertice(int indice,float x, float y, float z);
        void addFace(int indice,PROFOND::Vertice* v1, PROFOND::Vertice* v2, PROFOND::Vertice* v3);

        //Get
        std::list<PROFOND::Face * > getFacesAtVertice(PROFOND::Vertice* vertice);
        std::list<PROFOND::Face * > getFacesAtVertice(int indice_vertice);
        std::list<PROFOND::Vertice *> getVerticesAtFace(PROFOND::Face * face);
        std::list<PROFOND::Vertice *> getVerticesAtFace(int indice_face);
        
        //Deletion
        void delFacesWithVertice(PROFOND::Vertice* v);
        void delvertice(PROFOND::Vertice* v);

    private:
        std::map<int,PROFOND::Vertice*> vertices;
        std::map<int,PROFOND::Face*> faces;
        int nbvertices;
        int nbfaces;
    };
};

#endif	/* MESH_HPP */

