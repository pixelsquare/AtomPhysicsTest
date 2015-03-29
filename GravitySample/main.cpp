#include "AE lib\atom.h"
using namespace AtomEngine;

Lighting* light = new Lighting;

GameObject* ball = new GameObject;
bool fall = true;

GameObject* cube = new GameObject;
GameObject* cube1 = new GameObject;

void Start() {
	light->SetPosition(Vector3::One * 10.0f);
	light->SetDiffuse(LightPoint(1.0f, 1.0f, 1.0f, 1.0f));

	ball->SetPosition(Vector3::Up * 10.0f);
	cube1->SetPosition(Vector3::Right * 20.5f);
}

void Update() {
	light->AddLight(Light::Light1);

	if(ball->HasCollidedWith(*cube1) || ball->HasCollidedWith(*cube)) {
		fall = false;
		ball->SetAcceleration(Vector3::Zero);
		ball->SetVelocity(Vector3::Zero);
	}

	if(GetKeyDown(' ')) {
		ball->SetVelocity(1.0f, 2.0f, 0.0f);
		fall = true;
	}

	ball->GetVelocity().Print();
	ball->UseGravity(fall);
	
	ball->DrawPrimitive(AE_SOLID_SPHERE);
	cube->DrawPrimitive(AE_SOLID_CUBE);
	cube1->DrawPrimitive(AE_SOLID_CUBE);

	atomCameraPosition(ball->GetPosition().X, 10.0f, 50.0f);
	atomCameraLookAt(ball->GetPosition().X, 10.0f, 0.0f);
}

int main(int argc, char** argv) {
	atomStartFunc(&Start);
	atomUpdateFunc(&Update);
	//atomEditMode(true);
	atomInitialize(argc, argv);

	return 0;
}