/* 
 * File:   Vertice.hpp
 * Author: zeus
 *
 * Created on 17 juin 2013, 09:54
 */

// #include "Mesh.hpp" (récurcive

#ifndef VERTICE_HPP
#define	VERTICE_HPP

// #include "Mesh.hpp"


namespace PROFOND {

    class Mesh;

    class Vertice {
    public:
        //Contructeur
        Vertice(float x, float y, float z);
        //Destructeur
        ~Vertice();
        //Getter
        float get_x();
        float get_y();
        float get_z();
        //Setter
        void set_x(float x);
        void set_y(float y);
        void set_z(float z);
    private:
        float x;
        float y;
        float z;
    };
};


#endif	
/* VERTICE_HPP */
