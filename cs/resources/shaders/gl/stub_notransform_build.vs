#include "common.h"

out gl_PerVertex { vec4 gl_Position; };

float4		screen_res;		// Screen resolution (x-Width,y-Height, zw - 1/resolution)

layout(location = 0) in vec4 iPos;
layout(location = 1) in vec2 iTex0;
layout(location = 2) in vec2 iTex1;
layout(location = 3) in vec2 iTex2;
layout(location = 4) in vec2 iTex3;

layout(location = 0) out vec2 vTex0;
layout(location = 1) out vec2 vTex1;
layout(location = 2) out vec2 vTex2;
layout(location = 3) out vec2 vTex3;
layout(location = 4) out vec4 vColor;

//////////////////////////////////////////////////////////////////////////////////////////
// Vertex
void main ()
{
	vec4 HPos, P = iPos;

	{

		P.xy += 0.5f;	//	Bugs with rasterizer??? Possible half-pixel shift.
//		HPos.x = P.x/1024 * 2 - 1;
//		HPos.y = (P.y/768 * 2 - 1)*-1;
		HPos.x = P.x * screen_res.z * 2 - 1;
		HPos.y = (P.y * screen_res.w * 2 - 1)*-1;
		HPos.zw = P.zw;
	}

	vTex0 = iTex0;
	vTex1 = iTex1;
	vTex2 = iTex2;
	vTex3 = iTex3;

	gl_Position = HPos;
}