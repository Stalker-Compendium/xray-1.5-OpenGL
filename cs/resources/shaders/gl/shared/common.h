//////////////////////////////////////////////////
//  All comments by Nivenhbro are preceded by !
/////////////////////////////////////////////////


#ifndef SHARED_COMMON_H
#define SHARED_COMMON_H

#define half        float
#define half2       vec2
#define half3       vec3
#define half4       vec4
#define float2      vec2
#define float3      vec3
#define float4      vec4
#define int2        ivec2
#define int3        ivec3
#define int4        ivec4
#define half3x3     mat3
#define half4x4     mat4
#define half3x4     mat3x4
#define float3x3    mat3
#define float4x4    mat4
#define float3x4    mat3x4

#define lerp        mix
#define frac        fract
#define saturate(a) clamp(a, 0.0, 1.0)
#define clip(x)		if (x < 0) discard
#define mul(a,b)	(a * b)
#define tex2D		texture2D
#define tex2Dproj	textureProj
#define tex2Dlod	textureLod
#define tex3D		texture
#define texCUBE 	texture
#define samplerCUBE	samplerCube

//
uniform half3x4		m_W;
uniform half3x4		m_V;
uniform half4x4 	m_P;
uniform half3x4		m_WV;
uniform half4x4 	m_VP;
uniform half4x4 	m_WVP;
//uniform float4x4 	m_texgen;
uniform float4x4 	mVPTexgen;
uniform half4		timers;
uniform half4		fog_plane;
uniform float4		fog_params;		// x=near*(1/(far-near)), ?,?, w = -1/(far-near)
uniform half4		fog_color;
uniform float3		L_sun_color;
uniform half3		L_sun_dir_w;
uniform half3		L_sun_dir_e;
uniform half4		L_hemi_color;
uniform half4		L_ambient;		// L_ambient.w = skynbox-lerp-factor
uniform float3 		eye_position;
uniform half3		eye_direction;
uniform half3		eye_normal;
uniform	float4 		dt_params;

#define unpack_D3DCOLOR(x)	x.bgra
half3 	unpack_normal	(half3 v)	{ return 2*v-1;			}
half3 	unpack_bx2	(half3 v)	{ return 2*v-1; 		}
float3 	unpack_bx4	(float3 v)	{ return 4*v-2; 		} //!reduce the amount of stretching from 4*v-2 and increase precision
float3 	unpack_bx4	(float4 v)	{ return unpack_bx4(v.xyz);	}

float2 	unpack_tc_base	(float2 tc, float du, float dv)		{
		return (tc.xy + float2	(du,dv))*(32.f/32768.f);	//!Increase from 32bit to 64bit floating point
}

float2 	unpack_tc_lmap	(half2 tc)	{ return tc*(1.f/32768.f);	} // [-1  .. +1 ] 

float 	calc_cyclic 	(float x)				{
	float 	phase 	= 1/(2*3.141592653589f);
	float 	sqrt2	= 1.4142136f;
	float 	sqrt2m2	= 2.8284271f;
	float 	f 	= sqrt2m2*frac(x)-sqrt2;	// [-sqrt2 .. +sqrt2] !No changes made, but this controls the grass wave (which is violent if I must say)
	return 	f*f - 1.f;				// [-1     .. +1]
}
float2 	calc_xz_wave 	(float2 dir2D, float frac)		{
	// Beizer
	float2  ctrl_A	= float2(0.f,		0.f	);
	float2 	ctrl_B	= float2(dir2D.x,	dir2D.y	);
	return  lerp	(ctrl_A, ctrl_B, frac);			//!This calculates tree wave. No changes made
}

#endif
