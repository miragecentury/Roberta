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
#include <map>
#include <string>

namespace PROFOND {

    class Mesh {
    public:
        Mesh();
        ~Mesh();
        
        //JSON
        void populeJSON(std::string pathToJSON);
        void generateJSON(std::string pathToJSON);
        
        //Add
        void addVertice(float x, float y, float z);
        void addFace(PROFOND::Vertice* v1, PROFOND::Vertice* v2, PROFOND::Vertice* v3);
        void addFace(int indice_v1, int indice_v2, int indice_v3);
        
        //Deletion
        void delFace(int indice);
        void delvertice(int indice);

    private:
        std::map<int, PROFOND::Vertice*> vertices;
        std::map<int, PROFOND::Face*> faces;
    };
};

#endif	/* MESH_HPP */

