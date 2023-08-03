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

typedef struct timer_framework {
	u32 t0;
	u32 t1;
	f32 delta;
} timer_framework;

timer_framework* timer_system_initialize();
void timer_system_shutdown(timer_framework* timer);
void timer_system_control_fps1(timer_framework* timer);
void timer_system_control_fps2(timer_framework* timer);
