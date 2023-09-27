#version 330

in vec3 Color;

uniform vec3 SolidColor = vec3(-1,-1,-1);
uniform bool ComplimentaryEnabled = false;

out vec4 Fragment;

void main()
{
	vec3 colorShown = Color;

	if(SolidColor.r != -1.0 && SolidColor.g != -1.0 && SolidColor.b != -1.0)
		colorShown = SolidColor;

	if(ComplimentaryEnabled == true)
	{
		colorShown = vec3(1.0f, 1.0f, 1.0f) - colorShown;
	}

	Fragment = vec4(colorShown,1);
	return;
}