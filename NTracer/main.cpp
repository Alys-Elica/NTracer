#include <cmath>
#include <iostream>

#include <SDL.h>

#include "NT_Base/ntrenderer.h"
#include "NT_3DObjects/nt3dobjectsphere.h"
#include "NT_3DObjects/nt3dobjectplane.h"
#include "NT_Light/ntlightomni.h"

// http://www.alrj.org/docs/3D/raytracer/raytracertutchap1.htm
int main(int argc, char** argv)
{
	/* INIT */
	int width = 800;
	int height = 600;

	NTScene scene;

	NTCamera* cam = new NTCamera(width, height, NCore::NCVector3D(0.0, 3.0, -15.0), NCore::NCVector3D(0.0, 0.0, 10.0), NCore::NCVector3D(0.0, 1.0, 0.0));

	scene.setCamera(cam);

	/* OBJECTS */
	NTMaterial mat;

	// Spheres
	NT3DObject* obj1 = new NT3DObjectSphere(NCore::NCVector3D(0.0, 0.0, 10.0), 1.0);
	mat.setDiffuseColor(NTColor(1.0, 0.6f, 0.8f));
	mat.setReflectivity(0.5f);
	mat.setRefractivity(0.5f);
	obj1->setMaterial(mat);
	scene.addObject(obj1);

	NT3DObject* obj2 = new NT3DObjectSphere(NCore::NCVector3D(-2.0, 0.0, 8.0), 0.5f);
	mat.setDiffuseColor(NTColor(0.4f, 1.0, 0.6f));
	mat.setReflectivity(0.0);
	mat.setRefractivity(0.0);
	obj2->setMaterial(mat);
	scene.addObject(obj2);

	// Planes
	// Left wall
	NT3DObject* leftWall = new NT3DObjectPlane(NCore::NCVector3D(-8.0, 0.0, 0.0), NCore::NCVector3D(1.0, 0.0, 0.0));
	mat.setDiffuseColor(NTColor(1.0, 0.0, 0.0));
	mat.setReflectivity(0.0);
	mat.setRefractivity(0.0);
	leftWall->setMaterial(mat);
	scene.addObject(leftWall);

	// Ceilling
	NT3DObject* ceilling = new NT3DObjectPlane(NCore::NCVector3D(0.0, 4.0, 0.0), NCore::NCVector3D(0.0, -1.0, 0.0));
	mat.setDiffuseColor(NTColor(0.0, 1.0, 0.0));
	mat.setReflectivity(0.0);
	mat.setRefractivity(0.0);
	ceilling->setMaterial(mat);
	scene.addObject(ceilling);

	// Right wall
	NT3DObject* rightWall = new NT3DObjectPlane(NCore::NCVector3D(8.0, 0.0, 0.0), NCore::NCVector3D(-1.0, 0.0, 0.0));
	mat.setDiffuseColor(NTColor(0.0, 0.0, 1.0));
	mat.setReflectivity(0.0);
	mat.setRefractivity(0.0);
	rightWall->setMaterial(mat);
	scene.addObject(rightWall);

	// Floor
	NT3DObject* floor = new NT3DObjectPlane(NCore::NCVector3D(0.0, -4.0, 0.0), NCore::NCVector3D(0.0, 1.0, 0.0));
	mat.setDiffuseColor(NTColor(1.0, 1.0, 0.0));
	mat.setReflectivity(0.0);
	mat.setRefractivity(0.0);
	floor->setMaterial(mat);
	scene.addObject(floor);

	// Opposite wall
	NT3DObject* opositeWall = new NT3DObjectPlane(NCore::NCVector3D(0.0, 0.0, 64.0), NCore::NCVector3D(0.0, 0.0, -1.0));
	mat.setDiffuseColor(NTColor(1.0, 1.0, 1.0));
	mat.setReflectivity(0.0);
	mat.setRefractivity(0.0);
	opositeWall->setMaterial(mat);
	scene.addObject(opositeWall);

	// Behind wall
	NT3DObject* behindWall = new NT3DObjectPlane(NCore::NCVector3D(0.0, 0.0, -15.2), NCore::NCVector3D(0.0, 0.0, 1.0));
	mat.setDiffuseColor(NTColor(1.0, 0.0, 1.0));
	mat.setReflectivity(0.0);
	mat.setRefractivity(0.0);
	behindWall->setMaterial(mat);
	//scene.addObject(behindWall);

	/* LIGHTS */
	scene.addLight(new NTLightOmni(NCore::NCVector3D(0.0, 3.5f, 4.0), NTColor(1.0, 1.0, 1.0), 1.0, 1.0));
	scene.addLight(new NTLightOmni(NCore::NCVector3D(3.0, 0.0, 0.0), NTColor(1.0, 0.0, 0.0), 1.0, 1.0));
	scene.addLight(new NTLightOmni(NCore::NCVector3D(-3.0, 3.0, 0.0), NTColor(0.0, 0.0, 1.0), 1.0, 1.0));

	/* SCENE RENDER */

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL Failed to init: " + std::string(SDL_GetError()) << std::endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("NTracer",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height, SDL_WINDOW_OPENGL);
	if (!window) {
		std::cout << "Failed to create SDL window: " + std::string(SDL_GetError()) << std::endl;
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) {
		std::cout << "Failed to create SDL renderer: " + std::string(SDL_GetError()) << std::endl;
		SDL_DestroyWindow(window);
		return 1;
	}

	bool isRunning = true;
	bool render = false;
	while (isRunning) {
		/* EVENT MANAGEMENT */
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_ESCAPE: {
					isRunning = false;
					break;
				}
				case SDLK_r: {
					render = true;
					break;
				}
				}
			}
			else if (event.type == SDL_QUIT) {
				isRunning = false;
			}
		}

		if (render) {
			/* RENDERING */
			// Render scene
			std::cout << "Start rendering" << std::endl;
			NCore::NCImage img = LTRenderer::render(scene);

			// Draw on screen
			std::cout << "Start drawing on screen" << std::endl;
			SDL_RenderClear(renderer);
			for (int x = 0; x < img.width(); ++x) {
				for (int y = 0; y < img.height(); ++y) {
					NCore::NCRgb pix = img.pixel(x, y);

					SDL_SetRenderDrawColor(renderer, pix.r(), pix.g(), pix.b(), 255);
					SDL_RenderDrawPoint(renderer, x, y);
				}
			}

			SDL_RenderPresent(renderer);

			render = false;
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
