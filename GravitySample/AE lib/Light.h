#ifndef __ATOM_ENGINE_LIGHT_LIBRARY_H__
#define __ATOM_ENGINE_LIGHT_LIBRARY_H__

/* Light must be defined in the main project */

/* definition for vector3 library */
# ifndef __ATOMENGINE_VECTOR3_LIBRARY_H__
#  include "Vector3.h"
# endif

#include <glut.h>

/*
	A macro defined to export or import functions, variables, etc.
*/
# ifdef ATOMAPI
#  define ATOMAPI __declspec(dllexport)
# else
#  define ATOMAPI __declspec(dllimport)
# endif

namespace LightLibrary {
	using namespace Vector3Library;

	/* Light options, since glut has 7 lights only, all
		of them are included
	*/
	extern enum ATOMAPI Light {
		Light1 = GL_LIGHT0, 
		Light2 = GL_LIGHT1, 
		Light3 = GL_LIGHT2, 
		Light4 = GL_LIGHT3,
		Light5 = GL_LIGHT4, 
		Light6 = GL_LIGHT5, 
		Light7 = GL_LIGHT6,
		Light8 = GL_LIGHT7
	};

	/* struct used to change the vcolor value of the light */
	struct ATOMAPI LightPoint {
		LightPoint() {
			r = 1.0f;
			g = 1.0f;
			b = 1.0f;
			a = 1.0f;
		}

		LightPoint(float R, float G, float B, float A) {
			r = R;
			g = G;
			b = B;
			a = A;
		}
		float r;
		float g;
		float b;
		float a;
	};

	/* class that holds the lighting subsystem */
	class ATOMAPI Lighting {
	public:
		Lighting();

		void AddLight(Light light);

		void SetActiveLight(bool active);
		void SetPosition(Vector3 position);
		void SetAmbient(LightPoint ambient);
		void SetDiffuse(LightPoint diffuse);
		void SetSpecular(LightPoint specular);

	private:
		Vector3 position;
		LightPoint ambient;
		LightPoint diffuse;
		LightPoint specular;
		bool isActive;
	protected:
	};
}

#endif