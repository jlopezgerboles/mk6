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
//  -
//
//-----------------------------------------------------------------------------------------------------------------------

#pragma once

#include "standard.h"
#include "canvas_system.h"

typedef struct renderer_framework {
	SDL_Renderer*	renderer;
	SDL_Texture*	texture;
	i32		color;
	vec2*		points;
} renderer_framework;

renderer_framework* renderer_system_initialize(canvas_framework* canvas);
void renderer_system_update(renderer_framework* renderer);
void renderer_system_shutdown(renderer_framework* renderer);
