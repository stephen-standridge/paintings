
#version 120
varying vec3  texcoord;

void main()
{
 	vec4	texcoord0 = gl_ModelViewMatrix * gl_Vertex;
	texcoord = normalize(gl_Vertex.xyz);

  gl_Position    = ftransform();

}
