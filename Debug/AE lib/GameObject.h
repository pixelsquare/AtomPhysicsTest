#ifndef __ATOMENGINE_GAMEOBJECT_LIBRARY_H__
# define __ATOMENGINE_GAMEOBJECT_LIBRARY_H__

/* definition for physics library */
# ifndef __ATOMENGINE_PHYSICS_LIBRARY_H__
#  include "Physics.h"
# endif

/* definition for windows.h and time.h */
# if defined (_WIN32)
#  define WIN32_LEAN_AND_MEAN
#   include <Windows.h>
#	include <time.h>
# endif

#include <vector>

/*
	A macro defined to export or import functions, variables, etc.
*/
# ifdef ATOMAPI
#  define ATOMAPI __declspec(dllexport)
# else
#  define ATOMAPI __declspec(dllimport)
# endif

namespace GameObjectLibrary {
	using namespace PhysicsLibrary;

	// Object Property
	class ObjectProperty {
	public:
		std::vector<Vector3*> vec;

		Vector3* vertices;
		Vector3* normals;
		Vector3* faces;
		Color3* colors;
		char* fileName;

		long connectedTris;
		long connectedPts;

		int indx;

		Vector3 GetNormal(Vector3 coord1, Vector3 coord2, Vector3 coord3);
	private:
	protected:
	};

	// ObjectLoader
	class ObjectLoader : public ObjectProperty {
	public:
		ObjectLoader();

		ObjectLoader& operator=(ObjectLoader rhs);

		void LoadObject(char* filename);
		void DrawObject();

	private:
	protected:
	};

	extern ObjectLoader asset[8];

	// GameObject
	class ATOMAPI GameObject : public Physics {
		public:
			GameObject();
			~GameObject();

			void SetActiveGameObject(bool active);

			void DrawPrimitive(int type);

			//void DrawPrimitive(const char* type);
			//void DrawClone(GameObject* clone);
			//void Duplicate(GameObject* clone);

			void SetName(char* name);

			virtual void SetColor(Color3 Color);
			virtual void SetColor(float Red, float Green, float Blue);

			virtual void SetScale(Vector3 scale);
			virtual void SetScale(float scaleX, float scaleY, float scaleZ);
		private:
			char* name;
			bool isActive;
			bool initModel;
			ObjectLoader* objLoader;
		protected:

	};
}

#endif