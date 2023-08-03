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
//  - Building up the VULKAN renderer for the display of 3D meshes.
//
//-----------------------------------------------------------------------------------------------------------------------

#include "renderer_system.h"
#include "canvas_system.h"

/* 
 * - Function: renderer_framework_create().
 * - Returns: Returns a pointer to an empry renderer framework and allocates its memory.
 */
renderer_framework* renderer_framework_create() {
	renderer_framework* renderer;
	renderer = malloc(sizeof(renderer_framework));
	return renderer;
}

/* 
 * - Function: renderer_framework_create_renderer(canvas_framework* canvas).
 * - Returns: Returns a pointer to an SDL renderer, notice the renderer is created out of the windos in canvas system .
 */
SDL_Renderer* renderer_framework_create_renderer(canvas_framework* canvas) {
	SDL_Renderer* renderer = SDL_CreateRenderer(canvas -> window, -1, SDL_RENDERER_ACCELERATED);
	return renderer;
}

/* 
 * - Function: renderer_framework_create_texture(canvas_framework* canvas, renderer_framework* renderer).
 * - Returns: Returns a pointer to an SDL texture, notice its requires the surface of the canvas system.
 */
SDL_Texture* renderer_framework_create_texture(canvas_framework* canvas, renderer_framework* renderer) {
	SDL_Texture* texture;
	texture = SDL_CreateTextureFromSurface(renderer -> renderer, canvas -> surface);
	return texture;
}

/* 
 * - Function: renderer_framework_create_color(renderer_framework* renderer).
 * - Returns: Returns color used to initialize the renderer, notice the function clears the renderer with selected color.
 */
i32 renderer_framework_create_color(renderer_framework* renderer) {
	i32 color;
	color = SDL_SetRenderDrawColor(renderer -> renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer -> renderer);
	SDL_RenderPresent(renderer -> renderer);
	return color;
}

/* 
 * - Function: renderer_system_initialze().
 * - Returns: Initializes the renderer system.
 */
renderer_framework* renderer_system_initialize(canvas_framework* canvas) {
	renderer_framework* renderer;
	renderer = renderer_framework_create();
	renderer -> renderer = renderer_framework_create_renderer(canvas);
	renderer -> texture = renderer_framework_create_texture(canvas, renderer);
	renderer -> color = renderer_framework_create_color(renderer);
	return renderer;
}

/* 
 * - Function: renderer_system_shutdown().
 * - Returns: Shuts down the renderer system.
 */
void renderer_system_shutdown(renderer_framework* renderer) {
	SDL_DestroyRenderer(renderer -> renderer);
	SDL_DestroyTexture(renderer -> texture);
	free(renderer);
}
