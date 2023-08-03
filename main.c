//-----------------------------------------------------------------------------------------------------------------------
//
// Copyright (C) 2023 by Swiss Entertainment Software AG.
//
// This source is available for distribution and/or modification only under the terms of the Source Code License as
// published by Swiss Entertainment Software AG. All rights reserved.
//
// The source is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of FITNESS FOR A PARTICULAR PURPOSE.
//
// DESCRIPTION:
//  - Main script og the application, the systems are being sourced from the foldr "src". Please notice the mercury
//	script are not yet implemented.
//
//-----------------------------------------------------------------------------------------------------------------------

#include "src/standard.h"
#include "src/timer_system.h"
#include "src/canvas_system.h"
#include "src/renderer_system.h"

const i8* NAME = "mk6";

void main(int argc, char **argv) {

	timer_framework* timer = timer_system_initialize();
	canvas_framework* canvas = canvas_system_initialize(NAME);
	renderer_framework* renderer = renderer_system_initialize(canvas);
	SDL_Event event;
	b8 quit = FALSE;

	while(quit == FALSE) {
	
		while(SDL_PollEvent(&event) != 0) {
			timer_system_control_fps1(timer);
			if((event.type == SDL_QUIT) || (event.key.keysym.sym == SDLK_ESCAPE)) {
				quit = TRUE;
				renderer_system_shutdown(renderer);
				canvas_system_shutdown(canvas);
				timer_system_shutdown(timer);
				SDL_Quit();
			}
			timer_system_control_fps2(timer);
		}
	}
}
