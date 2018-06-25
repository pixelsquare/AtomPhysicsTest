/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_PLATFORM_GL_H_
#define _ATOM_PLATFORM_GL_H_

#include "PlatformMacros.h"

#if TARGET_PLATFORM == PLATFORM_WIN32
    #include "GL-win32.h"
#elif TARGET_PLATFORM == PLATFORM_LINUX
    #include "GL-linux.h"
#endif

#endif // _ATOM_PLATFORM_GL_H_