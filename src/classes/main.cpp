#include "../atom/include/atom.h"
using namespace AtomEngine;

Light* light = new Light;

GameObject* ball = new GameObject;
bool fall = true;

GameObject* cube = new GameObject;
GameObject* cube1 = new GameObject;

void Start() {
	light->SetPosition(Vector3f::ONE * 10.0f);
	light->SetDiffuse(Color4(1.0f, 1.0f, 1.0f, 1.0f));

	ball->SetPosition(Vector3f::UP * 10.0f);
	cube1->SetPosition(Vector3f::RIGHT * 20.5f);
}

void Update() {
	light->AddLight(LightType::Light1);

	if(ball->HasCollidedWith(*cube1) || ball->HasCollidedWith(*cube)) {
		fall = false;
		ball->SetAcceleration(Vector3f::ZERO);
		ball->SetVelocity(Vector3f::ZERO);
	}

	if(Input::GetKeyDown(' ')) {
		ball->SetVelocity(1.0f, 2.0f, 0.0f);
		fall = true;
	}

	//ball->GetVelocity().Print();
	ball->UseGravity(fall);
	
	ball->DrawPrimitive(AE_SOLID_SPHERE);
	cube->DrawPrimitive(AE_SOLID_CUBE);
	cube1->DrawPrimitive(AE_SOLID_CUBE);

	//atomCameraPosition(ball->GetPosition().X, 10.0f, 50.0f);
	//atomCameraLookAt(ball->GetPosition().X, 10.0f, 0.0f);
}

int main(int argc, char *argv[]) {
	atomStartFunc(&Start);
	atomUpdateFunc(&Update);
	//atomEditMode(true);
	atomInitialize(argc, argv);

	return 0;
}