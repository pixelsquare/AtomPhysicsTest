#ifndef __ATOMENGINE_CAMERA_LIBRARY_H__
# define __ATOMENGINE_CAMERA_LIBRARY_H__

/* definition for Vector3 library */
# ifndef __ATOMENGINE_VECTOR3_LIBRARY_H__
#  include "Vector3.h"
# endif

/*
	A macro defined to export or import functions, variables, etc.
*/
# ifdef ATOMAPI
#  define ATOMAPI __declspec(dllexport)
# else
#  define ATOMAPI __declspec(dllimport)
# endif

namespace CameraLibrary { 
	using namespace Vector3Library;

	/* Window Properties */
	struct Window {
		Window() {
			this->windowHandle = 0;
			this->width = 800;
			this->height = 600;
			this->name = "Atom Engine v2.0 Project";
		}

		int windowHandle;
		char *name;
		int width;
		int height;

		struct Color{ 
			Color() {
				this->r = 0.0;
				this->g = 0.0;
				this->b = 0.0;
				this->a = 0.0;
			}
			double r;
			double g;
			double b;
			double a;

		
		}; Color color;

	}; extern Window window;

	/* Camera Properties */
	struct Camera {
		Camera() {
			this->Position = Vector3(0.0f, 0.0f, 10.0f);
			this->LookAt = Vector3(0.0f, 0.0f, 0.0f);
			this->Up = Vector3(0.0f, 1.0f, 0.0f);
		}

		Vector3 Position;
		Vector3 LookAt;
		Vector3 Up;

	}; extern Camera camera;

	/* Atom Engine edit mode properties */
	struct CameraEditMode {
		CameraEditMode() {
			this->position = Vector3(0.01f, 0.01f, 10.0f);
			this->rotation = Vector3(0.01f, 0.01f, 0.0f);
			this->lastX = 0;
			this->lastY = 0;
			this->mouseClick[0] = false;
			this->mouseClick[1] = false;
			this->mouseClick[2] = false;
		}

		Vector3 position;
		Vector3 rotation;
		int lastX;
		int lastY;
		bool mouseClick[3];

	}; extern CameraEditMode editMode;

	extern bool inEditMode;

	/* Functions that exported and can be used outside  */
	extern void ATOMAPI atomCameraPosition(float x, float y, float z);
	extern void ATOMAPI atomCameraLookAt(float x, float y, float z);
	extern void ATOMAPI atomCameraUp(float x, float y, float z);
	extern void ATOMAPI atomEditMode(bool flag);
}

#endif