precision highp float;

uniform mat4 		modelViewProjectionMatrix;
uniform mat4 		modelViewMatrix;

attribute vec4 position;
varying vec3  texcoord;

void main()
{
 	vec4	texcoord0 = modelViewMatrix * position;
	texcoord = normalize(position.xyz);

  gl_Position    = modelViewProjectionMatrix * position;

}
