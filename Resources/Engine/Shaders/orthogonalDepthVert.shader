<shader>
	<type name = "vertexShader" />
	<uniform name = "ProjectViewModel" />
	<source>
	<!--
		#version 300 es
		precision highp float;

		// Fixed Attributes.
		in vec3 vPosition;
		in vec3 vNormal;
		in vec2 vTexture;

		uniform mat4 ProjectViewModel;
		
		void main()
		{
		  gl_Position = ProjectViewModel * vec4(vPosition, 1.0);
		}
	-->
	</source>
</shader>