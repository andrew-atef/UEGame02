#pragma once
#pragma once

#include "DrawDebugHelpers.h"
//#include "DrawDebugHelpers.h"
#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, false, 40.f);
#define DRAW_SPHERE_S(Location) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, false, -1.f);
#define DRAW_LINE(StartV, EndV) if(GetWorld()) DrawDebugLine(GetWorld(), StartV, EndV, FColor::Cyan, true);
#define DRAW_LINE_S(StartV, EndV) if(GetWorld()) DrawDebugLine(GetWorld(), StartV, EndV, FColor::Cyan, false, -1.f);
#define DRAW_POINT(Location) if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Cyan, true);
#define DRAW_POINT_S(Location) if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Cyan, false, -1.f);
#define DRAW_VECTOR(StartV, EndV) if(GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), StartV, EndV, FColor::Cyan, true);\
		DrawDebugPoint(GetWorld(), EndV, 15.f, FColor::Cyan, true);\
	}

#define DRAW_VECTOR_S(StartV, EndV) if(GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), StartV, EndV, FColor::Cyan, false, -1.f);\
		DrawDebugPoint(GetWorld(), EndV, 15.f, FColor::Cyan, false, -1.f);\
	}